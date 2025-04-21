#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>
using namespace std;

struct Task {
    string title;
    bool completed;
    string dueDate; // e.g., "2025-04-25"
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
    void toggleTask();
    void searchTasks(const string& keyword) const;
    void filterTasks(bool showCompleted) const;
    void sortTasks();
    void exportToCSV(const string& filename) const;
   


    bool isEmpty() const;
};
bool isOverdue(const std::string& dueDate);
#endif
