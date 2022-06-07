
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid+1;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    
    return -1;
}

int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    
    for(int i=0; i<n; i++)
    {
      cin >> arr[i];
    
      if(i != 0 && arr[i] <= arr[i-1])
      {
         cout << "Numbers are not in ascending order\n";
         exit(0);
      }
    }
    
    int m;
    cin >> m;
    
    while(m--)
    {
        int num;
        cin >> num;
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << binarySearch(arr,0, n-1,num)<< " ";
    }
}
