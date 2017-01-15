#include <iostream>
#include <limits>

using namespace std;

class Node
{
public:
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int value;
    Node* left;
    Node* right;
};

bool validate(Node* root, int lower, int upper)
{
    if (root == nullptr)
    {
        return true;
    }

    if (!(lower < root->value && root->value <= upper))
    {
        return false;
    }

    return validate(root->left, lower, root->value) && validate(root->right, root->value, upper);
}

int main()
{
    // TODO: free allocated objects.
    cout << validate(new Node(20, new Node(20), nullptr), INT_MIN, INT_MAX) << endl; // true

    cout << validate(new Node(20, nullptr, new Node(20)), INT_MIN, INT_MAX) << endl; // false

    cout << validate(new Node(
        20,
        new Node(10, nullptr, new Node(25)),
        new Node(30)),
        INT_MIN,
        INT_MAX) << endl; // false

    cout << validate(new Node(
        20,
        new Node(10,
            new Node(5,
                new Node(3),
                new Node(7)),
            new Node(15,
                nullptr,
                new Node(17))),
        new Node(30)),
        INT_MIN,
        INT_MAX) << endl; // true

    return 0;
}
