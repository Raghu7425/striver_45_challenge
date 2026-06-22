class Solution {
public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<tuple<int,int,int>> meetings;

        for (int i = 0; i < s.size(); i++) {
            meetings.push_back({f[i], s[i], i + 1});
        }

        sort(meetings.begin(), meetings.end());

        vector<int> result;
        int lastEnd = -1;

        for (auto &m : meetings) {
            int end = get<0>(m);
            int start = get<1>(m);
            int idx = get<2>(m);

            if (start > lastEnd) {
                result.push_back(idx);
                lastEnd = end;
            }
        }

        sort(result.begin(), result.end());   // <-- missing step
        return result;
    }
};