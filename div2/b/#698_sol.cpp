#include <bits/stdc++.h>
 
#define forn(i, n) for( int i=0;i<n;i++)
#define ll long long
using namespace std;
 
 
int main(){
     int test;
    cin>>test;
 
    while(test--){
        int q, d;
        cin>>q>>d;
        
        long int a[q];
        forn(i,q){
            cin>>a[i];
        }
        
        int flag=0;
        for(int i=0; i<q; i++){
            if(d==1){
                 cout<<"YES"<<endl;
                //flag=1;
                continue; 
            }
            if(a[i]<d){
                cout<<"NO"<<endl;
                continue;
            }
            if(a[i]==d || a[i]%10==d || (a[i]/10)%10==d || (a[i]/100)%10==d || (a[i]/1000)%10==d || (a[i]/10000)%10==d || (a[i]/100000)%10==d || (a[i]/1000000)%10==d || (a[i]/10000000)%10==d || (a[i]/100000000)%10==d || (a[i]/1000000000)%10==d){
                cout<<"YES"<<endl;
                //flag=1;
                continue;
            }
            else if(a[i]/d == 0){
                cout<<"YES"<<endl;
                //flag=1;
                continue;
            }
            else if(a[i]>0){
                while(a[i]>0){
                    a[i] -= d;
                    if(a[i]==d || a[i]%10==d || (a[i]/10)%10==d || (a[i]/100)%10==d || (a[i]/1000)%10==d || (a[i]/10000)%10==d || (a[i]/100000)%10==d || (a[i]/1000000)%10==d || (a[i]/10000000)%10==d || (a[i]/100000000)%10==d || (a[i]/1000000000)%10==d){
                        cout<<"YES"<<endl;
                        flag=1;
                        break;
                    }
                    else if(a[i]<0){
                        cout<<"NO"<<endl;}
                }
            }
        }
    }
    
 
    return 0;
}
