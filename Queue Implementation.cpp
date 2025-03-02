#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Queue class implementation
class Queue {
public:
    queue<int> q;

    void enqueue(int value) {
        q.push(value);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    int front() {
        if (!q.empty()) {
            return q.front();
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// Job Scheduling (Round Robin)
void roundRobinScheduling(const Queue& jobQueue, int timeQuantum) {
    Queue q = jobQueue;  // Copy of the job queue
    cout << "Executing Job Scheduling (Round Robin):" << endl;

    while (!q.isEmpty()) {
        int job = q.front();
        q.dequeue();
        cout << "Executing job: " << job << endl;
        // Simulate job execution (we can simulate time taken by job execution)
    }
}

// Bank Queue System (First Come First Serve)
void bankQueueSystem(const Queue& bankQueue) {
    Queue q = bankQueue;  // Copy of the queue
    cout << "Bank Queue System (First Come First Serve):" << endl;

    while (!q.isEmpty()) {
        cout << "Serving customer with job number: " << q.front() << endl;
        q.dequeue();
    }
}

int main() {
    Queue jobQueue;
    Queue bankQueue;

    // Adding jobs/customers to queues
    jobQueue.enqueue(1);
    jobQueue.enqueue(2);
    jobQueue.enqueue(3);
    bankQueue.enqueue(101);
    bankQueue.enqueue(102);
    bankQueue.enqueue(103);

    // Job Scheduling (Round Robin)
    roundRobinScheduling(jobQueue, 5);

    // Bank Queue System
    bankQueueSystem(bankQueue);

    return 0;
}
