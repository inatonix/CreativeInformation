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

int getDigit(int num){
  return log10(num) + 1;
}

int main() {
  string Rome[7] = {"I","V","X","L","C","D","M"};
  int reference[7] = {1,5,10,50,100,500,1000};

  string numSt; cin >> numSt;
  int result = 0;
  vector<int> transformedRome;
  rep(i,numSt.length()){
    rep(j,7){
      if ( Rome[j] == numSt.substr(i,1)) {
        transformedRome.pb(reference[j]);
        break;
      }
    }
  }

  rep(i,transformedRome.size()){
    if( i == transformedRome.size() - 1) {
      result += transformedRome[i];
      break;
    }
    if(transformedRome[i] >= transformedRome[i+1]){
      result += transformedRome[i];
    }else{
      result += transformedRome[i+1] - transformedRome[i];
      i += 1;
    }
  }

  cout << result << endl;
  return 0;
}
