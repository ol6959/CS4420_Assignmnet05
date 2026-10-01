#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void simulateFCFS(vector<Process>& processes);
void simulateRR(vector<Process>& processes, int quantum);
void simulateSJF(vector<Process>& processes);

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    
    int remainingTime;
    int startTime;
    int endTime;
    int waitingTime;

    bool completed;
};


int main(int argc, char* argv[]){

    if (argc < 3) {
        cout << "Usage proj2 input_file [FCFS | RR | SJF] [time_quantum]" << endl;
        return 1;
    }

    string filename = argv[1];
    string algorithm = argv[2];

    ifstream input(filename);

    if (!input) {
        cout << "Error: Could not open input file." << endl;
        return 1;
    }

    int numProcesses;
    input >> numProcesses;

    vector<Process> processes;

    for (int i = 0; i < numProcesses; i++) {
        Process p;

        input >> p.pid;
        input >> p.arrivalTime;
        input >> p.burstTime;

        p.remainingTime = p.burstTime;
        p.startTime = -1;
        p.endTime = -1;
        p.waitingTime = 0;
        p.completed = false;

        processes.push_back(p);
    }

    input.close();

    cout << "Loaded " << numProcesses << " processes." << endl;

    if (algorithm == "FCFS") {
        simulateFCFS(processes);
    }
    else if (algorithm == "SJF") {
        simulateSJF(processes);
    }
    else if (algorithm == "RR") {
        int quantum = 0;//////////tmp remove when def completed
        simulateRR(processes, quantum);
    }
    else {
        cout << "Unknown scheduling algorithm." << endl;
        return 1;
    }

    return 0;



    return 0;
}


