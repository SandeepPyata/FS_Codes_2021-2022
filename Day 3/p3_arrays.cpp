/*
You are given a bunch of sticks with diffrent lengths.
All the even length sticks should be arranged to appear first in the bunch and 
all the odd length sticks should be arranged to appear first in the bunch.

Print the length of the sticks, after arranging them according to above conditions. 

Input Format:
-------------
Line-1: An integer N, number of sticks in the bunch
Line-2: N space separated integers, lengths of the sticks.

Output Format:
--------------
Print the list of length of the sticks after arrangements accordingly.


Sample Input-1:
---------------
4
1 4 3 2

Sample Output-1:
----------------
[4, 2, 1, 3]


Sample Input-2:
---------------
8
10 13 1 6 9 12 9 10


Sample Output-2:
----------------
[10, 6, 12, 10, 13, 1, 9, 9]
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    
    for(int i=0;i<n;i++){
        if(arr[i]%2){
            int j = i+1;
            while(j<n and arr[j]%2)
                j++;
                
            if(j>=n)
                break;
            
            int temp = arr[j];
            for(int k=j;k>i;k--)
                arr[k] = arr[k-1];
            arr[i] = temp;
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    
    return 0;
}