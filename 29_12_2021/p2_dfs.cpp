/*
Brahmi and his gang was chased by group of police officers, unfortunately 
they all got locked up in a building consist of M*N rooms in the form of 
a grid. All the rooms are connected with  the adjacent rooms both horizontally
and vertically. There are few rooms for them to escape called as safe zones. 

Now help Brahmi and his gang to reach the safe zones in the building.

In the Building we have the rooms filled with following values: [0,-1,-2] 
where, -1 -> Danger zone (they should not enter into it).
0 -> Safe Zone (room to escape)
-2 -> a thief

Now create a method to print the grid after performing following step: 
Fill each room with one of the member from The Brahmi and his gang with 
the distance to its nearest safe zone.
If it is impossible to reach a safezone, fill with '-2' only.

Input Format:
-------------
Line-1 -> two integers M and N, size of the grid of rooms.
Next M Lines -> N space separated integers, from this set [-2,-1,0] only.

Output Format:
--------------
Print an integer as result.


Sample Input-1:
---------------
4 4
-2 -1 0 -2
-2 -2 -2 -1
-2 -1 -2 -1
0 -1 -2 -2

Sample Output-1:
----------------
3 -1 0  1
2  2 1 -1
1 -1 2 -1
0 -1 3  4
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &v,int n,int m,int i,int j,int timee){
    if(i>=n || i<0 || j>=m || j<0 || v[i][j]==-1 || v[i][j]==0)
        return;

    if(v[i][j]==-2)
        v[i][j] = timee;
    else{
        if(timee>v[i][j])
            return;
        v[i][j] = timee;
    }
    
    dfs(v,n,m,i+1,j  ,timee+1);
    dfs(v,n,m,i  ,j+1,timee+1);
    dfs(v,n,m,i-1,j  ,timee+1);
    dfs(v,n,m,i  ,j-1,timee+1);
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> v(n,vector<int>(m));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                dfs(v,n,m,i+1,j,1);
                dfs(v,n,m,i,j+1,1);
                dfs(v,n,m,i-1,j,1);
                dfs(v,n,m,i,j-1,1);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}