#include<bits/stdc++.h>
using namespace std;
vector<int>kmp(string &s){
    int n=s.size(),len=0;
    vector<int>lps(n,0);
    for(int i=1;i<n;){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0)len=lps[len-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int main(){
    //freopen("input.txt","r",stdin);
    string a,b;
    cin>>a>>b;
    vector<int>lps=kmp(b);
    int ans=0,i=0,j=0,n=a.size(),m=b.size();
    while(i<n){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        if(j==m){
            ans++;
            j=lps[j-1];
        }
        else if(i<n && a[i]!=b[j]){
            if(j!=0)j=lps[j-1];
            else i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
