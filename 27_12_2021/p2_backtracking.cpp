/*
Bablu is working in a construction field.
He has N number of building blocks, where the height and width of all the blocks are same.
And the length of each block is given in an array, blocks[].

Bablu is planned to build a wall in the form of a square.
The rules to cunstruct the wall are as follows:
	- He should use all the building blocks.
	- He should not break any building block, but you can attach them with other.
	- Each building-block must be used only once.
	
Your task is to check whether Bablu can cunstruct the wall as a square
with the given rules or not. If possible, print true. Otherwise, print false.

Input Format:
-------------
Line-1: An integer N, number of BuildingBlocks.
Line-2: N space separated integers, length of each block.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
6
1 2 6 4 5 6

Sample Output-1:
----------------
true

Sample Input-2:
---------------
6
5 3 2 5 5 6

Sample Output-2:
----------------
false
*/
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &vis,int side,vector<int> &v,int f,int &sum){
    if(sum==side && f==v.size())
        return 1;
    if(sum==side)
        sum = 0;
    if(sum>side)
        return 0;
    
    for(int i=0;i<v.size();i++){
        if(vis[i]==0){
            vis[i] = 1;
            sum+=v[i];
            if(func(vis,side,v,f+1,sum)==1)
                return 1;
            sum-=v[i];
            vis[i] = 0;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    
    int sum = 0;
    for(auto &i:v){
        cin>>i;
        sum += i;
    }
        
    if(sum%4!=0){
        cout<<"false"<<endl;
        return 0;
    }
    
    int side = sum/4, flag = 0;
    vector<int> vis(n,0);
    int temp = 0;
    if(func(vis,side,v,0,temp)==1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
    return 0;
}