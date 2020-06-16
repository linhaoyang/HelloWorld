
SlidingWindow!!!

MY UGLY Solution~~~
class Solution {
public:
	string minWindow(string s, string t) {
	
		map<char, int> mm;
		int temp = 0;
		for (int i = 0; i < t.size(); i++) {
			mm[t[i]]++;
			temp++;
		}

		int left = 0;
		int minLeft = -1;
		int right = 0;
		int minRight = -1;

		while (right<s.size()) {

			char rc = s[right];
			if (mm.find(rc) != mm.end()) {
				if (--mm[rc] >= 0) {
					temp--;
				}
				if (temp <= 0) {
					cout << "right:" << right;
					while (left <= right) {
						char lc = s[left];
						if (mm.find(lc) != mm.end()) {
							if (++mm[lc] > 0) {
								temp++;
								cout << "left:" << left << endl;
								if (minLeft < 0 || right - left < minRight - minLeft) {
									minLeft = left;
									minRight = right;
								}
							}
						}
						left++;
						if (temp > 0) break;
					}
				}
			}

			right++;
		}

		string result = minLeft >= 0 ? s.substr(minLeft, minRight - minLeft + 1) : "";
		cout << "result:" << result;
		return result;
	}
};



===========================================================================================================

思路和楼上一样  写法elegant
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        vector<int> letterCnt(128, 0);
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};


=====================================================================================================================

通过 filteredS 加快跳转

class Solution {
    public String minWindow(String s, String t) {

        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        Map<Character, Integer> dictT = new HashMap<Character, Integer>();

        for (int i = 0; i < t.length(); i++) {
            int count = dictT.getOrDefault(t.charAt(i), 0);
            dictT.put(t.charAt(i), count + 1);
        }

        int required = dictT.size();

        // Filter all the characters from s into a new list along with their index.
        // The filtering criteria is that the character should be present in t.
        List<Pair<Integer, Character>> filteredS = new ArrayList<Pair<Integer, Character>>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (dictT.containsKey(c)) {
                filteredS.add(new Pair<Integer, Character>(i, c));
            }
        }

        int l = 0, r = 0, formed = 0;
        Map<Character, Integer> windowCounts = new HashMap<Character, Integer>();  
        int[] ans = {-1, 0, 0};

        // Look for the characters only in the filtered list instead of entire s.
        // This helps to reduce our search.
        // Hence, we follow the sliding window approach on as small list.
        while (r < filteredS.size()) {
            char c = filteredS.get(r).getValue();
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }

            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required) {
                c = filteredS.get(l).getValue();

                // Save the smallest window until now.
                int end = filteredS.get(r).getKey();
                int start = filteredS.get(l).getKey();
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictT.containsKey(c) && windowCounts.get(c).intValue() < dictT.get(c).intValue()) {
                    formed--;
                }
                l++;
            }
            r++;   
        }
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}
