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
      int n,x,y;
      cin>>n;
      vector<pair<pair<int,int>,int>> v;
      mii mm;
      for(int i=0;i<n;i++){
        cin>>x>>y;
        v.pb({{x,y},i});
      }
      sort(v.begin(),v.end());
      set<pair<int,int>> s;
      s.insert({v[0].first.first,v[0].first.second});
      mm[v[0].second] = 1;
      for(int i=1;i<n;i++){
        auto j = s.begin();
        auto k = s.rbegin();
        if(v[i].first.second<=(*j).first){
          s.insert({v[i].first.first,v[i].first.second});
          mm[v[i].second] = 1;
        }else if(v[i].first.first>=(*k).second){
          s.insert({v[i].first.first,v[i].first.second});
          mm[v[i].second] = 1;
        }else{
          vpi res;
          for(auto l:s)res.pb({l.first,l.second});
          for(int l=1;l<(int)res.size();l++){
            if(v[i].first.first>=res[l-1].second && v[i].first.second<=res[l].first){
              s.insert({v[i].first.first,v[i].first.second});
              mm[v[i].second] = 1;
              break;
            }
          }
        }
      }
      set<pair<int,int>> st;
      for(int i=0;i<n;i++){
        if(!mm[v[i].second] && st.size()==0){
          st.insert({v[i].first.first,v[i].first.second});
          mm[v[i].second] = 2;
        }else if(!mm[v[i].second] && st.size()!=0){
          auto j = st.begin();
          auto k = st.rbegin();
          if(v[i].first.second<=(*j).first){
            st.insert({v[i].first.first,v[i].first.second});
            mm[v[i].second] = 2;
          }else if(v[i].first.first>=(*k).second){
            st.insert({v[i].first.first,v[i].first.second});
            mm[v[i].second] = 2;
          }else{
            vpi res;
            for(auto l:st)res.pb({l.first,l.second});
            for(int l=1;l<(int)res.size();l++){
              if(v[i].first.first>=res[l-1].second && v[i].first.second<=res[l].first){
                st.insert({v[i].first.first,v[i].first.second});
                mm[v[i].second] = 2;
                break;
              }
            }
          }
        }
      }
      int flag = 0;
      for(int i=0;i<n;i++){
        if(!mm[i]){
          flag++;
          break;
        }
      }
      if(flag!=0)cout<<"Case #"<<z<<": "<<"IMPOSSIBLE"<<endl;
      else{
        cout<<"Case #"<<z<<": ";
        for(int i=0;i<n;i++){
          if(mm[i]==1)cout<<"C";
          else cout<<"J";
        }
        cout<<endl;
      }
      z++;
    }
}
