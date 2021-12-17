/*
Mr Sudhakar is given a checkerboard of size 400*400, where the indices starts 
from (-200,-200) and ends at (199,199). In one step, he can move the box from 
position (p,q) to one of the following positions in L shape like as follows: 
	- (p-2, q-1), (p-2, q+1), (p+2, q-1), (p+2, q+1)
	- (p-1, q+2), (p+1, q+2), (p-1, q-2), (p+1, q-2)

Initially the box is at (0,0) position, and need to move the box to position (m,n).
You will be given two integers m and n indicates the position(m,n).

Now your task is to help by Mr Sudhakar to find the minimum number of steps 
required to move the box from (0,0) to (m,n).

Note: It is allowed to move out of the board also.

Input Format:
-----------------
Two space separated integers, m and n, position.

Output Format:
------------------
Print an integer, minimum number of steps to reach (m,n).


Sample Input-1:
---------------
2 4

Sample Output-1:
----------------
2

Explanation:
-------------
Initially, you are at (0,0) position, you can reach (2,4) as follows:
(0,0) -> (1, 2) -> (2, 4) 


Sample Input-2:
---------------
4 7

Sample Output-2:
----------------
5

Explanation:
------------
Initially, you are at (0,0) position, you can reach (4,7) as follows:
(0,0) -> (1, 2) -> (2, 4) -> (1, 6) -> (3, 5) -> (4, 7)
*/
#include<bits/stdc++.h>
using namespace std;

int dfs(int i, int j, map<string,int>&mp){
    string key = to_string(i) + "," + to_string(j);
    if(mp[key])
        return mp[key];
    if(i+j==0)          // at origin (0,0)
        return 0;
    else if(i+j==2)     // at 1,1 => 2 steps to (0,0) => 2,-1 and 0,0 
        return 2;
    else{
        int res = 1 + min(dfs(abs(i-1),abs(j-2),mp),dfs(abs(i-2),abs(j-1),mp));
        mp[key] = res;
        return res;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    map<string,int>mp;    
    
    cout<<dfs(abs(a),abs(b),mp)<<endl;
    
    
    return 0;
}
