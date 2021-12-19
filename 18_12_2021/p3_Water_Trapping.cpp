/*
A Kid is arranging a structure using building blocks, 
by placing individual building-block adjacent to each other.

A building-block is a vertical alignment of blocks.
	                                ___
here one block each represents  as |___|.

The following structure made up of using building blocks

                          ___
                      ___|___|    ___
                     |___|___|_w_|___|___              ___
                  ___|___|___|___|___|___| w   _w_  w |___| 
              ___|___|___|___|___|___|___|_w__|___|_w_|___|____________
    
               0  1   3   4   2   3    2   0   1   0   2

Once the structure is completed, kid pour water(w) on it.

You are given a list of integers, heights of each building-block in a row.
 Now your task How much amount of water can be stored by the structure.

 Input Format:
 -------------
 Space separated integers, heights of the blocks in the structure. 

Output Format:
 --------------
 Print an integer, 
  
Sample Input:
-------------
 0 1 3 4 2 3 2 0 1 0 2
    
Sample Output:
--------------
6
    
Explanation:
 -----------
In the above structure,  6 units of water (w represents the water in the structure)
can be stored.
*/
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> h)
{
    if(h.empty())
        return 0;
    int ans = 0;
    int size = h.size();
    
    vector<int> lmax(size), rmax(size);
    lmax[0] = h[0];
    
    for (int i = 1; i < size; i++) 
        lmax[i] = max(h[i], lmax[i - 1]);
    
    rmax[size - 1] = h[size - 1];
    for (int i = size - 2; i >= 0; i--) 
        rmax[i] = max(h[i], rmax[i + 1]);
    
    for (int i = 1; i < size - 1; i++) 
        ans += min(lmax[i], rmax[i]) - h[i];
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    
    for(int i=0;i<n;i++)
        cin>>vec[i];
    
    cout<<func(vec)<<endl;
    return 0;
}