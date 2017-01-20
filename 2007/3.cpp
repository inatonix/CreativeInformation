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
  //cout << "child = " << child[i] << " G = ";
    rep(j,G[child[i]].size()){
    //  cout << G[child[i]][j] << " ";
      if(claster_used[G[child[i]][j]])
        cnt += 1;
    }
  //  cout << endl;
  }
  cnt /= 2;
  if(cnt == 0) return 0;
//  cout << "st = " << st << " cnt = " << cnt << endl;
  sum += cnt / ((k * (k - 1)) / 2);
  return cnt / ((k * (k - 1)) / 2);

}

int main() {
  vector<string> edges;
  vector<string> splitedEdges;
  fileReader("edges.txt",edges);
  int i = 0;
  while(true){
      split(edges[i]," ",splitedEdges);
      G[string_to_int(splitedEdges[0])].pb(string_to_int(splitedEdges[1]));
      G[string_to_int(splitedEdges[1])].pb(string_to_int(splitedEdges[0]));

      i += 1;
  }

  for(int i = 1; i < 101; i++){
    cout << i << ":" << claster_variable(i) << endl;
  }

  cout << "average = " << sum / 100 << endl;
  return 0;
}
