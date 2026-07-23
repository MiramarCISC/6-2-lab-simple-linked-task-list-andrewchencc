[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=24260983)
# CISC 192 Lab 6.2: Simple Linked Task List

## Overview

In this lab, you will build a simple task list using pointers and a linked list.

Each task is stored in a dynamically allocated node. Each node contains a task description, a priority, and a pointer to the next node.

## Learning Goals

By completing this lab, you will practice:

- Defining structures
- Using pointers
- Using `nullptr`
- Dynamically allocating nodes with `new`
- Releasing nodes with `delete`
- Inserting nodes into a linked list
- Traversing a linked list
- Searching a linked list
- Removing nodes from a linked list
- Running automated tests with `make test`

## Required Features

Your program must:

- Define a `Task` structure
- Define a `TaskNode` structure
- Insert tasks at the front of the linked list
- Count the number of tasks
- Search for a task by description
- Mark a task complete
- Remove completed tasks
- Print all tasks
- Clear the full list before the program exits
- Pass the automated tests

## Build and Run

```bash
make
./main
```

## Run Tests

```bash
make test
```

## Required Functions

```cpp
bool isValidPriority(int priority);
Task createTask(std::string description, int priority);

void insertFront(TaskNode*& head, Task task);
int countTasks(const TaskNode* head);
TaskNode* findTask(TaskNode* head, std::string description);
bool markTaskComplete(TaskNode* head, std::string description);
int removeCompletedTasks(TaskNode*& head);
void clearTasks(TaskNode*& head);

void printTask(const Task& task);
void printTasks(const TaskNode* head);
```

## Grading Notes

This lab is about pointers and linked lists. Do not replace the linked list with an array or `std::vector`.

Every node created with `new` must eventually be released with `delete`.
