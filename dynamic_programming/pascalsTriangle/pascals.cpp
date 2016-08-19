#include <iostream>
#include <vector>

//   1
//  1 1
// 1 1 1 

vector<vector<int> > returnPascal(int rows) {
	vector<vector<int> > result; 
	for(int i = 0; i < rows; i++) {
		vector<int> newRow(i+1, 1); 
		result.push_back(newRow); 

		//Check the boundaries in a second
		for(int j = 1; j < newRow.size() - 1; j++) {
			result[i][j] = result[i-1][j-1] + result[i-1][j];
		}
	}

	return result; 
}