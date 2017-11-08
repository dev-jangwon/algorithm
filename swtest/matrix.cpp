#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int arr[50][50];

int main(void) {
  int T;
  int N;
  string s;
  cin >> T;
  for (int k = 0; k < T; k++) {
    cin >> N;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < 50; i++) {
      for (int j = 0; j < 50; j++) {
        arr[i][j] = 0;
      }
    }
    int char_count = 1;
    int first, second;
    for (int i = 0; i < (int)s.size(); i++) {
      if (i % 4 == 0) {
        first = s[i] - '0';
      } else if (i % 4 == 2) {
        second = s[i] - '0';
        arr[first][second] = 1;
        for (int j = 1; j <= char_count; j++) {
          if (second - j >= 0) {
              arr[first][second - j] = 1;
          }
          if (second + j < N) {
              arr[first][second + j] = 1;
          }
          if (first - j >= 0) {
              arr[first - j][second] = 1;
          }
          if (first + j < N) {
              arr[first + j][second] = 1;
          }
        }
      } else if (i % 4 == 3) {
        char_count++;
      }
    }
    int num = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (arr[i][j] == 0) {
          num++;
        }
      }
    }
    cout << "#" << (k+1) << ' ';
    cout << num << '\n';
  }
  return 0;
}
