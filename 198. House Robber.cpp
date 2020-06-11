class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> dp(nums.size()+3, 0);

		for (int i = 0; i<nums.size(); i++) {
			int val = max(dp[i], dp[i+1]) + nums[i];
			dp[i+3] = val;

			//cout << "dp:" << i << " val:" << val << endl;
		}

		return max(dp[dp.size() - 1], dp[dp.size() - 2]);
	}
};


============================================================================================================

#define max(a, b) ((a)>(b)?(a):(b))
int rob(int num[], int n) {
    int a = 0;
    int b = 0;
    
    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }
    
    return max(a, b);
}

================================================================================================================
	
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = Math.max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}
