#include <iostream>
#include <list>
#include <memory.h>

using namespace std;

class Graph{
	int num_of_vertices;
	list <int> *L;

	void BFS(int v,bool visited[]){
	    list<int> q;
	    visited[v] = true;
	    q.push_back(v);
	    list<int>::iterator it;

	    while(!q.empty()){
	        v = q.front();
	        cout << v << " ";
	        q.pop_front();
	        
	        for(it = L[v].begin(); it != L[v].end(); ++it){
	            if(!visited[*it]){
	                visited[*it] = true;
	                q.push_back(*it);
	            }
	        }
	    }
	}
public:
	Graph(int num){

		this->num_of_vertices	= num;
		L = new list <int> [num];
	}
	void add(int v,int w){
		L[v].push_back(w);
	}
	void init(){
		bool visited[num_of_vertices];
		// memset(visited,0,sizeof(visited));
		for(int i=0;i<num_of_vertices;i++) visited[i]=false;
		BFS(0,visited);
	}

};
int main(){
	ios_base::sync_with_stdio(false);

	Graph O(6);
    O.add(0, 2);
    O.add(2, 3);
    O.add(5, 1);
    O.add(2, 4);
    O.add(3, 5);
 
    cout << "BFS: ";
    O.init();
 

	return 0;
}