#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> generate(int numrows) {
        
        vector<vector<int>>triangle;
        
        for(int i=0; i<numrows; i++){
            vector<int>rows(i+1,1);
            for(int j=0; j<i; j++){
                rows[j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
            triangle.push_back(rows);
        }
    return triangle;
    }
    
};