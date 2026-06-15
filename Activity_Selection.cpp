class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        
        vector<tuple<int,int,int>>meetings;
        
        for(int i=0; i<start.size(); i++){
            meetings.push_back({finish[i], start[i], i+1});
        }
        
        sort(meetings.begin(), meetings.end());
        
        vector<int>result;
        int lastEnd=-1;
        
        int count = 0;
        
        for(auto  &m: meetings){
            int e = get<0>(m);
            int s = get<1>(m);
            int index = get<2>(m);
            
            if(s > lastEnd){
                count++;
                result.push_back(index);
                lastEnd=e;
            }
        }
        
        return count;
        
    }
};