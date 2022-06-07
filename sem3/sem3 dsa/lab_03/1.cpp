#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n=0;

class node{
public:
    int data;
    node *next;
    ~node(){
        free(next);
    }
};
    
node *push(node *temp,int num)
{
    node *new_node = new node();
    if(n > 10 || new_node == NULL)
    {
        cout << "Stack Overflow";
        exit(0);
    }
    else
    {
        new_node->data = num;
        new_node->next = temp;
        temp = new_node;
        n++;
        return temp;
    }
    
}

node *pop(node *temp)
{
    if(temp == NULL)
    {
        cout<<"Stack Underflow";
        exit(0);
    }
    else
    {
        n--;
        node *del = temp;
        temp = temp->next;
        free(del);
        return temp;
    }
}
void change(int index,int value,node *head)
{
    node *temp= head;
    if( index>0 && index <=n)
    {
        index--;
        while(index--)
            head = head->next;  
        if(head == NULL)
        {
            cout << "Indexed item not present in stack";
            exit(0);
        }
        else
        {
            head->data = value;
            head = temp;
        }
    }
    else
    {
        cout<<"Indexed item not present in stack";
        exit(0);
    }
}
void display(node *temp)
{
    if(temp != NULL)
    {
        while(NULL != temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    else
    {
        cout << "Stack is empty";
        exit(0);
    }
}


int main() 
{
    node *head = NULL;   
    int type,value,index;
    do
    {
        cin >> type;
        switch(type)
        {
            case 1:
                cin >> value;
                head = push(head,value);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                cin >> index >> value;
                change(index,value,head);
                break;
            case 4:
                display(head);
                break;
            default:
                cout << "Operation not supported";
                exit(0);
                break;
                
        }
    }   
    while(type != 4);
    
    
    return 0;
}