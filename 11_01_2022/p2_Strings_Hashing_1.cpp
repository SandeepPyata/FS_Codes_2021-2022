/*
"Emphatic Pronunciation" of a given word is where we take the word and
replicate some of the letter to emphasize their impact.

Instead of saying 'oh my god', someone may say "ohhh myyy goddd", 
We define emphatic pronunciation of a word, which is derived by replicating 
a group (or single) of letters in the original word. 

So that the replicated group is atleast 3 characters or more and 
greater than or equal to size of original group. 
For example Good -> Goood is an emphatic pronunciation,
but Goodd is not because in Goodd the 'd' are only occuring twice consecutively.
 
In the question you are given the "Emphatic pronunciation" word, 
you have to findout how many words can legal result in the 
"emphatic pronunciation" word.

Input Format:
-------------
Line-1 -> A String contains a single word, Emphatic Pronunciation word
Line-2 -> Space seperated word/s

Output Format:
--------------
Print an integer as your result


Sample Input-1:
---------------
Goood
Good

Sample Output-1:
----------------
1


Sample Input-2:
---------------
heeelllooo
hello hi helo

Sample Output-2:
----------------
2
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<char,int>> countFreq(string word){
    vector<pair<char,int>> v;    
    int count = 1;
    for(int i=1;i<word.length();i++){
        if(word[i-1]==word[i]){
            count++;
        }else{
            v.push_back({word[i-1],count});
            count = 1;
        }
    }
    v.push_back({word[word.length()-1],count});
    return v;
}

int check(vector<pair<char,int>> &w1, vector<pair<char,int>> &w2){
    if(w2.size()!=w1.size())   return 0;
    for(int i=0;i<w2.size();i++){
        pair<char,int> word = w1[i];
        pair<char,int> curr = w2[i];
        
        if(word.first!=curr.first)
            return 0;
        if(word.second<curr.second)
            return 0;
        if(curr.second!=word.second && word.second<3)
            return 0;
    }
    return 1;
}

int main()
{
    string word;
    getline(cin,word);
    
    // words
    string s;
    getline(cin,s);
    stringstream ss(s);
    string t;
    vector<string> words;
    while(ss>>t)
        words.push_back(t);
    
    vector<pair<char,int>> mainWord = countFreq(word);
    
    int count = 0;
    for(string s:words){
        vector<pair<char,int>> curr = countFreq(s);
        count += check(mainWord,curr);
    }
    
    cout<<count<<endl;
    return 0;
}