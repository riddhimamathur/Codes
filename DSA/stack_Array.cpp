#include <iostream>
using namespace std;

#define n 100

int top = -1;

void push(int A[], int val)
{
    if (top == n - 1)
    {
        cout << "overflow";
    }
    else
    {
        top++;
        A[top] = val;
        cout << val << " pushed" << endl;
    }
}

void pop(int A[])
{
    if (top == -1)
    {
        cout << "underflow" << endl;
        return;
    }

    int val = A[top];
    top--;
    cout << val << " popped" << endl;
}

void peep(int A[])
{
    if (top == -1)
    {
        cout << "underflow" << endl;
        return;
    }

    cout << "top element: " << A[top] << endl;
}

void display(int A[])
{
    if (top == -1)
    {
        cout << "no element found" << endl;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int stack[n];

    push(stack, 23);
    push(stack, 31);
    push(stack, 29);

    display(stack);

    pop(stack);
    peep(stack);
    display(stack);

    return 0;
}
