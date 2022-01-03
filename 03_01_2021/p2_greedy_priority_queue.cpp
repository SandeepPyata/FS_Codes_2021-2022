/*
M.P.Ahammed the founder of Malbar Gold and Diamonds merchant, announced an offer
that they will charge the minimum amount to make all the gold-biscuits into one.

Mr. Praveen, a gold supplier has different weighed gold-biscuits with him.
He wants to utilize the offer.

The processing charge to make two biscuits into one is calculated as follows:
	- To make two biscuits of weights A and B into one biscuit, 
	you have to pay the amount 'A + B'. 

Your task is to help M.P.Ahammed to keep his promise and 
to charge the minimum amount to make Mr. Praveen's gold-biscuits 
into one gold-biscuit.

Input Format:
-------------
Single line of space separated integers, number on the boxes.

Output Format:
--------------
Print an integer, minimum amount to be paid by Mr Shravan.


Sample Input-1:
---------------
4 3 6

Sample Output-1:
----------------
20

Sample Input-2:
---------------
5 2 4 3 6

Sample Output-2:
----------------
45
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    int x;
    while(ss>>x)
        pq.push(x);
    
    int sum = 0;
    
    while(pq.empty()==false) {
        int a = pq.top();pq.pop();
        if(pq.empty())
            break;
        int b = pq.top();pq.pop();
        sum += (a+b);
        pq.push(a+b);
    }
    cout<<sum<<endl;
    return 0;
}