/* Given a integer value N, indicates number of bits in a binary number.

Your task is to design a Binary Code System, where two consecutive 
values in BCS having N bits, must have one bit difference only. 
For example refer the sample testcases.

Find and print the integer values of BCS, starting from 0.


Input Format:
-------------
A integer N, number of bits in BCS

Output Format:
--------------
Print the list of integer values, in BCS form. 


Sample Input-1:
---------------
2

Sample Output-1:
----------------
[0, 1, 3, 2]

Explanation:
------------
00 - 0
01 - 1
11 - 3
10 - 2

Sample Input-2:
---------------
3

Sample Output-2:
----------------
[0, 1, 3, 2, 6, 7, 5, 4]

Explanation:
------------
000 - 0
001 - 1
011 - 3
010 - 2
110 - 6
111 - 7
101 - 5
100 - 4
 */
#include <bits/stdc++.h>
using namespace std;

void generate(int n)
{
	if (n <= 0)
		return;
	vector<string> arr;

	arr.push_back("0");
	arr.push_back("1");

	for(int i=2;i<(1<<n);i=i<<1){
		for(int j=i-1;j>=0;j--)
			arr.push_back(arr[j]);

		for(int j=0;j<i;j++)
			arr[j] = "0" + arr[j];

		for(int j=i;j<2*i;j++)
			arr[j] = "1" + arr[j];
	}
	for(int i=0;i<arr.size();i++)
		cout << stoi(arr[i], 0, 2) << endl;
}

int main()
{
    int n;
    cin>>n;
	generate(n);
	return 0;
}
