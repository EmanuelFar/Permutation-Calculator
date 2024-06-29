#include <iostream>
#include "LL.h"
#include <sstream>

using namespace std;

// Function prototypes
bool validateArguments(int argc, char* argv[], int& permDim, int& permMax);
void displayMenu();
void processChoice(LL& ll, int choice, int permDim, int permMax);
bool addPermutation(LL& ll, int permDim);
bool addFactorial(LL& ll, string buf, int permDim);
bool pushToTop(LL& ll, string buf, int permDim);
void printOptions(LL& ll);

int main(int argc, char* argv[]) {
    int permDim, permMax;

    // Validate and parse command line arguments
    if (!validateArguments(argc, argv, permDim, permMax)) {
        return -1;
    }

    // Create an instance of the LinkedList class
    LL ll(permDim);

    // Display menu options
    displayMenu();

    int choice;
    while (true) {
        cin >> choice;

        // Exit option
        if (choice == 5) {
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            cerr << "Invalid option.\n";
            continue;
        }

        // Check if the calculator is full
        if (ll.getlength() >= permMax) {
            cerr << "Full calculator.\n";
            continue;
        }

        // Process user choice
        processChoice(ll, choice, permDim, permMax);
    }

    return 0;
}

// Function to validate and parse command line arguments
bool validateArguments(int argc, char* argv[], int& permDim, int& permMax) {
    if (argc != 3 || !isdigit(*argv[1]) || !isdigit(*argv[2])) {
        cerr << "Invalid arguments <int><int>.\n";
        return false;
    }

    permDim = stoi(argv[1]);
    permMax = stoi(argv[2]);
    return true;
}

// Function to display menu options
void displayMenu() {
    cout << "[1] Add Permutation" << endl;
    cout << "[2] Add Factorial" << endl;
    cout << "[3] Push to the Top" << endl;
    cout << "[4] Print" << endl;
    cout << "[5] Exit" << endl;
}

// Function to process user choice
void processChoice(LL& ll, int choice, int permDim, int permMax) {
    switch (choice) {
        case 1:
            if (addPermutation(ll, permDim)) {
                ll.singlePrint();
            }
            break;
        case 2: {
            string buf;
            cin >> buf;
            if (addFactorial(ll, buf, permDim)) {
                ll.singlePrint();
            }
            break;
        }
        case 3: {
            string buf;
            cin >> buf;
            if (pushToTop(ll, buf, permDim)) {
                ll.singlePrint();
            }
            break;
        }
        case 4:
            printOptions(ll);
            break;
    }
}

// Function to add a permutation to the linked list
bool addPermutation(LL& ll, int permDim) {
    string buf;
    cin >> buf;
    int* array = new int[permDim];

    if (ll.analyzeString(buf, array, permDim) && ll.insert(ll.getFactValue(array, permDim))) {
        delete[] array;
        return true;
    }

    delete[] array;
    return false;
}

// Function to add a factorial to the linked list
bool addFactorial(LL& ll, string buf, int permDim) {
    int num;
    stringstream str(buf);
    str >> num;

    if ((num < 0 || num > (ll.calcFactorial(permDim) - 1)) || ll.searchElement(num)) {
        cerr << "Invalid or already exists factorial representation.\n";
        return false;
    }

    if (!ll.tryPushToTop(num, 1) || !ll.tryPushToTop(num, 2)) {
        cerr << "Invalid or already exists factorial representation.\n";
        return false;
    }

    if (ll.insert(num)) {
        return true;
    }

    return false;
}

// Function to push to the top of the specified stack
bool pushToTop(LL& ll, string buf, int permDim) {
    int num;
    stringstream str(buf);
    str >> num;

    if (ll.getlength() == 0) {
        cerr << "Empty calculator.\n";
        return false;
    }

    if (num < 3 || num > permDim || !ll.tryPushToTop(ll.getHeadVal(), num)) {
        cerr << "Invalid or already exists factorial representation.\n";
        return false;
    }

    int newFactVal = ll.pushToTop(ll.getHeadVal(), num);
    if (ll.insert(newFactVal)) {
        return true;
    }

    return false;
}

// Function to handle printing options
void printOptions(LL& ll) {
    int printChoice;
    cout << "[1] Full Print" << endl;
    cout << "[2] Factorial Print" << endl;
    cout << "[3] Permutation Print" << endl;
    cin >> printChoice;

    switch (printChoice) {
        case 1:
            ll.fullPrint();
            break;
        case 2:
            ll.factPrint();
            break;
        case 3:
            ll.permPrint();
            break;
        default:
            cerr << "Invalid print option.\n";
            break;
    }
}
