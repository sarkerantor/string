#include<bits/stdc++.h>
using namespace std;
string longestpalindrome(string s){
    string t="#";
    for(char c:s){
        t+=c;
        t+="#";
    }
    int n=t.size(),center=0,right=0,centeridx=0,mxlen=0;
    vector<int>p(n,0);
    for(int i=1;i<n-1;i++){
        int mirror=2*center-i;
        if(i<right)p[i]=min(right-i,p[mirror]);
        int a=i+p[i]+1;
        int b=i-p[i]-1;
        while(a<n && b>=0 && t[a]==t[b]){
            a++;
            b--;
            p[i]++;
        }
        if(p[i]>mxlen){
            mxlen=p[i];
            centeridx=i;
        }
        if(i+p[i]>right){
            center=i;
            right=i+p[i];
        }
    }
    int start=(centeridx-mxlen)/2;
    return s.substr(start,mxlen);
}
int main(){
    string s;
    cin>>s;
    cout<<longestpalindrome(s)<<endl;
    return 0;
}
