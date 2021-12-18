/*
Arjun is playing a word game in his tab. When he start the game , It displays a
word and he has to check for any two adjacent characters which are same.If found 
he has to select those two characters by tapping, so that both characters will
be deleted from the word and the word size shrinks by 2. This process to be 
repeated until the word has no two adjacent characters are same.
You task is to help Arjun to perform the above task and Return the final word
obtained.

Input Format:
-------------
Line-1: A string represents the word.

Output Format:
--------------
Return a string or empty string.

Constraints:
------------   
    1 <= word.length <= 10^5   
    word consists only lower case letters.

Sample Input-1:
---------------
pqqprs

Sample Output-1:
----------------
rs

Explanation:
-------------
Initially , Delete two 'q's then the word will be 'pprs'. Now Delete two 'p's 
then the word will be rs.

Sample Input-2:
---------------
pqqqprrs

Sample Output-2:
----------------
pqps

Explanation:
-------------
Initially , Delete two 'q's then the word will be 'pqprrs'. Now Delete two 'r's
then the word will be pqps.


*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1;
    cin>>s1;
    
    stack<char>s;
    // string res;
    int n = s1.length();
    for(int i=0;i<n;i++){
        if(!s.empty() and s.top()==s1[i])
            s.pop();
        else
            s.push(s1[i]);
    }
    
    string res;
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}

/*
Method 2: Recursion
#include<bits/stdc++.h>
using namespace std;

int recur(int arr[], int &count, int vis[], int i){
    if(vis[i])  return count;
    vis[i] = 1;
    count++;
    return recur(arr,count,vis,arr[i]);
}

int main()
{
    int n;
    cin>>n;
    int arr[n], visited[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        visited[i] = 0;
    }
    
    int maxcount = 1;
    for(int i=0;i<n;i++){
        int temp = 0;
        if(visited[i])  continue;
        temp = recur(arr,temp,visited,i);
        maxcount = max(maxcount,temp);
    }
    cout<<maxcount<<endl;
    
*/