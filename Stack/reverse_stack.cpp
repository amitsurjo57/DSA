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


void reverse(stack<int> &stack){
    if(stack.empty()){
        return;
    }

    int top = stack.top();
    stack.pop();
    reverse(stack);
    pushAtBottom(top, stack);
}

int main()
{
    stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    reverse(stack);

    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}
