class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    int min = 2147483647;
    MinStack() {
        
    }
    
    void push(int x) {
        if(min > x){
            min = x;
        }
        vec.push_back(x);
    }
    
    void pop() {
       vec.pop_back();
        min = 2147483647;
        for(int i =0;i<vec.size();i++){
            if(min > vec[i]) min = vec[i];
        }
    }
    
    int top() {
        
        if(vec.size()>0){
            return vec[vec.size()-1];
        }
        return 0;
    }
    
    int getMin() {
        return min;
    }
};

===================================================================================================================

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};
