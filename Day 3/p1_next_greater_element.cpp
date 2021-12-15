
/*
Kiran Rao purchased two boxes (Box1,Box2) of unique weights 
of gold coins, where first box weights are subset of second box gold weights.

 Now design a method for Gumadi Baleshwar Rao to find all the next largest weights 
of Box1 gold coins in the corresponding locations of box2 , 
if doesn’t exist return -1.

The Next largest Weight is Weight ‘W’ in Box1 is the first largest weight 
 to its right side weight in Box2.

NOTE: Unique weights means, no two coins will have same weight.

 Input Format:
 -------------
Line-1: space separated integers, weihts of gold coins in the first box.
Line-2: space separated integers, weihts of gold coins in the second box.

Output Format:
--------------
 Print a list of integers, next largest weights

Sample Input-1:
---------------
 4 3 2
 1 3 4 2

Sample Output-1:
 ----------------
 [-1, 4, -1]


 Sample Input-2:
 ---------------
5 6 3 4
1 5 3 7 8 6 4 2

 Sample Output-2:
 ----------------
[7, -1, 7, -1]

*/
/*
Sample Input-1:
---------------
 4 3 2
 1 3 4 2

Sample Output-1:
 ----------------
 [-1, 4, -1]


 Sample Input-2:
 ---------------
5 6 3 4
1 5 3 7 8 6 4 2

 Sample Output-2:
 ----------------
[7, -1, 7, -1]
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    
    getline(cin,s1);
    getline(cin,s2);
    
    vector<int>v1, v2;
    
    int curr = 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]>='0' and s1[i]<='9')
            curr = curr*10 + (s1[i]-'0');
        else{
            v1.push_back(curr);
            curr = 0;
        }
    }
    v1.push_back(curr);
    curr = 0;
    for(int i=0;i<s2.length();i++){
        if(s2[i]>='0' and s2[i]<='9')
            curr = curr*10 + (s2[i]-'0');
        else{
            v2.push_back(curr);
            curr = 0;
        }
    }
    v2.push_back(curr);
    
    int n2 = v2.size();
    vector<int>res(n2,0);
    
    stack<int>s;
    map<int,int>mp;
    
    for(int i=n2-1;i>=0;i--){
        
        while(!s.empty() and s.top()<=v2[i])
            s.pop();
        
        mp[v2[i]] = s.empty()?-1:s.top();
        s.push(v2[i]);
    }
    
    for(int it:v1)
        cout<<mp[it]<<" ";
    
    
    
    
    return 0;
}