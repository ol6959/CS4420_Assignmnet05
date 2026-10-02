# CS4420_Assignmnet05

Introduction 

The goal of this project was to create a CPU scheduling simulator in C++ that implements three scheduling algorithms: First Come First Serve (FCFS), Shortest Job First (SJF), and Round Robin (RR). The program reads process information from an input file, simulates scheduling, and calculates the average waiting time for the processes. 

Compilation and Execution 

The project uses CMake to configure and build the C++ program. To compile the program, a build directory is created inside the project directory. The following commands are used: 

mkdir build 
cd build 
cmake .. 
cmake --build . 

After the build completes successfully, the executable is named proj2. 

The program uses the following command-line format: 

./proj2 input_file [FCFS|RR|SJF] [time_quantum] 

For FCFS, the program can be run using: 

./proj2 ../input1.txt FCFS 

For SJF: 

./proj2 ../input1.txt SJF 

For Round Robin, a time quantum must also be provided. For example, using a time quantum of 5 milliseconds: 

./proj2 ../input1.txt RR 5 

The input file contains the number of processes on the first line, followed by the process ID, arrival time, and burst time for each process. 

 