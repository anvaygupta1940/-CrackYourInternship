class Solution {
public:
    bool isPalindrome(int low,int high, string s)
    {
        while(low<=high)
        {
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                if(isPalindrome(i+1,j,s)) return true;
                if(isPalindrome(i,j-1,s)) return true;
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
        
    }
};