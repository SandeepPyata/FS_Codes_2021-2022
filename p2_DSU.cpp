/*
There are P people in a Village, some of the people are relatives, others are not.
Their relationship is transitive in nature. 

For example, 
 if A is a direct relative of B, and B is a direct relative of C, 
then A is an indirect relative of C. And we define a Relation Chain is a group 
of people who are direct or indirect relatives.
 
 Given a P*P matrix R representing the relationship between people in the village. 
 If R[i][j] = 1, then the i and j persons are direct relatives with each other, 
 otherwise not. 

Your task is to findout the total number of Relation Chains among all the people.

Input Format:
-------------
Line-1 : An integer P, number of people
Next P lines : P space separated integers.

Output Format:
--------------
Print an integer, the total number of Relation Chains


Sample Input-1:
---------------
3
1 1 0
1 1 0
0 0 1

Sample Output-1:
----------------
 2

 Explanation:
 ------------
 The 0-th and 1-st people are direct relatives, so they are in a relation chain.
 The 2-nd person himself is in a relation chain. So return 2.

Sample Input-2:
---------------
3
 1 1 0
 1 1 1
 0 1 1
 
Sample Output-2:
----------------
 1

Explanation:
------------
The 0-th and 1-st people are direct relatives, 1-st and 2-nd people are direct 
relatives. So, the 0-th and 2-nd people are indirect relatives.
All of them in the same relative chain. So return 1.

*/

#include<bits/stdc++.h>
using namespace std;

int find(int x, int par[]){
    while(x!=par[x])
        x = par[x];
    return x;
}

void union1(int i,int j,int par[]){
    int a = find(i,par);
    int b = find(j,par);
    if(a!=b)
        par[max(a,b)] = min(a,b);
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> mat(n,vector<int>(n));
    int par[n];
    
    for(int i=0;i<n;i++)
        par[i] = i;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
            
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1)
                union1(i,j,par);
        }
    }
    int c = 0;
    for(int i=0;i<n;i++)
        c += (par[i]==i);
    
    cout<<c<<endl;
    
    return 0;
}    
