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
bool claster_used[100];
vector<int> clasters;
float sum = 0;

float claster_variable(int st){
  float k = G[st].size();
  if( k == 1 ) return 0;

  float cnt = 0;
  vector<int> child;
  memset(claster_used,false,sizeof(claster_used));

  rep(i,G[st].size()){
    child.pb(G[st][i]);
    claster_used[G[st][i]] = true;
  }

  rep(i,child.size()){
    rep(j,G[child[i]].size()){
      if(claster_used[G[child[i]][j]])
        cnt += 1;
    }
  }
  cnt /= 2;
  if(cnt == 0) return 0;
//  cout << "st = " << st << " cnt = " << cnt << endl;
  sum += cnt / ((k * (k - 1)) / 2);
  return cnt / ((k * (k - 1)) / 2);

}


int main() {
  DisJointSet dj(101);
  bool succeedFlag = true;

  vector<string> edges;
  vector<string> splitedEdges;
  fileReader("edges.txt",edges);
  int cnt = 0;
  while(true){
      succeedFlag = true;
      split(edges[cnt]," ",splitedEdges);

      G[string_to_int(splitedEdges[0])].pb(string_to_int(splitedEdges[1]));
      G[string_to_int(splitedEdges[1])].pb(string_to_int(splitedEdges[0]));

      dj.unite(string_to_int(splitedEdges[0]),string_to_int(splitedEdges[1]));
      if(cnt >= 100)
        for(int i = 1; i < 101 ; i++){
          if(!dj.same(1,i)){
            succeedFlag = false;
          }
        }

      if(succeedFlag && cnt >= 100){
        cout << "全部達成" << cnt << endl;
        break;
      }
      cnt += 1;
  }

  for(int i = 1; i < 101; i++){
    cout << i << ":" << claster_variable(i) << endl;
  }

  cout << "average = " << sum / 100 << endl;
  return 0;
}
