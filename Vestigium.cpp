// @uthor........ _|EE|_

#include<bits/stdc++.h>
#define int long long
#define double long double
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define set set<int>
#define u_set unordered_set<int>
#define pb push_back
#define M 1000000007
#define endl "\n"
#define BRISK ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main()
{
    BRISK;
    int t;
    cin>>t;
    int z=1;
    while(t--){
      int n;
      cin>>n;
      int a[n][n];
      int trace=0;
      int r=0, c=0;
      for(int i=0;i<n;i++){
        set s;
        for(int j=0;j<n;j++){
          cin>>a[i][j];
          if(i==j)trace+=a[i][j];
          s.insert(a[i][j]);
        }
        if(s.size()<n)r++;
      }
      for(int i=0;i<n;i++){
        set s;
        for(int j=0;j<n;j++){
          s.insert(a[j][i]);
        }
        if(s.size()<n)c++;
      }
      cout<<"Case #"<<z<<": "<<trace<<" "<<r<<" "<<c<<endl;
      z++;
    }
}
