"""
Data Structures and Algorithms - Task Two
Factorial computation using a Stack (forward and backward approaches)
"""


class Stack:
    """A simple array-based Stack ADT."""

    def __init__(self):
        self._items = []

    def push(self, item):
        self._items.append(item)

    def pop(self):
        if self.is_empty():
            raise IndexError("pop from an empty stack")
        return self._items.pop()

    def peek(self):
        if self.is_empty():
            raise IndexError("peek from an empty stack")
        return self._items[-1]

    def is_empty(self):
        return len(self._items) == 0

    def size(self):
        return len(self._items)


def validate_input(n):
    """Module 1: input validation."""
    if not isinstance(n, int):
        raise TypeError("n must be an integer")
    if n < 0:
        raise ValueError("factorial is undefined for negative numbers")


def factorial_forward_stack(n):
    """
    Module 2: Forward stack approach.

    Pushes 1, 2, ..., n onto the stack (the natural, forward order of
    the recurrence n! = (n-1)! x n), then pops and multiplies -
    multiplication happens in descending order (n, n-1, ..., 1).
    """
    validate_input(n)
    stack = Stack()

    for i in range(1, n + 1):
        stack.push(i)

    result = 1
    while not stack.is_empty():
        result *= stack.pop()

    return result


def factorial_backward_stack(n):
    """
    Module 3: Backward stack approach.

    Pushes n, n-1, ..., 1 onto the stack, mirroring how a recursive
    call stack unwinds backward from n down to the base case. Popping
    then multiplies in ascending order (1, 2, ..., n), matching the
    order a real recursive n! = n x (n-1)! call would resolve in.
    """
    validate_input(n)
    stack = Stack()

    i = n
    while i >= 1:
        stack.push(i)
        i -= 1

    result = 1
    while not stack.is_empty():
        result *= stack.pop()

    return result


def demo(n):
    print(f"n = {n}")
    print(f"Forward stack factorial:  {n}! = {factorial_forward_stack(n)}")
    print(f"Backward stack factorial: {n}! = {factorial_backward_stack(n)}")


if __name__ == "__main__":
    for value in (0, 1, 5, 10):
        demo(value)
        print("-" * 40)