#include <iostream>
#include <vector>

using namespace std;

void setRowsAndColumnsToZeroSquaredSpace(vector<vector<int> > &matrix);
void setRowsAndColumnsToZeroLinearSpace(vector<vector<int> > &matrix);
void createTestVector(vector<vector<int> > &matrixToRotate);

int main() {
	vector<vector<int> > matrix; 
	createTestVector(matrix); 

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	setRowsAndColumnsToZeroSquaredSpace(matrix); 

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	vector<vector<int> > matrix2; 
	createTestVector(matrix2); 
	setRowsAndColumnsToZeroLinearSpace(matrix2); 

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix2[i].size(); j++) {
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}
}

void setRowsAndColumnsToZeroSquaredSpace(vector<vector<int> > &matrix) {

	vector<vector<bool> > bitMap; 
	for(int i = 0; i < matrix.size(); i++) {
		vector<bool> boolVector; 
		for(int j = 0; j < matrix[i].size(); j++) {
			boolVector.push_back(0); 
		}
		bitMap.push_back(boolVector); 
	}

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			if(matrix[i][j] == 0 && bitMap[i][j] != 1) {
				for(int k = 0; k < matrix[i].size(); k++) { 
					if(matrix[i][k] != 0) {
						bitMap[i][k] = 1; 
						matrix[i][k] = 0;
					}  
				}
				for(int k = 0; k < matrix.size(); k++) {
					if (matrix[k][j] != 0) {
						bitMap[k][j] = 1; 
						matrix[k][j] = 0; 
					}
				}
			}
		}
	}
}

void setRowsAndColumnsToZeroLinearSpace(vector<vector<int> > &matrix) {
	vector<bool> rowHasZero(matrix.size()); 
	vector<bool> columnHasZero(matrix[0].size());

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			if(matrix[i][j] == 0) {
				rowHasZero[i] = true; 
				columnHasZero[j] = true; 
			}
		}
	}

	for(int i = 0; i < rowHasZero.size(); i++) {
		if(rowHasZero[i] == true) {
			for(int j = 0; j < matrix[0].size(); j++) {
				matrix[i][j] = 0; 
			}
		}
	}

	for(int i = 0; i < columnHasZero.size(); i++) {
		if(columnHasZero[i] == true) {
			for(int j = 0; j < matrix.size(); j++) {
				matrix[j][i] = 0; 
			}
		}
	}
}

void createTestVector(vector<vector<int> > &matrixToRotate) {
	vector<int> firstVec; 
	firstVec.push_back(1); 
	firstVec.push_back(1);
	firstVec.push_back(1); 
	firstVec.push_back(1); 
	matrixToRotate.push_back(firstVec); 
	firstVec.clear(); 

	firstVec.push_back(1); 
	firstVec.push_back(1);
	firstVec.push_back(1);
	firstVec.push_back(1);
	matrixToRotate.push_back(firstVec); 
	firstVec.clear(); 

	firstVec.push_back(0);
	firstVec.push_back(1);
	firstVec.push_back(1);
	firstVec.push_back(1);
	matrixToRotate.push_back(firstVec); 
	firstVec.clear(); 

	firstVec.push_back(0);
	firstVec.push_back(0);
	firstVec.push_back(1);
	firstVec.push_back(1);
	matrixToRotate.push_back(firstVec); 
}