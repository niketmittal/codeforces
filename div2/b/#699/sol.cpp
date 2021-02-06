#include <bits/stdc++.h>

#define forn(i, n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;


int main(){
     int test;
    cin>>test;

    while(test--){
        long int n, k;
        cin>>n>>k;
        
        int h[n];
        forn(i,n)
            cin>>h[i];
            
        int pos, flag=0, temp=0;
        while(k--){
            
            if(temp==n){
                break;
            }
            pos = 1;
            for(int i=0; i<n; i++){
                if(pos==n){
                    temp = n;
                    break;
                }
                if(h[i]<h[i+1]){
                    //cout<<h[i];
                    h[i]++;
                    break;
                }
                else{
                    pos++;
                    continue;
                }
            }
        }
        if(pos<n)
            cout<<pos<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}
