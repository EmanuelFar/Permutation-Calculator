# Permutation Calculator

## Overview
Excercise no.1 as a CS student.
Permutation Calculator is a C++ project designed to manipulate and manage permutations using linked lists. This project involves inserting permutations into a linked list, validating them, converting between factorial values and permutations, and performing permutation transformations.

## Features

- **Linked List Management:** Store and manage permutations as factorial values within a linked list.
- **Permutation Validation:** Check and validate new permutations before insertion.
- **Factorial and Permutation Conversion:** Convert between factorial values and their corresponding permutations.
- **Permutation Manipulation:** Perform the Push-to-Top (PT) algorithm on permutations and update the list.
  
## Usage
You can use the LL class to manage permutations stored as factorial values. Below are some common operations:

Insert a permutation: Inserts a new permutation into the linked list after validating its first two values.
Search for a permutation: Checks if a permutation (by its factorial value) exists in the list.
Convert between factorial values and permutations: Provides methods to convert between factorial values and their corresponding permutations.
Print the list: Various functions to print the linked list in different formats.
## Prerequisites

- C++11 or later
- A C++ compiler (e.g., g++)

## Installation

Clone the repository:

``bash
git clone https://github.com/your-username/permutation-calculator.git
cd permutation-calculator``



## Compile the project:

Manually compiling:
g++ -std=c++11 -o permutation_calculator LL.cpp main.cpp

Arguments to main:

< Permutation Dimention > ( ((1, 3, 2) is a permutation of dimention 3.) , < Max Number of permutations > (3! for the exmaple, for big numbers insert a reasonable number, not neccesarily n!) 

## Run the executable
./permutation_calculator


