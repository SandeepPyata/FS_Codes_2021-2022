/*

Leetcode : Brace Expansion

 Naresh is working on expression of words.
If you give him an expression like, [p,q,r]s[t,u],
Naresh will form the words like as follows : [pst, psu, qst,qsu, rst, rsu]
Another example, [a,b]c[d,e] will be converted as: [acd, ace, bcd, bce].

Naresh will be given an expression as a string EXP, like the above format.
He needs to return all words that can be formed in like mentioned above, 
Can you help Naresh to convert iven expression into a list of words, 
in lexicographical order.

NOTE: 
Expression consist of lowercase alphabets, comma, and square brackets only.

Input Format:
-------------
A string EXP, expression.

Output Format:
--------------
Print list of words, formed from the expression.


Sample Input-1:
---------------
[b]c[e,g]k

Sample Output-1:
----------------
[bcek, bcgk]


Sample Input-2:
---------------
[a,b][c,d]

Sample Output-2:
----------------
[ac, ad, bc, bd]


Sample Input-3:
---------------
[xyz]a[b,c]

Sample Output-3:
----------------
[xyzab, xyzac] 
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> expand(string S) {
    vector<string> result;
    int sz = S.size(), i = 0;
    while (i < sz){
        char ch = S[i];
        vector<string> A;
        if (ch == '['){
            ++i;
            while (i < sz and S[i] != ']'){
                string t;
                while (i < sz and S[i] != ',' and S[i] != ']'){
                    t.push_back(S[i]);
                    ++i;
                }
                if (i < sz and S[i] == ',')
                    ++i;
                A.push_back(t);
            }
            ++i;
        }
        else{
            string t;
            while (i < sz and S[i] != ',' and S[i] != '[' and S[i] != ']'){
                t.push_back(S[i]);
                ++i;
            }
            A.push_back(t);
        }
        if (result.empty())
            swap(A, result);
        else{
            vector<string> B;
            for (auto & i : result)
                for (auto & j : A)
                    B.push_back(i + j);
            swap(B, result);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    string s;
    cin>>s;
    vector<string> v = expand(s);
    for(auto it:v)
        cout<<it<<endl;
    return 0;
}