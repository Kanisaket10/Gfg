//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    
    string rotate_clockwise(string s){
        char first = s[0], second = s[1];
        
        int i=0;
        while(i < s.size()-2){
           s[i] = s[i+2];
           i++;
        }
        s[i]=first;
        s[i+1]=second;
        return s;
    }
    string rotate_anticlockwise(string s){
        int n= s.size()-1;
        char first = s[n-1], second = s[n];
        
        int i=n-2;
        while(i >=0){
           s[i+2] = s[i];
           i--;
        }
        s[0]=first;
        s[1]=second;
    return s;    
    }
    
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size() <=1) return str1==str2;
       
        string ans =rotate_clockwise(str1);
        if(str2 == ans) return 1;
        string ans2 = rotate_anticlockwise(str1);
       
        if(str2 == ans2) return 1;
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends