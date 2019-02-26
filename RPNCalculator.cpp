
#include <iostream>
#include "RPNCalculator.hpp"



RPNCalculator::RPNCalculator() {
    stackHead = NULL;
    return;
}


RPNCalculator::~RPNCalculator() {

    if (stackHead == NULL) { //if no elements, return
        return;
    }

    Operand* temp = stackHead;
    while (temp->next != NULL) {

        stackHead = temp->next;
        delete temp;
        temp = stackHead;

    }
    delete temp;
    stackHead = NULL;
    return;
}


bool RPNCalculator::isEmpty() {
    return stackHead == NULL;
}


void RPNCalculator::push(float num) {

    Operand* temp = new Operand; //make space in dynamic memory
    temp->next = stackHead; //we point to the most recent head
    temp->number = num;
    stackHead = temp; //and make the new head point to this element

    return;
}


void RPNCalculator::pop() {

    Operand* temp;
    if (stackHead == NULL) {
        std::cout << "Stack empty, cannot pop an item." << "\n\n";
    }
    else {

        temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }

    return;
}


Operand* RPNCalculator::peek() {

    if (stackHead == NULL) {
        std::cout << "Stack empty, cannot peek." << "\n\n";
        return NULL;
    }

    return stackHead;
}

bool RPNCalculator::compute(std::string symbol) {

    Operand* temp = stackHead;
    if ((symbol != "*") && (symbol != "+")) {
        std::cout << "err: invalid operation" << std::endl;
        return false;
    }

    if (stackHead == NULL) {
        std::cout << "\nNo elements in stack\n";
        return false;
    }

    if (stackHead->next == NULL) {
        std::cout << "\nOnly one element in stack\n";
        return false;
    }

    if (symbol == "+") {

        stackHead = stackHead->next; //make stackhead next element in list
        stackHead->number += temp->number; //add temp
        delete temp;

    }
    else {

        stackHead = stackHead->next;
        stackHead->number *= temp->number;
        delete temp;

    }
    return true;
}
