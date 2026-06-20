//infix to prefix conversion
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char stackarr[100];
int top=-1;
void push(char x)
{
    stackarr[++top]=x;
}
char pop()
{
    return stackarr[top--];
}
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return -1;
}
void convert (char infix[])
{
    top = -1;
    int n = strlen(infix);
    reverse(infix, infix + n);
    for (int i = 0; i < n; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    char postfix[100];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix[k++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while (top != -1 && stackarr[top] != '(')
                postfix[k++] = pop();
            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && precedence(stackarr[top]) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
    reverse(postfix, postfix + k);
    cout << "Prefix expression: " << postfix << endl;
}

int main()
{
    char infix[100];
    cout << "Enter infix expression: ";
    cin.getline(infix, 100);
    convert(infix);
    return 0;
}
