/*
Mahalakshmi participated in a treasure-hunt conatins N boxes in it.
Each box is numbered from 0,1,2,3,...,N-1. 
All the boxes are intially locked with the passcodes, except Box-0.
The passcode is written in a envolope and marked with its concern box number.

Each box in the treasure hunt contains a list of envelopes, which has 
passcodes to open the other boxes. You can open the boxes in any order, 
but you have to start from box-0 intially.

The rule to win the treasure-hunt is to open all the boxes.
Your task is to find out, whether Mahalakshmi win the treasure hunt or not.
If she win, print "Win".
Otherwise, print "Lost"

Input Format:
-------------
Line-1: An integer, number of boxes.
Next N lines: space separated integers, box numbers.

Output Format:
--------------
Print a string value, Win or Lost


Sample Input-1:
---------------
5
1
2
3
4

Sample Output-1:
----------------
Win


Sample Input-2:
---------------
4
1 3
3 0 1
2
0

Sample Output-2:
----------------
Lost
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj, vector<int> &vis, int n, int ind){
    
    if(ind>=n or vis[ind])    return;
    
    vis[ind] = 1;
    for(int i=0;i<adj[ind].size();i++){
        dfs(adj,vis,n,adj[ind][i]);
    }
}

string check(vector<int> &vis){
    for(int i=0;i<vis.size();i++)
        if(vis[i]==0)
            return "Lost";
    return "Win";    
}

int main()
{
    int n;
    string s;
    getline(cin,s);
    stringstream ss(s);
    int t;
    while(ss>>t)
        n = t;
    
    vector<vector<int>> adj(n);
    
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int t;
        while(ss>>t)
            adj[i].push_back(t);
    }
    

    vector<int> vis(n,0);
    dfs(adj,vis,n,0);
    
    cout<<check(vis)<<endl;
    
    return 0;
}