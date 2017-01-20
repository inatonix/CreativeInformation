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

bool isAlphabet(char ch,int mode){
  bool flag = false;
  switch(mode){
    case 0://小文字判定
    if(ch - 'a' >= 0 && ch - 'z' <= 0){
      flag = true;
    }
    break;

    case 1://大文字
    if(ch - 'A' >= 0 && ch - 'Z' <= 0){
      flag = true;
    }
    break;

    case 2://アルファベット全体
    if(ch - 'A' >= 0 && ch - 'z' <= 0){
      flag = true;
    }
  }
    return flag;
}

//１０進数を２進数へ変換する
int binary(int bina){
    int ans = 0;
    for (int i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}

vector<int> dici;
void dicimalGenerator(int num,int digit){
  dici.clear();
  if(num == 0) dici.pb(0);
  while(num > 0){
    dici.pb(num % 2);
    num /= 2;
  }

  while(dici.size() < digit){
    dici.pb(0);
  }

  reverse(dici.begin(),dici.end());
  rep(i,dici.size()){
    cout << dici[i];
  }
  cout << endl;
}



int main(void){
  vector<string> bools;
  string st; cin >> st;
  split(st,"+",bools);

  set<string> result;
  vector<int> result_v;
  set<int> usedAlp;

  rep(i,bools.size()){
    rep(j,bools[i].length()){
      if(isAlphabet(bools[i][j],0)){
        usedAlp.insert(bools[i][j] - 'a');
        //aだったら0が入るはず
      }
    }
  }
  int generalAlpSize = usedAlp.size();
  cout << generalAlpSize << endl;

  int localAlpSize;
  bool ignore[26];
  bool exclamation[26];
  //rep(i,26) {ignore[i] = false;}

  rep(i,bools.size()){

    localAlpSize = 0;
    rep(j,26) {
      ignore[j] = false;
      exclamation[j] = false;
    }
    rep(j,bools[i].size()){
      if(isAlphabet(bools[i][j],0)){
        ignore[bools[i][j] - 'a'] = true;
        localAlpSize += 1;
        if(bools[i][j - 1] == '!'){
          exclamation[bools[i][j] - 'a'] = true;
          //cout << "ex = " <<  " " << bools[i][j] - 'a' << endl;
        }
      }
    }

    int cnt;
    rep(j,pow(2,generalAlpSize - localAlpSize)){
      cnt = 0;
      cout << "j = " << j << endl;
      dicimalGenerator(j,generalAlpSize-localAlpSize);
      rep(k,generalAlpSize){
          if(ignore[k]){
            if(exclamation[k])  result_v.pb(0);
            else                result_v.pb(1);
          }else{
            /*
            if(cnt >= dici.size())
              result_v.pb(0);
            else*/
              result_v.pb(dici[cnt]);
            cnt += 1;
          }
      }

      string resStr = "";
      rep(k,result_v.size()){
        resStr += to_string(result_v[k]);
      }
      result.insert(resStr);
      result_v.clear();
      //cout << endl;
    }
    //cout << endl;
  }

  for(auto itr = result.begin(); itr != result.end(); itr++){
    cout << *itr << endl;
  }
  if(result.size() == 0){
    cout << "none" << endl;
  }


  return 0;
}
