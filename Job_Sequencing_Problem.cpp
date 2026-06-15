class Solution {
  public:
    
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        vector<pair<int,int>> jobs;
        int maxDeadline = 0;
        
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        int cntJobs = 0;
        int totalProfit = 0;
        
        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;
            
            int availableSlot = find(min(d, maxDeadline), parent);
            
            if (availableSlot > 0) {
                cntJobs++;
                totalProfit += p;
                
                // mark this slot as occupied
                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }
        
        return {cntJobs, totalProfit};
    }
};