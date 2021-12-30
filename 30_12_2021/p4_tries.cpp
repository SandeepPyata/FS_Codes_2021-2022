/* Mr Suresh is working with the plain text P, a list of words w[], 
He is converting P into C [the cipher text], C is valid cipher of P, 
if the following rules are followed:
	- The cipher-text C is a string ends with '$' character.
	- Every word, w[i] in w[], should be a substring of C, and 
	the substring should have $ at the end of it.

Your task is to help Mr Suresh to find the shortest Cipher C,  
and return its length.

Input Format:
-------------
Single line of space separated words, w[].

Output Format:
--------------
Print an integer result, the length of the shortest cipher.


Sample Input-1:
---------------
kmit it ngit

Sample Output-1:
----------------
10

Explanation:
------------
A valid cipher C is "kmit$ngit$".
w[0] = "kmit", the substring of C, and the '$' is the end character after "kmit"
w[1] = "it", the substring of C, and the '$' is the end character after "it"
w[2] = "ngit", the substring of C, and the '$' is the end character after "ngit"


Sample Input-2:
---------------
ace

Sample Output-2:
----------------
4

Explanation:
------------
A valid cipher C is "ace$".
w[0] = "ace", the substring of C, and the '$' is the end character after "ace"
 */
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char a;
    Node *arr[26];
    Node(char a){
        this->a=a;
    }
};

Node* fun(string &d,int i){
    Node *root = new Node(d[i]);
    if(i==d.size()-1){
        return root;
    }
    root->arr[d[i+1]-'a'] = fun(d,i+1);
    return root;
}
bool fun(Node* root,string s,int i){
    if(i==s.size()){
        for(int j=0;j<26;j++){
            if(root->arr[j]!=0){
                return 0;
            }
        }
        return 1;
    }
    return fun(root->arr[s[i]-'a'],s,i+1);
}

void create(vector<string> v, Node* root){
    for(int i=0;i<v.size();i++){
        string d = v[i];
        Node *x = root;
        for(int j=0;j<d.size();j++){
            if(x->arr[d[j]-'a']!=0){
                x=x->arr[d[j]-'a'];
            }
            else{
                string d1=d.substr(j,d.size()-j+1);
                x->arr[d[j]-'a']=fun(d1,0);
                break;
            } 
        }
    }
}

int countBranches(vector<string> v,Node* root){
    int ans=0;
    set<string> res;
    for(int i=0;i<v.size();i++){
        if(res.find(v[i])==res.end()){
            if(fun(root,v[i],0)){
                ans+=v[i].size()+1;
            }
            res.insert(v[i]);
        }
    }
    return ans;
}

int main()
{
    string input;
    getline(cin,input);
    
    stringstream str(input);
    
    string a;
    vector<string> v;
    while(str>>a){
        reverse(a.begin(),a.end());
        v.push_back(a);
    }

    Node *root=new Node('$');
    
    create(v,root);
    
    cout<<countBranches(v,root)<<endl;
    
    return 0;
}