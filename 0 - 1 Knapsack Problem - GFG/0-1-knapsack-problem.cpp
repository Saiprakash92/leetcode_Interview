//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    //  int solve(int W, int wt[], int val[], int n,vector<vector<int>>&memo){
    //      if(n == 0)
    //      {
    //          if(wt[0] <= W)
    //           return val[0];
    //           return 0;
    //      }
    //      if(memo[n][W] != -1)
    //       return memo[n][W];
    //      int nottake = solve(W,wt,val,n-1,memo);
    //      int take = INT_MIN;
    //      if(wt[n] <= W)
    //      take = val[n] + solve(W-wt[n],wt,val,n-1,memo);
    //      return memo[n][W]  = max(take,nottake);
    //  }
    //tabulation
    //space optimisation
    ///further space optimisation
    int knapSack(int W, int wt[], int val[], int n) 
    { 
         vector<int>prev(W+1,0);
        for(int w = 0;w<=W;w++)
        {
            if(wt[0] <= w)
            prev[w] = val[0];
        }
        for(int ind = 1;ind < n; ind++)
        {
            for(int w = W; w >=0;w--)
            {
             
               if(wt[ind] <= w)
               prev[w] = max(prev[w], val[ind] + prev[w - wt[ind]]);
            }
        }
        
       return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends