/* 

Leetcode 505 : Maze II
https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/solutions-501-550/505-the-maze-ii.html


Aravind went to a forest, he stuck inside the forest and He is blind.
The forest is given as a square grid. The forest grid is filled with trees 
and empty cells. He can move upwards, downwadrs, left and right, 
but he cannot stop until he touches the tree. Once he touches a tree, 
he can choose the next direction to move. Intially Aravind is at poistion A, 
and he is trying to reach a safe-point at position S.

You will be given the forest grid filled with 1's and 0's, 1 means tree 
and 0 means empty cell. And initial position of Aravind, safe-point S.

Your task is to find the minimum distance travelled by Aravind to reach 
the safe-point, If he cannot stop at the safe-point, return -1.

You may assume that the borders of the forest are all trees.


Input Format:
-------------
Line-1: An integer N, size of the grid.
Next N lines: N space separated integers
Next line:  two space separated integers, initial position of Aravind
Next line:  two space separated integers, position of safe-point.

Output Format:
--------------
Print an integer, minimum distance travelled by Aravind to reah safe-point.


Sample Input-1:
---------------
5
0 1 0 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 0 1
0 0 0 0 0
2 4
4 0

Sample Output-1:
----------------
10

Explanation:
------------
For Picture look at hint.
The minimum path is : up -> left -> down -> left.

Sample Input-2:
---------------
5
0 1 0 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 0 1
0 0 0 0 0
0 3
3 3

Sample Output-2:
----------------
-1

Explanation: 
------------
Aravind cannot stop at safe-point.
 */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int sti,int stj, vector<vector<int>> &mat, vector<vector<int>> &dist)
{
    
    for(auto it:dir){
        int x = sti + it[0];
        int y = stj + it[1];
        int count = 0;
        while(x>=0 && y>=0 && x<mat.size() && y<mat[0].size() && mat[x][y]==0)
        {
            x += it[0];
            y += it[1];
            count++;
        }
        if(dist[sti][stj]+count<dist[x-it[0]][y-it[1]]){
            dist[x-it[0]][y-it[1]] = dist[sti][stj] + count;
            dfs(x-it[0],y-it[1],mat,dist);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    int x1,y1,x2,y2;
    
    cin>>x1>>y1;
    cin>>x2>>y2;
    
    dist[x1][y1] = 0;
    
    dfs(x1,y1,mat,dist);
    
    cout<<(dist[x2][y2]==INT_MAX?-1:dist[x2][y2])<<endl;
    return 0;
}