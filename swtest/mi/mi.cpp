#include<iostream>
#include<cstdio>
#define MAX_GUNZIP 1005
using namespace std;

int N, M, K;
typedef struct _gunzip {
  int row;
  int col;
  int count;
  int direction;
} gunzip[MAX_GUNZIP];

int main(void) {
  int T;
  scanf("%d ", &T);
  while(T--) {
    scanf("%d %d %d ", &N, &M, &K);
    for (int i = 0; i < K; i++) {
      scanf("%d %d %d %d ", gunzip[i].col, gunzip[i].row, gunzip[i].count, gunzip[i].direction);
    }
  }
  return 0;
}
