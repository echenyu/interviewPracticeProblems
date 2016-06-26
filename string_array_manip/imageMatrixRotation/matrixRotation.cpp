#include <iostream>
#include <vector>
#include <ctime>

// THE IN PLACE SOLUTION IS FASTER BY ABOUT A FACTOR OF 10! 
// 1 0 0 1						0 1 0 1     
// 0 0 1 0    ----> Solution:	0 1 0 0 
// 1 1 1 1						1 1 1 0
// 0 0 1 1     					1 1 0 1 
//Pattern: Column becomes row && 3 - row becomes column. 
// (0,0) -> (0,3); (0, 1) -> (1, 3); (0, 2) -> (2, 3); 
// (0,3) -> (3,3); (1, 3) -> (3, 2); (2, 3) -> (3, 1); 
using namespace std;

void rotateMatrixAdditionalSpace(vector<vector<int> > &matrixToRotate);
void rotateMatrixInPlace(vector<vector<int> > &matrixToRotate);
void createTestVector(vector<vector<int> > &matrixToRotate);

int main() {
	vector<vector<int> > matrixToRotate; 
	createTestVector(matrixToRotate); 

	int start_s = clock(); 
	rotateMatrixInPlace(matrixToRotate); 
	int stop_s = clock(); 
	cout << "Execution Time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	for(int i = 0; i < matrixToRotate.size(); i++) {
		for(int j = 0; j < matrixToRotate[i].size(); j++) {
			cout << matrixToRotate[i][j] << " ";
		}
		cout << endl;
	}

	start_s = clock(); 
	rotateMatrixAdditionalSpace(matrixToRotate); 
	stop_s = clock(); 
	cout << "Execution Time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

void rotateMatrixAdditionalSpace(vector<vector<int> > &matrixToRotate) {
	vector<vector<int> > rotatedMatrix; 

	for(int i = 0; i < matrixToRotate.size(); i++) {
		vector<int> rotatedInts; 
		for(int j = 0; j < matrixToRotate[i].size(); j++) {
			rotatedInts.insert(rotatedInts.begin(), matrixToRotate[j][i]); 
		}
		rotatedMatrix.push_back(rotatedInts); 
		rotatedInts.clear(); 
	}
	matrixToRotate = rotatedMatrix; 
}

void rotateMatrixInPlace(vector<vector<int> > &matrixToRotate) {
	int endIndex = matrixToRotate.size() - 1; 
	for(int i = 0; i < matrixToRotate.size()/2; i++) {
		for(int j = i; j < matrixToRotate[i].size() - 1 - i; j++) {
			int topVal = matrixToRotate[i][j]; 
			matrixToRotate[i][j] = matrixToRotate[endIndex-j][i];
			matrixToRotate[endIndex-j][i] = matrixToRotate[endIndex-i][endIndex-j];
			matrixToRotate[endIndex-i][endIndex-j] = matrixToRotate[j][endIndex-i]; 
			matrixToRotate[j][endIndex-i] = topVal; 
		}
	}
}

void createTestVector(vector<vector<int> > &matrixToRotate) {
	vector<int> firstVec; 
	firstVec.push_back(1); 
	firstVec.push_back(0);
	firstVec.push_back(0); 
	firstVec.push_back(1); 
	matrixToRotate.push_back(firstVec); 
	firstVec.clear(); 

	firstVec.push_back(0); 
	firstVec.push_back(0);
	firstVec.push_back(1);
	firstVec.push_back(0);
	matrixToRotate.push_back(firstVec); 
	firstVec.clear(); 

	firstVec.push_back(1);
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