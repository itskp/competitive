/*
Problem statement:
	Given a 2D grid and a person standing at TOP LEFT (0,0)
	find if there is a path from TOP LEFT of the grid to BOTTOM RIGHT of the grid ( N (rows), M (columns)).
	NOTE: Integer '5' denotes a valid path rest all integers are obstacles

	INPUT FORMAT:
		the first line of input contains two space seperate integers:
			->	the number of rows (n) and the number of columns (m)
		there are 'n' lines:
			->	each of 'n' line contains m' space seperated integers
	OUTPUT FORMAT:
		print 'YES' if there is a path else 'NO'
	
	-------------------------------
	SAMPLE TEST CASES:
	-------------------------------
	5 5
	5 5 5 5 5
	1 5 1 1 5
	1 5 5 1 5        
	1 1 5 1 1
	1 1 5 5 5
	YES
	-------------------------------
	5 5
	5 5 5 5 5
	1 5 1 1 5
	1 5 5 1 5        
	1 1 5 1 1
	1 1 5 5 1
	NO
	-------------------------------
*/

#include <iostream>
#include <list>
using namespace std;

#define MAX_SIZE 100 // max grid size

int	grid[MAX_SIZE][MAX_SIZE]; // 2D grid for taking path

bool VISITED[MAX_SIZE][MAX_SIZE]; // 2D visit array for grid

int ROWS,COLUMNS; // for storing number of rows and number of columns in a grid
bool destination_check; // flag for checking whether destination is reached

list < pair <int,int> > possible_path; // list of path which can be a possible path and need to be traversed in future

void display(){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLUMNS;j++){
			cout<<VISITED[i][j]<<" ";
		}
		cout<<endl;
	}
}

void dfs(int x,int y){
	VISITED[x][y] = true;

	if(x== (ROWS-1) && y== (COLUMNS-1) ){
		destination_check = true; // if BOTTOM RIGHT reached set flag to true
		return;
	}
	if(x== (ROWS-1) ){
		if(grid[x][y+1] == 5) return dfs(x,y+1);
		else return;
	}
	if(y== (COLUMNS-1) ){
		if(grid[x+1][y] == 5) return dfs(x+1,y);
		else return;
	}
	if(grid[x+1][y] == 5){
		if(grid[x][y+1] == 5 && VISITED[x][y+1] == false) possible_path.push_back(make_pair(x,y+1)); // valid path to be traversed in future
		return dfs(x+1,y);
	}
	if(grid[x][y+1] == 5){
		if(grid[x+1][y] == 5 && VISITED[x+1][y] == false) possible_path.push_back(make_pair(x,y+1)); // valid path to be traversed in future
		return dfs(x,y+1);
	}	
}

int main(){
	destination_check = false;
	cin>>ROWS>>COLUMNS;
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLUMNS;j++){
			cin>>grid[i][j];
			VISITED[i][j]= false;
		}
	}
	// for debug
	// cout<<"<-----BEFORE----->\n";
	// display();

	dfs(0,0);	// start DFS from TOP LEFT

	//apply DFS from pending possible paths
	while(!possible_path.empty()){
		if(destination_check == true){
			cout<<"YES"<<endl;
			break;
		}
		pair <int,int> p = possible_path.front();
		possible_path.pop_front();
		VISITED[p.first][p.second]=0;
		dfs(p.first,p.second);
	}

	// for debug
	// cout<<"<-----AFTER----->\n";
	// display();
	if(destination_check == false) cout<<"NO"<<endl;
	return 0;
}