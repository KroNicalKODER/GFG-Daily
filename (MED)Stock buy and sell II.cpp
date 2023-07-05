class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int buy = INT_MAX;
        int sell = 0;
        int ans = 0;
        for(auto itr : prices){
            if(itr > buy) ans += (itr - buy);
            buy = itr;
        }
        return ans;
        // code here
    }
};
