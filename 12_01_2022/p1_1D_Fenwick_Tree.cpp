// Reference Link : https://medium.com/carpanese/a-visual-introduction-to-fenwick-tree-89b82cac5b3c


/*
Mallika taught a new fun time program practice for Engineering Students.
As a part of this she has given set of numbers, and asked the students 
to find the sum of numbers between indices S1 and S2 (S1<=S2),
both S1 and S2 inclusive.

There are P Students in the class, numbered from 1 to P. Each student is
given set of indices and that student has to find the sum of the numbers 
between the indices and print the result.

And return the answer in the same order of

Input Format:
-------------
Line-1: Two integers N and P, N is length of set of numbers.
		where 1<= N <= 1000
Line-2: N space separated integers, array set[]
Next P lines: Two integers S1 and S2, index positions 
		where 0 <= S1 <= S2 < N
		and 1<= set[i] <= 100000

Output Format:
--------------
Print the sum of numbers between indices(s1, s2) given to each student.


Sample Input-1:
---------------
8 2
115053 59099 681359 526248 123844 612168 920784 591204
2 6
1 5

Sample Output-1:
----------------
2864403
2002718
*/
#include<bits/stdc++.h>
using namespace std;

int query(int i,vector<int>& fenwick){
    int ans=0;
    while(i){
        ans+=fenwick[i];
        i=i-(i&(-i));
    }
    return ans;
}

int sum(int l,int r,vector<int>& fenwick){
    return (query(r,fenwick)-query(l-1,fenwick));
}

void update(int i,vector<int>& fenwick,int n,int x){
    while(i<=n){
        fenwick[i]+=x;
        i=(i+(i&(-i)));
    }
    
}

int main(){
    int n,queries;
    cin>>n>>queries;
    
    vector<int> vec(n+1,0), fenwick(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>vec[i];
    
    for(int i=1;i<=n;i++)
        update(i,fenwick,n,vec[i]);
    
    for(int i=0;i<queries;i++){
        int l,r;
        cin>>l>>r;
        cout<<sum(++l,++r,fenwick)<<endl;
    }
    return 0;
}