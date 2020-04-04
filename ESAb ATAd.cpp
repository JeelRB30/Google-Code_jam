// @uthor........ _|EE|_

#include<bits/stdc++.h>
#define int long long
#define double long double
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define u_set unordered_set<int>
#define pb push_back
#define M 1000000007
#define BRISK ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

void My_fun(string& s){
    for(int i=0;i<(int)s.size();i++){
      if(s[i]=='0')s[i]='1';
      else if(s[i]=='1')s[i]='0';
    }
}

signed main()
{
    int t,n;
    cin>>t>>n;
    while(t--){
      int r=-1,c=-1;
      char x,y;
      string s(n,'!');
      for(int i=1,j=0;j<n/2;i+=2){
        if(i>10 && i%10==1){
            if(c!=-1){
                cout<<c+1<<endl;
                cin>>x;
                if(s[c]!=x)My_fun(s);
            }
            else{
              cout<<"1\n";
              cin>>x;
            }
            if(r!=-1){
              cout<<r+1<<endl;
              cin>>x;
              if(s[r]!=x)reverse(s.begin(),s.end());
            }
            else{
              cout<<"1\n";
              cin>>x;
            }
        }else{
            cout<<j+1<<endl;
            cin>>s[j];
            cout<<n-j<<endl;
            cin>>s[n-1-j];
            if(s[j]==s[n-1-j])c=j;
            else if(s[j]!=s[n-1-j])r=j;
            j++;
        }
      }
      cout<<s<<endl;
      cin>>y;
      if(y=='N')return 0;
    }
}
