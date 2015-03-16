# ActiveRecord.js module #

Defined in file `active_record.js`.

More info on [activerecordjs.org](http://www.activerecordjs.org/record.html).

A new adapter has been added to support TeaJS's MySql module: ActiveRecord.Adapters.TeaJSMySQL

Classes: **ActiveRecord**.

  * `ActiveRecord.connect(adapter, {user: 'myUsername', pass: 'myPass', name: 'dbName'})` - adapter should be ActiveRecord.Adapters.TeaJSMySQL
  * `ActiveRecord.create(tableName, oAttributes[, methods])` - creates a model


### Code example ###
```

var ActiveRecord = require('active_record').ActiveRecord;

ActiveRecord.connect(ActiveRecord.Adapters.TeaJSMySQL, {
	user: 'root', 
	pass: 'root', 
	name: 'testdb'
});


var User = ActiveRecord.create('users',{
    username: '',
    password: '',
    post_count: 0,
    profile: {
        type: 'TEXT',
        value: ''
    }
},{
    getProfileWordCount: function(){
        return this.get('profile').split(/\s+/).length;
    }
});

var jessica = User.create({
    username: 'Jessica',
    password: 'rabbit'
});

/*
jessica.username // 'Jessica'  
jessica.get('username'); // 'Jessica'  
jessica.username = 'new username';  
jessica.get('username'); // 'Jessica'  
jessica.set('username','new username');  
jessica.get('username'); // 'new username'
*/

User.findByUsername('Jessica');  
User.findAllByPassword(''); //finds all with blank passwords

```