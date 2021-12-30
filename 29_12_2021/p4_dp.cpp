/*
In the present situation, most of the movies releasing in OTTs.
The Showtime OTT in US, introduced a new offer for the customers, 
they can purchase either 1-day, 7-day, or 30-day subscription,
and the cost is as follows price[0], price[1], price[2].

The Subscription allows you to watch as many movies as you want with in subscribed days. 
For example:
If you purchased, a 7-day subscription on day 5, then you can watch
the movies for 7 days: day 5, 6, 7, 8, 9, 10 and 11.

Your task is to find out the minimum cost, you spend to watch the movies
in the given list of days .

NOTE: Days are numbered from 1, 2, 3, ...365, in sorted order.

Input Format:
-------------
Line 1: Space separated integer days[], list of days.
Line 2: 3 space separated integer price[], cost of subscription.

Output Format:
--------------
Print an integer, minimum cost. 


Sample Input-1:
---------------
1 4 6 7 8 20
2 7 15

Sample Output-1:
----------------
11

Explanation:
------------
For example, here is a way to buy subscription, to watch the movies in given days:
On day 1, buy a 1-day subscription for price[0] = $2, which cover day 1.
On day 4, buy a 7-day subscription for price[1] = $7, which cover days 4, 5, ..., 10.
On day 20, buy a 1-day subscription for price[0] = $2, which cover day 20.
In total you spent $11.


Sample Input-2:
---------------
1 2 3 4 5 6 7 8 9 10 30 31
2 7 15

Sample Output-2:
----------------
17

Explanation:
------------
For example, here is a way to buy subscription, to watch the movies in given days:
On day 1, buy a 30-day subscription for price[2] = $15, which cover days 1, 2, 3,....,30.
On day 31, buy a 1-day subscription for price[0] = $2, which cover day 31.
In total you spent $17.
*/
#include<bits/stdc++.h>
using namespace std;
int dpProb(vector<int>&days,int i,int cover,vector<int>&price,vector<int>&dp){
    if(i==days.size())return 0;
    if(cover<days[i]){
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=price[0]+dpProb(days,i+1,dp[i],price,dp);
        int b=price[1]+dpProb(days,i+1,days[i]+6,price,dp);
        int c=price[2]+dpProb(days,i+1,days[i]+29,price,dp);
        dp[i]=min(a,min(b,c));
        return dp[i];
    }
    else return dpProb(days,i+1,cover,price,dp);
}
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int>days;
    while(ss>>x)days.push_back(x);
    vector<int>price(3);
    for(int i=0;i<3;i++){
        cin>>price[i];
    }
    vector<int>dp(days.size(),-1);
    cout<<dpProb(days,0,days[0]-1,price,dp);
}