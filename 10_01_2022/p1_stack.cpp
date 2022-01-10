// Leetcode : https://leetcode.com/problems/asteroid-collision/



/*
Due to side effects of vaccination in Europe, Few people turned as zombies.
And other people fight againest zombies called as warriors to save their lives.

You are given a list of integers strength[], represent the strength of the people.
all the people running in same line with same speed.
If the strength value is negative the person is a zombie running towards left,
If the strength value is positive the person is a warrior running towards right.
and the absolute value represents their strength.

If a zombie and a warrior meet, the person with smallest strength will die. 
If both have the same strength, both will die. 
Two persons moving in the same direction will never meet.

Your task is to find out the list of strengths of people who will be alive. 

Input Format:
-------------
space separated integers, list of strength[].

Output Format:
--------------
Print the list of strengths people who will be alive.


Sample Input-1:
---------------
4 9 -5

Sample Output-1:
----------------
4 9

Explanation:
------------
The 9 and -5 meet resulting in 9. The 4 and 9 never meet.


Sample Input-2:
---------------
-3 -2 2 3

Sample Output-2:
----------------
-3 -2 2 3

Explanation:
------------
The people with the strengths,
-3 and -2 moving left, 3 and 2 moving right. No one will die.


Sample Input-3:
---------------
8 3 -6

Sample Output-3:
----------------
8

Explanation:
------------
The people with the strengths,
3 and -6 meet, 3 will die, -6 is alive.
And 8 and -6 meet, -6 will die, 8 is alive.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    getline(cin,st);
    
    stringstream ss(st);
    int x;
    
    vector<int> vec;
    
    while(ss>>x)
        vec.push_back(x);
        
    int n = vec.size();
    
    stack<int> s;
    
    for(int i=0;i<n;i++){
        if(vec[i]<0){
            int f = 1;
            while(!s.empty() and s.top()<=-vec[i]){
                if(-vec[i]>s.top()){
                    s.pop();
                }
                else{
                    f = 0;
                    s.pop();
                    break;
                }
            }
            if(s.empty() and f)
                cout<<vec[i]<<" ";
        }
        else if(vec[i]>=0){
            s.push(vec[i]);
        }
    }
    
    stack<int> res;
    while(!s.empty()){
        res.push(s.top());
        s.pop();
    }
    
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    return 0;
}