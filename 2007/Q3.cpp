#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <math.h>
#include <set>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back
const static int MAX = 10000;
const static int INF = 1000000;

typedef pair<int, int> P;
typedef pair<P, int> PP;

class DisJointSet {
public:
  vector<int> rank,p;

  DisJointSet(){}
  DisJointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
    for(int i = 0; i < size; i++) makeSet(i);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y){
    return findSet(x) == findSet(y);
  }

  void unite(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if( rank[x] > rank[y] ){
      p[y] = x;
    }else {
        p[x] = y;
        if( rank[x] == rank[y]){
          rank[y] ++;
        }
    }
  }

  int findSet(int x){
    if ( x != p[x] ){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};


void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
  while(getline(ifs,str)){
  //  cout << "push" << " " <<str <<endl;
    vec.push_back(str);
  }
}

//文字列を任意の文字で分割できる
//split("文字列","分解したい文字",入れる変数)
template <typename List>
void split(const std::string& s, const std::string& delim, List& result)
{
    result.clear();

    using string = std::string;
    string::size_type pos = 0;

    while(pos != string::npos )
    {
        string::size_type p = s.find(delim, pos);

        if(p == string::npos)
        {
            result.push_back(s.substr(pos));
            break;
        }
        else {
            result.push_back(s.substr(pos, p - pos));
        }

        pos = p + delim.size();
    }
}

int string_to_int(std::string str){
  int ret;
  std::stringstream ss;
  ss << str;
  ss >> ret;
  return ret;
}

vector<int> G[MAX];
bool claster_used[100];
vector<int> clasters;
float sum = 0;
int d[MAX];

void bfs(int s){
  queue<int> Q; bool used[MAX];
  memset(used,false,sizeof(used));

  Q.push(s);
  memset(d,INF,sizeof(d));//dはsからの距離
  d[s] = 0; used[s] = true;
  int u;
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    rep(v,G[u].size()){
      if(!used[G[u][v]]){
        Q.push(G[u][v]);
        used[G[u][v]] = true;
        d[G[u][v]] = d[u] + 1;
      }
    }
  }
}

int dis[MAX];

void bfs(int st, int num){
  queue<int> Q;
  memset(dis,0,sizeof(dis));
  int cnt = 1;
  Q.push(st);
  dis[st] = 0;
  while(!Q.empty()){
    st = Q.front(); Q.pop();
    rep(i,G[st].size()){
    //  cout << G[st][i] << " ";
    //  cout << "d[" << st << "] = " << d[st] << endl;
      dis[G[st][i]] = dis[st] + 1;
      Q.push(G[st][i]);
      if(G[st][i] == 63){
        cout << "G" << num << " = " << dis[G[st][i]] << endl;
        return;
      }

    }
    //cout << endl;
  }
}


int main() {
  DisJointSet dj(101);
  bool succeedFlag = true;

  vector<string> edges;
  vector<string> splitedEdges;
  fileReader("edges.txt",edges);
  int cnt = 0;
  rep(i,202){
      split(edges[i]," ",splitedEdges);
      G[string_to_int(splitedEdges[0])].pb(string_to_int(splitedEdges[1]));
      G[string_to_int(splitedEdges[1])].pb(string_to_int(splitedEdges[0]));
  }

  float s = 0;

  bfs(27,3);
  bfs(1);
  for(int i = 1; i < 101; i++){
  //  cout << "i = " <<  i << " " << d[i] << endl;
    s += d[i];
  }

  cout << " average = " <<  s/100 << endl;

  for(int i = 202; i < 302 ; i++){
    split(edges[i]," ",splitedEdges);
    G[string_to_int(splitedEdges[0])].pb(string_to_int(splitedEdges[1]));
    G[string_to_int(splitedEdges[1])].pb(string_to_int(splitedEdges[0]));
  }

  s = 0;
  bfs(27,4);
  bfs(1);
  for(int i = 1; i < 101; i++){
    s += d[i];
  }

  cout << " average = " <<  s/100 << endl;

  return 0;
}
