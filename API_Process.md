# Process control module #

Defined in file `js_process.cc`. Not complete at all.

Classes: **Process**.

  * `var p = new Process()` - creates new Process object
  * `var code = p.system(command)` - executes a given `command`, returns its exit code
  * `var data = p.exec(command)` - executes a given `command`, returns its output