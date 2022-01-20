/* 

Leetcode 306 : https://leetcode.com/problems/additive-number/

Pramod is working on Strings consist of digits only. He wants to findout, 
whether the given string can form Fibonacci sequence or not.

A String can form a Fibonacci Sequence, if it contains at least 
three numbers, and numbers are in the following order:
first, second, third  = first + second, fourth = third + second, .. so on.

Return true, if the given string can form fibonacci sequence,
otherwise, return false.

Note: Numbers in the fibonacci sequence contains no leading 0's.
for example, 2, 03,5 or 2,3,05 or 02,3,5 are not valid.

Input Format:
-------------
A String consist of digits only

Output Format:
--------------
Print a boolean value as result.


Sample Input-1:
---------------
23581321

Sample Output-1:
----------------
true

Explanation: 
------------
Fibonacci Sequence is : 2, 3, 5, 8, 13, 21
2, 3, 2+3=5, 3+5=8, 5+8=13, 8+13=21.

Sample Input-2:
---------------
199100199

Sample Output-2:
----------------
true

Explanation: 
------------
Fibonacci Sequence is : 1 99 100 199
1, 99, 1+99=100, 99+100=199.

 */

#include<bits/stdc++.h>
using namespace std;

bool backtrack(string s, int ind, vector<int> &vec){
    
    // end of string
    if(ind==s.length()){
        
        // checking if series contains more than 2 elements{a,b,c} so that a+b=c
        return vec.size()>2;
    }
    
    int curr = 0;   // curret number
    for(int i=ind;i<s.length();i++){
        curr = curr*10 + s[i]-'0';
        
        // if current digit is zero in string
        if(curr==0)
            return false;
            
        // if vec size<2 => insert elements to make {a,b}
        // or
        // if more than 2 elements => last 2 elements must be equal to current
        // else loop through further digits
        
        if(vec.size()<2 || vec[vec.size()-1]+vec[vec.size()-2]==curr){
            vec.push_back(curr);
            if(backtrack(s,i+1,vec))
                return true;
            vec.pop_back();
        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;
    
    vector<int> vec;
    if(backtrack(s,0,vec))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
        
    return 0;
}