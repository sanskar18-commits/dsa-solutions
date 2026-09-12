class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int>m;
        int largest = 0;
        int left = 0;
       

        for(int right=0; right<s.length(); right++){
            
            m[s[right]]++;

            while(m[s[right]] > 1){
                m[s[left]]--;
                left++;
            }

            largest = max(largest, right-left+1);
        }
       return largest;
    }
};