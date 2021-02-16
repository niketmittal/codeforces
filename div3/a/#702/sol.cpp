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
              
             int count=0;  
            forn(i,n-1){
                double maxm = max(a[i], a[i+1]);
                double minm = min(a[i], a[i+1]);
                if(maxm/minm <=2)
                    continue;
                else{
                    count++;
                    if(a[i] == maxm){
                        if(a[i]%2 == 0)
                            a[i] /= 2;
                        else
                            a[i] = (a[i]+1)/2;
                    }
                    else{
                        a[i] *= 2;
                    }
                    //cout<<a[i]<<" ";
                    i--;
                }
            }
            cout<<count<<endl;
     }

    return 0;
}
