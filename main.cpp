#include <iostream>
#include <queue>
using namespace std;

// Task structure
struct Task {
    string name;
    int priority;
    int duration;

    // For priority queue (max heap)
    bool operator<(const Task& t) const {
        return priority < t.priority;
    }
};

int main() {
    priority_queue<Task> pq;
    int n;

    cout << "----- Brain Inspired Task Scheduler -----\n";
    cout << "Enter number of tasks: ";
    cin >> n;

    // Input tasks
    for(int i = 0; i < n; i++) {
        Task t;
        cout << "\nEnter Task Name: ";
        cin >> t.name;

        cout << "Enter Priority (higher = more important): ";
        cin >> t.priority;

        cout << "Enter Duration: ";
        cin >> t.duration;

        pq.push(t);
    }

    cout << "\n--- Task Execution Order ---\n";

    int time = 0;

    while(!pq.empty()) {
        Task current = pq.top();
        pq.pop();

        // Brain-inspired behavior
        if(current.priority >= 8) {
            cout << "\n⚡ Urgent signal detected! Executing immediately.\n";
        }

        cout << "Executing Task: " << current.name
             << " | Priority: " << current.priority << endl;

        cout << "Waiting Time: " << time << endl;

        time += current.duration;
    }

    cout << "\nAll tasks executed successfully.\n";

    return 0;
}
