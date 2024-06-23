Permutation Calculator

Overview


Permutation Calculator is a C++ project designed to manipulate and manage permutations using linked lists. This project involves inserting permutations into a linked list, validating them, converting between factorial values and permutations, and performing permutation transformations.

Features
Linked List Management: Store and manage permutations as factorial values within a linked list.
Permutation Validation: Check and validate new permutations before insertion.
Factorial and Permutation Conversion: Convert between factorial values and their corresponding permutations.
Permutation Manipulation: Perform the Push-to-Top (PT) algorithm on permutations and update the list.


Prerequisites
C++11 or later
A C++ compiler (e.g., g++)



git clone https://github.com/your-username/permutation-calculator.git
cd permutation-calculator
Compile the project:

Manually compiling:
g++ -std=c++11 -o permutation_calculator LL.cpp main.cpp

Run the executable
./permutation_calculator


Usage
You can use the LL class to manage permutations stored as factorial values. Below are some common operations:

Insert a permutation: Inserts a new permutation into the linked list after validating its first two values.
Search for a permutation: Checks if a permutation (by its factorial value) exists in the list.
Convert between factorial values and permutations: Provides methods to convert between factorial values and their corresponding permutations.
Print the list: Various functions to print the linked list in different formats.
