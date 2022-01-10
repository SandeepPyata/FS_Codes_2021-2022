// Question Link : https://leetcode.com/problems/jump-game-iii/

// Cpp Code

#include<bits/stdc++.h>
using namespace std;

bool fun(int i, vector<int> &arr, vector<int> &pos){
    if(i<0 || i>=arr.size() || pos[i]==0 || pos[i]==2)
		return 0;
    if(arr[i]==0)
		return 1;
    pos[i] = 2;
    return pos[i] = fun(i-arr[i],arr,pos) || fun(i+arr[i],arr,pos);
}

int main(){
    int n,ini;
    cin>>n>>ini;
    
	vector<int>arr(n);
    for(int i=0;i<n;i++)
		cin>>arr[i];
	
    vector<int>poss(n,-1);
    if(fun(ini,arr,poss))
		cout<<"true";
    else 
		cout<<"false";
}




/*
Java Code

import java.util.*;

class CanReach {
   public boolean canReach(int[] arr, int start) {
        if(start<0 || start>=arr.length || arr[start]<0) return false;
        if(arr[start] == 0) return true;

        arr[start] = -arr[start];
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
	
	public static void main(String[] args) { 
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int start=sc.nextInt();
		int arr[]=new int[n];
		for(int j=0;j<n;j++)
			arr[j]=sc.nextInt();
		System.out.println(new CanReach().canReach(arr,start) ); 
	}
}
*/