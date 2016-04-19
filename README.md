# bfInterpreter
A very simple brainf\*ck interpreter I pieced together in C++. 

" Brainfuck is an esoteric programming language created in 1993 by Urban Müller, and notable for its extreme minimalism.
The language consists of only eight simple commands and an instruction pointer. While it is fully Turing-complete, it is not intended for practical use, but to challenge and amuse programmers. " -from Wikipedia

The 8 commands are :

| Command        | Explanation           | 
| ------------- |:-------------:| 
| >   |increment the data pointer  | 
| < |    decrement the data pointer   |    
| + | increment the byte at the data pointer     |  
| - |decrement the byte at the data pointer    |    
| . | output the byte at the data pointer      |   
| , | accept one byte of input, storing its value in the byte at the data pointer      |   
| [ | if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command     |   
| ] |if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command      |    



The interpreter reads a file containing bf code and stores contents in the instruction memory. It ignores any non-bf characters.
It then proceeds to execute the commands one by one. 

The data memory and the instruction memory are 30,000 bytes each (arbitrary number )

 
