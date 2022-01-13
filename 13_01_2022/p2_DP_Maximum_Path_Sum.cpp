// Reference Link : https://www.geeksforgeeks.org/maximum-path-sum-matrix/

/* The bomb grid is filled with danger values, with both positive and negative integers.
positive means you will lose power of grid[i][j], 
negative means you will gain power of grid[i][j].

Naresh wants to cross the bridge, with the minimum loss of power.
He can cross the grid in the following way:
	- He can start at any bomb cell in the first row.
	- He can step on the next bomb cell in the next row that 
	  is either directly below of the current cell or diagonally left/right. 
	- Specifically, the next bomb cell from position grid(i, j) will be grid(i+1,j-1),
	(i + 1, j) , or (i + 1, j + 1) .

Can you help Naresh to lose the minimum power after crossing the bomb grid.

Input Format:
-------------
Line-1: An integer N, size of N*N grid 
Next N lines: N space separated  integers, values in the grid.

Output Format:
--------------
Print an integer, minimum sum of TopDown path.


Sample Input-1:
---------------
3
1 3 2
5 4 6
9 8 7

Sample Output-1:
----------------
12

Explanation:
-------------
Minimum lose of power is as follows:
start from bomb cell	1 -> 4 -> 7
Total lose is 12.


Sample Input-2:
---------------
3
32 10 23
-15 14 -16
19 -18 17

Sample Output-2:
----------------
-24

Explanation:
-------------
Minimum lose of power is as follows:
start from bomb cell	10 -> -16 -> -18
Total lose is -24.

 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
        
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0)    v[i][j] += min(v[i-1][j],v[i-1][j+1]);
            else if(j==n-1) v[i][j] += min(v[i-1][j],v[i-1][j-1]);
            else    v[i][j] += min({v[i-1][j-1],v[i-1][j],v[i-1][j+1]});
        }
    }
    
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
        ans = min(ans,v[n-1][i]);
    
    cout<<ans<<endl;
    
    return 0;
}