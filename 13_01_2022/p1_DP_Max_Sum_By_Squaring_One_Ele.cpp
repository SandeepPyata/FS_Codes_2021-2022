// Link : https://www.geeksforgeeks.org/maximum-subarray-sum-possible-by-replacing-an-array-element-by-its-square/
/* 
Aziz is given a set of integers SOI[], consists of both +ve and -ve integers.

Aziz wants to find the maximum sum of contiguous subset of the SOI, with a twist.

You have to perform the following operation before finding the maximum sum:
- You are allowed to replace exactly one integer X, with its square value (X*X).

Can you please help Aziz to find out the maximum sum of contiguous subset.


Input Format:
-------------
Single line of space separated integers, values of the array.

Output Format:
--------------
Print an integer value as result.


Sample Input-1:
---------------
-5 -3 1 2 -3 4 -4 3

Sample Output-1:
----------------
26

Explanation:
------------
max sum is: (-5)^2 + (-3) + 1 + 2 + (-3) + 4 = 26


Sample Input-2:
---------------
2 -2 2 2 -2 -2 2

Sample Output-2:
----------------
10

Explanation:
------------
max sum is: 2 +(-2)^2 + 2 + 2 = 10
 */
#include<bits/stdc++.h>
using namespace std;

// Recursive - Not Working
// int msa(vector<int> &v, int n, int flag){
//     if(n==0){
//         if(flag==1)
//             return v[n];
//         return v[n]*v[n];
//     }
//     int a = INT_MIN, b = INT_MIN;
//     if(flag==0){
//         a = max(msa(v,n-1,1)+(v[n]*v[n]),v[n]*v[n]);
//         b = max(msa(v,n-1,0)+v[n],v[n]);
//     }
//     return max({a,b,msa(v,n-1,1)+v[n]});
// }


int main()
{
    string s;
    getline(cin,s);
    
    stringstream ss(s);
    int x;
    vector<int> v;
    while(ss>>x)
        v.push_back(x);
    // cout<<msa(v,n-1,0);
    

    
                // kadane's algo    
    int maxsum = 0, n = v.size();
    
    for(int i=0;i<n;i++){
        int currsum = 0, maxcurrsum = 0;
        for(int j=0;j<n;j++){
            if(i==j)
                currsum += (v[i]*v[i]);
            else
                currsum += v[j];
            maxcurrsum = max(maxcurrsum,currsum);
            if(currsum<0){
                currsum = 0;
                if(j>i) break;
            }
        }
        maxsum = max(maxcurrsum,maxsum);
    }
    
    cout<<maxsum<<endl;
    
    return 0;
}