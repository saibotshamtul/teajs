# Mail module #

Defined in file `mail.js`.

Functions: **mail()**.

```
var to = "target@example.com";
var subject = "test";
var body = "testing the mail!";
var headers = { From: "me@example.com" };
var auth = {
  type: "login",
  user: "test",
  password: "secret"
};

require("mail").mail(to, subject, body, headers, auth);
```