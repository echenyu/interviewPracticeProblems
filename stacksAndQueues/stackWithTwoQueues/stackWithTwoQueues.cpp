//2 queue solution and 1 queue solution. With two queue, we just switch elements over
//and keep track of a boolean that is the current queue that we're pushing onto. 
//Every time we get top or pop, we move all elements over. With the 1 queue solution,
//all the work is done in push (we rotate elements in push until it's at the front)

class StackWith2 {
public:
    // Push element x onto stack.
    void push(int x) {
        current ? first.push(x) : second.push(x); 
    }

    // Removes the element on top of the stack.
    void pop() {
        current ? switchQueues(first, second) : switchQueues(second, first); 
    }

    // Get the top element.
    int top() {
        int returnVal = current ? switchQueues(first, second) : switchQueues(second, first); 
        current ? first.push(returnVal) : second.push(returnVal); 
        return returnVal;
    }

    // Return whether the stack is empty.
    bool empty() {
        return first.empty() && second.empty(); 
    }
    
private:
    queue<int> first;
    queue<int> second;
    bool current = true; 
    
    int switchQueues(queue<int> &q1, queue<int> &q2) {
        int topVal = -1; 
        if(q2.empty()) {
            while(!q1.empty()) {
                topVal = q1.front(); 
                q1.pop(); 
                if(!q1.empty()) {
                    q2.push(topVal); 
                }
            }
        }
        current = !current; 
        return topVal; 
    }
};

// 1 2 3
// we want 3, but we get 1

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        first.push(x); 
        for(int i = 1; i < first.size(); i++) {
            first.push(first.front()); 
            first.pop(); 
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        first.pop(); 
    }

    // Get the top element.
    int top() {
        return first.front(); 
    }

    // Return whether the stack is empty.
    bool empty() {
        return first.empty();
    }
    
private:
    queue<int> first;
};