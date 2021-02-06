#include <bits/stdc++.h>

#define forn(i, n) for( int i=0;i<n;i++)
#define ll long long
using namespace std;


int main(){
     int test;
    cin>>test;

    while(test--){
        int x,y;
        cin>>x>>y;
        
        string s;
        cin>>s;
        
        int r=0,l=0,d=0,u=0;
        forn(i,s.size()){
            if(s[i]=='R')
                r++;
            else if(s[i]=='L')
                l++;
            else if(s[i]=='U')
                u++;
            else if(s[i]=='D')
                d++;
        }
        
        // if(x==0 && y==0){
        //     cout<<"YES"<<endl;
        //     //continue;
        // }
         if(x<0 && y<0){
            if(abs(x)<=l && abs(y)<=d)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x<0 && y>0){
            if(abs(x)<=l && y<=u)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x>0 && y<0){
            if(x<=r && abs(y)<=d)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x>0 && y>0){
            if(x<=r && y<=u)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x==00 && y>0){
            if(y<=u)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x==0 && y<0){
            if(x<=r && abs(y)<=d)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x>0 && y==0){
            if(x<=r)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        else if(x<0 && y==0){
            if(abs(x)<=l)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            //continue;
        }
        
    }

    return 0;
}
