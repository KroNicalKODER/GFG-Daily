//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isSafe(int x,int y,int n){
        if(x>=0 && x<n && y>=0 && y<n) return true;
        return false;
    }
    bool isGood(vector<vector<int>>& matrix,int i,int j,long long ans){
        int n = matrix.size();
        long long diagSum1 = 0,diagSum2 = 0;
        for(int i=0;i<n;i++) (matrix[i][i]==0) ? diagSum1+=ans :diagSum1+=matrix[i][i];
        for(int i=0;i<n;i++) (matrix[i][n-i-1]==0) ? diagSum2+=ans : diagSum2+=matrix[i][n-i-1];
        vector<long long> rowSum(n,0);
        vector<long long> colSum(n,0);
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                (matrix[i][j]==0) ? rowSum[i]+=ans : rowSum[i]+=matrix[i][j];
                (matrix[i][j]==0) ? colSum[j]+=ans : colSum[j]+=matrix[i][j];
            }
        }
        bool rowEq = true;
        bool colEq = true;
        for(int i=0;i<n-1;i++){
            if(rowSum[i]!=rowSum[i+1]) rowEq = false;
            if(colSum[i]!=colSum[i+1]) colEq = false;
        }
        if(rowEq && colEq && diagSum1==diagSum2) return true;
        else return false;
    }
    long long int MissingNo(vector<vector<int> >& matrix) {
        int x,y;        int n = matrix.size();
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    x = i;
                    y = j;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        long long rowSum1 = 0;
        for(int i=0;i<matrix.size();i++){
            rowSum1+=matrix[x][i];
        }
        int nx;
        if(x==n-1) nx=x-1;
        else nx = x+1;
        long long rowSum2 = 0;
        for(int i=0;i<n;i++){
            rowSum2+=matrix[nx][i];
        }
        long long ans = abs(rowSum2-rowSum1);
        if(isGood(matrix,x,y,ans)&&ans!=0) return ans;
        else return -1;
        
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
