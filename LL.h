#ifndef MATALA1_LL_H
#define MATALA1_LL_H
#include <iostream>


/** A simple Node class implementation
 *  with getters/setters.
 * */
class Node {
public:
    explicit Node(int value):data(value),next(nullptr){}
    int getData() const{return data;}
    Node* getNext() const{return next;}
    void setNext(Node* nextValue){next = nextValue;}
private:
    int data;
    Node* next;
};
/**
 * This is A Linked list that Stores only the Factorial Value of permutations.
 * It does support "Casting" between permutation Values and factorial values by using
 * Static methods, eventually storing only the factorial values.
 * */
class LL {
public:
    explicit LL(int permLen):head(nullptr),iterator(nullptr),llsize(0),permLength(permLen){}
    // T/F if the insert process ended successfully
    bool insert(int value);
    int getHeadVal() const{return head->getData();}
    int getlength() const{return llsize;}
    // T/F if the element was found in the list
    bool searchElement(int data);
    // Gets a factorial value and returns it's factorial Permutation list.
    static int *getPermValue(int data,int size);
    // Gets a Permutation list and returns it's factorial value.
    static int getFactValue(const int* data,int size);
    // for n it returns the value of n!
    static int calcFactorial(int data);
    // Gets a reference to a string as it determines whether it suits the LL or not.
    bool analyzeString(std::string& str,int* permArray, int arraySize);
    // Gets a factorial value and determines whether it can be added or not after the pushToTop change.
    bool tryPushToTop(int factValue, int index);
    // Gets a factorial value and an index and performs PT algorithm as it returns the new factorial value.
    int pushToTop(int factValue, int index);
    void singlePrint() const;
    void fullPrint();
    void factPrint();
    void permPrint();
    ~LL();

private:
    Node* head;
    Node* iterator;
    int llsize;
    const int permLength;
};


#endif //MATALA1_LL_H
