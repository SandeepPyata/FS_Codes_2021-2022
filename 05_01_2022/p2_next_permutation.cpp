/*
Crazy Mohan is interested to disturb the order of the items.
There is a number N, each digit of the number is printed on a cube
and arranged accordingly in a row. Now, Crazy Mohan is allowed to swap 
the positions of the cubes, It is not allowed to add or remove the cubes.

You have to stop Crazy Mohan, when you find the new sequence of the cubes 
forms a new number W, such that W>N and W should be minimum.

If it is possible to form W from N, print the value of W, otherwise print '-1'

Input Format:
-------------
An integer N, given number.

Output Format:
--------------
Print an integer, the next nearest higher number.


Sample Input-1:
---------------
121

Sample Output-1:
----------------
211

132453

Sample Input-2:
---------------
321

Sample Output-2:
----------------
-1
*/
#include<bits/stdc++.h>
using namespace std;

void checkPerm(string s1){
    string s = s1;
    int n = s.size();
    int i;
    for(i=n-2;i>=0;i--){
        if(s[i]<s[i+1])
            break;
    }
    if(i>=0){
        int j = s.length() - 1;
        while(s[j]<=s[i]){
            j--;
        }
        swap(s[i],s[j]);
    }
    else{
        cout<<-1;
        return;
    }
    reverse(s.begin()+i+1,s.end());
    if(s==s1)
        cout<<"-1"<<endl;
    else
        cout<<s<<endl;
}

int main()
{
    string s;
    cin>>s;
    checkPerm(s);
    
    return 0;
}