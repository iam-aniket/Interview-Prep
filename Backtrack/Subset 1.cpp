#define rep(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) 
    {
        vector<vector<int>> ans;
        
        sort(a.begin(),a.end());
        
        vector<int> temp;
        
        backtrack(ans,temp,a,0);
        
        return ans;
    }
    void backtrack(vector<vector<int>>& ans,vector<int> temp,vector<int> a,int start)
    {
        ans.pb(temp);
        for(int i = start;i < a.size();i++)
        {
            temp.pb(a[i]);
            backtrack(ans,temp,a,i+1);
            temp.pop_back();
        }
    }
};
