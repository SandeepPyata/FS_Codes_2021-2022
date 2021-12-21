/*
KCR Chief Minister of Telangana Government has passed a new G.O to Telangana police for
safety of Telangana people. In this regard he announced new Vehicles to be released for all
the stations working for this mission especially.
Here we have a 2D mesh, there are P police officers and V vehicles, with P<=V.
Each police officer and vehicle is a 2D coordinate on this mesh.
Here the government has assigned a unique vehicle to each police officer.

Now create a method which prints the minimum possible sum of distances between each
police officer and their assigned vehicle.

Here the distance is between police officer Pi and vehicle Vi assigned to him.
And distance between Pi, Vi is calculated as follows: |Pi.x - Vi.x| + |Pi.y - Vi.y|


Input Format:
-------------
Line-1: Two integers P and V, number of police officers and vehicles.
Next P lines: Two space separated integers co-ordinates of Police officers.
Next V lines: Two space separated integers co-ordinates of Vehicles.

Output Format:
--------------
Print an integer, the minimum possible sum of distances.


Sample Input-1:
---------------
3 3
0 1		// co-ordinates of police
1 2
1 3
4 5		// co-ordinates of vehicles
2 5
3 6

Sample Output-1:
----------------
17




Sample Input-2:
---------------
2 2
0 0		// co-ordinates of police
2 1
1 2		// co-ordinates of vehicles
3 3

Sample Output-2:
----------------
6
*/
#include<bits/stdc++.h>
using namespace std;

void minDist(int p, int v, vector<pair<int,int>> &police, vector<pair<int,int>> &vehicle, int index, int curr, int &result, vector<int>&vis){
    if(index==p){
        result = min(result,curr);
        return;
    }
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            vis[i] = 1;
            curr += abs(police[index].first - vehicle[i].first) + abs(police[index].second - vehicle[i].second);
            
            minDist(p,v,police,vehicle,index+1,curr,result,vis);
            
            curr -= abs(police[index].first - vehicle[i].first) + abs(police[index].second - vehicle[i].second);
            vis[i] = 0;
        }
    }
}

int main()
{
    int p,v;
    cin>>p>>v;
    
    vector<pair<int,int>> police, vehicle;
    
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        police.push_back({a,b});
    }
    for(int i=0;i<v;i++){
        int a,b;
        cin>>a>>b;
        vehicle.push_back({a,b});
    }
    
    int result = INT_MAX;
    vector<int> vis(v,0);
    
    minDist(p,v,police,vehicle,0,0,result,vis);
    cout<< result <<endl;
    
    return 0;
}