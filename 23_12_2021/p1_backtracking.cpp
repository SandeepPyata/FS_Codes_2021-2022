/*
Mr Shravan Kumar is given a word W and a list of words[]. He wants to check 
whether is it possible to create the word W from the given list of words 
by appending them or not. It is not necessary to use all the words from the list.
It is allowed to use the words in the list repeatedly if required to form the 
original W. 
Your task if to help Mr Nagireddy to find it is possibe to create the oridinal
word W or not. If possible print true. Otherwise flase.


Input Format:
-------------
Line-1: A single line word W, Original word.
Line-2: A single line space space-separated words, list[].

Output Format:
--------------
Print a boolean value.

Sample Input-1:
---------------
capable
cap cable ap able 

Sample Output-1:
----------------
true


Sample Input-2:
---------------
capable
cable ap able

Sample Output-2:
----------------
false
*/
#include<bits/stdc++.h>
using namespace std;

string backtrack(string s, vector<string>&v, string curr){
    if(curr==s)
        return "true";
    if(curr.length()>=s.length())
        return "false";
    
    for(int i=0;i<v.size();i++){
        string temp = curr;
        curr += v[i];
        if(backtrack(s,v,curr)=="true")
            return "true";
        curr = temp;
    }
    return "false";
}

int main()
{
    string s;
    string l;
    getline(cin,s);
    getline(cin,l);
    
    vector<string> v;
    stringstream ss(l);
    string x;
    while(ss>>x)
        v.push_back(x);
    
    cout<<backtrack(s,v,"");
    
    return 0;
}