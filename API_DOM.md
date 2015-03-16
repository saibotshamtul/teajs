# DOM module #

Defined in file `dom.js`.

Classes: **Document**, **XMLSerializer**, **DOMParser**.

This JS module implements a large subset of the XML portion of DOM as described at https://developer.mozilla.org/en/dom.

Example usage:

```
var DOM = require("dom");
var parser = new DOM.DOMParser();
var serializer = new DOM.XMLSerializer();

var xmlStr = "<root><node1 /><node2 a='b'>xxx</node2></root>";
var xmlDoc = parser.parseFromString(xmlStr);
system.stdout.writeLine(xmlDoc.getElementsByTagName("node2")[0].getAttribute("a") + "\n");
system.stdout.writeLine(serializer.serializeToString(xmlDoc));
```