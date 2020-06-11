
通过累计计数算最大值处理排除重复问题

class Solution {
public:
	int minMeetingRooms(vector<Interval> &intervals){
		map<int, int> meetingTimeMap;
		for(auto &a :intervals){
			meetingTimeMap[a.start]++;	//开始时间
			meetingTimeMap[a.end]--;	//结束时间
		}
		int res = 0, rooms = 0;
		for(auto &m : meetingTimeMap){
			rooms += m.second;
			res = max(res, rooms);
		}
		return res;
}

--------------------------------------------------------------------------------------------------------

用priorityQueue处理排重问题

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto interval : intervals) {
            if (!q.empty() && q.top() <= interval[0]) q.pop();
            q.push(interval[1]);
        }
        return q.size();
    }
};
