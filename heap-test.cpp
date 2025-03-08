#include <iostream>
#include "heap.h"

void testHeap() {
    Heap<int> minHeap(3);  // Default Min-Heap

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(3);

    std::cout << "Heap top: " << minHeap.top() << std::endl;  // Expected 3
    minHeap.pop();
    std::cout << "Heap top after pop: " << minHeap.top() << std::endl;  // Expected 5
}

void testMaxHeap() {
    Heap<int, std::greater<int>> maxHeap(2); // Max-Heap

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    maxHeap.push(3);

    std::cout << "Max-Heap top: " << maxHeap.top() << std::endl;  // Expected 20
    maxHeap.pop();
    std::cout << "Max-Heap top after pop: " << maxHeap.top() << std::endl;  // Expected 10
}

int main() {
    testHeap();
    testMaxHeap();
    return 0;
}
