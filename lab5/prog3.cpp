#include <iostream>
using namespace std;

class Process {
public:
    int time;
    Process* next;

    Process(int t) {
        time = t;
        next = nullptr;
    }
};

class RoundRobinScheduler {
private:
    Process* tail;
    int timeSlice;

public:
    RoundRobinScheduler(int slice) {
        tail = nullptr;
        timeSlice = slice;
    }

   
    void insertProcess(int t) {
        Process* newProcess = new Process(t);
        if (!tail) {
            tail = newProcess;
            tail->next = tail;
        } else {
            newProcess->next = tail->next;
            tail->next = newProcess;
            tail = newProcess;
        }
    }

    
    void execute() {
        if (!tail) {
            cout << "No processes in the queue.\n";
            return;
        }

        Process* head = tail->next;  
        cout << "Executing process with time: " << head->time << endl;

        head->time -= timeSlice;
        if (head->time <= 0) {
            cout << "Process completed.\n";
            if (head == tail) {  
                delete head;
                tail = nullptr;
            } else {
                tail->next = head->next;
                delete head;
            }
        } else {
            cout << "Remaining time: " << head->time << ", moving to end of queue.\n";
            tail = head;  
        }
    }

    // Display the process queue
    void display() {
        if (!tail) {
            cout << "No processes in the queue.\n";
            return;
        }
        Process* temp = tail->next;
        cout << "Process queue: ";
        do {
            cout << temp->time << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(HEAD)\n";
    }

   
    ~RoundRobinScheduler() {
        while (tail) {
            execute();  
        }
    }
};

int main() {
    int timeSlice;
    cout << "Enter time slice: ";
    cin >> timeSlice;

    RoundRobinScheduler scheduler(timeSlice);
    int choice, time;

    do {
        cout << "\n1. Insert Process\n2. Execute\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> time;
                scheduler.insertProcess(time);
                break;
            case 2:
                scheduler.execute();
                scheduler.display();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
