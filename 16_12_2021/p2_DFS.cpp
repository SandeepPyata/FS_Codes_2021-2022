/*
There are some Warships, approaching the borders of India and curretly
situated in Bay of Bengal. One of the secret agent sent the picture of the warships.
 
The picture size is M * N, and he has marked each 1*1 part of the picture either 
with the Warships as 'W' or an empty place as 'E'. The Indian Navy want to destroy
those Warships using Torpedos, with one Torpedo you can destroy one Warship.

 The Warships are mentioned either horizontally or vertically in the picture. 
 And it is also mentioned that there are no adjacent warships.

Your target is find the number of Torpedos required to destroy all the Warships.

Input Format:
-------------
 Line-1: Two space separated integers M and N.
 Next M lines: N space separated characters, either W or E

Output Format:
--------------
Print an integer, number of torpedos required.
  
 Sample Input-1:
 ---------------
 2 3
 W E E
 W E E

Sample Output-1:
 ----------------
 1


 Sample Input-2:
---------------
 4 5
 W E E W W
 W E W E E
 W E W E W
 W E W E W
 
Sample Output-2:
----------------
 4

*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j, vector<vector<char>> &vec, int n,int m)
{
    if(i<0 or j<0 or i>=n or j>=m or vec[i][j]=='E')
        return;
    
    vec[i][j] = 'E';
    dfs(i+1,j,vec,n,m);
    dfs(i,j+1,vec,n,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> vec(n,vector<char>(m));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>vec[i][j];
    
    int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]=='W'){
                dfs(i,j,vec,n,m);
                count++;
            }
        }
    }
            
    cout<<count<<endl;
    
    return 0;
}