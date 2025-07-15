# CP-Makefile
This is a Competetive Programming Boilerplate for writing competetive programming code:

input.txt:
- place to copy in inputs or change them yourself
- piped into code.cpp

code.cpp:
- cpp file containing the code
- takes in inputs from input.txt and outputs in terminal

bits/stdc++.h:
- a standard all-encompassing header file that includes all relevant CP datastructures
- modified from the https://gist.github.com/Einstrasse/ac0fe7d7450621a39364ed3b05cacd11 header file

Makefile:
- Compiles the input into the code.cpp file
- Creates the ./run executable which runs the code

Also, there is an algos cpp file where copy and pasted scratch work and/or algorithms can be put.

Note that to pipe the input to the executable, run cat input.txt | ./run