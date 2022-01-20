/* 

Leetcode 562 : 
https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/solutions-551-600/562-longest-line-of-consecutive-one-in-matrix.html

A merchant has two types of idols, gold and silver.
He has arranged the idols in the form of m*n grid, 
	- the gold idols are represented as 1's 
	- the silver idols are represented as 0's.

Your task is to find the longest consecutive arrangement of gold idols, 
The arrangement can be either horizontal, vertical, diagonal or 
antidiagonal, but not the combination of these.


Input Format:
-------------
Line-1: Two space separated integers m and n, grid size.
Next m lines : n space separated integers, arrangement of idols.

Output Format:
--------------
Print an integer, longest arranement of gold idols.


Sample Input:
---------------
4 5
1 0 1 1 1
0 1 0 1 0
1 0 1 0 1
1 1 0 1 1

Sample Output:
----------------
4

 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    
    
    vector< vector<vector<int>> > dp(n,vector<vector<int>>(m,vector<int>(4,0)));
    
    // 0 => up, 1 => diagonal, 2 => left
    int count = mat[0][0];
    
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = mat[0][0];
    
    // filling up - 0th column
    for(int i=1;i<n;i++){
        if(mat[i][0]){
            dp[i][0][0] = dp[i-1][0][0] + mat[i][0];
            dp[i][0][1] = dp[i][0][2] = dp[i][0][3] = mat[i][0];
            
            if(n>1)
                dp[i][0][3] += dp[i-1][1][3];
            
            count = max({count,dp[i][0][0],dp[i][0][1],dp[i][0][2]});
        }
    }
    // filling left:wise - 0th row
    for(int i=1;i<m;i++){
        if(mat[0][i]){
            dp[0][i][2] = dp[0][i-1][2] + 1;
            dp[0][i][0] = dp[0][i][1] = dp[0][i][3] = mat[0][i];
            count = max({count,dp[0][i][0],dp[0][i][1],dp[0][i][2]});
        }
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]){
                dp[i][j][0] = dp[i-1][j][0]  +1;
                dp[i][j][1] = dp[i-1][j-1][1]+1;
                dp[i][j][2] = dp[i][j-1][2]  +1;
                dp[i][j][3] = 1;
                
                if(j+1<m)
                    dp[i][j][3] += dp[i-1][j+1][3];
                count = max({count,dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]});
            }
        }
    }
    
    cout<<count<<endl;
    
    return 0;
}