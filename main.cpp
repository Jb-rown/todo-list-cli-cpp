#include <iostream>
#include "TaskManager.h"
using namespace std;

void showMenu() {
    cout << "\n--- TO-DO LIST MENU ---" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Mark Task as Done/Undone" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}


int main() {
    TaskManager manager;
    string filename = "tasks.txt";

    manager.loadFromFile(filename);

    int choice;
    cout << "Welcome to your To-Do List App!" << endl;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: manager.addTask(); break;
            case 2: manager.viewTasks(); break;
            case 3: manager.deleteTask(); break;
            case 4: manager.toggleTask(); break;
            case 5:
                manager.saveToFile(filename);
                cout << "Goodbye!" << endl;
                break;
            default: cout << "Invalid choice." << endl;
        }
        
    } while (choice != 5);

    return 0;
}
