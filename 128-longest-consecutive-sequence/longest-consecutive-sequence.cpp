class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int val : nums){
            s.insert(val);
        }
        int val = *s.begin();
        int max_count = INT_MIN;
        int count = 0;
        for(int i:s){
            if(i == val){
                count++;
                val++;
            }else{
                val = i+1;
                max_count = max(max_count,count);
                count =1;
            }
        }

        return max(max_count,count);
    }
};