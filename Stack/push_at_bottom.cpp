#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(int data, stack<int> &stk)
{
    if (stk.empty() == true)
    {
        stk.push(data);
        return;
    }

    int temp = stk.top();
    stk.pop();
    pushAtBottom(data, stk);
    stk.push(temp);
}

int main()
{
    stack<int> stack, ans;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    

    pushAtBottom(4, stack);

    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}
