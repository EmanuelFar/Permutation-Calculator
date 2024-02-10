#include <iostream>
#include "LL.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    // Check the correct number and type of arguments.
    if (argc != 3 || !isdigit(*argv[1]) || !isdigit(*argv[2])) {
        cerr << "Invalid arguments <int><int>.\n";
        return -1;
    }
    int permDim = stoi(argv[1]), permMax = stoi(argv[2]);
    // Create an instance of the LinkedList class
    LL ll(permDim);
    // Display menu options
    cout << "[1] Add Permutation" << endl;
    cout << "[2] Add Factorial" << endl;
    cout << "[3] Push to the Top" << endl;
    cout << "[4] Print" << endl;
    cout << "[5] Exit" << endl;
    int choice = 0;
    while (true) {
        string buf;
        cin >> choice;
        if(choice == 5){
            break;
        }
        // Check the user's choice
        else if (choice < 1 || choice > 5) {
            cerr << "Invalid option.\n";
            continue;
        }
        // Check if the calculator is full
        if (ll.getlength() >= permMax) {
            cerr << "Full calculator.\n";
            continue;
        }
        switch (choice) {
            case 1: {
                cin >> buf;
                int *array = new int[permDim];
                // Analyze and insert the permutation into the linked list
                if (ll.analyzeString(buf, array, permDim) && ll.insert(ll.getFactValue(array, permDim))) {
                    ll.singlePrint();
                }
                delete[] array;
                break;
            }
            case 2: {
                cin >> buf;
                int num;
                stringstream str(buf);
                str >> num;
                // Validate and insert the factorial into the linked list
                if ((num < 0 || num > (ll.calcFactorial(permDim) - 1)) || ll.searchElement(num)) {
                    cerr << "Invalid or already exists factorial representation.\n";
                } else if (!ll.tryPushToTop(num,1 ) || !ll.tryPushToTop(num, 2)){
                    cerr << "Invalid or already exists factorial representation.\n";
                } else if(ll.insert(num)){
                    ll.singlePrint();
                }
                break;
            }
            case 3: {
                cin >> buf;
                int num;
                stringstream str(buf);
                str >> num;
                // Validate and push to the top of the specified stack
                if (ll.getlength() == 0) {
                    cerr << "Empty calculator.\n";
                } else if (num < 3 || num > permDim || !ll.tryPushToTop(ll.getHeadVal(),num)) {
                    cerr << "Invalid or already exists factorial representation.\n";
                } else {
                    int newFactVal = ll.pushToTop(ll.getHeadVal(), num);
                    if(ll.insert(newFactVal)){
                        ll.singlePrint();
                    }
                }
                break;
            }
            case 4: {
                // Display print options
                int printChoice;
                cout << "[1] Full Print" << endl;
                cout << "[2] Factorial Print" << endl;
                cout << "[3] Permutation Print" << endl;
                cin >> printChoice;
                if (printChoice > 3 || printChoice < 1) {
                    cerr << "Invalid print option.\n";
                } else {
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
                        }
                    }
                break;
            }
        }
    }
    return 0;
}
