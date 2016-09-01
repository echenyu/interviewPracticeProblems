int numTrees(int n) {
    unordered_map<int, int> valToCombinations; 
    int sum = numTrees_helper(n, valToCombinations); 
    return sum; 
}

int numTrees_helper(int n,  unordered_map<int, int> &valToCombinations) {
    if(n == 0 || n == 1) {return 1;}
    int sum = 0; 
    if(valToCombinations.find(n) != valToCombinations.end()) {
        return valToCombinations[n]; 
    }
    for(int i = 1; i <= n; i++) {
        int val1 = numTrees_helper(i - 1, valToCombinations);
        int val2 = numTrees_helper(n - i, valToCombinations); 
        sum += (val1 * val2);
    }
    valToCombinations[n] = sum; 
    return valToCombinations[n]; 
}
