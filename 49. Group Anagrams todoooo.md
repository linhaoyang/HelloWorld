
与顺序无关
hash？


每一个数要么是质数要么是由一组独一无二的质数相乘得来！

public static List<List<String>> groupAnagrams(String[] strs) { 
   int[] prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};//最多10609个z
    
            List<List<String>> res = new ArrayList<>();
            HashMap<Integer, Integer> map = new HashMap<>();
            for (String s : strs) {
                int key = 1;
                for (char c : s.toCharArray()) {
                    key *= prime[c - 'a'];
                }
                List<String> t;
                if (map.containsKey(key)) {
                    t = res.get(map.get(key));
                } else {
                    t = new ArrayList<>();
                    res.add(t);
                    map.put(key, res.size() - 1);
                }
                t.add(s);
            }
            return res;
    }



======================================================================================================

1.让无序变有序 

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		vector<vector<string>> result;

		map<string, vector<string>> resultMap;

		map<string, vector<string>>::iterator it;

		for (int i = 0; i<strs.size(); i++) {

			string aaa = GetSortedResult(strs[i]);

			it = resultMap.find(aaa);
			if (it != resultMap.end()) {
				resultMap[aaa].push_back(strs[i]);
			}
			else {
				vector<string> tmp;
				tmp.push_back(strs[i]);
				resultMap[aaa] = tmp;
			}

		}

		for (map<string, vector<string>>::iterator it = resultMap.begin(); it != resultMap.end(); ++it) {
			result.push_back(it->second);
		}

		return result;

	}

	string GetSortedResult(string word) {

		string b = word;
		std::sort(b.begin(), b.end());
		return b;

	}
};


同排序

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > retMap;
        for (string& s : strs){
            string s2 = s;
            sort(s2.begin(),s2.end());
            if (retMap.find(s2) == retMap.end()) retMap.emplace(s2,vector<string>());
            retMap[s2].push_back(s);
        }
        vector<vector<string> > ret;
        for (auto& each : retMap) ret.push_back(each.second);
        return ret;
    }
};

===============================================================================================================

对于输入范围为26个英文字母时有效, 记录各字符出现次数

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        int[] count = new int[26];
        for (String s : strs) {
            Arrays.fill(count, 0);
            for (char c : s.toCharArray()) count[c - 'a']++;

            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.append('#');
                sb.append(count[i]);
            }
            String key = sb.toString();
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
