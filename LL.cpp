#include "LL.h"
#include <iostream>
#include <sstream>

/**
 *Inserts a new element at the beginning of the linked list.
 * before inserting,returns false if first 2 values in both new permutation and current head are similar,
 * else inserts and returns true.
 * @param value The value to be inserted into the linked list.
 * @returns true if permutation is valid to insert, else false.
 */
bool LL::insert(int value) {
    // A check if list isn't empty and comparison between first 2 indexes in new perm and current perm in head position.
    if (head) {
        int* existingHeadPermArray = getPermValue(head->getData(), permLength);
        int* newPermArray = getPermValue(value, permLength);
        if (existingHeadPermArray[0] == newPermArray[0] && existingHeadPermArray[1] == newPermArray[1]) {
            std::cerr << "Invalid or already exists factorial representation.\n";
            delete[] existingHeadPermArray;
            delete[] newPermArray;
            return false;
        }
        delete[] existingHeadPermArray;
        delete[] newPermArray;
    }
    head = new Node(value);
    llsize++;

    return true;
}

/** Iterates over the linked list and searches for a specific value.
 * if found it returns true, else false.
 * @param data the value to search in the list.
 * @returns True if found, False if not.
 * */
bool LL::searchElement(int data) {
    if(llsize == 0){return false;}
    iterator = head;
    do{
        if(iterator->getData() == data){
            return true;
        }
        iterator = iterator->getNext();
    } while (iterator != nullptr);
    return false;
}

/** getPermValue receives a factorial value and size of an array
 *  and returns an array of the certain permutation.
 *  @param data factorial value to transform to array.
 *  @param size size of the array.
 *  @returns as permutation array.
 * */
int *LL::getPermValue(int data,int size) {
    // Reverse factorial representation algorithm array.
    int revPermArrayIdx = size-1,counter = 1;
    int revPermArray[size];
    while(counter<=size){
        // insertion of values in the array.
        revPermArray[revPermArrayIdx] = data%counter;
        data = int(data/counter);
        counter++;
        revPermArrayIdx--;
    }
    // Creation of [1,2,3, n] array and matching values with reversed array
    // to create the final permutation array.
    int currRangeSize = size,rangeArray[size];
    int* finalPerm = new int[size];
    for(int i = 1;i<=size;i++) {
        rangeArray[i - 1] = i;
    }
    for(int j = 0;j<size;j++){
        finalPerm[j] = rangeArray[revPermArray[j]];
        // A loop that shrinks the range array once a value is found, according to the algorithm.
        // It pushes all the used values left >> as it lowers the bounds of the array.
        for(int range = revPermArray[j]; range<currRangeSize;range++){
            rangeArray[range] = rangeArray[range+1];
        }
    }
    return finalPerm;
}
/** getFactValue receives an array that represents a permutation
 * and returns its factorial value.
 * @param data an array that represents a permutation.
 * @param size the size of the given array.
 * @returns a factorial value of the permutation.
 * */
int LL::getFactValue(const int *data,const int size) {
    // Calculation according to the algorithm
    int permArray[size], sum=0;
    for(int i = 0;i<size;i++){
        int smallerCounter = 0;
        for(int j = i;j<size;j++){
            if(data[i] > data[j]){++smallerCounter;}
        }
        permArray[i] = smallerCounter;
    }
    // A sum of each (value * index factorial number)
    for(int f = 1;f<=size;f++){
        sum+= permArray[f-1] * calcFactorial(size-f);
    }
    return sum;
}
/** This function gets a factorial value and an index for PT algorithm.
 *  Calls pushToTop function and gets the new factorial value after PT,
 *  eventually searches if the value is already in the linked list.
 *  @param factValue factorial value of the permutation.
 *  @param index index to perform PT algorithm.
 *  @returns true if permutation can be added, else false.
 * */
bool LL::tryPushToTop(int factValue, int index) {
    if (index < 1 || index > permLength) {
        return false;
    }
    int newFactValue = pushToTop(factValue,index);
    if(searchElement(newFactValue)){
        // Element is already in the list
        return false;
    }
    return true;
}

/** pushToTop gets a factorial value, index for PT algorithm, it performs PT algorithm
 * and returns the permutation factorial value after PT.
 * @param index for PT algorithm.
 * @param factValue factorial value of a permutation.
 * @returns a new array after the PT change.
 * */
int LL::pushToTop(int factValue, int index) {
    int arraySize = permLength;
    int* permArray = getPermValue(factValue,arraySize);
    int savedValue = permArray[index-1];
    // a loop that pushes all the elements to the right
    for(int i = index-1;i>0;i--){
        permArray[i] = permArray[i-1];
    }
    // sets the value in the first array element
    permArray[0] = savedValue;
    int newPermFactValue = getFactValue(permArray,permLength);
    delete[] permArray;
    return newPermFactValue;
}
// A simple calculation of factorial number
int LL::calcFactorial(int data) {
    int sum=1;
    for(int i=1;i<=data;i++){
        sum*=i;
    }
    return sum;
}
/**
 * This function parses a comma-separated string permutation,
 * validates its elements, calculates their sum, and checks if the sum is valid.
 * @param str The input string representing a permutation.
 * @param permArray An array to store the parsed permutations.
 * @param arraySize The size of the permutation array.
 *
 * @returns true if the string is a valid permutation.
 *         false otherwise with  error messages printed to std::cerr.
 */
bool LL::analyzeString(std::string& str, int* permArray, int arraySize) {
    int num, index = 0, arrSum = 0;
    std::string text;
    std::stringstream ss(str);
    // Parse the comma-separated string
    while (std::getline(ss, text, ',')) {
        std::stringstream ssText(text);
        if (ssText >> num) {
            // Validate and store the parsed number
            if (num < 0 || num > arraySize) {
                std::cerr << "Invalid permutation.\n";
                return false;
            }
            arrSum += num;
            permArray[index++] = num;
        }
    }
    // Check if the sum of the permutation is valid
    int sumOfMathSeries = (arraySize + 1) * arraySize / 2;
    if (arrSum != sumOfMathSeries) {
        std::cerr << "Invalid permutation.\n";
        return false;
    }
    // Calculate the factorial value of the permutation
    int factVal = getFactValue(permArray, arraySize);
    // Update the linked list with the factorial value
    if (this->llsize > 0) {
        if (!tryPushToTop(1, factVal) || !tryPushToTop(2, factVal)) {
            std::cerr << "Invalid permutation.\n";
            return false;
        }
    }
    return true;
}
// A destructor for the Nodes.
LL::~LL() {
    iterator = head;
    while (iterator != nullptr) {
        Node* prev = iterator;
        iterator = iterator->getNext();
        delete prev;
    }
    head = nullptr;
}

// ALL BELOW ARE 4 PRINTING FUNCTIONS.

void LL::singlePrint() const{
    int* array = getPermValue(getHeadVal(),permLength);
    std::cout << "[ ";
    for(int i = 0;i<permLength;i++){
        if(i == permLength-1){
            std::cout << array[i] << " ";
        }else{
            std::cout << array[i]<< ",";
        }
    }
    std::cout << "]" << "\t" << getHeadVal() << std::endl;
    delete[] array;
}

void LL::fullPrint() {
    iterator = head;
    while(iterator != nullptr){
        int element = iterator->getData();
        int* array = getPermValue(element,permLength);
        std::cout << "[ ";
        for(int i = 0;i<permLength;i++){
            if(i == permLength-1){
                std::cout << array[i] << " ";
            }else{
                std::cout << array[i]<< ",";
            }
        }
        std::cout << "]" << "\t" << element << std::endl;
        delete[] array;
        iterator = iterator->getNext();
    }
}

void LL::factPrint(){
    iterator = head;
    while(iterator != nullptr){
        int element = iterator->getData();
        std::cout << element << std::endl;
        iterator = iterator->getNext();
    }
}
void LL::permPrint(){
    iterator = head;
    while(iterator != nullptr){
        int element = iterator->getData();
        int* array = getPermValue(element,permLength);
        std::cout << "[ ";
        for(int i = 0;i<permLength;i++){
            if(i == permLength-1){
                std::cout << array[i] << " ";
            }else{
                std::cout << array[i] << ",";
            }
        }
        std::cout << "]" << std::endl;
        delete[] array;
        iterator = iterator->getNext();
    }
}


