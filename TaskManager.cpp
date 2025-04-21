#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime> 
#include <sstream>

#define RED     "\033[1;31m"
#define RESET   "\033[0m"
// #define GREEN   "\033[1;32m"
using namespace std;

void TaskManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t first = line.find(',');
        size_t second = line.find(',', first + 1);
        if (first != string::npos && second != string::npos) {
            Task t;
            t.title = line.substr(0, first);
            t.completed = (line.substr(first + 1, second - first - 1) == "1");
            t.dueDate = line.substr(second + 1);
            tasks.push_back(t);
        }
    }
    file.close();
}

void TaskManager::saveToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& t : tasks) {
        file << t.title << "," << t.completed << "," << t.dueDate << endl;
    }
    file.close();
}


void TaskManager::addTask() {
    Task t;
    cout << "Enter task title: ";
    cin.ignore();
    getline(cin, t.title);

    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, t.dueDate);

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
        else if (isOverdue(tasks[i].dueDate)) cout << RED << " [!! OVERDUE !!]" << RESET;
        else cout << " [Pending]";
        // Display due date if it's not empty
       // if (!tasks[i].dueDate.empty())

    
        cout << " (Due: " << tasks[i].dueDate << ")" << endl;
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

void TaskManager::toggleTask() {
    viewTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to mark as done/undone: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = !tasks[index - 1].completed;
        cout << "Task status updated!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void TaskManager::searchTasks(const string& keyword) const {
    cout << "\n--- Search Results for '" << keyword << "' ---" << endl;
    bool found = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].title.find(keyword) != string::npos) {
            cout << i + 1 << ". " << tasks[i].title;
            if (tasks[i].completed) cout << " [Done]";
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "No matching tasks found." << endl;
}

void TaskManager::filterTasks(bool showCompleted) const {
    cout << (showCompleted ? "\n--- Completed Tasks ---" : "\n--- Pending Tasks ---") << endl;
    bool found = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].completed == showCompleted) {
            cout << i + 1 << ". " << tasks[i].title << endl;
            found = true;
        }
    }
    if (!found) cout << "No tasks match this filter." << endl;
}

void TaskManager::sortTasks() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.title < b.title;
    });
    cout << "Tasks sorted alphabetically!" << endl;
}

void TaskManager::exportToCSV(const string& filename) const {
    ofstream file(filename);
    file << "Title,Completed,Due Date\n";
    for (const auto& t : tasks) {
        file << "\"" << t.title << "\","
             << (t.completed ? "Yes" : "No") << ","
             << t.dueDate << "\n";
    }
    file.close();
    cout << "Tasks exported to " << filename << "!" << endl;
}

bool TaskManager::isEmpty() const {
    return tasks.empty();
}


bool isOverdue(const string& dueDate) {
    if (dueDate.empty()) return false;

    time_t now = time(0);
    tm* ltm = localtime(&now);

    int yearNow = 1900 + ltm->tm_year;
    int monthNow = 1 + ltm->tm_mon;
    int dayNow = ltm->tm_mday;

    int y, m, d;
    char sep;
    stringstream ss(dueDate);
    ss >> y >> sep >> m >> sep >> d;

    if (y < yearNow) return true;
    if (y == yearNow && m < monthNow) return true;
    if (y == yearNow && m == monthNow && d < dayNow) return true;

    return false;
}
