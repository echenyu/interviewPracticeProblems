class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> individualTokens;
        
        for(auto i : tokens) {
            if(i == "+" || i == "/" || i =="-" || i == "*") {
                int second = individualTokens.top(); 
                individualTokens.pop(); 
                int first = individualTokens.top(); 
                individualTokens.pop(); 
                
                individualTokens.push(calculateValue(first, second, i));
            } else {
                individualTokens.push(stoi(i)); 
            }
        }
        
        return individualTokens.top(); 
    }
    
    int calculateValue(int first, int second, string operation) {
        if(operation == "+")
            return first + second; 
        else if(operation == "/")
            return first / second; 
        else if(operation == "-")
            return first - second; 
        else if(operation == "*")
            return first * second; 
        
        return - 1; 
    }
};