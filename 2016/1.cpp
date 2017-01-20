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

vector<string> digitalNumber[7];
bool digit_bool[8];

void makeDigitalNumber(){

  if(digit_bool[1] || digit_bool[2] || digit_bool[3]){
    if(digit_bool[1] || digit_bool[2]){
      digitalNumber[0].pb("*");
    }else{
        digitalNumber[0].pb(" ");//3space
    }
    if(digit_bool[1]){
      digitalNumber[0].pb("--");
    }else{
      digitalNumber[0].pb("  ");
    }

    if(digit_bool[1] || digit_bool[3]){
      digitalNumber[0].pb("*");
    }
  }else{
    digitalNumber[0].pb("    ");
  }

  rep(i,2){
    if(digit_bool[2] || digit_bool[3]){
      if(digit_bool[2]){
        digitalNumber[i+1].pb("|");
      }else{
        digitalNumber[i+1].pb(" ");
      }
      digitalNumber[i+1].pb("  ");
      if(digit_bool[3]){
        digitalNumber[i+1].pb("|");
      }else{
        digitalNumber[i+1].pb(" ");
      }
    }else{
      digitalNumber[i+1].pb("    ");
    }
  }

  if(digit_bool[2] || digit_bool[4] || digit_bool[5] || digit_bool[3] || digit_bool[6]){
    if(digit_bool[2] || digit_bool[4] || digit_bool[5]){
      digitalNumber[3].pb("*");
    }else{
      digitalNumber[3].pb(" ");//3
    }
    if(digit_bool[4]){
      digitalNumber[3].pb("--");
    }else{
      digitalNumber[3].pb("  ");
    }
    if(digit_bool[3] || digit_bool[4] || digit_bool[6]){
      digitalNumber[3].pb("*");
    }
  }else{
    digitalNumber[3].pb("    ");
  }

  for(int i = 4; i < 6; i++){
    if(digit_bool[5] || digit_bool[6]){
      if(digit_bool[5]){
        digitalNumber[i].pb("|");
      }else{
        digitalNumber[i].pb(" ");
      }
      digitalNumber[i].pb("  ");
      if(digit_bool[6]){
        digitalNumber[i].pb("|");
      }else{
        digitalNumber[i].pb(" ");
      }
    }else{
      digitalNumber[i].pb("    ");
    }
  }

  if(digit_bool[5] || digit_bool[7] || digit_bool[6]){
    if(digit_bool[5] || digit_bool[7]){
      digitalNumber[6].pb("*");
    }else{
      digitalNumber[6].pb("   ");//3
    }
    if(digit_bool[7]){
      digitalNumber[6].pb("--");
    }
    if(digit_bool[7] || digit_bool[6]){
      digitalNumber[6].pb("*");
    }


  }else{
    digitalNumber[6].pb("    ");
  }

  rep(i,7){
    digitalNumber[i].pb("  ");
  }
}


int main() {
  string num; cin >> num;
  rep(i,num.length()){
    rep(i,8){
      digit_bool[i] = false;
    }
    switch (string_to_int(num.substr(i,1))) {
      case 1:
        digit_bool[3] = digit_bool[6] = true;
        break;
      case 2:
        digit_bool[1] = digit_bool[3] = digit_bool[4] = digit_bool[5] = digit_bool[7] = true;
        break;
      case 3:
        digit_bool[1] = digit_bool[3] = digit_bool[4] = digit_bool[6] = digit_bool[7] = true;
        break;
      case 4:
        digit_bool[2] = digit_bool[4] = digit_bool[3] = digit_bool[6] = true;
        break;
      case 5:
        digit_bool[1] = digit_bool[2] = digit_bool[4] = digit_bool[6] = digit_bool[7] = true;
        break;
      case 6:
          digit_bool[1] = digit_bool[2] = digit_bool[4] = digit_bool[5] =  digit_bool[6] = digit_bool[7] = true;
        break;
      case 7:
        digit_bool[1] = digit_bool[3] = digit_bool[6] = true;
        break;
      case 8:
        rep(i,8) digit_bool[i] = true;
        break;
      case 9:
        rep(i,8) digit_bool[i] = true;
        digit_bool[5] = false;
        break;
      case 0:
      rep(i,8) digit_bool[i] = true;
      digit_bool[4] = false;
      break;
    }

    makeDigitalNumber();

  }

  rep(i,7){
    rep(j,digitalNumber[i].size()){
      cout << digitalNumber[i][j] ;//<< endl;
    }
    cout << endl;
  }



  return 0;
}
