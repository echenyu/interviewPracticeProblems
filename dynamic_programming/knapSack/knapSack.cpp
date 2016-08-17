#include <iostream>
#include <vector>

using namespace std;

int return_maxProfit(int w, int n, vector<int> &weights, vector<int> &values);

int main() {
    vector<int> weights; 
    weights.push_back(10); 
    weights.push_back(20); 
    weights.push_back(5); 

    vector<int> values; 
    values.push_back(40); 
    values.push_back(60); 
    values.push_back(25); 

    cout << "Max: " << return_maxProfit(20, 3, weights, values); 
}

//
int return_maxProfit(int w, int n, vector<int> &weights, vector<int> &values) {
    int arr[n+1][w+1]; 

    for(int i = 0; i <= n; i++) {
        for(int weight = 0; weight <= w; weight++) {
            if(i == 0 || weight == 0) {
                arr[i][weight] = 0; 
            } else if(weights[i-1] <= weight) {
                arr[i][weight] = max(arr[i-1][weight], values[i-1] + arr[i-1][weight-weights[i-1]]); 
            } else {
                arr[i][weight] = arr[i-1][weight]; 
            }
        }
    }

    return arr[n][w]; 
}