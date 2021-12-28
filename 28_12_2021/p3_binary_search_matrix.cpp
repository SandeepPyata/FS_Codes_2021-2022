/*
There are B bags containing N gold boxes each. In each bag, gold boxes are 
arranged  in ascending order of their weights strictly, create a method in 
such a way that we need to return the least weight of gold box which is 
common least weight in all the given bags.

If we don’t have any common least weighted gold box, among all the bags then return -1.

Input Format:
-------------
Line-1: Two integers B and N, number of bags and number of goldboxes in each Bag.
Next B lines: N space separated integers, weights of GoldBoxes.

Output Format:
--------------
Print the least weight of gold box, if found
Print -1, if not found.


Sample Input:
---------------
5 5
1 2 3 4 5
2 3 6 7 9
1 2 3 5 8
1 3 4 6 8 
2 3 5 7 8

Sample Output:
----------------
3
*/

#include<bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int> v, int ele, int size){
    int l = 0, h = size-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(v[mid]==ele)
            return true;
        if(v[mid]>ele)
            h = mid-1;
        else
            l = mid+1;
    }
    return false;
}

int fun(vector<vector<int>> vec){
    int n = vec.size(), m = vec[0].size();
    for(int i=0;i<m;i++){
        int ele = vec[0][i];
        int count = 0;
        for(int j=1;j<n;j++){
            if(binarysearch(vec[j],ele,m))
                count++;
        }
        if(count==n-1)
            return ele;
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    
    cout<<fun(v);

    return 0;
}