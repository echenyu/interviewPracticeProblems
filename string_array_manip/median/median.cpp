#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void fix(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > & minHeap);
void insert(int val, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > & minHeap);
int returnMedian(vector<int> &vals);
double medianOf(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > & minHeap);

int main() {
	vector<int> vals = {1, 1, 2, 6, 6, 9 }; 
	//1, 2, 2, 3, 3, 4, 4, 14, 16, 16
	cout << "Median is: " << returnMedian(vals) << endl;; 
}
// 
int returnMedian(vector<int> &vals) {
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap; 
	int currentMedian = 0; 
	for(auto i : vals) {
		insert(i, maxHeap, minHeap); 	
	}
	return medianOf(maxHeap, minHeap); 
}

void insert(int val, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > & minHeap) {
	if(maxHeap.empty()) { maxHeap.push(val); return; }
	val > medianOf(maxHeap, minHeap) ? minHeap.push(val) : maxHeap.push(val); 
	fix(maxHeap, minHeap); 
}

double medianOf(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > & minHeap) {
	if(maxHeap.size() == minHeap.size()) {
		return (double(minHeap.top()) + double(maxHeap.top())) / 2;
	} 
	return (maxHeap.size() - minHeap.size() == 1) ? maxHeap.top() : minHeap.top(); 
} 

void fix(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > & minHeap) {
	if(int(maxHeap.size()) - int(minHeap.size()) >= 2) {
		minHeap.push(maxHeap.top()); 
		maxHeap.pop();
	} else if(int(minHeap.size()) - int(maxHeap.size()) >= 2) {
		maxHeap.push(minHeap.top()); 
		minHeap.pop(); 
	}
}