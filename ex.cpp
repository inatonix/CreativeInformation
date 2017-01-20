#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back
static const int INF = 1000000;
static const int MAX = 1000;

typedef pair<int, int> P;
typedef pair<P, int> PP;



struct edge{ int to, cap, rev;};
bool used[MAX];
vector<edge> G[MAX];

int dfs(int s, int t, int f){
  if(s == t) return f;
  used[s] = true;
  rep(i,G[s].size()){
    edge &e = G[s][i];
    if (!used[e.to] && e.cap > 0){
      int d = dfs(e.to,t,min(f,e.cap));
      if (d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow = 0;
  while(true){
    memset(used,0,sizeof(used));
    int f = dfs(s,t,INF);
    if (f == 0) return flow;
    flow += f;
  }
}


int main(void){
  int V,E; cin >> V >> E;
  int a,b,c;
  rep(i,E){
    cin >> a >> b >> c;
    G[a].pb((edge){b,c,G[b].size()});
    G[b].pb((edge){a,0,G[a].size() - 1});
  }

  cout << max_flow(0,V-1) << endl;
  return 0;
}
