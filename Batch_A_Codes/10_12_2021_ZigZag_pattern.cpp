/*
Mr. Bob is a Military Encoders. 
Mr. Bob writes a word as shown below and then merges them. 
Help Bob to write the code. 

Mr. Bob will be given a word 'w' and a number 'n' 

Sample Test Case - 1
input = 
ABCDE
2
output = ACEBD


This is How Bob writes the letters of the word 
A    C    E
   B    D

Now concatenate the two rows and ignore spaces in every row. We get ACEBD


Sample Test Case - 2
input = system
3
output = seytms


s         e
  y    t    m
     s

Now concatenate the 3 rows we get seytms
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int k;
    cin>>k;

    vector<string> v(k);
    int l = s.length();

    int index = -1, dir = 1;

    for(int i=0;i<l;i++){
        if(dir==-1 and index-1==-1)
            dir *= -1;
        else if(dir==1 and index+1==k)
            dir *= -1;
        cout<<"index : "<<index<<" , index+dir : "<<index+dir<<endl;
        v[index+dir] += s[i];
        index+=dir;
    }

    for(auto it:v)
        cout<<it;

    return 0;
}
