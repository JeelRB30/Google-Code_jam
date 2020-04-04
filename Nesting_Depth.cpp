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

int parent[101], Size[101];

int find_set(int x)
{
  if(x==parent[x])return x;
  return parent[x] = find_set(parent[x]);
}

void Union(int x,int y)
{
  x = find_set(x);
  y = find_set(y);
  if(Size[x]>Size[y]){
    parent[y] = parent[x];
    Size[x]+=Size[y];
  }else{
    parent[x] = parent[y];
    Size[y]+=Size[x];
  }
}

signed main()
{
    BRISK;
    int t;
    cin>>t;
    int z=1;
    while(t--){
      string s;
      cin>>s;
      int n = s.length();
      for(int i=1;i<=n;i++){
        parent[i] = i;
        Size[i] = 1;
      }

      for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])Union(i+1,i+2);
      }

      mii mm;
      vector<pair<char,int>> res;
      int c=0;
      for(int i=0;i<n;i++){
        int p = find_set(i+1);
        if(!mm[p]){
          res.pb({s[i],Size[p]});
          mm[p]++;
        }
      }
      vi v(res.size());
      v[0] = res[0].first-'0';
      for(int i=1;i<(int)res.size();i++)v[i] = (res[i].first-'0')-(res[i-1].first-'0');
      for(int i=0;i<(int)res.size();i++)c+=v[i];
      string ans;

      for(int i=0;i<(int)res.size();i++){
        if(v[i]>0)for(int j=0;j<v[i];j++)ans+='(';
        else if(v[i]<0)for(int j=0;j<abs(v[i]);j++)ans+=')';
        for(int j=0;j<res[i].second;j++)ans+=res[i].first;
      }
      for(int i=0;i<c;i++)ans+=')';
      cout<<"Case #"<<z<<": "<<ans<<endl;
      z++;
    }
}
