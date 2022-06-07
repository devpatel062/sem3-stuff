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
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
   
int minDistanceance(int distance[], bool sptSet[], int number){
    int min=INT_MAX, min_index=0;
    for(int v=0; v<number; v++){
        if(sptSet[v]==false && distance[v]<=min){
            min=distance[v];
            min_index=v;
        }
    }
    return min_index;
}
void printPath(int parent[], int j){
    if(parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    cout<<"->"<<j+1;
}
void printSolution(int distance[], int n, int parent[], int src){
    for(int i=0; i<n; i++){
        cout<<i+1<<"\t"<<distance[i]<<"\t"<<src;
        printPath(parent, i);
        cout<<endl;
    }
}

int main()
{
    int number, start_point;
    cin>>number;
    int matrix[number][number];
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++){
            cin>>matrix[i][j];
            if(i==j && matrix[i][j]!=0){
                cout<<"Weight of the edge "<<i+1<<" <-> "<<i+1<<" must be 0";
                exit(0);
            }
            if(matrix[i][j]!=-1 && i!=j && matrix[i][j]<0){
                cout<<"Weight of the edge "<<i+1<<" <-> "<<j+1<<" can not be negative";
                exit(0);
            }
            if(matrix[i][j]!=-1 && i!=j && matrix[i][j]==0){
                cout<<"Weight of the edge "<<i+1<<" <-> "<<j+1<<" can not be 0";
                exit(0);
            }
        }
    }
    cin>>start_point;
    int distance[number];
    bool sptSet[number];
    int parent[number];
    for(int i=0; i<number; i++){
        parent[start_point-1]=-1;
        distance[i]=INT_MAX;
        sptSet[i]=false;
    }
    distance[start_point-1]=0;
    for(int count=0; count<number-1; count++){
        int u=minDistanceance(distance, sptSet, number);
        sptSet[u]=true;
        for(int v=0; v<number; v++){
            if(!sptSet[v] && matrix[u][v]!=-1 && distance[u]+matrix[u][v]<distance[v]){
                parent[v]=u;
                distance[v]=distance[u]+matrix[u][v];
            }
        }
    }
    printSolution(distance, number, parent, start_point);
    return 0;
}