#include <bits/stdc++.h>
 
#define forn(i, n) for( int i=0;i<n;i++)
#define ll long long
using namespace std;
 
 
int main(){
     int test;
    cin>>test;
 
    while(test--){
        int n;
        cin>>n;
 
        int a[n];
        forn(i,n){
            cin>>a[i];
        }
        //sort(a,a+n);
 
        //  if(n==1){
        //      cout<<1;
        //      continue;
        //  }
 
        int maxm = 0;
        int j=1;
        forn(i,n){
            //if(n==1)
            
            if(i<n-1){
                if(a[i]==a[i+1]){
                    j++;
                }
                else{j=1;}
                maxm = max(maxm, j);
                
            }
        }
        
        if(maxm!=0){
            cout<<maxm<<endl;
        }
        else
            cout<<j<<endl;
        //sort(b, b+n);
        
    }
 
    return 0;
}
