# SysHook

CREDITS:
This project was not my idea. 
The credits for that go to Creo#0444 (for coming up with the original idea) and Ghoul#6066 (further interest in the idea)
The hook code is credit to BTBD, specifically his access project.

INFO:
This project is comprised of a target process and a DLL.
You can inject the dll into the target process which will hook the system function and output what it says to a file.
You can change this however you like and even make it call the system function after it prints the commands.

EXTRA INFO:
I don't feel like adding images to this to show it works but feel free to compile and test for yourself (x64 release)

One thing I just caught is the System_t. It should be System_f not to confuse you with a template versus a function.
