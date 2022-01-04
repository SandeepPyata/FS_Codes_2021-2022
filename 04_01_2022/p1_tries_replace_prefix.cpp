/*
In an english training institute, the trainer Reeta given a task to the trainees.
We know that, in english we have prefixes and suffixes for the words.
You can divide a word as concatenation of prefix and suffix.
i.e., word = prefix + suffix, another = an + other

You will be given a list of prefixes and a statement consisting of words.
Now, the task given to the trainees is as follows:
	- Replace all the words in the statement with the prefix, 
	  if you found prefix of that word in the list.
	- If you found more than one prefix in the list for a word in the statement,
	  replace the word with the prefix that has the shortest length.

Your task is to help the trainees to prepare and print the final statement
after all the replacements done.

Input Format:
-------------
Line-1: Space separated strings, prefixes.
Line-2: A single line of words, statement.

Output Format:
--------------
Print the String, the final statement.


Sample Input-1:
---------------
am add mean ref 
amigos used to address or refer to a friend

Sample Output-1:
----------------
am used to add or ref to a friend


Sample Input-2:
---------------
th the pa tho
thomas the trainer teaches theroy part of thermodynamics

Sample Output-2:
----------------
th th trainer teaches th pa of th
*/

/*******************  TRIES TEMPLATE ********************/
/*
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char c;
    bool end;
    node* arr[26];
    node(char c){
        this->c=c;
        this->end=0;
    }
};
node* create(string d,int i){
    node* root=new node(d[i]);
    if(i==d.size()-1){
        root->end=1;
        return root;
    }
    root->arr[d[i+1]-'a']=create(d,i+1);
    return root;
}
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string d;
    vector<string>list;
    while(ss>>d)list.push_back(d);
    node *root=new node('$');
    for(int i=0;i<list.size();i++){
        node* x=root;
        d=list[i];
        for(int j=0;j<d.size();j++){
            if(x->arr[d[j]-'a']!=0){
                x=x->arr[d[j]-'a'];
                if(j==d.size()-1){
                    x->end=1;
                }
            }
            else{
                string q=d.substr(j,d.size()-j+1);
                x->arr[d[j]-'a']=create(q,0);
                break;
            }
        }
    }
    vector<string>ans;
    vector<string>ques;
    getline(cin,s);
    stringstream ss1(s);
    while(ss1>>d)ques.push_back(d);
    for(int i=0;i<ques.size();i++){
        string word=ques[i];
        string curr;
        node* x=root->arr[word[0]-'a'];
        int j=0;
        while(x!=0&&x->end==0){
            curr+=word[j];
            j++;
            x=x->arr[word[j]-'a'];
        }
        if(x!=0&&x->end==1){
            curr=curr+(x->c);
            ans.push_back(curr);
        }
        else ans.push_back(word);
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}
*/



#include<bits/stdc++.h>
using namespace std;

class Trie
{
    public:
    bool isLeaf;                        // indicating if this node is last or not
    Trie *arr[26];                      // each node might have 26 children [a-z] 
    Trie(){
        this->isLeaf = false;           // treating every node not as leaf 
        for(int i=0;i<26;i++)
            this->arr[i] = nullptr;     // initialising every child as false
    }
};

int main()
{
    string s1, s2, a, b;
    getline(cin,s1);
    getline(cin,s2);
    
    vector<string> pref, words;
    
    stringstream ss1(s1);
    while(ss1>>a)
        pref.push_back(a);

    stringstream ss2(s2);
    while(ss2>>a)
        words.push_back(a);
    
    // sort prefix vector according to length
    sort(begin(pref),end(pref),[]
        (const std::string &s1,const std::string &s2){
            return s1.size()<s2.size();
        }
    );
    
    Trie *head = new Trie();
    
    // Creation of Trie : prefix vector strings
    for(string s:pref){
        Trie *curr = head;
        for(int i=0;i<s.length();i++){
            if(curr->isLeaf==true)
                break;
                
            if(curr->arr[s[i]-'a']==nullptr)
                curr->arr[s[i]-'a'] = new Trie();
            curr = curr->arr[s[i]-'a'];
        }
        curr->isLeaf = true;
    }
    
    // iterate words vector and check for Trie branch
    vector<string> res;
    
    for(string curr:words){
        Trie *x = head;
        string resWord;
        int i;
        for(i=0;i<curr.size();i++){
            if(x->arr[curr[i]-'a']!=nullptr){
                resWord += curr[i];
                x = x->arr[curr[i]-'a'];
            }
            else{
                if(resWord.size()==0)
                    resWord = curr;
                break;
            }
        }
        if(x->isLeaf==false){
            res.push_back(curr);
        }
        else{
            res.push_back(resWord);
        }
    }
    
    for(string s:res)
        cout<<s<<" ";
    cout<<endl;

    return 0;
}

