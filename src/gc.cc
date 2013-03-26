/**
 * Garbage collection support. Every C++ class can subscribe to be notified 
 * when its JS representation gets GC'ed.
 */

#include "gc.h"
#include "macros.h"

/**
 * GC handler: executed when given object dies
 * @param {v8::Value} object
 * @param {void *} ptr Pointer to GC instance
 */
void GC::handler(v8::Isolate * isolate, v8::Persistent<v8::Value> object, void * ptr) {
	GC * gc = (GC *) ptr;
	GC::objlist::iterator it = gc->data.begin();
	GC::objlist::iterator end = gc->data.end();
	while (it != end && it->first != object) { it++; }
	
	/* only if we have this one */
	if (it != end) { gc->go(it); }
}

/**
 * Add a method to be executed when object dies
 * @param {v8::Value} object Object to monitor
 * @param {char *} method Method name
 */
void GC::add(v8::Handle<v8::Value> object, GC::dtor_t dtor) {
	v8::Persistent<v8::Value> p = PERSISTENT(v8::Value, object);
	p.MakeWeak(v8::Isolate::GetCurrent(), (void *) this, &handler);
	this->data.push_back(std::pair<v8::Persistent<v8::Value>, GC::dtor_t>(p, dtor));
}

/**
 * Execute ongarbagecollection callback
 */
void GC::go(objlist::iterator it) {
	dtor_t dtor = it->second;
	dtor(it->first->ToObject());
	it->first.Dispose(v8::Isolate::GetCurrent());
	this->data.erase(it);
}

/**
 * Finish = execute all callbacks
 */
void GC::finish() {
	while (!this->data.empty()) {
		this->go(this->data.begin());
	}
	this->data.clear();
}
