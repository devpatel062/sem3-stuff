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

class stacks
{
    int n=10,x,top = -1;
    int *arr = new int[10];
    public :
    void PUSH()
    {
        if(top>=n-1)
        {
            cout<<"Stack Overflow";
            exit(0);
        }
        else
        {
            cin>>x;
            top++;
            arr[top]=x;
        }
    }
    void POP()
    {
        if(top<=-1)
        {
            cout<<"Stack Underflow";
            exit(0);
        }
        else
        {
            top--;
        }
    }
    void CHANGE ()
{
        int index,num;
        cin>>index>>num;
        if(index>0 && top+1 >= index)
            arr[top-index+1]=num;
        else
        {
            cout<<"Indexed item not present in stack";
            exit(0);
        }
    }

    void DISPLAY ()
    {
         if(top!=-1)
           {
               for(int i = top;i>=0;i--)
               {
                  cout<<arr[i]<<" ";
               }  
           }
        else
        {
            cout<<"Stack is empty";
            exit(0);
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int input=0;
    stacks s;
    
    do
    {
        cin>>input;
        
        
            if(1 == input)
            {
                s.PUSH();
                
            }
            else if(2 == input)
            {
                s.POP();
                
            }
            else if(3 == input)
            {
                s.CHANGE();
                
            }
            else if(4 == input)
            {
                s.DISPLAY();
                
            }
            else
            {
                cout<<"Operation not supported";
                break;
            }
        
    }
    while(input != 4);
    return 0;
}
