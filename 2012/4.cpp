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
static const int INF = 100000;


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

//参照わたしをしなきゃ、このままじゃ機能しません！
void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
  while(getline(ifs,str)){
    //cout << "push" << " " <<str <<endl;
    vec.push_back(str);
  }
}


int main() {
  vector<string> Lines;
  fileReader("sample.txt",Lines);
  vector<string> strVec;
  vector<pair<string, int> > variables;

  int lineCnt = 0;
  while(lineCnt < Lines.size()){

    split(Lines[lineCnt]," ",strVec);


    int a = INF; int b = INF;
    int a_position,b_position;
    rep(i,variables.size()){
      if(variables[i].first == strVec[1]){
        a = variables[i].second;
        a_position = i;
      }
      if(variables[i].first == strVec[2]){
        b = variables[i].second;
        b_position = i;
      }
    }
    //cout << "命令は " << strVec[0] << endl;
    //cout << "a = " << a << " b = " << b << endl;


    if(strVec[0] == "ADD"){
      if(a == INF){
        //見つからなかったってことはaは定数
        a = string_to_int(strVec[1]);
      }
      //cout << " a = " << a << " b = " << b;
      variables[b_position].second += a;
    }

    if(strVec[0] == "CMP"){
      if(a == INF)
        a = string_to_int(strVec[1]);
      if(b == INF)
        b = string_to_int(strVec[2]);
      if(a == b){
        lineCnt += 1;
      //  cout << "Equal" << endl;
      }
    //  cout << "not Equal" << endl;
    }

    if(strVec[0] == "JMP"){
      a = string_to_int(strVec[1]);
    //  cout << "JUMP定数は　 " << a << endl;
      lineCnt += a;
      lineCnt -= 1; //調整
    }

    if(strVec[0] == "PRN"){
      cout << "PRINT a = " << a << " b = " << b << endl;
    }

    if(strVec[0] == "SET"){
      if(a != INF){
      //  cout << "maybe b is INF " << b << endl;
        b = string_to_int(strVec[2]);
        variables[a_position].second = b;
      }else{
        //変数がすでになければ新規追加
        variables.pb(make_pair(strVec[1],string_to_int(strVec[2])));
      //  cout << "new variable added " << strVec[1] << " = " << strVec[2] << endl;
      }
    }


    lineCnt += 1;
  }


  return 0;
}
