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

int getDigit(int num){
  return log10(num) + 1;
}

int main() {
  string Rome[7] = {"on","tw","th","fo","fi","si","se","ei","ni","te"
  int reference[7] = {1,5,10,50,100,500,1000};

  int num; cin >> num;
  vector<string> result;
  int mod;


  return 0;
}
