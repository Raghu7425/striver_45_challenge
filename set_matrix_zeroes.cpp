#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       
       vector<int>row(m,0);
       vector<int>col(n,0);
       
       for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){
               if(matrix[i][j]==0){
                   row[i]=1;
                   col[j]=1;
               }
           }
       }
       
       for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){
               if(row[i]==1 || col[j]==1){
                   matrix[i][j]=0;
               }
           }
       }
    }
};

//optimized approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        for(int i=0; i<m; i++){
            if(matrix[0][i]==0){
                firstRowZero=true;
            }
        }
        
        for(int j=0; j<n; j++){
            if(matrix[j][0]==0){
                firstColZero=true;
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(firstRowZero){
            for(int i=0; i<m; i++){
                matrix[0][i]=0;
            }
        }
        
        if(firstColZero){
            for(int j=0; j<n; j++){
                matrix[j][0]=0;
            }
        }
    }
};

