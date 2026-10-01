#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

void simulateFCFS(vector<Process>& processes);
void simulateRR(vector<Process>& processes, int quantum);
void simulateSJF(vector<Process>& processes);




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
        int quantum = stoi(argv[3]);
        simulateRR(processes, quantum);
    }
    else {
        cout << "Unknown scheduling algorithm." << endl;
        return 1;
    }

    return 0;



    return 0;
}

void simulateFCFS(vector<Process>& processes){

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < processes.size()) {

        int selected = -1;

        // Find the first process that has arrived
        // and has not completed yet.
        for (int i = 0; i < processes.size(); i++) {

            if (!processes[i].completed &&
                processes[i].arrivalTime <= currentTime) {

                if (selected == -1 ||
                    processes[i].arrivalTime < processes[selected].arrivalTime) {

                    selected = i;
                }
            }
        }

        // No process is ready
        if (selected == -1) {
            cout << "Time " << currentTime << ": CPU idle" << endl;
            currentTime++;
            continue;
        }

        // Record when this process starts
        processes[selected].startTime = currentTime;

        cout << "Time " << currentTime
             << ": PID " << processes[selected].pid
             << " starts" << endl;

        // Run the process until it finishes
        currentTime += processes[selected].burstTime;

        // Record when it finishes
        processes[selected].endTime = currentTime;

        processes[selected].remainingTime = 0;
        processes[selected].completed = true;

        // Waiting time
        processes[selected].waitingTime =
            processes[selected].startTime -
            processes[selected].arrivalTime;

        cout << "Time " << currentTime
             << ": PID " << processes[selected].pid
             << " finishes" << endl;

        completedProcesses++;
    }

    // Print results
    cout << endl;
    cout << "PID\tArrival\tStart\tEnd\tRunning\tWaiting" << endl;

    int totalWaitingTime = 0;

    for (const Process& p : processes) {

        cout << p.pid << "\t"
             << p.arrivalTime << "\t"
             << p.startTime << "\t"
             << p.endTime << "\t"
             << p.burstTime << "\t"
             << p.waitingTime << endl;

        totalWaitingTime += p.waitingTime;
    }

    double averageWaitingTime =
        static_cast<double>(totalWaitingTime) / processes.size();

    cout << endl;
    cout << "Average Waiting Time: "
         << averageWaitingTime << endl;
}

void simulateRR(vector<Process>& processes, int quantum) {

}

void simulateSJF(vector<Process>& processes) {

}
