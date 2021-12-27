/*
Giridhar went to a bank to get 1-rupee coins for N rupees.
In the cash counter, there are unlimited CoinBags, 
each bag contains square number of coins (i.e, 1,4,9,16,...)

The clerk in the cash counter needs to provide the CoinBags,
Find the minimum number of CoinBags to give to Giridhar, whose total value equals N rupees.

Input Format:
-------------
An integer N.

Output Format:
--------------
Print an integer, minimum number of bags.


Sample Input-1:
---------------
13

Sample Output-1:
----------------
2

Explanation: 13 = 9 + 4

Sample Input-2:
---------------
21

Sample Output-2:
----------------
3

Explanation: 21 = 16+4+1.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int dp[n+1];
    for(int i=0;i<n+1;i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i],dp[i-(j*j)]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}


// back-tracking - 62.50% passed : other tcs: TLE

// #include<bits/stdc++.h>
// using namespace std;

// void func(vector<int> &nums, int target, bool &f,int index, int &count,int &minCount){
    
//     if(target==0){
//         f = true;
//         minCount = min(minCount,count);
//         return;
//     }
//     if(target<0)
//         return;
    
//     for(int i=index;i>=0;i--){
//         count++;
//         func(nums,target-nums[i],f,i,count,minCount);
//         if(f)
//             return;
//         count--;
//     }
// }

// int main()
// {
//     int n;
//     cin>>n;
    
//     int l = sqrt(n);
    
//     vector<int> nums(l+1);
//     for(int i=1;i<=l+1;i++)
//         nums[i-1] = i*i;
    
//     bool f = false;
//     int count = 0;
//     int minCount = INT_MAX;
//     func(nums,n,f,nums.size()-1,count,minCount);
    
//     cout<<minCount<<endl;
//     return 0;
// }