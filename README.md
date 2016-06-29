# Lua-Cidr

> Experimental check whether ip in given range.

Example:

```
local network = require("network")

if network.inCidr("127.0.0.1", "127.0.0.1/32")
then
   print("Yes")
else
   print("No")
end
```
