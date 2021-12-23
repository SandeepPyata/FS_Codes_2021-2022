/*
aYou are given an alphanumeric word W.
You need find the number of words that can be formed from W.

The words have the following properties:
    - It should be a substring of W of any length, minimum 1.
    - All the letters in the word should be same.


Input Format:
-------------
Single String W.

Output Format:
--------------
Print an integer, the number of words can be formed


Sample Input-1:
---------------
daddy
 
Sample Output-1:
----------------
6

Explanation:
------------
The words are : d, a, d, d, dd, y


Sample Input-2:
---------------
binary11100

Sample Output-2:
----------------
15

Explanation:
------------
The words are : b, i, n, a, r, y, 1, 1, 1, 11, 11, 111, 0, 0, 00 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int l = s.length();
    string same;
    int count = 1, res = l;
    for(int i=0;i<l;i++){
        while(i<l-1 and s[i]==s[i+1]){
            count++;
            i++;
        }
        res += ((count)*(count-1)/2);
        count = 1;
    }

    cout<<res<<endl;
    return 0;
}