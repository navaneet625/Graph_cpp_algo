#include<bits/stdc++.h>
using namespace std;
const int INF = 10000000;// use any number or INT_MAX

int main(){

	int n,m,a,b,wt;

	cin>>n>>m;

	unordered_map<int ,vector<pair<int,int>>> adj;

	for(int i=0;i<m;i++){
		cin>>a>>b>>wt;
		adj[a].push_back({b,wt});
		// adj[b].push_back({a,wt});  for undirected graph
	}

	vector<int>dist(n,INF);
	vector<int>parent(n,-1);

	set<pair<int,int>>s;
	int src;
	cin>>src;

	dist[src]=0;

	s.insert({0,src});

	while(!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());

		for(auto x:adj[v]){
			int u = x.first;
			int weight = x.second;

			if(dist[v]+weight<dist[u]){

				if(s.find({dist[u],u})!=s.end())
					s.erase({dist[u],u});
				dist[u]=dist[v]+weight;
				parent[u]=v;
				s.insert({dist[u],u});
			}
		}
	}

	for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }
    return 0;
}
