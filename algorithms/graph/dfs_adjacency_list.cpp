#include <iostream>
#include <list>
#include <memory.h>

using namespace std;

class Graph{
	int num_of_vertices;
	list <int> *L;
	void DFS(int v,bool visited[]){
		visited[v] = true;
		cout<<v<<" ";
		if(L[v].empty()) return;
		list <int> :: iterator it = L[v].begin();

		for(;it!=L[v].end();it++){
			if(!visited[*it]){
				DFS(*it,visited);
			}
		}
	}
public:
	Graph(int num){

		this->num_of_vertices	= num;
		L 						= new list <int> [num];
	}
	void add(int v,int w){
		L[v].push_back(w);
	}
	void init(){
		bool visited[num_of_vertices];
		// memset(visited,0,sizeof(visited));
		for(int i=0;i<num_of_vertices;i++) visited[i]=false;
			 DFS(0,visited);
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
 
    cout << "DFS: ";
    O.init();
 

	return 0;
}