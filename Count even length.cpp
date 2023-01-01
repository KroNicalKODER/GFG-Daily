//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	unsigned long long power(unsigned long long x,int y, int p){
	unsigned long long res = 1;

	x = x % p; 
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

unsigned long long modInverse(unsigned long long n,int p){
	return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,int r, int p){
	if (n < r)	return 0;
	if (r == 0)	return 1;
	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;
}

	int compute_value(int n)	{
	    return nCrModPFermat(2*n, n, 1000000007);
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
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
