假DP cache方法 重复运算查找 子串

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {

		set<string> dict;
		map<string, bool> dp;
		for (int i = 0; i < wordDict.size(); i++) {
			dict.insert(wordDict[i]);
		}

		return checkBreak(s, dict,dp);
	}

	bool checkBreak(string s, set<string>& dict,map<string,bool>& dp) {

		if (dp.find(s) != dp.end()) {
			//cout << "!!!already find---" << s << endl;
			return dp[s];
		}
		bool result = false;
	

		for (int i = 1; i <= s.size() && !result; i++) {
			string b = s.substr(0, i);
			//cout << "checkword:" << b;
			if (dict.find(b) != dict.end()) {
				//cout << "---find" << endl;
				string sub = s.substr(i, s.size());

				if (sub.size() <= 0) {
					return true;
				}

				result = result || checkBreak(sub, dict,dp);
			}
			//cout << endl;
		}
	
		dp.insert(make_pair(s, result));
		//cout << "###make pair---" << s << result << endl;
		return result;
	}
};


====================================================================================================================

真DP

bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
    
===============================================================================================================
    
转换字符串问题为图的问题 interesting

The question is simply to check if there is a path from 0 to 9. 
The most efficient way is traversing the graph using BFS with the help of a queue and a hash set. 
The hash set is used to keep track of the visited nodes to avoid repeating the same work.

bool wordBreak(string s, unordered_set<string> &dict) {
// BFS
queue<int> BFS;
unordered_set<int> visited;

BFS.push(0);
while(BFS.size() > 0)
{
    int start = BFS.front();
    BFS.pop();
    if(visited.find(start) == visited.end())
    {
        visited.insert(start);
        for(int j=start; j<s.size(); j++)
        {
            string word(s, start, j-start+1);
            if(dict.find(word) != dict.end())
            {
                BFS.push(j+1);
                if(j+1 == s.size())
                    return true;
            }
        }
    }
}

return false;
}
