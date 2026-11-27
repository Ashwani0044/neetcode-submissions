/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int cnt = 1;
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                cnt++;
            }
        }
        return cnt;
   }
};
