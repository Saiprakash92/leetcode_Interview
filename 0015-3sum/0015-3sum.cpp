class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                break;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
               int  sum = nums[i]+nums[l]+nums[r];
                if(sum>0)
                    r--;
                else if(sum<0)
                    l++;
                else
                {
                   ans.push_back({nums[i],nums[l],nums[r]});
                    int low_last_occurance=nums[l];
                    int right_last_occurance=nums[r];
                    while(l<r&&nums[l]==low_last_occurance)
                        l++;
                    while(l<r&&nums[r]==right_last_occurance)
                        r--;
                }
            }
        }
            return ans;
    }
};