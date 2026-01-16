class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();

        sort(arr.begin(),arr.end());

        for(int i = 0; i < n; i++){
            int l=i+1, h=n-1;
        
        if(i > 0 && arr[i] == arr[i-1]) continue;

            while(l<h){
                if(arr[i]+arr[l]+arr[h] == 0){
                    ans.push_back({arr[i],arr[l],arr[h]});
                    l++; h--;
                    while(l<h && arr[l] == arr[l-1]) l++;
                }else if(arr[i]+arr[l]+arr[h] > 0){
                    h--;
                }else {
                    l++;
                }
            }
        }
        return ans;
    }
};
