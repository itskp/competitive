// Dijkstra using PQ
// Time Complexity: (E * Log(V) )

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_SIZE 100001
#define RANGE (1<<20)

priority_queue < pair<int,int> , vector < pair<int,int> > , greater <pair <int,int> > > q;
 
//priority_queue <int, vector<int>, greater<int> > pq;   
//pq is a priority queue of integers that uses a vector of integers for storage 
//and uses > to determine priority. This means that if a > b,	a has *lower* priority than b.

vector < pair <int,int> > MAT[MAX_SIZE]; // for storing graph

int DIST[MAX_SIZE]; // Distance matrix
bool VISITED[MAX_SIZE]; // visited matrix

int main(){
	int nodes,edges,sz,u,v,wt,start,cur;

	// create graph
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>u>>v>>wt;
		MAT[u].push_back(make_pair(v,wt));
		MAT[v].push_back(make_pair(u,wt));
	}
	// get the start vertex
	cin>>start;

	// init distance to MAX
	for(int i=1;i<=nodes;i++) DIST[i] = RANGE;

	//distance from start to start = 0
	DIST[start] = 0;

	// push start to pqueue
	q.push(make_pair(start,0));


	// apply dijkstra
	while(!q.empty()){

		cur = q.top().first; // set top vertex as current_vertex(cur)
		q.pop();//pop top

		if(VISITED[cur]) continue; // if top vertex is visited then continue

		sz = MAT[cur].size();

		for(int i=0;i<sz;i++){
			v = MAT[cur][i].first;
			wt = MAT[cur][i].second;

			if(!VISITED[cur] && (DIST[cur] + wt)  < DIST[v]){
				// if current vertex is not visited
				DIST[v] = DIST[cur] + wt;
				q.push(make_pair(v,DIST[cur]));
			}
		}
		VISITED[cur] = 1;
	}

	// print shortest distances from start to i'th vertex
	for(int i=1;i<=nodes;i++){
		cout<<"node: "<<i<<" "<<DIST[i]<<endl;
	}
	return 0;
}