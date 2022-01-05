/*
Vicky, an expert in gaming software, lives in Australia and never compromises
in his life, a principle that he adheres to since his childhood. After 
long time he returns to India to establish a start-up gaming company. 

He meets his uncle Jalsa Kishore and Vicky tells about his plan. 
Jalsa Kishore came up with an idea for Vicky with a new game. 
He draws a grid with combination of 0’s and 1’s of size P X Q, where
we can reorganize the columns of the grid in any order. 

Jalsa Kishore says that build a grid such that we get the area of 
the greatest subunits within the grid where every unit of the sub grid is 1
after reorganizing the columns.

Now it’s your aim to write a method which prints the area of 
the greatest subunits within the grid according to idea of Jalsa Kishore.


Input Format:
-------------
Line-1: Two integers P and Q, size of the grid.
Next P lines: Q separated integers, either 0 or 1.

Output Format:
--------------
Print an integer, area of the greatest subunits.


Sample Input-1:
---------------
3 4
1 0 1 0
0 1 1 1
0 1 0 1

Sample Output-1:
----------------
4

Explanation:
----------
After Reorganizing the columns, the grid looks like as follows:
1 0 0 1
0 1 1 1
0 1 1 0


Sample Input-2:
---------------
1 5
1 0 1 0 1

Sample Output-2:
----------------
3
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> mat(n,vector<int>(m));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
        
    vector<vector<int>> v(n+1,vector<int>(m+1));
    
    for(int i=0;i<m;i++){
        v[0][i] = mat[0][i];
        for(int j=1;j<n;j++)
            v[j][i] = (mat[j][i] == 0) ? 0 : v[j - 1][i] + 1;
    }
    for (int i=0;i<n;i++) {
        int count[n+1];
        for(int i=0;i<n+1;i++)
            count[i] = 0;
            
        for (int j=0;j<m;j++)
            count[v[i][j]]++;
            
        int col_no = 0;
        for (int j=n;j>=0;j--) {
            if (count[j] > 0) {
                for (int k=0;k<count[j];k++){
                    v[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
    
    int curr_area, max_area = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            curr_area = (j+1)*v[i][j];
            if (curr_area>max_area)
                max_area = curr_area;
        }
    }
    cout<<max_area<<endl;
    return 0;
}