/*
 * Data Structures and Algorithms - Task Two
 * Factorial computation using a Stack (forward and backward approaches)
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

//Create stack class to hold long long values
class Stack {
private:
    std::vector<long long> items;

public:
    void push(long long item) {
        items.push_back(item);
    }

    long long pop() {
        if (isEmpty()) {
            throw std::runtime_error("pop from an empty stack");
        }
        long long top = items.back();
        items.pop_back();
        return top;
    }

    long long peek() const {
        if (isEmpty()) {
            throw std::runtime_error("peek from an empty stack");
        }
        return items.back();
    }

    bool isEmpty() const {
        return items.empty();
    }

    size_t size() const {
        return items.size();
    }
};

// Module 1: input validation
void validateInput(long long n) {
    if (n < 0) {
        throw std::invalid_argument("factorial is undefined for negative numbers");
    }
}

// Module 2: Forward stack approach.
// Pushes 1, 2, ..., n (ascending order), then pops - multiplication
// happens in descending order (n, n-1, ..., 1). This follows the
// recurrence n! = (n-1)! x n directly, forward.
long long factorialForwardStack(long long n) {
    validateInput(n);
    Stack stack;

    for (long long i = 1; i <= n; ++i) {
        stack.push(i);
    }

    long long result = 1;
    while (!stack.isEmpty()) {
        result *= stack.pop();
    }

    return result;
}

// Module 3: Backward stack approach.
// Pushes n, n-1, ..., 1, mirroring how a recursive call stack unwinds
// backward from n down to the base case. Popping then multiplies in
// ascending order (1, 2, ..., n) - the order a real recursive
// n! = n x (n-1)! call would resolve in.
long long factorialBackwardStack(long long n) {
    validateInput(n);
    Stack stack;

    for (long long i = n; i >= 1; --i) {
        stack.push(i);
    }

    long long result = 1;
    while (!stack.isEmpty()) {
        result *= stack.pop();
    }

    return result;
}

void demo(long long n) {
    std::cout << "n = " << n << "\n";
    std::cout << "Forward stack factorial:  " << n << "! = "
               << factorialForwardStack(n) << "\n";
    std::cout << "Backward stack factorial: " << n << "! = "
               << factorialBackwardStack(n) << "\n";
    std::cout << std::string(40, '-') << "\n";
}

int main() {
    long long values[] = {0, 1, 5, 10};
    for (long long v : values) {
        demo(v);
    }
    return 0;
}
