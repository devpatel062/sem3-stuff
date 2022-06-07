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
    int priority;
};

struct Queue{
    
    struct qNode *front = NULL;
    struct qNode *rear = NULL;
};

void enqueue(struct Queue *Q, int data,int priority)
{
    if(top > 10)
    {
        cout<<"Queue Overflow"<<endl;
        exit(0);
    }
    else
    {
        struct qNode *new_struct = new struct qNode;
        new_struct->data = data;
        new_struct->priority = priority;
        struct qNode *temp = new struct qNode;
        struct qNode *rotate = new struct qNode;
        if(top == 0)
        {
            Q->front = new_struct;
            Q->rear = new_struct;
            new_struct->next = NULL;
            top++;
            return;
        }
        else if(new_struct->priority <= Q->front->priority)
        {
            if(new_struct->priority == Q->front->priority)
            {
                rotate = Q->front;
                while(rotate->next != NULL && rotate->priority == rotate->next->priority)
                {
                    rotate = rotate->next;
                }
                new_struct->next = rotate->next;
                rotate->next = new_struct;
                top++;
                rotate = Q->front;
                return;
            }
            new_struct->next = Q->front;
            Q->front = new_struct;
            top++;
            return;
        }
        // else if(new_struct->priority == Q->front->priority)
        // {
        //     rotate = Q->front;
        //     while(rotate->next != NULL)
        //     {
        //         rotate = rotate->next;
        //     }
        //     new_struct->next = NULL;
        //     Q->front->next = new_struct;
        //     Q->rear = new_struct;
        //     top++;
        //     rotate = Q->front;
        //     return;
        // }
        temp = Q->front;
        while(temp->next != NULL && temp->next->priority <= new_struct->priority)
        {
            temp = temp->next;
        }
        new_struct->next = temp->next;
        temp->next = new_struct;
        top++;
    }
        
    
}

void dequeue(struct Queue *Q)
{
    if(Q->front == NULL)
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
    if(top == 0)
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
    int input,data,priority;
    Queue q;
    Queue *Q=&q;
    
    do
    {
        cin>>input;
       switch(input)
       {
           case 1:
               cin>>data>>priority;
               if((data < -100000 || data > 100000) && (priority < 1 || priority >1000))
               {
                   break;
               }
               else
               {
                   enqueue(Q,data,priority);
               }
               break;
           case 2:
               dequeue(Q);
               break;
           case 3:
               display(Q);
               break;
           default:
               cout<<"Operation not supported";
               exit(0);
       }
    }while(input != 3);
    return 0;
}