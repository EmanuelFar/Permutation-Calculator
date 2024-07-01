#include <iostream>
#include "LL.h"
#include "utils.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    int permDim, permMax;
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
        if (choice < 1 || choice > 5) {
            cerr << "Invalid option.\n";
            continue;
        }
        if (ll.getlength() >= permMax) {
            cerr << "Full calculator.\n";
            continue;
        }

        // Process user choice
        processChoice(ll, choice, permDim, permMax);
    }

    return 0;
}
