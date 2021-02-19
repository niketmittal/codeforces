//gave TLE at testcase 5
#include <bits/stdc++.h>

#define forn(i, n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;


int solve(int a[], int l, int r){
    
    int temp[r-l];
    int i=0;
    for(int j=l; j<r; j++){
        if(i==r-l)
            break;
        temp[i] = a[j];
        i++;
    }
    
    
    
    int s = r-l;
    int med = (s-1)/2;
    sort(temp, temp+s);
    
    // forn(i,r-l){
    //     cout<<temp[i]<<"-";
    // }
    // cout<<endl;
    
    // cout<<med<<" ";
   return temp[med]; 
}

int main(){
     
            int n, k;
            cin>>n>>k;
            
            int a[n];
            forn(i,n){
                cin>>a[i];
            }
            
            int med, ans, med2;
            if(n==k){
                med = (n-1)/2;
                cout<<a[med];
            }
            // else if(k==1){
            //     cout<<a[n-1];
            // }
            else{
                med = (n-1)/2;
                int maxm = 0;
                for(int i=0; i<n; i++){
                    for(int j=i+k; j<=n; j++){
                        med2 = solve(a,i,j);
                        //cout<<med2<<" ";
                        if(med2>maxm)
                            maxm = med2;
                    }
                }
                cout<<maxm;
            }
            

    return 0;
}
