/*
Alice wants send a mail to his clients,
He has saved the clients Mail IDs in a list.
There exists an email parser, which perform the following checks 
and send the mail to the distinct clients, the checks are as follows:
- Each mail id has two parts, one is username one is domain name.
- The part before the @ symbol is username, and other is domain name.
- In username, if there exists a '.' symbol, remove it.
- In username, if there exists a '+' symbol, ignore the 
  suffix of the username from that symbol (including '+') 
- In domain name, the '.' symbol will be stays as it is.
- There will be no '+' symbol in domain name.

After performing above checks, your task is to find the count
of distinct client mail ids, who recieves the mail sent by Alice.

Input Format:
-------------
Space separated strings, emails list[].

Output Format:
--------------
Print an integer result.


Sample Input-1:
---------------
a.v.nagireddy@kmit.in av.nagireddy@gmail.com avnagireddy@kmit.in a.v.nagireddy+org@kmit.in

Sample Output-1:
----------------
2

Explanation:
------------
These 3 mail id's: a.v.nagireddy@kmit.in, avnagireddy@kmit.in, a.v.nagireddy+org@kmit.in
are belons to same client with mail ID: avnagireddy@kmit.in
and another client with mail ID-av.nagireddy@gmail.com
So, there are 2 distinct clients.


Sample Input-2:
---------------
avnreddy@gmail.com avnreddy@yahoo.co.in nsudha@outlook.com

Sample Output-2:
----------------
3

Explanation:
------------
All 3 mail IDs belons to different clients.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s);
    
    string x;
    vector<string> v;
    while(ss>>x)
        v.push_back(x);
    
    set<string>s1;
    for(string a:v){
        string temp;
        int i = 0;
        for(i=0;i<a.length() and a[i]!='@';i++){
            if(a[i]=='+'){
                while(a[++i]!='@');
                break;
            }
            if(a[i]!='.')
                temp+=a[i];
        }
        
        for(int k=i;k<a.length();k++)
            temp += a[k];
        s1.insert(temp);
    }
    
    cout<<s1.size()<<endl;
    
    return 0;
}