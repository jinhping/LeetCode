/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.size() <= 1) return intervals;
        
        List<Interval> res = new ArrayList<>();
        Collections.sort(intervals, new Comparator<Interval>(){
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        Interval last = intervals.get(0);
        for (int i = 1; i < intervals.size(); i++) {
            Interval interval = intervals.get(i);
            if (interval.start > last.end) {
                res.add(last);
                last = interval;
            } else{
                last.end = Math.max(last.end, interval.end);
            }
        }
        res.add(last);
        return res;
    }
}