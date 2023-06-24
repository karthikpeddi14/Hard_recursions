class Solution{
public:
    bool ispalindrome(string s , int start , int end)
    {
        while(start <= end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void partdontpart (string s , int& ans , int index ,int& fin_ans)
    {
        if(ans > fin_ans) return;
        for(int i=index ; i<s.size() ; i++)
        {
            if(ispalindrome(s,index , i)) 
            {
                if(i==s.size()-1) 
                {
                   fin_ans = min(fin_ans,ans); 
                   return;
                }
                ans = ans+1;
                partdontpart(s,ans,i+1,fin_ans);
                ans = ans-1;
            }
        }
    }
    int palindromicPartition(string str)
    {
        int ans =0;
        int fin_ans = str.size()-1;
        partdontpart(str,ans,0,fin_ans);
        return fin_ans;
    }
};
