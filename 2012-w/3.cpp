#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>
#include <set>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back


int string_to_int(std::string str){
  int ret;
  std::stringstream ss;
  ss << str;
  ss >> ret;
  return ret;
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

void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
  while(getline(ifs,str)){
    cout << "push" << " " <<str <<endl;
    vec.push_back(str);
  }
}

int x[30];int y[30];
int a,b;

void graphWrite(){
  string graph[31][31];

  rep(i,31){
    rep(j,31){
      graph[i][j] = "　";
    }
  }
  graph[0][0] = "＋";

  for(int i = 1;i < 31 ; i++){
    graph[0][i] = "ー";
    graph[i][0] = "｜";
  }
  int tmp_x = 0; int tmp_y = 0;
  rep(i,30){
    rep(j,30){
      tmp_y = a * j + b;
      graph[j][(int)round(tmp_y)] = "○";
    }
  }


  for(int i = 30; i >= 0; i--){
    rep(j,30){
      cout << graph[i][j];
    }
    cout << endl;
  }

}


int main() {
  cin >> a >> b;
  graphWrite();
  return 0;
}
