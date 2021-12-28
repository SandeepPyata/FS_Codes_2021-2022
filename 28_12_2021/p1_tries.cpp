/*
At university of Chicago a Computer Science programing faculty as a part of 
teaching passion, in order to make newly joined students more enthusiastic 
in learning the subject he is given a problem at the first day of semester.
The student who solved it first, will be awarded with a cash prize. In regard 
to this he asked the students to work on concept related to strings, he gave a 
task to read a word and find the count of all the turn of phrases of the word, 
and the phrases should be distinct.

Now it’s your time to create a method which satisfies the above program.
The turn of phrases of a word is obtained by deleting 
any number of characters (possibly zero) from the front of the word and
any number of characters (possibly zero) from the back of the word.

Input Format:
-------------
A single string, the word contains only lowercase alphabets [a-z].

Output Format:
--------------
Print an integer, number of distinct phrases possible.


Sample Input-1:
---------------
aabbaba

Sample Output-1:
----------------
21

Explanation:
-------------
The turn of phrases of the word, which are distinct as follows:
a, b, aa, bb, ab, ba, aab, abb, bab, bba, aba, aabb, abba, bbab, baba, 
aabba, abbab, bbaba, aabbab, abbaba, aabbaba


Sample Input-2:
---------------
kmithyd

Sample Output-2:
----------------
28
*/
#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndOfWord;
};
 
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

void insert(struct TrieNode *root, string key, int &count)
{
    struct TrieNode *pCrawl = root;
    
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
            count++;
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

int main()
{
    string s;
    cin>>s;

    struct TrieNode *root = getNode();
    int count = 1;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string sub = s.substr(i,j);
            insert(root,sub,count);
        }
    }
    cout<<count<<endl;
    
    return 0;
}