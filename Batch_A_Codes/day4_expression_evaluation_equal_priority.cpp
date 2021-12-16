/*
Scoops an 2nd class boy is doing a maths assignment given by his teacher.
Scoops is very poor at maths. 

When given an expression he will evaluate the expression from the start to the end. 

Help Scoops to solve the problem. He assumes the +,-,*,/ has the equal priority. 

Sample Test Case - 1
input = 2+5*2
output = 14

Explanation - The expression when evaluated from start to end
we have 2+5 which is 7 and when 7 is multiplied with 2 we have 14 as the output 

Sample Test Case - 2
input = 2+3*6
output = 30

Explanation :- The sum of 2+3 is 5 and 5*6 = 30 

Sample Test Case - 3
input = 5+7-9+0*0+1
output = 1

Explanation :- The sum of 5+7 is 12 
12-9 is 3 and 3+0 is 3, 3*0 is 0 and 0+1 is 1 

Sample Test Case - 4
input = -1+-1*2
output = -4

Explanation :-
-1 + -1 is -2 
and -2 * 2 is -4

*/
#include<bits/stdc++.h>
using namespace std;

int operation(char oper, int a, int b){
    int res;
    switch (oper){
        case '+':   return a+b;
        case '-':   return a-b;
        case '*':   return a*b;
        case '/':   return a/b;
    }
    return 0;
}

int extractInt(int &i, int l, string s){
    int a = 0;
    while(i<l and s[i]>='0' and s[i]<='9'){
        a = a*10 + (s[i]-'0');
        i++;
    }
    return a;
}

int main()
{
    string s;
    cin>>s;

    int l = s.length();
    int i = 0, curr = 0, res = 0;

    int a = 0, b = 0, negFlag = 0;
    char oper;
    while(i<l){
        if(i==0)    
            oper = '+';
        else        
            oper = s[i++];
        
        if(s[i]=='-'){
            negFlag = 1;
            i++;
        }

        curr = extractInt(i,l,s);

        if(negFlag)    
            curr *= -1;
        res = operation(oper,res,curr);
        
        negFlag = 0;
    }

    cout<<res<<endl;

    return 0;
}
