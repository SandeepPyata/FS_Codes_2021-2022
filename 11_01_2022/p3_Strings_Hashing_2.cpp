/*
Gnanesh is working on Machine Learning domain. He wants train the machine 
in such a way that, if he provided an image printed with a string on it,
the machine has to extract the text as a string and verify that, 
after shuffling  the letters in the string, 'the shuffled string should be 
like no two adjacent letters should be same' 

You will be given extracted string, and
Can you help Gnanesh to train the machine with the given constraint 
The machine has to print "true", if the constarint is met, 
Otherwise, print "false".

Input Format:
-------------
A String S

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
aaabd

Sample Output-1:
----------------
true

Sample Input-2:
---------------
aaab

Sample Output-2:
----------------
false
*/
#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int mp[26] = {0};
    
    int maxfreq = 0;
    for(char c:s){
        mp[c-'a']++;
        maxfreq = max(maxfreq,mp[c-'a']);
    }
    
    int minimum = (s.length()%2)?(s.length()/2+1):(s.length()/2);
    
    if(minimum>=maxfreq)    cout<<"true"<<endl;
    else    cout<<"false"<<endl;
    
    return 0;
}