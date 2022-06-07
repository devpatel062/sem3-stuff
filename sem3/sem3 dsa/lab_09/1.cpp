
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[low]; 
    int i = low;
    int j = high;

    while(i < j)
    {
        do
        {
            i++;
        }while(arr[i] <= pivot);
        do
        {
            j--;
        }while(arr[j] > pivot);
        if(i < j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int j = partition(arr, low, high);

        
        quickSort(arr, low, j);
        quickSort(arr, j+ 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int num;
    cin>>num;
    int arr[num+1];
    for(int i=0 ;i<num;i++)
    {
        cin>>arr[i];
    }
    arr[num]=INT_MAX;
    
    quickSort(arr, 0, num);
    printArray(arr, num);
    return 0;
}


