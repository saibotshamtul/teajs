# Json-Rpc handler module #

Defined in file `jsonRpcHandler.js`.

Based on the [JSON-RPC 2.0 Specification proposal](http://groups.google.com/group/json-rpc/web/json-rpc-1-2-proposal).

### Code example ###
 var jsonRpcHandler = require("jsonRpcHandler.js").jsonRpcHandler;

 jsonRpcHandler({

	multiply: function(opts) {
		// Do what you want...
		return opts.a*opts.b;
	}
	
 );

}}```