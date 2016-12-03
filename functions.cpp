#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;


class DisJointSet {
public:
  vector<int> rank,p;

  DisJointSet(){}
  DisJointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
    for(int i = 0; i < size; i++) makeSet(i);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y){
    return findSet(x) == findSet(y);
  }

  void unite(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if( rank[x] > rank[y] ){
      p[y] = x;
    }else {
        p[x] = y;
        if( rank[x] == rank[y]){
          rank[y] ++;
        }
    }
  }

  int findSet(int x){
    if ( x != p[x] ){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

//数値を分割して配列に入れることができる
void sliceDigit(int num, vector<int> &result){
  while(num > 0){
    result.push_back(num % 10);
    num /= 10;
  }
  reverse(result.begin(),result.end());
}

//絶対値を求める
int absol(int a){
  if( a > 0) return a;
  return -a;
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

//素数を判定する
bool isPrime(int x){
  int i;
  if ( x < 2 )       return false;
  else if ( x == 2 ) return true;
  if( x % 2 == 0 )   return false;
  for( int i = 3; i*i <= x; i+=2 ){
    if( x % i == 0) return false;
  }
  return true;

}

//最大公約数
int gcd(int x, int y){
  int r;
  if ( x < y ) swap(x,y);

  while (y > 0){
    r = x % y;
    x = y;
    y = r;
  }
  return x;

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

int max (vector<int> array){
  int maxval = 0;
  for (int i = 0; i < array.size(); i ++) {
    if( array[i] > maxval){
      maxval = array[i];
    }
  }

  return maxval;
}

//ファイルの行数を指定して読み込む
//fileOpener("ファイル名",行数)
string fileOpenerSelectingLine(string filename, int line_num){
  ifstream ifs(filename);
  string result;string str;
  int cnt = 1;

  if (ifs.fail())
  {
      return "失敗";
  }

  while(getline(ifs,str)){
    if(cnt == line_num){
      result = str;
    }
    cnt += 1;
  }

  return result;
}

static const int MAX = 10000;
static const int INFTY = (1<<20);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n;
vector<pair<int,int> > adj[MAX];

void dijkstra(){
  priority_queue<pair<int,int> > PQ;
  int color[10000];
  int d[10000];
  for( int i = 0; i < n; i++){
    d[i] = INFTY;
    color[i] = WHITE;
  }

  d[0] = 0;
  PQ.push(make_pair(0,0));
  color[0] = GRAY;

  while( !PQ.empty() ){
    pair<int,int> f = PQ.top(); PQ.pop();
    int u = f.second;
    color[u] = BLACK;

    if( d[u] < f.first * (-1) ) continue;

    for ( int j = 0; j < adj[u].size(); j++ ){
      int v = adj[u][j].first;
      if ( color[v] == BLACK ) continue;
      if ( d[v] > d[u] + adj[u][j].second ){
        d[v] = d[u] + adj[u][j].second;
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }


}

//参照わたしをしなきゃ、このままじゃ機能しません！
void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
  while(getline(ifs,str)){
    cout << "push" << " " <<str <<endl;
    vec.push_back(str);
  }
}

int strCount(string str,string aim){
  int cnt = 0;
  for (int i = 0; i < (int)str.length(); i++){
    if (str[i] == aim[0]){
      cnt += 1;
    }
  }
  return cnt;
}

//sstreamのインクルードが必要
int string_to_int(std::string str){
  int ret;
  std::stringstream ss;
  ss << str;
  ss >> ret;
  return ret;
}
