#include <iostream>

using namespace std;

void clearBit(int &m, int index);
void insertIntoBit(int &m, int n, int i, int j);

//2 32 bit numbers M and N. 
//2 bit positions, i and j. 
//Insert the values from M into N from i to j. 
//CLEAR BIT: To clear a bit, we shift 1 over by however the bit index, and then negate it. 
//Example: We have 11011010, and we want to clear Bit 4.
//We would do 1 << 4, and then we would negate that value. So we have: 10000, and then 01111. 
//Next, we do an and with this bit mask that we made. 

//
int main() {
	int m = 51;
	int n = 5; 
	int i = 1; 
	int j = 3; 
	cout << m << " is the value before masking." << endl;
	insertIntoBit(m, n, i, j); 
	cout << m << " is the final value. " << endl;
}

void insertIntoBit(int &m, int n, int i, int j) {
	for(int x = i; x <= j; x++) {
		clearBit(m, x); 
	}
	
	n = n << i; 
	m = m | n; 
}

void clearBit(int &m, int index) {
	//All bits are set to 1
	int shiftMask = 1; 
	shiftMask = ~(shiftMask << index);
	m = m & shiftMask; 
}

// 1 & 0 = 0
// 1 & 1 = 1
// 1 || 1 = 1
// 1 || 0 = 1
// 110011 = N
// 101 = M insert at i = 1 and j = 3
// 110101 
// 0 with 1 = 1
// 1 with 0 = 0 
// 1 with 1 = 1
// 1. Clear all the bits from index i to index j. 
// 2. Shift M over by the index difference. 
// 3. Do an or operation between M and N. 