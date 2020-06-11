处理 window 相关问题时, 通常在遍历时使用另一个容器来(如本题中的dequeue)保持特定结构
对于取可能消失的最大值,通常按一定规则保留promising max values

public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n == 0) {
            return nums;
        }
        int[] result = new int[n - k + 1];
        LinkedList<Integer> dq = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (!dq.isEmpty() && dq.peek() < i - k + 1) {
                dq.poll();
            }
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()]) {
                dq.pollLast();
            }
            dq.offer(i);
            if (i - k + 1 >= 0) {
                result[i - k + 1] = nums[dq.peek()];
            }
        }
        return result;
    }
}

---------------------------------------------------------------------------------------------

class Monoqueue {
    deque<int> myque; // every element in this queue is maintained to be monotonously decreasing.
public:
    void push(int n) {
        while(!myque.empty() && myque.back() < n) myque.pop_back();
        myque.push_back(n);
    }
    
    int front() {
        return myque.front();
    }
    
    void pop(int val) {
        if(val == myque.front())
            myque.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Monoqueue mq;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(i < k-1) mq.push(nums[i]);
            else {
                mq.push(nums[i]);
                res.push_back(mq.front());
                mq.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};
