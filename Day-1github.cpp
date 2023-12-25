#include<bits/stdc++.h>
 using namespace std;

 int numDecoding(string s){
    
       if(s.empty()  || s[0] == '0'){
           return 0;
       }
       int n = s.length();

       vector<int> dp(n+1 ,  0);
      dp[0] = 1;
      dp[1] = 1;

      for(int i = 2; i<=n; i++){
          if(s[i-1] >= '1' && s[i-1] <= '9'){
              dp[i] += dp[i-1];
          }
          int twoDigit = stoi(s.substr(i-2, 2));
          if( 10 <=twoDigit && twoDigit <= 26){
              dp[i] += dp[i-2];
          }
      }
       
 return dp[n];

 }

int main(){
    int t;
    cin>>t; 
     while(t--){
        string s;
        cin>>s;

        int result = numDecoding(s);
        cout << result << endl;

     }
return 0;}
