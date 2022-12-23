//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

 int f(int i , int j, int arr[], vector<vector<int>>&memo)
 {
     if(i == j)
     return 0;
     if(memo[i][j] != -1)
     return memo[i][j];
     
     int minSteps = 1e9;
     
     for(int k = i; k<=j-1;k++)
     {
         int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,memo) + f(k+1,j,arr,memo);
         
         minSteps = min(minSteps,steps);
     }
    return memo[i][j] = minSteps;
 }

    int matrixMultiplication(int N, int arr[])
    { 
        vector<vector<int>>memo(N,vector<int>(N,-1));
        return f(1,N-1,arr,memo);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends