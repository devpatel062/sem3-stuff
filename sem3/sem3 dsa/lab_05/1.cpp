#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int top = 0;

struct qNode{
    
    int data;
    struct qNode *next;
};

struct Queue{
    
    struct qNode *front = NULL;
    struct qNode *rear = NULL;
};

void enqueue(struct Queue *Q, int data)
{
    if(top >= 10)
    {
        cout<<"Queue Overflow"<<endl;
        exit(0);
    }
    else
    {
        struct qNode *new_struct = new struct qNode;
        top++;
        new_struct->data = data;
        new_struct->next = NULL;
        if(top == 1)
        {
            Q->front = new_struct;
            Q->rear = new_struct;
        }
        else
        {
            Q->rear->next = new_struct;
            Q->rear = new_struct;
        }
    }
    
}

void dequeue(struct Queue *Q)
{
    if(top <= 0)
    {
        cout<<"Queue Underflow";
        exit(0);
    }
    if(top == 1)
    {
        Q->rear = NULL;
        free(Q->front);
        Q->front = NULL;
        top--;
    }
    else
    {
        struct qNode *temp = new struct qNode;
        temp = Q->front;
        Q->front = Q->front->next;
        temp->next = NULL;
        free(temp);
        top--;
    }
    
}
void display(struct Queue *Q)
{
    if(Q->front == NULL)
    {
        cout<<"Queue is empty";
        exit(0);
    }
    else
    {
        struct qNode *ptr;
        ptr = Q->front;
        while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long input,data;
    Queue q;
    Queue *Q=&q;
    
    do
    {
        cin>>input;
       
           if(input == 1)
           {
               cin>>data;
               if(data < -100000 || data > 100000)
               {
                   continue;
               }
               else
               {
                   enqueue(Q,data);
               }
           }
               
           else if(input == 2)
           {
               dequeue(Q);
           }
               
           else if(input == 3)
           {
               display(Q);
           }
               
           else
           {
                cout<<"Operation not supported";
               exit(0);
           }
              
       
    }while(input != 3);
    return 0;
}