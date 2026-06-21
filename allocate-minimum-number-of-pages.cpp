class Solution {
public:
    bool canAllocate(vector<int>& arr, int k, int maxPages) {
        int students = 1;
        int pages = 0;

        for (int book : arr) {
            if (pages + book <= maxPages) {
                pages += book;
            } else {
                students++;
                pages = book;

                if (students > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if (k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAllocate(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};