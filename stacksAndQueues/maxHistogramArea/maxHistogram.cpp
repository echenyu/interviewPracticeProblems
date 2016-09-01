int largestRectangleArea(vector<int> &height) {
    int ret = 0;
    height.push_back(0);
    stack<int> index;
    
    int i = 0; 
    while(i < height.size()) {
        if(index.empty() || height[index.top()] <= height[i]) {
            index.push(i++); 
        } else {
            int topVal = index.top(); 
            index.pop(); 
            int mult = index.empty() ? i : i-index.top()-1; 
            ret = max(ret, height[topVal] * mult); 
        }
    }
    
    return ret;
}