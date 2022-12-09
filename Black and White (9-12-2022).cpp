//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

long long numOfWays(int N, int M)
{
    int checker[8][2] = {{1,2},{2,1},{-2,1},{1,-2},{-1,2},{2,-1},{-2,-1},{-1,-2}};
    long long sqrs = (N*M);
    long long MOD = 1000000007;
    long long ans = 0;
    int inv;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i>=2&&j>=2&&(N-i)>=3&&(M-j)>=3) inv = 8;
            else {
                int cnt = 0;
                for(int a=0;a<8;a++){
                    int nx = checker[a][0]+i;
                    int ny = checker[a][1]+j;
                    if(nx>=0 && nx<N && ny>=0 && ny<M) cnt++;
                }
                inv = cnt;
            }
            ans = (ans+(sqrs-inv-1));
        }
    }
    return ans%MOD;
    // write code here
}
