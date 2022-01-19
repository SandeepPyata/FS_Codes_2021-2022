/* 

Leetcode : https://leetcode.com/problems/integer-replacement/


Sampoornesh Babu is learning arithmatics.
His teacher given him a task to find the minimum number of operations
required to convert a given integer I to 1.

Sampoornesh is allowed to perform the following operations:
	- If I is even, convert I with I/2 .
	- In I is odd, convert I with either I+1 or I-1.

Now it's your task to help Sampoornesh Babu to find and print
the minimum number of operations required.

Input Format:
-------------
An integer I.

Output Format:
--------------
Print an integer, the minimum number of operations required.


Sample Input-1:
---------------
10

Sample Output-1:
----------------
4

Explanation:
------------
10 -> 5 -> 4-> 2 -> 1.


Sample Input-2:
---------------
15

Sample Output-2:
----------------
5

Explanation:
------------
15 -> 16 -> 8 -> 4 -> 2 -> 1.
 */
#include<bits/stdc++.h>
using namespace std;

int integerReplacement(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0) 
        return (1 + integerReplacement(n / 2));
    else 
    return (2 + min(integerReplacement(n/2), integerReplacement(n/2 + 1)));
}

int main()
{
    long n;
    cin>>n;
    
    cout<<integerReplacement(n);
    
        // Bottom-Up => TLE & Memory-limit Exceeded
    // vector<long>dp(n+1);
    // dp[0] = dp[1] = 0;
    // for(long i=2;i<=n;i++){
    //     if(i%2==0){
    //         dp[i] = 1+dp[i/2];
    //     }
    //     else{
    //         dp[i] = 1+min(dp[(i-1)],1+dp[(i+1)/2]);
    //     }
    // }
    
    // cout<<dp[n];
    return 0;
}