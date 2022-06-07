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
class Stack
{
    int arr[1000];
    public:
        int top=-1;
        void push(int number){
            top++;
            arr[top]=number;
        }
        int pop(){
            int temp=arr[top];
            top--;
            return temp;
        }
        int gettopelement(){
            return arr[top];
        }
};
bool is_number(string take){
    int flag=0;
    for(long long  i=0; i<take.length(); i++){
        if(take[i]>='0' && take[i]<='9')
            flag=0;
        else{
            flag=1;
            break;
        }
    }
    if(flag==1)
        return false;
    else
        return true;
}
bool is_operator(string take){
    int flag=0;
    for(long long i=0; i<take.length(); i++){
        if(take[i]=='+' || take[i]=='-' || take[i]=='*' || take[i]=='/' || take[i]=='^')
            flag=0;
        else{
            flag=1;
            break;
        }
    }
    if(flag==0)
        return true;
    else
        return false;
}
int operate(int num1, int num2, string op){
    if(op[0]=='+')
        return num1+num2;
    else if(op[0]=='-')
        return num1-num2;
    else if(op[0]=='*')
        return num1*num2;
    else if(op[0]=='/')
        return num1/num2;
    else if(op[0]=='^')
        return pow(num1,num2);
    else return 0;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string take;
    int operand1, operand2, result;
    Stack input_stack;
    cin>>take;
    while(take!=""){
        if(is_number(take))
            input_stack.push(stoi(take));
        else if(is_operator(take)){
            if(input_stack.top>=1)
                operand2=input_stack.pop();
            else{
                cout<<"INPUT EXPRESSION IS INVALID";
                exit(0);
            }
            if(input_stack.top>=0)
                operand1=input_stack.pop();
            else{
                cout<<"INPUT EXPRESSION IS INVALID";
                exit(0);
            }
            result=operate(operand1,operand2,take);
            input_stack.push(result);
        }
        else{
            cout<<"INPUT EXPRESSION IS INVALID";
            exit(0);
        }
        take="";
        cin>>take;
    }
    if(input_stack.top==0)
        cout<<input_stack.gettopelement();
    else cout<<"INPUT EXPRESSION IS INVALID";
    return 0;
}