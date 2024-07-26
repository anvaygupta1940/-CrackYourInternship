class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int elem=-1;
        
        
        for(auto it : nums)
        {
            if(cnt==0) elem=it;
            
            if(elem==it) cnt++;
            else cnt--;
        }
        
        return elem;
    }
};