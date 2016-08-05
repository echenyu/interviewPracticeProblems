#include <iostream>

using namespace std;

//Recursively call each possible path that you can take
//At each step, append to a vector that direction that you take
//If at any point, your location is equal to the end location, then print out the path taken

struct Coordinate {
	int row;
	int col;
};

int main() {
	Coordinate startLocation; 
	startLocation.row = 0; startLocation.col = 0; 

	vector<bool> visitedMap; 
	for(int i = 0; i < grid.size(); i++) {
		vector<bool> boolVector; 
		for(int j = 0; j < grid[i].size(); j++) {
			boolVector.push_back(false); 
		}
		visitedMap.push_back(boolVector); 
	}
}

void findPath(vector<vector<int> > &grid, 
			  Coordinate currentLocation, 
			  vector<char> pathTaken,
			  vector<vector<bool> > &visitedMap) {
	if(currentLocation.col = grid.size() - 1 && currentLocation.col = grid[0].size() - 1) {
		printPath(); 
		return; 
	}
	visitedMap[currentLocation.row][currentLocation.col] = true; 

	if(!visitedMap[currentLocation.row+1][currentLocation.col]) {
		currentLocation.row = currentLocation.row+1; 
		findPath(currentLocation); 
		currentLocation.row = currentLocation.row - 1; 
	}
	
	if(!visitedMap[currentLocation.row][currentLocation.col+1]) {
		currentLocation.col = currentLocation.col + 1; 
		findPath(currentLocation); 
	}
}