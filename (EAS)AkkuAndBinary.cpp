//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
set<long long> nums;
    void precompute()
    {
        for(int i=0;i<63;i++){
            for(int j=i+1;j<63;j++){
                for(int k = j+1;k<63;k++){
                    long long num = 0;
                    num = pow(2,i) + pow(2,j) + pow(2,k);
                    if(num>0) nums.insert(num);
                    if(num<0) break;
                }
            }
        }
        // Code Here
    }
    
    long long solve(long long l, long long r){
        int ans=0;
        for(auto itr : nums){
            if(itr >=l&&itr<=r) ans++;
        }
        return ans;
        // Code Here
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends
