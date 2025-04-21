#include <iostream>
#include "TaskManager.h"
using namespace std;

void showMenu() {
    cout << "\n--- TO-DO LIST MENU ---" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Mark Task as Done/Undone" << endl;
    cout << "5. Search Tasks" << endl;
    cout << "6. Filter Completed" << endl;
    cout << "7. Filter Pending" << endl;
    cout << "8. Sort Tasks A-Z" << endl;
    cout << "9. Exit" << endl;
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

        string keyword;

switch (choice) {
    case 1: manager.addTask(); break;
    case 2: manager.viewTasks(); break;
    case 3: manager.deleteTask(); break;
    case 4: manager.toggleTask(); break;
    case 5:
        cout << "Enter keyword to search: ";
        cin.ignore();
        getline(cin, keyword);
        manager.searchTasks(keyword);
        break;
    case 6: manager.filterTasks(true); break;
    case 7: manager.filterTasks(false); break;
    case 8: manager.sortTasks(); break;
    case 9:
        manager.saveToFile(filename);
        cout << "Goodbye!" << endl;
        break;
    default: cout << "Invalid choice." << endl;
}

        
    } while (choice != 9);

    return 0;
}
