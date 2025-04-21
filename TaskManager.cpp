#include "TaskManager.h"
#include <iostream>
#include <fstream>
using namespace std;

void TaskManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t comma = line.find(',');
        if (comma != string::npos) {
            Task t;
            t.title = line.substr(0, comma);
            t.completed = (line.substr(comma + 1) == "1");
            tasks.push_back(t);
        }
    }
    file.close();
}

void TaskManager::saveToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& t : tasks) {
        file << t.title << "," << t.completed << endl;
    }
    file.close();
}

void TaskManager::addTask() {
    Task t;
    cout << "Enter task title: ";
    cin.ignore();
    getline(cin, t.title);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added!" << endl;
}

void TaskManager::viewTasks() const {
    cout << "\n--- Your Tasks ---" << endl;
    if (tasks.empty()) {
        cout << "No tasks yet!" << endl;
        return;
    }
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].title;
        if (tasks[i].completed) cout << " [Done]";
        cout << endl;
    }
}

void TaskManager::deleteTask() {
    viewTasks();
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

bool TaskManager::isEmpty() const {
    return tasks.empty();
}
