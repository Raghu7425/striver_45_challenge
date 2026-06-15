class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 1;
        int result = 1;

        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            result = max(result, platforms);
        }

        return result;
    }
};