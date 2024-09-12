//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string sort(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    }
return 0;
}




// } Driver Code Ends


string sort(string s){
    //complete the function here
    vector<int> alp(26,0);
    
    for(int i=0; i<s.size(); i++){
        alp[s[i]-'a']++;
    }
    s ="";
    for(int i=0; i<26; i++){
        while(alp[i]){
            s +='a'+i;
            alp[i]--;
        }
    }
    
    return s;
}