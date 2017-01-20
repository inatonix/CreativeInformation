#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <cmath>
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



int main() {
  float d; cin >> d;
  int cntOne = 0;
  int p = 0;int q = 0;
  while(abs(d) * p <= 10){
    q = 0;
    while(abs(d) * q <= 10){
      if(pow((abs(d) * p)-5,2) + pow((abs(d) * q)-5,2) <= 25){
        cntOne += 1;
      }
      q += 1;
    }
    p += 1;
  }


  cout << (float)( cntOne / pow((int)(11 / d),2) ) / 4 << endl;

  return 0;
}
