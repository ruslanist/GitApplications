In the terminale of Linux you need to connect the MPI library 
Command: sudo apt-get install mpich

We collect the program for launch under MPI
Then use the terminal to enter Command:
mpicxx.mpich /path/to/Trapezoidal2.cpp -o trapezoidal

This command is mpicxx.mpich is an analog of g ++. The first parameter is the path to the sipipi file. The second parameter is -o and the name of the output file is the executable file.

Then, that you start using this command Enter:
mpirun.mpich -np 4 ./trapezoidal

Here mpirun.mpich is the name of the trigger, -np 4 is the flag that says that you need to run all 4 computers. Well, ./trapezoidal is the path to the executable file, to the executable, which will be executed on 4 computers.

