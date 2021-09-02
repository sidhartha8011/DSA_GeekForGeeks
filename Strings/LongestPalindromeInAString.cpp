// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
  int pallindrome(string S ,int s ,int l){
      int N=S.length();
      int pass=0,final;
      while(s>=0 && l < N){
          if(S[s]!=S[l])
            break;
        s--;
        l++;
      }
      if(pass)
        final= s*(N+1)+l;
      else
        final=(s+1)*(N+1)+l;
      
      return final;
  }
  
    string longestPalin (string S) {
        // code here
        int s=0,l=1,ci=0,cl=1;
        int so,se;
        int N=S.length();
        for(int i=0;i<N;i++)
        {
            so=pallindrome(S,i-1,i+1);
            se=pallindrome(S,i-1,i);
            
            int evens=se/(N+1);
            int evenl=se%(N+1);
            
            int odds=so/(N+1);
            int oddl=so%(N+1);
            
            if(evenl-evens>oddl-odds){
             //   cout<<"here1";
                ci=evens;
                cl=evenl;
            }
            else
            {
                
               // cout<<"here2";
                ci=odds;
                cl=oddl;
                
            }
            
            if(l-s<cl-ci){
                //cout<<"here3"<<endl;
                //cout<<ci<<" "<<cl;
                s=ci;
                l=cl;
            }
        }
        return S.substr(s,l-s);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
