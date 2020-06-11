
学习单调栈的概念 始终保持栈递增
核心是找到当前bar的最大宽度

To find the maximal rectangle, if for every bar x, we know the first smaller bar on its each side, let's say l and r,
we are certain that height[x] * (r - l - 1) is the best shot we can get by using height of bar x

Then, the question comes: for every bar, can we really find the first smaller bar on its left and on its right in O(1) time? 
That seems impossible right? ... It is possible, by using a increasing stack.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        stack<int> mystack;
        mystack.push(-1);
        int i=0;
        for(; i<heights.size(); i++){
            while(mystack.top()!=-1 && heights[i]<=heights[mystack.top()])
            {
                int ht = heights[mystack.top()];
                mystack.pop();
                //此时ht为最小高度
                maxarea=max(maxarea, ht*(i-1-mystack.top()));
            }
            mystack.push(i);
        }
        while(mystack.top()!=-1 ){
            int ht = heights[mystack.top()];
            mystack.pop();
            maxarea=max(maxarea, ht*(i-1-mystack.top()));
        }
        return maxarea;
    }
};

========================================================================================================

 int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        //trick 优化循环
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
 }

=========================================================================================================

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int max = 0;
        for(int i =0;i<heights.size();i++){
            
            int a = findMax(heights,i);
            if(a > max){
                max = a;
            }
            
        }
        
        return max;
        
    }
    
    int findMax(vector<int>& heights,int index){
        
        int height = heights[index];
        
        int left = index;
        int right = index;
        
        while(heights[left-1]>= height && left > 0){
            left--;
        }
        
        while(heights[right+1]>= height && right < heights.size()-1){
            right++;
        }
        
        return (right-left+1)*height;
        
        
        
    }
};
