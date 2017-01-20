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

typedef pair<int, int> P;
typedef pair<P, int> PP;

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


int main(void){
  vector<string> result;
  string st; cin >> st;

  split(st,"+",result);
  rep(i,result.size()){
    cout << result[i] << endl;
  }

  return 0;
}
