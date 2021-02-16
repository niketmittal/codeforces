#include <bits/stdc++.h>

#define forn(i, n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;


int main(){
     int t;
     cin>>t;
     
     while(t--){
            int n;
            cin>>n;
            
            int a[n];
            forn(i,n)
                cin>>a[i];
              
            int d=0, b=0, c=0;
            int maxm = n/3;
            int count=0;
            forn(i,n){
                if(a[i]%3 == 0 && d < maxm){
                    d++;
                    continue;
                } 
                else if(a[i]%3 == 1 && b < maxm){
                    b++;
                    continue;
                }
                else if(a[i]%3 == 2 && c < maxm){
                    c++;
                    continue;
                }
                else{
                    count++;
                    a[i]++;
                    //cout<<a[i]<<" ";
                    i--;
                    continue;
                }
            }
            cout<<count<<endl;
     }

    return 0;
}
