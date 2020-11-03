class Solution {
public:
    bool canJump(vector<int>& a) 
    {
        int reach = 0;//Maximum pos that can be reached
        if(a.size() == 1 )return true; 
        for(int i = 0; i < a.size() && i <= reach; i++)
            reach = max(i+a[i],reach);
        return reach >= a.size()-1;        
    }
};
