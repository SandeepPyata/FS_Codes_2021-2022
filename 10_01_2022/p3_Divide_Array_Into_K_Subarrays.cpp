// Leetcode 1296 : https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/



/*
In a class of XII, computer teacher asked one of the student 
to perform a task as practical session .

There is a box contains N balls in it, each ball is printed 
with a positive integer. The teacher ask the student to split 
all the balls in the box into ball-groups,
each group should contain exatly S balls.

The student has to pick the ball-groups as follows:
	- the balls should be numbered consecutively.
	e.g., 1,2 3, 4 or 4,5,6,7 etc.

Finally, the student should say whether it is possible to 
split all the balls in the box, into ball-groups accordingly.

Now, its your task to help the student to find whether it is possible or not.
if possible, print "true".
otherwise, print "false".


Input Format:
-------------
Line-1: Two integers N and S, number of balls and size of ball-group.
Line-2: N space separated integers, integers printed on each ball.

Output Format:
--------------
Print a boolean value, whether it is possible to split all the balls into groups.


Sample Input-1:
---------------
8 4
2 6 3 4 3 5 4 5

2 - 1
3 - 2
4 - 2
5 - 2
6 - 1


Sample Output-1:
----------------
true

Explanation:
-------------
Ball-groups are [2,3,4,5] and [3,4,5,6]


Sample Input-2:
---------------
12 3
12 2 9 5 3 4 13 7 6 8 11 7

Sample Output-2:
----------------
true

Explanation:
-------------
Ball-groups are [2,3,4], [5,6,7], [7,8,9] and [11,12,13]


Sample Input-3:
---------------
6 3
2 5 7 3 4 8

Sample Output-3:
----------------
false

Explanation:
-------------
you cannot form ball groups.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,g1;
    cin>>n1>>g1;
    int a[n1];
    
    map<int,int> mp1;
    for(int i=0;i<n1;i++){
        cin>>a[i];
        mp1[a[i]]++;
    }
    
    int a1 = mp1.begin()->first, res = 0;
    map<int,int>::iterator it1 = mp1.begin();
    
    while(it1!=mp1.end()){
        int a = it1->first, target = a + g1, mini1 = it1->second;
        while(a<target){
            if(mp1.find(a)!=mp1.end() && mp1[a]!=0){
                mini1=min(mini1,mp1[a]);
                a++;
            }
            else{
                it1++;
                break;
            }
        }
        if(a==target){
            res+=mini1;
            int t1 = it1->first;
            while(t1!=a){
                mp1[t1] -= mini1;
                t1++;
            }
            it1++;
        }
    }
    if(n1/g1 == res && n1%g1 == 0)
        cout<<"true";
    else 
        cout<<"false";
        
    return 0;
}