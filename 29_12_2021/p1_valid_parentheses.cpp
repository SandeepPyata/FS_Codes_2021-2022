/*
Clavius, the person who suggested grouping of data using brackets.
He has suggested that the grouping should be well formed.
Well formed groupings are as follows, (), [], {}, {()}, {[]()}, {[]}(), etc.

You will be given a string S, return true if the string S is a well formed 
grouping, otherwise false.

Note: S contains only characters ( ) [ ] { }

Input Format:
-------------
A string S, contains only characters (){}[]

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
{[([])[]]}

Sample Output-1:
----------------
true

Sample Input-2:
---------------
{[([])[]}]

Sample Output-2:
----------------
false
*/
#include<bits/stdc++.h>
using namespace std;

bool match(char a, char b){
    return ((a=='{' && b=='}')||(a=='[' && b==']')||(a=='(' && b==')'));
}
string isValid(string st) {
    if(st.size()<2) return "false";
    stack<char>s;
    for(auto it:st){
        if(it=='(' || it=='{' || it=='[')   s.push(it);
        else{
            if(s.empty())   return "false";
            if(match(s.top(),it))   s.pop();
            else    return "false";
        }
    }
    return (s.size()==0)?"true":"false";
}

int main()
{
    string s;
    cin>>s;
    
    cout<<isValid(s);
    
    return 0;
}