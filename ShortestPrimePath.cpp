//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> prime;
    Solution(){
        prime.assign(10000,1);
        prime[1]= 0;
        for(int i=2;i<10000;i++){
            for(int j=2*i;j<10000;j+=i){
                prime[j] = 0;
            }
        }
    }
  
    int shortestPath(int Num1,int Num2)
    {   
        vector<int> vis(10000,-1);
        queue<int> q;
        q.push(Num1);
        vis[Num1] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            string str = to_string(curr);
            for(int i=0;i<4;i++){
                string str1 = str;
                int ind = 0;
                if(i==0) ind = 1;
                else ind = 0;
                for(int j = ind ; j < 10;j++){
                    str1[i] = '0' + j;
                    int y = stoi(str1);
                    if(prime[y] && vis[y]==-1){
                        vis[y] = 1 + vis[curr];
                        q.push(y);
                    }
                    if(y==Num2) return vis[Num2]-1;
                }
            }
        }
        return vis[Num2]-1;
        // Complete this function using prime vector
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends
