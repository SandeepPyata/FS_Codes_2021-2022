/* 
Minimum Platforms GFG
Minimum Rooms ii - Leetcode
https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms-ii



KMIT hosting a Keshav Memorial Badminton League. They planned to conduct 
N number of games. Each game begin and ends in perticular time slot. 
 
You are given an array of time slots of the N games, consisting of 
begin and end times (b1,e1),(b2,e2),... (b < e ). 
Your task is to determine minimum number of badminton courts required  
to conduct all the games smoothly. 
 
NOTE: If a game begins at time 'a' ends at time 'b',  
another game can start at 'b'. 
 
Input Format: 
------------- 
Line-1: An integer N, number of games. 
Next N lines: Two space separated integers, begin and end time of each game. 
 
Output Format: 
-------------- 
Print an integer, minimum number of badminton courts required. 
 
 
Sample Input-1: 
--------------- 
3 
0 30 
5 10 
15 20 
 
Sample Output-1: 
---------------- 
2 
 
Sample Input-2: 
--------------- 
3 
0 10 
15 25 
25 35 
 
Sample Output-2: 
---------------- 
1
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int> v, v1;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(a);
        v1.push_back(b);
    }
    
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    
    int c = 1, res = 1;
    for(int i=1,j=0;i<n and j<n;){
        if(v[i]<v1[j]){
            c++;
            i++;
        }
        else{
            c--;
            j++;
        }
        res = max(res,c);
    }
    
    cout<<res<<endl;
    return 0;
}