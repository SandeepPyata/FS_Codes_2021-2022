/*
You are given a list of N integers List[], list contains both +ve and -ve integers.
Your task is to findout, the Highest Product possible,
Where the product is the product of all the elements of contiguous sublist sList[],
and sublist should conatin atleast 1 integer.

Input Format:
-------------
Line-1: An integer N.
Line-2: N space separated integers, List[].

Output Format:
--------------
Print an integer output, the highest product.

Sample Input-1:
---------------
4
2 3 -2 4

Sample Output-1:
----------------
6

Explanation:
------------
Product of contiguous sub list [2,3].


Sample Input-2:
---------------
3
-2 0 -3

Sample Output-2:
----------------
0

Explanation:
------------
Product of sub list [0], where [-2,-3] is not a contiguous sublist
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)
        cin>>i;
        
    // Method 1: DP
    int maxp = 1, minp = 1, maxprod = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(v[i]<0)
            swap(maxp,minp);
        maxp = max(v[i],maxp*v[i]);
        minp = min(v[i],minp*v[i]);
        maxprod = max(maxprod,maxp);
    }
    cout<<maxprod<<endl;        


    // Method 2: Prefix & Suffix Array
        
    // int pre[n],suff[n], prod = 1;
    
    // for(int i=0;i<n;i++){
    //     pre[i] = (prod*=v[i]);
    //     if(prod==0)
    //         prod = 1;
    // }
    // prod = 1;
    // int maxprod = INT_MIN;
    // for(int i=n-1;i>=0;i--){
    //     prod *= v[i];
    //     maxprod = max({maxprod,pre[i],prod});
    //     if(prod==0)
    //         prod = 1;
    // }
    // cout<<maxprod<<endl;
    return 0;
}