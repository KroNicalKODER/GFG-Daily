//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    bool opSign(int a,int b){
        if((a>0&&b<0)) return true;
        else return false;
    }
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        
        st.push(asteroids[0]);int q=1;
        if(asteroids[0]<0){
            for(q=1;q<N;q++){
                if(asteroids[q] < 0) st.push(asteroids[q]);
                else break;
            }
        }
        for(int i=q;i<N;i++){
            int curr = asteroids[i];
            int frmIf = 1;
            
            while(!st.empty()&&opSign(st.top(),curr)){
                int currv = abs(curr);
                int stv = abs(st.top());
                if(stv < currv){
                    st.pop();
                    frmIf = 1;
                }
                else if(stv == currv) {
                    st.pop();
                    frmIf = 0;
                    break;
                }
                else{
                    frmIf = 0;
                    break;
                }
            }
            if(frmIf==1) st.push(curr);
        }
        vector<int> ans;
        while(!st.empty()){
            int curr = st.top();st.pop();
            ans.push_back(curr);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
