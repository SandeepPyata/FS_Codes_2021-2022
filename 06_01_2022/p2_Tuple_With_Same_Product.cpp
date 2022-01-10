// Question Link : https://leetcode.com/problems/tuple-with-same-product/


#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>m;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    map<int,int>m1;
    map<int,set<int> >m2;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]!=arr[j]){
                set<int>s = m2[arr[i]*arr[j]];
                if(s.find(arr[i])!=s.end() || s.find(arr[j])!=s.end()){
                    continue;
                }
                m2[arr[i]*arr[j]].insert(arr[i]);
                m2[arr[i]*arr[j]].insert(arr[j]);
                m1[arr[i]*arr[j]]++;
            }
        }
    }
    map<int,int>::iterator it=m1.begin();
    int ans=0;
    for(;it!=m1.end();it++){
        ans+=(it->second)*(it->second-1)/2;
    }
    cout<<ans*8;
}


/*

Java Code

import java.util.*;

class TupleSameProduct {
    public int tupleSameProduct(int[] nums) {
        int cnt = 0;
        Map<Integer, Integer> products = new HashMap<>();
        for (int i = 0, n = nums.length; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int prod = nums[i] * nums[j];
                int numOfProducts = products.getOrDefault(prod, 0);
                cnt += 8 * numOfProducts;
                products.put(prod, 1 + numOfProducts);
            }
        }
        return cnt;
    }
	
	public static void main(String[] args) { 
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=sc.nextInt();
		System.out.println(new TupleSameProduct().tupleSameProduct(arr) ); 
	}
}
*/