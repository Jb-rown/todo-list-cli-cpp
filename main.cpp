#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Welcome to your To-Do List App!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "! Let's get productive." << endl;
    return 0;
}