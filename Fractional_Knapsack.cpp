class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<pair<double, int>> items; // {ratio, index}

        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        sort(items.begin(), items.end(),
             [](const pair<double, int>& a, const pair<double, int>& b) {
                 return a.first > b.first;
             });

        double ans = 0.0;

        for (auto &item : items) {
            int idx = item.second;

            if (capacity >= wt[idx]) {
                ans += val[idx];
                capacity -= wt[idx];
            } else {
                ans += item.first * capacity;
                break;
            }
        }

        return ans;
    }
};