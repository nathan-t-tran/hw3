#include <iostream>
#include "stack.h"

void testStack() {
    std::cout << "Testing Stack..." << std::endl;
    
    Stack<int> s;

    // Test empty stack behavior
    try {
        s.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught (pop on empty stack): " << e.what() << std::endl;
    }

    try {
        s.top();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught (top on empty stack): " << e.what() << std::endl;
    }

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack top: " << s.top() << " (expected 30)" << std::endl;
    s.pop();
    std::cout << "Stack top after pop: " << s.top() << " (expected 20)" << std::endl;

    std::cout << "Stack size: " << s.size() << " (expected 2)" << std::endl;
    std::cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << " (expected No)" << std::endl;

    // Empty the stack
    s.pop();
    s.pop();
    
    std::cout << "Stack empty after popping all elements? " 
              << (s.empty() ? "Yes" : "No") << " (expected Yes)" << std::endl;

    // Try popping again to trigger exception
    try {
        s.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught (pop on empty stack again): " << e.what() << std::endl;
    }
}

int main() {
    testStack();
    return 0;
}
