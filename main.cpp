#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string title;
    bool completed;
};

void showMenu() {
    cout << "\n--- TO-DO LIST MENU ---" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

void addTask(vector<Task>& tasks) {
    Task t;
    cout << "Enter task title: ";
    cin.ignore();
    getline(cin, t.title);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n--- Your Tasks ---" << endl;
    if (tasks.empty()) {
        cout << "No tasks yet!" << endl;
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].title;
        if (tasks[i].completed) cout << " [Done]";
        cout << endl;
    }
}

void deleteTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "Welcome to your To-Do List App!" << endl;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: deleteTask(tasks); break;
            case 4: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}
// This is a simple console-based To-Do List application in C++.