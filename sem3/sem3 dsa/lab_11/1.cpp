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

struct node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
};

node *insert_in_tree(node *ptr, int value)
{
    if (ptr == NULL)
    {
        node *new_node = new node;
        new_node->data = value;
        return new_node;
    }
    else
    {
        node *new_node = new node;
        new_node->data = value;
        if (ptr->data < value)
        {
            ptr->right = insert_in_tree(ptr->right, value);
        }
        else
        {
            ptr->left = insert_in_tree(ptr->left, value);
        }
        return ptr;
    }
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}
bool ifNodeExists(struct node* node, int key)
{
    if (node == NULL)
        return false;
 
    if (node->data == key)
        return true;

    bool res1 = ifNodeExists(node->left, key);
    if(res1) return true;
 
    bool res2 = ifNodeExists(node->right, key);
 
    return res2;
}
node *delete_from_tree(node *ptr, int value)
{
    if (ptr == NULL)
    {
        return ptr;
    }
    if(ifNodeExists(ptr, value)){
    if (ptr->data < value)
    {
        ptr->right = delete_from_tree(ptr->right, value);
    }
    else if (ptr->data > value)
    {
        ptr->left = delete_from_tree(ptr->left, value);
    }
    else if (ptr->data == value)
    {
        if (ptr->left == NULL && ptr->right == NULL)
            return NULL;
        else if (ptr->left == NULL)
        {
            struct node *temp = ptr->right;
            free(ptr);
            return temp;
        }
        else if (ptr->right == NULL)
        {
            struct node *temp = ptr->left;
            free(ptr);
            return temp;
        }
        struct node *temp = minValueNode(ptr->right);

        ptr->data = temp->data;

        ptr->right = delete_from_tree(ptr->right, temp->data);
    }
    return ptr;
    }
    else
    {
        cout << "Node ";
        cout << value;
        cout << " is not found in the tree";
        exit(0);
    }

    return ptr;
}

void inorder(node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    node *ptr = NULL;
    int num;cin >> num;
    int arr[num];

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    
    ptr=insert_in_tree(ptr,arr[0]);
    for (int i = 1; i < num ; i++)
    {
        insert_in_tree(ptr, arr[i]);
    }
    int m;
    cin >> m;
    int deletes[m];
    for (int i = 0; i < m; i++)
    {
        cin >> deletes[i];
    }
    ptr = delete_from_tree(ptr, deletes[0]);
    for (int i = 1; i < m; i++)
    {
        delete_from_tree(ptr, deletes[i]);
    }

    inorder(ptr);
    cout << '\n';
    preorder(ptr);
    return 0;
}