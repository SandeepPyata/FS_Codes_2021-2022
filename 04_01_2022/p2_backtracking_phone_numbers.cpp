/*
Given a classic mobile phone, and the key pad of the phone looks like below.
	1		2		3
		   abc	   def
		 
	4		5		6
   ghi     jkl     mno
  
	7		8		9
  pqrs     tuv    wxyz
	
	*		0		#


You are given a string S contains digits between [2-9] only, 
For example: S = "2", then the possible words are "a", "b", "c".

Now your task is to find all possible words that the string S could represent.
and print them in a lexicographical order. 

Input Format:
-------------
A string S, consist of digits [2-9]

Output Format:
--------------
Print the list of words in lexicographical order.


Sample Input-1:
---------------
2

Sample Output-1:
----------------
[a, b, c]


Sample Input-2:
---------------
24

Sample Output-2:
----------------
[ag, ah, ai, bg, bh, bi, cg, ch, ci]
*/
#include<bits/stdc++.h>
using namespace std;

void func(map<int,string> &mp, string &s,string &curr,int index,vector<string> &vec){
    
    if(index>=s.size()){
        vec.push_back(curr);
        return;
    }

    char digit = s[index]-'0';
    string letters = mp[digit];
    
    for(int j=0;j<letters.size();j++){
        curr+=letters[j];
        func(mp,s,curr,index+1,vec);
        curr.pop_back();
    }
}

int main()
{
    map<int,string> mp;
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";
    
    string s;
    cin>>s;
    string curr;
    vector<string> vec;
    func(mp,s,curr,0,vec);

    for(string x:vec)
        cout<<x<<" ";
    
}