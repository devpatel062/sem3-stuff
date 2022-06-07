/*
    PRIYANSHU IS A PEACEFULL SOUL
*/
#include <bits/stdc++.h>
using namespace std;

/* Enter your code here. Read input from STDIN. Print output to STDOUT .p. */
class Stack
{
public:
    int size;
    int top;
    char *arr;
};
int prec(char c)
{
    if (c == '^')
        return 4;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else if (c == '(')
        return 1;
    else
        return 0;
}

void push(Stack *s, char ch)
{
    if (s->top <= s->size)
    {
        s->top++;
        s->arr[s->top] = ch;
    }
}

void pop(Stack *s)
{
    if (s->top > 0)
    {
        s->top--;
    }
    else
    {
        cout << "INPUT EXPRESSION IS INVALID";
        exit(0);
    }
}

int Isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ')' || c == '(')
        return 1;
    else
        return 0;
}
char *Infix2Postfix(string infix)
{
    Stack *sp = (Stack *)malloc(sizeof(Stack));
    sp->top = 0;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((infix.length() + 1) * sizeof(char));
    int i = 0, j = 0, rank = 0;

    while (infix[i] != '\0')
    {
        if ((infix[i] <= 'z' && infix[i] >= 'A') || Isoperator(infix[i]))
        {
            if (!Isoperator(infix[i]))
            {
                postfix[j] = infix[i];
                j++;
                i++;
                rank++;
                if (rank < 1)
                {
                    cout << "INPUT EXPRESSION IS INVALID";
                    exit(0);
                }
            }
            else if (infix[i] == '(')
            {
                push(sp, infix[i]);
                i++;
            }
            else if (infix[i] == ')')
            {
                while (sp->arr[sp->top] != '(')
                {
                    pop(sp);
                    postfix[j] = sp->arr[sp->top + 1];
                    j++;
                    rank--;
                    if (rank < 1)
                    {
                        cout << "INPUT EXPRESSION IS INVALID";
                        exit(0);
                    }
                }
                pop(sp);
                i++;
            }
            else
            {
                if (infix[i] == '^' && prec(infix[i]) >= prec(sp->arr[sp->top]))
                {
                    push(sp, infix[i]);
                    i++;
                }
                else if (prec(infix[i]) > prec(sp->arr[sp->top]))
                {
                    push(sp, infix[i]);
                    i++;
                }
                else
                {
                    pop(sp);
                    postfix[j] = sp->arr[sp->top + 1];
                    j++;
                    rank--;
                    if (rank < 1)
                    {
                        cout << "INPUT EXPRESSION IS INVALID";
                        exit(0);
                    }
                }
            }
        }
        else
        {
            cout << "INPUT EXPRESSION IS INVALID";
            exit(0);
        }
    }

    while (sp->top > 0)
    {
        pop(sp);
        postfix[j] = sp->arr[sp->top + 1];
        j++;
        rank--;
        if (rank < 1)
        {
            cout << "INPUT EXPRESSION IS INVALID";
            exit(0);
        }
    }

    postfix[j] = '\0';

    return postfix;
}
int main()
{
    string s;
    cin >> s;

    cout << Infix2Postfix(s);
    return 0;
}