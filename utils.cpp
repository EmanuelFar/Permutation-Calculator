#include "utils.h"
#include <iostream>
#include <sstream>

bool validateArguments(int argc, char* argv[], int& permDim, int& permMax) {
    if (argc != 3 || !isdigit(*argv[1]) || !isdigit(*argv[2])) {
        std::cerr << "Invalid arguments <int><int>.\n";
        return false;
    }

    permDim = std::stoi(argv[1]);
    permMax = std::stoi(argv[2]);
    return true;
}

void displayMenu() {
    std::cout << "[1] Add Permutation" << std::endl;
    std::cout << "[2] Add Factorial" << std::endl;
    std::cout << "[3] Push to the Top" << std::endl;
    std::cout << "[4] Print" << std::endl;
    std::cout << "[5] Exit" << std::endl;
}

void processChoice(LL& ll, int choice, int permDim, int permMax) {
    switch (choice) {
        case 1:
            if (addPermutation(ll, permDim)) {
                ll.singlePrint();
            }
            break;
        case 2: {
            std::string buf;
            std::cin >> buf;
            if (addFactorial(ll, buf, permDim)) {
                ll.singlePrint();
            }
            break;
        }
        case 3: {
            std::string buf;
            std::cin >> buf;
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

bool addPermutation(LL& ll, int permDim) {
    std::string buf;
    std::cin >> buf;
    int* array = new int[permDim];

    if (ll.analyzeString(buf, array, permDim) && ll.insert(ll.getFactValue(array, permDim))) {
        delete[] array;
        return true;
    }

    delete[] array;
    return false;
}

bool addFactorial(LL& ll, std::string buf, int permDim) {
    int num;
    std::stringstream str(buf);
    str >> num;

    if ((num < 0 || num > (ll.calcFactorial(permDim) - 1)) || ll.searchElement(num)) {
        std::cerr << "Invalid or already exists factorial representation.\n";
        return false;
    }

    if (!ll.tryPushToTop(num, 1) || !ll.tryPushToTop(num, 2)) {
        std::cerr << "Invalid or already exists factorial representation.\n";
        return false;
    }

    if (ll.insert(num)) {
        return true;
    }

    return false;
}

bool pushToTop(LL& ll, std::string buf, int permDim) {
    int num;
    std::stringstream str(buf);
    str >> num;

    if (ll.getlength() == 0) {
        std::cerr << "Empty calculator.\n";
        return false;
    }

    if (num < 3 || num > permDim || !ll.tryPushToTop(ll.getHeadVal(), num)) {
        std::cerr << "Invalid or already exists factorial representation.\n";
        return false;
    }

    int newFactVal = ll.pushToTop(ll.getHeadVal(), num);
    if (ll.insert(newFactVal)) {
        return true;
    }

    return false;
}

void printOptions(LL& ll) {
    int printChoice;
    std::cout << "[1] Full Print" << std::endl;
    std::cout << "[2] Factorial Print" << std::endl;
    std::cout << "[3] Permutation Print" << std::endl;
    std::cin >> printChoice;

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
            std::cerr << "Invalid print option.\n";
            break;
    }
}
