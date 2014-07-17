#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        Interval v = findPosition(intervals, newInterval);
        if (v.start > v.end) {
            intervals.insert(intervals.begin() + v.start, newInterval);
            return intervals;
        }
        else {
            vector<Interval> rtnval;
            if (v.start > 0)
                rtnval.insert(rtnval.begin(), intervals.begin(), intervals.begin() + v.start);
            Interval n(intervals[v.start].start, intervals[v.end].end);
            n.start = min(n.start, newInterval.start);
            n.end = max(n.end, newInterval.end);
            rtnval.push_back(n);
            if (v.end < intervals.size() - 1)
                rtnval.insert(rtnval.end(), intervals.begin() + v.end + 1, intervals.end());
            return rtnval;
        }
    }

    Interval findPosition(const vector<Interval> &intervals, Interval newInterval) {
        Interval rtnval(intervals.size(), -1);

        int start = 0;
        int end = intervals.size() - 1;
        int mid = (start + end) / 2;
        while (start < end) {
            mid = (start + end) / 2;
            if (intervals[mid].start <= newInterval.start && intervals[mid].end >= newInterval.start) {
                break;
            }
            else if (intervals[mid].end < newInterval.start) {
                start = mid + 1;
            }
            else if (intervals[mid].start > newInterval.start) {
                end = mid - 1;
            }
        }
        mid = (start + end) / 2;
        if (newInterval.start <= intervals[mid].end)
            rtnval.start = mid;
        else
            rtnval.start = mid + 1;

        start = 0;
        end = intervals.size() - 1;
        mid = (start + end) / 2;
        while (start < end) {
            mid = (start + end) / 2;
            if (intervals[mid].start <= newInterval.end && intervals[mid].end >= newInterval.end) {
                break;
            }
            else if (intervals[mid].end < newInterval.end) {
                start = mid + 1;
            }
            else if (intervals[mid].start > newInterval.end) {
                end = mid - 1;
            }
        }
        mid = (start + end) / 2;
       
        if (intervals[mid].start <= newInterval.end) {
            rtnval.end = mid;
        }
        else
            rtnval.end = mid - 1;
        return rtnval;
    }
};

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(0, 10));
    intervals.push_back(Interval(14, 14));
    intervals.push_back(Interval(15, 20));


    Solution s;
    s.insert(intervals, Interval(11, 11));
    return 0;
}