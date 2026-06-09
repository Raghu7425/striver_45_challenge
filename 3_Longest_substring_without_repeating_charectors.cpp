class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int n = s.size();
        int maxLength = 0;
        int left = 0, right = 0;

        while (right < n) {
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                seen.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};