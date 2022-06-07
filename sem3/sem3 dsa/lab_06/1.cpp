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

struct term{
    int co_efficient, power_of_x, power_of_y;
    struct term *next;
};

struct term* create_term(struct term *head, int co_efficient, int power_of_x, int power_of_y){
    if(co_efficient==0){
        return head;
    }
    else if(head==NULL){
        struct term *temp=new struct term;
        temp->co_efficient=co_efficient;
        temp->power_of_x=power_of_x;
        temp->power_of_y=power_of_y;
        temp->next=NULL;
        return temp;
    }
    else{
        struct term *temp=head;
        while(temp->next!=NULL && (temp->next->power_of_x>power_of_x || (temp->next->power_of_x==power_of_x&&temp->next->power_of_y>power_of_y)))
            temp=temp->next;
        if(temp->next==NULL){
            temp->next=new struct term;
            temp=temp->next;
            temp->co_efficient=co_efficient;
            temp->power_of_x=power_of_x;
            temp->power_of_y=power_of_y;
            temp->next=NULL;
            return head;
        }
        else{
            struct term *new_node=new struct term;
            new_node->co_efficient=co_efficient;
            new_node->power_of_x=power_of_x;
            new_node->power_of_y=power_of_y;
            new_node->next=temp->next;
            temp->next=new_node;
            return head;
        }
    }
}
struct term* add_poly(struct term *poly1, struct term *poly2, struct term *result){
    struct term *temp_poly1=poly1;
    struct term *temp_poly2=poly2;
    int power_of_x_poly1,power_of_x_poly2,power_of_y_poly1,power_of_y_poly2,co_efficient_poly1,co_efficient_poly2;
    while(temp_poly1!=NULL && temp_poly2!=NULL){
        co_efficient_poly1=temp_poly1->co_efficient;
        co_efficient_poly2=temp_poly2->co_efficient;
        power_of_x_poly1=temp_poly1->power_of_x;
        power_of_x_poly2=temp_poly2->power_of_x;
        power_of_y_poly1=temp_poly1->power_of_y;
        power_of_y_poly2=temp_poly2->power_of_y;
        if(power_of_x_poly1==power_of_x_poly2 && power_of_y_poly1==power_of_y_poly2){
            if(co_efficient_poly1+co_efficient_poly2!=0)
                result=create_term(result,co_efficient_poly1+co_efficient_poly2,power_of_x_poly1,power_of_y_poly1);
            temp_poly1=temp_poly1->next;
            temp_poly2=temp_poly2->next;
        }
        else if((power_of_x_poly1>power_of_x_poly2) || (power_of_x_poly1==power_of_x_poly2 && power_of_y_poly1>power_of_x_poly2)){
            result=create_term(result,co_efficient_poly1,power_of_x_poly1,power_of_y_poly1);
            temp_poly1=temp_poly1->next;
        }
        else{
            result=create_term(result,co_efficient_poly2,power_of_x_poly2,power_of_y_poly2);
            temp_poly2=temp_poly2->next;
        }
    }
    if(temp_poly1!=NULL){
        while(temp_poly1!=NULL){
            result=create_term(result,temp_poly1->co_efficient,temp_poly1->power_of_x,temp_poly1->power_of_y);
            temp_poly1=temp_poly1->next;
        }
    }
    else if(temp_poly2!=NULL){
        while(temp_poly2!=NULL){
            result=create_term(result,temp_poly2->co_efficient,temp_poly2->power_of_x,temp_poly2->power_of_y);
            temp_poly2=temp_poly2->next;
        }
    }
    return result;
}
void print_poly(struct term *head){
    int count=0;
    struct term *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count>10){
        cout<<"Number of terms exceed the MAXSIZE limit";
        exit(0);
    }
    cout<<count<<"\n";
    temp=head;
    while(temp!=NULL){
        cout<<temp->co_efficient<<" "<<temp->power_of_x<<" "<<temp->power_of_y<<"\n";
        count++;
        temp=temp->next;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    struct term *poly1=NULL, *poly2=NULL, *result=NULL;
    int m,n,co_efficient,power_of_x,power_of_y;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>co_efficient>>power_of_x>>power_of_y;
        poly1=create_term(poly1,co_efficient,power_of_x,power_of_y);
    }
    for(int i=0;i<n;i++){
        cin>>co_efficient>>power_of_x>>power_of_y;
        poly2=create_term(poly2,co_efficient,power_of_x,power_of_y);
    }
    result=add_poly(poly1,poly2,result);
    print_poly(result);
    return 0;
}