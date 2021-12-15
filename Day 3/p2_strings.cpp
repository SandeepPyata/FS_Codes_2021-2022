/*
The Valid shortcuts of a string "abcd", are as follows:
abcd, 1bcd, a1cd, ab1d, abc1, 2cd, a2d, ab2, 1b1d, 1bc1,a1c1, 1b2, 2c1, 3d,a3,4

You are given a string S and shortcut string  SC, 
Your task is to find out whether the string matches with the given shortcut or not.
if matched print true, else false.

Note:
String S contains only lowercase letters and String SC contains only lowercase
letters and digits.

Input Format:
-------------
Two space separated Strings S and SC

Output Format:
--------------
Print a boolean value


Sample Input-1:
---------------
internationalization i12iz4n

Sample Output-1:
----------------
true

Sample Input-2:
---------------
apple a2e

Sample Output-2:
----------------
false
*/
#include<bits/stdc++.h>
using namespace std;

string func(string s1, string s2){
    int l1 = s1.length(), l2 = s2.length();
    int i=0, j=0;
    int num = 0;
    while(j<l2 and i<l1){
        if(s2[j]>='0' and s2[j]<='9'){
            num = num*10 + (s2[j]-'0');
            j++;
        }
        else{
            i+=num;
            if(s2[j]!=s1[i])
                return "false";
            num = 0;
            i++;
            j++;
        }
    }
    return (j==l2 and i==l1)?"true":"false";
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    
    cout<<func(s1,s2)<<endl;
        
    return 0;
}
