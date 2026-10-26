# BankManagementSystem
A C++ based Bank Management System that simulates basic banking operations such as account creation, deposit, withdrawal, and balance inquiry. The project uses Object-Oriented Programming (OOP) concepts and file handling to store customer account details and maintain records between program executions. 

# Bank Management System

A console-based banking application developed using C++ to demonstrate Object-Oriented Programming and file handling.

## Features

- Create a new customer account
- Deposit money
- Withdraw money
- Check account balance
- Save account records locally
- Retain account information between program runs

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- Vectors and Functions

## How to Run

Compile the program:

```bash
g++ main.cpp -o bank
```

Run on Windows:

```powershell
.\bank.exe
```

## Data Storage

Account records are stored locally in `accounts.txt`. The application loads saved records when it starts and updates the file after banking operations.

## Project Purpose

This project was developed to practise C++ programming, classes, functions, conditional statements, loops, and file handling.

## Note

This is an educational project. It does not implement production-grade security and must not be used to store real banking information.