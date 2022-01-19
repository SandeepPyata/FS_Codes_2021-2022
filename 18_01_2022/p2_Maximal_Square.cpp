/* 

\\Maximal Square Leetcode

The decoration on the wall, made up of led bulbs. 
When the bulbs turned on they emit either bule color light
or white color light. The leds bulbs decorated in the form of a grid
of size m*n. And when you turned on the bulbs, the bulbs are emiting
the light in blue color (1) and white color (0).

You are given the current state of the decorated wall of size M*N,
Your task is to find the biggest square can be formed using blue colored bulbs,
and return its area.

Input Format:
-------------
Line-1: Two space separated integers, M and N size of the decoration grid.
Next M lines: N space separated integers ( either 0 or 1 only).

Output Format:
--------------
Print an integer, area of the biggest square grid of blue colored bulbs.


Sample Input:
-------------
5 6
1 0 0 1 0 1
0 1 1 1 1 1
1 1 1 1 0 1
0 1 1 1 0 1
1 0 1 0 1 1 

Sample Output:
--------------
9
 */
#include<bits/stdc++.h>
using namespace std;

int pyata(vector<vector<int>>& matrix) {
    if(matrix.size()==0)    return 0;
    
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(r+1,vector<int>(c+1,0));
    int ans = 0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(matrix[i-1][j-1]==1){
                dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                ans = max(ans,dp[i][j]);
            }
        }
    }
    return ans*ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    
    cout<<pyata(matrix)<<endl;
    
    return 0;
}