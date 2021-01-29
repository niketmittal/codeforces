#include <bits/stdc++.h>

#define forn(i, n) for( int i=0;i<n;i++)
#define ll long long
using namespace std;


int main(){
     int test;
    cin>>test;

    while(test--){
        long int n,k;
        cin>>n>>k;
        
        if(n==1 || k==1){
            cout<<k<<endl;
            //continue;
        }
        else if(n==k || (n>k && n%k==0)){
            cout<<1<<endl;
            //continue;
        }
        else if(n>k){
            int r = n%k;
            cout<<2<<endl;
            //continue;
        }
        else if(n<k && k%n!=0){
            int c=k/n;
            cout<<c+1<<endl;
            //continue;
        }
        else{
            cout<<k/n<<endl;
        }
        
    }

    return 0;
}
