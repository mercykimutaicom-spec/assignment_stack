/* question a)developing module to solve the problem
Step-by-step algorithm:

Start
Input number n
Set factorial = 1
For i = 1 to n:
factorial = factorial × i
Output factorial
End*/

#include <iostream>
using namespace std;

int main() {
    int n;
    long long factorial = 1;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Error: Factorial not defined for negative numbers." << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }

        cout << "Factorial of " << n << " is: " << factorial << endl;
    }

    return 0;
}/*question b)describing stalk as DSA and its implementation
A stack is a linear data structure that follows:

LIFO (Last In, First Out)
The last item added is the first one removed.

Example:

Push 1, 2, 3 → Stack = [1, 2, 3]
Pop → removes 3 first
Operations in Stack
Push → Add item
Pop → Remove item
Peek/Top → View top item
Real-Life Applications of Stack
Undo/Redo in Applications
Example: In Microsoft Word or Notepad
Last action is undone first
Browser History
Back button uses a stack
Last visited page is returned first  */
//working example//
// File: stack_demo.cpp
#include <iostream>
#include <stack>   // C++ Standard Library Stack
using namespace std;

int main() {
    stack<int> s;

    // PUSH operations
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    // POP operation
    s.pop();

    cout << "Top after pop: " << s.top() << endl;

    return 0;
}
/*}
🔍 Explanation
stack<int> s; → creates a stack
push() → adds element
pop() → removes top element
top() → shows top element
Key Concept

Stack follows:
LIFO (Last In First Out)*/

/*number c)implementing factorials in both forward and and backwards stalk*/
//forward factorial stalk
// File: factorial_forward_stack.cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    stack<int> s;

    // Push values from 1 to n
    for (int i = 1; i <= n; i++) {
        s.push(i);
    }

    int factorial = 1;

    // Pop and multiply
    while (!s.empty()) {
        factorial *= s.top();
        s.pop();
    }

    cout << "Factorial (Forward Stack) = " << factorial << endl;

    return 0;
}
/*Explanation (Forward)
Push numbers 1 → n
Stack top becomes n
Pop elements (n → 1)
Multiply step-by-step*/
//backward implementation 
// File: factorial_backward_stack.cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    stack<int> s;

    // Push values from n down to 1
    while (n > 0) {
        s.push(n);
        n--;
    }

    int factorial = 1;

    // Pop and multiply
    while (!s.empty()) {
        factorial *= s.top();
        s.pop();
    }

    cout << "Factorial (Backward Stack) = " << factorial << endl;

    return 0;
}/*Explanation (Backward)
Push numbers n → 1
Stack top becomes 1
Pop elements (1 → n)
Multiply step-by-step*/
