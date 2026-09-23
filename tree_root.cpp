#include <iostream>
#include <stack>
#include <string>
#include <cctype> 

using namespace std;

/* ---------- Part 1: Infix -> Postfix (same as before) ---------- */

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(const string& infix) {
    string output;
    stack<char> ops;

    for (char token : infix) {
        if (isspace(token)) continue;

        if (isalnum(token)) {
            output += token;
        } else if (token == '(') {
            ops.push(token);
        } else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop();
        } else if (isOperator(token)) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                output += ops.top();
                ops.pop();
            }
            ops.push(token);
        } else {
            cerr << "Unsupported character: " << token << endl;
            exit(1);
        }
    }

    while (!ops.empty()) {
        output += ops.top();
        ops.pop();
    }

    return output;
}

/* ---------- Part 2: Postfix -> Expression Tree ---------- */

struct Node {
    char value;
    Node* left;
    Node* right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

/**
 * Builds the expression tree from a postfix string.
 *
 *  - Operand  -> create a leaf node, push it
 *  - Operator -> pop two nodes (right child first, then left child),
 *                make a new node with the operator as root and those
 *                two popped nodes as its children, push the new subtree
 *
 * At the end, the single node left on the stack is the root of the
 * whole tree - exactly the algorithm walked through manually earlier.
 */
Node* buildExpressionTree(const string& postfix) {
    stack<Node*> nodes;

    for (char token : postfix) {
        if (isalnum(token)) {
            nodes.push(new Node(token));
        } else if (isOperator(token)) {
            Node* right = nodes.top(); nodes.pop();
            Node* left  = nodes.top(); nodes.pop();

            Node* parent = new Node(token);
            parent->left = left;
            parent->right = right;

            nodes.push(parent);
        }
    }

    return nodes.top(); // root
}

/* ---------- Part 3: Traversals to show the tree's shape ---------- */

void preorder(Node* root) {   // operator, left, right -> prefix form
    if (!root) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {    // left, operator, right -> infix form
    if (!root) return;
    bool isOp = isOperator(root->value);
    if (isOp) cout << "(";
    inorder(root->left);
    cout << root->value;
    inorder(root->right);
    if (isOp) cout << ")";
}

void postorder(Node* root) {  // left, right, operator -> back to postfix
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

// Simple sideways print so you can see the tree's structure in a console
void printTree(Node* root, int depth = 0) {
    if (!root) return;
    printTree(root->right, depth + 1);
    cout << string(depth * 4, ' ') << root->value << endl;
    printTree(root->left, depth + 1);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

/* ---------- main ---------- */

int main() {
    string infix;
    cout << "Enter an infix expression (e.g. A+B*C-D/E): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix : " << postfix << endl << endl;

    Node* root = buildExpressionTree(postfix);

    cout << "Tree (sideways, root on the left):" << endl;
    printTree(root);
    cout << endl;

    cout << "Preorder  (prefix form)   : ";
    preorder(root);
    cout << endl;

    cout << "Inorder   (fully parenthesized infix) : ";
    inorder(root);
    cout << endl;

    cout << "Postorder (back to postfix) : ";
    postorder(root);
    cout << endl;

    freeTree(root);
    
    return 0;
}