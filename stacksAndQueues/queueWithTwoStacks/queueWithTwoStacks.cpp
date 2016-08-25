class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        first.push(x); 
    }

    // Removes the element from in front of queue.
    void pop(void) {
        moveStacks(first, second); 
        second.pop(); 
        moveStacks(second, first); 
    }

    // Get the front element.
    // 1 2 3
    // 1 2 3    3 2 1
    int peek(void) {
        moveStacks(first, second); 
        int returnValue = second.top(); 
        moveStacks(second, first); 
        return returnValue; 
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return first.empty(); 
    }
    
private:
    stack<int> first;
    stack<int> second; 
    void moveStacks(stack<int> &s1, stack<int> &s2) {
        while(!s1.empty()) {
            s2.push(s1.top()); 
            s1.pop(); 
        }
    }
};