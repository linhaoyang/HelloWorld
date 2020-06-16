
backtrack!! 

public List<List<Integer>> permute(int[] nums) {
   List<List<Integer>> list = new ArrayList<>();
   // Arrays.sort(nums); // not necessary
   backtrack(list, new ArrayList<>(), nums);
   return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums){
   if(tempList.size() == nums.length){
      list.add(new ArrayList<>(tempList));
   } else{
      for(int i = 0; i < nums.length; i++){ 
	      //nums中有相同值时不可取
         if(tempList.contains(nums[i])) continue; // element already exists, skip  可优化？
         tempList.add(nums[i]);
         backtrack(list, tempList, nums);
         tempList.remove(tempList.size() - 1);
      }
   }
} 

========================================================================================

巧用swap

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()-1) {	
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};

=====================================================================================================================

	void string_permutation(std::string& orig, std::string& perm)
	{
		if (orig.empty())
		{
			std::cout << perm << std::endl;
			return;
		}

		cout << "-----------------permutateOrigin:"<< orig << endl;
		cout << "perm: "<< perm << endl;

		for (int i = 0; i<orig.size(); ++i)
		{
			std::string orig2 = orig;

			orig2.erase(i, 1);
			cout << "AfterErase: " << i << " orig2:"<<orig2 << endl;

			std::string perm2 = perm;

			perm2 += orig.at(i);

			string_permutation(orig2, perm2);
		}
	}
