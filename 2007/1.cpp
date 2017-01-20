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
    cout << "push" << " " <<str <<endl;
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
bool used[101];
queue<int> Q;
vector<int> clasters;

void bfs(int st){
  if(used[st])  return;

  int cnt = 1;
  Q.push(st);
  used[st] = true;
  while(!Q.empty()){
    st = Q.front(); Q.pop();

    rep(i,G[st].size()){
      if(!used[G[st][i]]){
        Q.push(G[st][i]);
        cout << "Push " << G[st][i] << endl;
        used[G[st][i]] = true;
        cnt += 1;
      }
    }
  }
  clasters.pb(cnt);

}

int main() {
  DisJointSet dj(100);
  vector<string> edges;
  vector<string> splitedEdges;
  memset(used,false,sizeof(used));

  fileReader("edges.txt",edges);
  rep(i,181){
      split(edges[i]," ",splitedEdges);
      G[string_to_int(splitedEdges[0])].pb(string_to_int(splitedEdges[1]));
      G[string_to_int(splitedEdges[1])].pb(string_to_int(splitedEdges[0]));
  }

  for(int i = 1; i < 101 ; i++){
    bfs(i);
  }

  sort(clasters.begin(),clasters.end());
  reverse(clasters.begin(),clasters.end());
  rep(i,clasters.size()){
    cout << clasters[i] << endl;
  }

  return 0;
}
