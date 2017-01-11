/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            vector<Interval> v = {};
            return v;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b ){
             return a.start < b.start;
        });
        vector<Interval> results;
        results.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (results.back().end < intervals[i].start) {
                results.push_back(intervals[i]);
            } else {
                results.back().end = max(results.back().end, intervals[i].end);
            }
        }
        return results;
    }
};