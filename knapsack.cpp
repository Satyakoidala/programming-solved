#include <bits/stdc++.h>
#include <vector>

using namespace std;

int optimal_weight(int W,vector<int> &w) {
  //write your code here
  vector <vector <int>> cw(w.size()+1,vector<int>(W+1,0));
  int val;
  //memset(cw, 0, sizeof(cw));
  sort(w.begin(),w.end());
  for (size_t i = 1; i < w.size()+1; ++i) {
    for (int j=1; j < W+1; ++j){
      cw[i][j] = cw[i-1][j];
      val = 0;
      if (w[i-1]<=j){
        val = cw[i-1][j-w[i-1]]+w[i-1];
      }
      cw[i][j] = max(cw[i][j],val);
    }
  }
  /*for (size_t i = 0; i < w.size()+1; ++i) {
    for (int j=0; j < W+1; ++j){
      cout<<cw[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return cw[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
