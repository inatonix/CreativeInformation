#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
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

void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
//  string pastStr = "";
  while(getline(ifs,str)){
    //cout << str <<endl;
  //  if ( str == pastStr) cout << str << endl;
  //  pastStr = str;
    vec.push_back(str);
  }
}



int main() {
  string filename = "program.txt"; vector<string> txt;
  fileReader(filename,txt);
  bool isUsed[txt.size()];
  rep(i,txt.size()){
    isUsed[i] = false;
  }

  rep(i,txt.size()){
    if(!isUsed[i]){
      for(int j = i + 1; j < txt.size(); j++){
        if(txt[i] == txt[j] && !isUsed[j]) {
          isUsed[j] = true;
          isUsed[i] = true;
        }
      }
      if(isUsed[i]) cout << txt[i] << endl;
    }
  }

  return 0;
}
