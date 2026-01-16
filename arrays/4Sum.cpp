class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        set<vector<int>>s;
        vector<vector<int>>ans;
        vector<int>rev;

        sort(arr.begin(), arr.end());

        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                
                int l = j+1, h = n-1;
                long long alpha = arr[i]+arr[j];
                long long left = target - alpha;

                while(l<h){
                    long long sum = arr[l]+arr[h];
                    if( sum > left){
                        h--;
                    }else if(sum < left){
                        l++;
                    }else{
                        rev.push_back(arr[i]);
                        rev.push_back(arr[j]);
                        rev.push_back(arr[l]);
                        rev.push_back(arr[h]);

                        if(s.find(rev) == s.end()){
                            ans.push_back(rev);
                            s.insert(rev);
                           
                        }
                        rev.clear();
                        l++;
                        h--;
                    
                    while(l<h && arr[l] == arr[l-1])l++;
                    while(l<h && arr[h] == arr[h+1])h--;
                    }
                }
                    
                    
                
            }
        }
        return ans;
    }
};
