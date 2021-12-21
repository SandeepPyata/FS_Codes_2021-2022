/*
There is a board with M*N size. 
The board contains M*N blocks of 1*1 size.
Each block is printed a number on it.

You will be given a number, your task is to find whether the number is printed on 
any of the blocks or not. If found print true, otherwise print false.

NOTE: 
- The numbers printed on the board in each row and each column are
  in increasing order. And all the numbers are unique.

Input Format:
-------------
Line-1 -> Two integers M and N, board size.
Next M lines -> N space separated integers.
Last Line -> An integer T, number to search.

Output Format:
--------------
Print a boolean value, 'true' if number found.
otherwise, 'false'.


Sample Input-1:
---------------
4 4
1 3 6 10
2 5 9 13
4 8 12 16
7 11 14 17
5

Sample Output-1:
----------------
true


Sample Input-2:
---------------
4 4
1 3 6 10
2 5 9 13
4 8 12 16
7 11 14 17
15

Sample Output-2:
----------------
false
*/
#include<bits/stdc++.h>
using namespace std;

string findele(vector<vector<int>> matrix, int target, int m, int n){
    int l = 0, r = n-1;
    while(l<m and r>=0){
        if(matrix[l][r]==target)
            return "true";
        if(matrix[l][r]>target)
            r--;
        else if(matrix[l][r]<target)
            l++;
    }
    return "false";
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        cin>>matrix[i][j];
    
    int target;
    cin>>target;
    
    cout<<findele(matrix,target,m,n);
    return 0;
}
  