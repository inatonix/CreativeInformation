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

int max_d = 0;
int max_v;

void bfs(int s){
  queue<int> Q; bool used[MAX];
  memset(used,false,sizeof(used));
  max_d = 0;

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
        if(d[G[u][v]] > max_d) {
          max_d = d[G[u][v]];
          max_v = G[u][v];
        }
      }
    }
  }

  cout << "max_d = " << max_d << " max_v = " << max_v << endl;
}


int main() {
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

  bfs(1);
  bfs(max_v);
  int defaultMax = max_d;

  for(int i = 202; i < 4951; i++){
    split(edges[i]," ",splitedEdges);
    G[string_to_int(splitedEdges[0])].pb(string_to_int(splitedEdges[1]));
    G[string_to_int(splitedEdges[1])].pb(string_to_int(splitedEdges[0]));

    bfs(1);
    bfs(max_v);

    if(defaultMax != max_d){
      cout << i << " " << max_d << endl;
      defaultMax = max_d;
    }
  }

  cout << "end" << endl;
  return 0;
}
