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

void DFS(int s, vector<int> arr[], bool visited[])
{
  visited[s] = true;
  cout<<s<<" ";

     vector<int>::iterator i;
     for (i = arr[s].begin(); i != arr[s].end(); ++i)
     {
         if(!visited[*i])
         {
             DFS(*i,arr,visited);
         }
     }
}
void BFS(int s, vector<int> arr[], bool visited[])
{
  queue<int> q; 
  q.push(s);
  visited[s] = true;
  while (!q.empty())
  {
    int u = q.front();
    cout << u << " ";
    q.pop();
   
    for (int i = 0; i < arr[u].size(); i++)
    {
      if (!visited[arr[u][i]])
      {
        q.push(arr[u][i]);
        visited[arr[u][i]] = true;
      }
    }
  }
}

void edge(vector<int> arr[], int u, int v)
{
  arr[u].push_back(v);
  arr[v].push_back(u);
}

int main()
{

  int n,m;
  cin>>n>>m;

  vector<int> arr[m]; 
  bool visited[n];      

  for (int i = 1; i <= n; i++)
  {
    visited[i] = false;
  }

  int number1,number2,root_node;
  for(int i=0;i<m;i++)
  {
      cin>>number1>>number2;
      edge(arr,number1,number2);
  }
  cin>>root_node;
  
  BFS(root_node, arr, visited); 
  
  cout << endl;
  for (int i = 1; i <= n; i++)
  {
    visited[i] = false;
  }

  DFS(root_node, arr, visited); 
}