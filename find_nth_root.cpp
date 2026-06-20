class Solution {
  public:
  
    long long power(long long base, int exp, int m) {
        long long res = 1;
        
        for (int i = 0; i < exp; i++) {
            res *= base;
            
            if (res > m) return 2; // greater than m
        }
        
        if (res == m) return 1; // equal to m
        return 0;               // less than m
    }
  
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            long long val = power(mid, n, m);
            
            if (val == 1) return mid;
            else if (val == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return -1;
    }
};