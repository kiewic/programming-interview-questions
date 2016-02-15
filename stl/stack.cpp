#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> myStack;
    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    cout << "size:" << myStack.size() << endl;
    
    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }

    cout << "size:" << myStack.size() << endl;

    return 0;
}
