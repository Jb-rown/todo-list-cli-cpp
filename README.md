# 📝 C++ Command-Line To-Do List App

A modern, beginner-friendly C++ command-line To-Do List application for managing daily tasks. Supports task creation, editing, completion, due dates, and file persistence.

## 🚀 Features

- Add, view, update, and delete tasks
- Set and track due dates
- Mark tasks as completed
- Save/load tasks from file
- Highlight overdue tasks
- Export tasks to CSV
- Simple CLI interface

## 🧠 Tech Used

- C++17
- Standard Library: `<fstream>`, `<vector>`, `<string>`, `<ctime>`, `<sstream>`
- Terminal colors using ANSI escape codes (optional)
- Built with simplicity and readability in mind for beginners

---

## 📂 Project Structure
```
todo-list-app/
            ├── main.cpp # Entry point 
            ├── TaskManager.h # Header file for task manager 
            ├── TaskManager.cpp # Logic and implementation 
            ├── tasks.txt # Saved tasks 
            ├── tasks.csv # Exported task list (optional) 
            ├── README.md # You are here 
            └── .gitignore # Ignore compiled binaries, etc.

```
---

## 🛠 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/yourusername/todo-list-app.git
cd todo-list-app
```
### 2. Compile the program

Using g++:
```bash

    g++ main.cpp TaskManager.cpp -o todo
```
 ### 3. Run it
```bash

 ./todo   # Linux/Mac
todo.exe # Windows (or just run `todo` in PowerShell)
```
## 📷 Sample Output
```pgsql
==== TO-DO LIST MENU ====
1. Add Task
2. View Tasks
3. Edit Task
4. Delete Task
5. Mark Task as Completed
6. Search Task by Title
7. Filter Tasks by Completion
8. Filter Tasks by Date
9. Export Tasks to CSV
10. Load Tasks from File
11. Exit
=========================
```
## 📅 Task Format

### Each task includes:

- Title

- Description

- Due date (YYYY-MM-DD)

- Completion status (Done/Not done)


## ✅ Example
Add task:
```yaml
Title: Finish report
Description: Complete the annual report
Due date: 2025-04-28
```
Output:
```less
1. Finish report [!! OVERDUE !!] (Due: 2025-04-01)
```
📦 Exported CSV
```javascript
Title,Description,Due Date,Completed
Finish report,Complete the annual report,2025-04-28,false
```
## ✨ Future Improvements (Optional Ideas)
- GUI version with Qt or wxWidgets

- Category/labels

- Notifications

- Task priority levels

- Sync with online storage or server


## 🤝 Contributing
Pull requests are welcome! If you’d like to contribute:

Fork the repo

Create a feature branch

Submit a pull request

