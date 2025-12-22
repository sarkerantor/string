#include<bits/stdc++.h>
using namespace std;
vector<string>duval(string s){
    int n=s.size(),i=0;
    vector<string>res;
    while(i<n){
        int j=i+1,k=i;
        while(j<n && s[k]<=s[j]){
            if(s[k]<s[j])k=i;
            else k++;
            j++;
        }
        int len=j-k;
        while(i<=k){
            res.push_back(s.substr(i,len));
            i+=len;
        }
    }
    return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    vector<string>lyndon=duval(s);
    for(string val:lyndon)cout<<val<<" ";
    return 0;
}
