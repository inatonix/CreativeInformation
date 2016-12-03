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
  string Rome[7] = {"I","V","X","L","C","D","M"};
  int reference[7] = {1,5,10,50,100,500,1000};

  int num; cin >> num;
  vector<string> result;
  int mod;
  cout << getDigit(num) << endl;
  rep(i,getDigit(num)){
    mod = num % 10;
    num = num / 10;
    cout << "i = " << i << " num = " << num << " mod = " << mod << endl;
      if(mod == 4){
        result.pb(Rome[(2 * i )+ 1]);result.pb(Rome[2 * i]);
        continue;
      }
      if(mod == 9){
        result.pb(Rome[(2 * i) + 2]);result.pb(Rome[2 * i]);
        continue;
      }
      while(mod > 0){
        if(mod == 5) {
          result.pb(Rome[(2*i)+1]);
          mod = mod - 5;
        }else{
          result.pb(Rome[2*i]);
          mod = mod - 1;
        }

      }


  }


  rep(i,result.size()){
    cout << result[result.size()-1-i];
  }
  cout << endl;

  return 0;
}
