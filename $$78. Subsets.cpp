
ugly!

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<vector<int>> result = DoSubsets(nums, 0);

		vector<int> empty;
		result.push_back(empty);

		return result;
	}

	vector<vector<int>> DoSubsets(vector<int>& nums, int start) {

		vector<vector<int>> result;

		vector<int> tmp(1, nums[start]);

		result.push_back(tmp);

		if (++start < nums.size()) {

			vector<vector<int>> pre = DoSubsets(nums, start);

			for (int i = 0; i<pre.size(); i++) {

				result.push_back(pre[i]);

				pre[i].push_back(nums[start-1]);

			}

			for (int i = 0; i < pre.size(); i++) {
				result.push_back(pre[i]);
			}
		}
		
		for (int k = 0; k < result.size(); k++) {
		
			vector<int> aaa = result[k];
			for (int j = 0; j < aaa.size(); j++) {
				cout << aaa[j];
			}
			cout << "|";
		}
		cout << "start:" << nums[start - 1] << endl;

		return result;
	}
};

=======================================================================================================

反复品味！！！  backtrace

class Solution {
private:
	vector<vector<int>> powerset; // stores all subsets
	vector<int> subset; // temporary subset which will be updated as the recursive function executes    
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(nums, 0);
		return powerset;
	}

	void backtrack(vector<int>& nums, int start) {
		powerset.push_back(subset);

		for (int i = start; i < nums.size(); i++) {
			// recording all subsets that include nums[i]
			cout << "push:" << nums[i] << endl;
			subset.push_back(nums[i]);
			backtrack(nums, i + 1);

			// remove nums[i] from the present subset and move further to explore subsets that don't contain nums[i]
			subset.pop_back();
			cout << "pop:" << nums[i] << endl;
		}
	}
};

==========================================================================================================

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
	    //key COPY VECTOR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
}; 
