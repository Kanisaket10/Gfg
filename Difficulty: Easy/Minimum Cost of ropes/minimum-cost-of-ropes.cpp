//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        long long cost =0;
        
        // MinHeap
        priority_queue<long long, vector<long long>, greater<long long>> p;
        for(long long i=0; i<arr.size(); i++){
            p.push(arr[i]);
        }
        
        while(p.size() > 1){
            long long rope =p.top();    // first smallest element
            p.pop();
            rope += p.top();           // second smallest element
            p.pop();
            cost += rope; 
            p.push(rope);             // push the new element
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends