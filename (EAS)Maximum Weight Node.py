#User function Template for python3

class Solution():

    def maxWeightCell(self, N, Edge):
        ans = []
        ans = [0 for i in range(N)]
        for i in range(N):
            if (Edge[i] != -1):
                ans[Edge[i]] = ans[Edge[i]] + i
        tar = max(ans)
        res = 1
        for i in range(N-1,-1,-1):
            if(tar == ans[i]):
                res = i
                break
        return res
        #your code goes here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        N = int(input())
        Edge = [int(i) for i in input().split()]
        obj = Solution()
        ans=obj.maxWeightCell(N, Edge);
        print(ans)

# } Driver Code Ends
