#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int num = 0;
typedef struct list_node
{
        int item;
        struct list_node *next;
        struct list_node *prev;
}node;

node *head=NULL, *tail=NULL;

void insert_at_beginning(int value)    //code 0
{
    if(num < 10)
    {
        if(num == 0)
        {
            node *new_node = new node;
            new_node->item = value;
            new_node->next = NULL;
            new_node->prev = NULL;
            head = new_node;
            tail = new_node;
            num++;
        }
        else
        {
            node *new_node = new node;
            new_node->item = value;
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            num++;
        }
    }
    else
    {
        cout<<"List can not accommodate more than 10 elements"<<endl;
        exit(0);
    }
}

void insert_at_end(int value)
{
    if(num < 10)
    {
        if(num == 0)
        {
            node *new_node = new node;
            new_node->item = value;
            new_node->next = NULL;
            new_node->prev = NULL;
            head = new_node;
            tail = new_node;
            num++;
        }
        else
        {
            node *new_node = new node;
            new_node->item = value;
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            num++;
        }
    }
    else
    {
        cout<<"List can not accommodate more than 10 elements"<<endl;
        exit(0);
    }
}
void delete_from_beginning()
{
    if(head == NULL)
    {
        cout<<"INVALID SEQUENCE OF COMMANDS";
        exit(0);
    }
    else if(num == 1)
    {
        node *temp = new node;
        temp = head;
        free(temp);
        head = NULL;
        tail = NULL;
        num--;
    }
    else
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        free(temp);
        num--;
    }
}
void delete_from_end()
{
    if(tail == NULL)
    {
        cout<<"INVALID SEQUENCE OF COMMANDS";
        exit(0);
    }
    else if(num == 1)
    {
        node *temp = new node;
        temp = head;
        free(temp);
        head = NULL;
        tail = NULL;
        num--;
    }
    else
    {
        node *temp = new node;
        temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        free(temp);
        num--;
    }
}
void print_list()
{
    if(head == NULL || tail == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        while(head != NULL)
        {
            cout<<head->item<<" ";
            head = head->next;
        }
        cout<<endl;
        while(tail != NULL)
        {
            cout<<tail->item<<" ";
            tail = tail->prev;
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int input,value;
    do
    {
        cin>>input;
        switch(input)
        {
            case 0:
                cin>>value;
                insert_at_beginning(value);
                break;
            case 1:
                cin>>value;
                insert_at_end(value);
                break;
            case 2:
                delete_from_beginning();
                break;
            case 3:
                delete_from_end();
                break;
            case 4:
                print_list();
                exit(0);
            default:
                cout<<"INVALID SEQUENCE OF COMMANDS"<<endl;
                exit(0);
        }
    }while(input != 4);
    return 0;
}