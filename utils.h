#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "LL.h" // Include your LinkedList header here

bool validateArguments(int argc, char* argv[], int& permDim, int& permMax);
void displayMenu();
void processChoice(LL& ll, int choice, int permDim, int permMax);
bool addPermutation(LL& ll, int permDim);
bool addFactorial(LL& ll, std::string buf, int permDim);
bool pushToTop(LL& ll, std::string buf, int permDim);
void printOptions(LL& ll);

#endif // UTILS_H
