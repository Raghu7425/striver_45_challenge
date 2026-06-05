class Solution {
public:
    bool binarySearch(vector<int>&row, int target){
        int low = 0;
        int high = row.size()-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(row[mid]==target){
                return true;
            }

            else if(row[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            if(matrix[i][0]<=target && target<=matrix[i][n-1]){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};