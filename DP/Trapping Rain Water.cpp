class Solution 
{
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if(n == 0 || n == 1)return 0;
        int left[30001] = {0},right[30001] = {0};
        left[0] = a[0];right[n-1] = a[n-1];
        
        for(int i = 1; i < n; i++)
            left[i] = max(left[i-1],a[i]); 
        for(int i = n-2; i >= 0; i--)
            right[i] = max(right[i+1],a[i]);
        
        for(int i = 0; i < n; i++)
            cout<<left[i]<<" ";
        cout<<"\n";
        
        for(int i = 0; i < n; i++)
            cout<<right[i]<<" ";
        cout<<"\n";
        
        int water = 0;
        for(int i = 0; i < n; i++)
            water+=min(left[i],right[i]) - a[i];
        return water;
    }
};
