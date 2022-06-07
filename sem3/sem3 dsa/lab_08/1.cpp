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

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node * rt = NULL;
bool search_node(node *root, int value)
{
    node *temp = root;
    if (temp == NULL)
    {
        return false;
    }
    if (temp->data == value)
    {
        rt = temp;
        return true;
    }
    bool is_left = search_node(temp->left, value);
    if (is_left)
        return true;

    bool is_right = search_node(temp->right, value);
    if (is_right)
        return true;

    return false;
}

void insertNode(node *root, int ro, int le, int ri)
{
    bool v = search_node(root, ro);
    bool l = search_node(root,le);
    bool r = search_node(root,ri);
    if (v == true)
    {
        if (l && le!=0)
        {
            cout << "Left node is already a child node" << endl;
            exit(0);
        }
        else if (r && ri!=0)
        {
            cout << "Right node is already a child node" << endl;
            exit(0);
        }
        else
        {
            if(ri!=0)
            {
                rt->right = new node(ri);
            }
            if(le!=0)
            {
                rt->left = new node(le);
            }
        }
    }
}

void inorder(node*root){
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node*root){
    if(root==NULL){
        return;

    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    if(root==NULL){
        return;

    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    cin >> n;

    int ro, le, ri;
    cin >> ro >> le >> ri;

    node *root = new node(ro);
    root->left = new node(le);
    root->right = new node(ri);
    if (ro == le || ri == ro)
    {
        cout << "Tree can not contain loop";
        exit(0);
    }
    
    for (int i = 1; i < n; i++)
    {
        cin >> ro >> le >> ri;
        if (le == 0 && ri == 0)
        {
            continue;
        }
        else if (ro == le || ri == ro)
        {
            cout << "Tree can not contain loop";
            exit(0);
        }
        else
        {
            insertNode(root, ro, le, ri);
        }
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}