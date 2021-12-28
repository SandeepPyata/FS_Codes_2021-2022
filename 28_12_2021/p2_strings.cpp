/*
Given a string S in encoded form, and  an integer array indices[] of string length.

You need to find the decoded form of String S, 
by moving each character at ith position in S, to indices[i] position in decoded string.
and then print the decoded string.

Input Format:
-------------
Line-1 -> A String S, enocded string of length L, 
          S conatins only lowercase alphabets [a-z]
Line-2 -> L space separated integers indices[], where 0 <=indices[i] < L 

Output Format:
--------------
Print a String, decoded string.


Sample Input-1:
---------------
aeilmmor
6 1 5 7 2 0 3 4

Sample Output-1:
----------------
memorial

Explanation:
---------------
Given String, a e i l m m o r
			  6 1 5 7 2 0 3 4
after shifting,	memorial


Sample Input-2:
---------------
aidin
4 3 2 0 1

Sample Output-2:
----------------
india

Explanation-2:
---------------
Given String, a i d i n
			  4 3 2 0 1
after shifting,	india
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int l = s.length();

    vector<int> v(l);
    for(int i=0;i<l;i++)
        cin>>v[i];
    
    vector<pair<int,char>> mp;
    
    for(int i=0;i<l;i++)
        mp.push_back({v[i],s[i]});
    
    sort(mp.begin(),mp.end());
    for(auto it:mp){
        s[it.first] = it.second;
    }
    cout<<s<<endl;
    
    return 0;
}