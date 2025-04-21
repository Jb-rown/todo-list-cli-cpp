#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>
using namespace std;

struct Task {
    string title;
    bool completed;
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);

    void addTask();
    void viewTasks() const;
    void deleteTask();

    bool isEmpty() const;
};

#endif
