#include <complex>
#include <algorithm>
#include <cstdio>

class node
{
public:
    node()
    {
    }

    node(node* left, node* right)
    {
        this->left = left;
        this->right = right;
    }

    node* left;
    node* right;

    // TODO: Define the content of the node.
};

int getLen(node* root, bool* isBalanced)
{
    *isBalanced = true;

    if (!root->left && !root->right)
    {
        return 1;
    }

    bool leftIsBalanced = true, rightIsBalanced = true;
    int left = root->left ? getLen(root->left, &leftIsBalanced) : 0;
    int right = root->right ? getLen(root->right, &rightIsBalanced) : 0;

    *isBalanced = std::abs(left - right) <= 1 && leftIsBalanced & rightIsBalanced;
    return std::max(left, right) + 1;
}

int main()
{
    bool isBalanced;

    // TODO: free allocated memory.

    // Case 1
    getLen(new node(new node(), new node()), &isBalanced);
    printf("%d\n", isBalanced);

    // Case 2
    getLen(new node(new node(), nullptr), &isBalanced);
    printf("%d\n", isBalanced);

    // Case 3
    getLen(new node(new node(new node(), new node()), nullptr), &isBalanced);
    printf("%d\n", isBalanced);

    // Case 4
    getLen(new node(new node(), new node(new node(), new node(new node(), new node()))), &isBalanced);
    printf("%d\n", isBalanced);

    return 0;
}
