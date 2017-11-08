#include <stdio.h>
#define ROWS 6
#define COLS 6
#define MAX_TERMS 10

typedef struct {
  int row;
  int col;
  int value;
} element;

typedef struct SparseMatrix {
  element data[MAX_TERMS];
  int rows; // 행의 개수
  int cols; // 열의 개수
  int terms; // 항의 개수
} sparseMatrix;

// 희소 행렬 덧셈 함수
// c = a + b
SparseMatrix sparse_matrix_add(SparseMatrix a, SparseMatrix b) {
  SparseMatrix c;
  int ca = 0, cb = 0, cc = 0; // 각 배열의 항목을 가리키는 인덱스
  // 배열 a와 배열 b의 크기가 같은지를 확인
  if (a.rows != b.rows || a.cols != b.cols) {
    fprintf(stderr, "희소행렬 크기 에러\n");
    exit(1);
  }
  c.rows = a.rows;
  c.cols = a.cols;
  c.terms = 0;

  while(ca < a.terms && cb < b.terms) {
    // 각 항목의 순차적인 번호를 계산한다.
    int inda = a.data[ca].row * a.cols + a.data[ca].col;
    int indb = b.data[cb].row * b.cols + b.data[cb].col;
    if (inda < indb) {
      // a 배열 항목이 앞에 있으면
      c.data[cc++] = a.data[ca++];
    } else if (inda == indb) {
      // a와 b가 같은 위치
      if ((a.data[ca].value + b.data[cb].value) != 0) {
        c.data[cc].row = a.data[ca].row;
        c.data[cc].col = a.data[ca].col;
        c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
      } else {
        ca++;
        cb++;
      }
    } else {
      c.data[cc++] = b.data[cb++];
    }
  }
  // 배열 a와 b에 남아 있는 항들을 배열 c로 옮긴다
  for (; ca < a.terms;) {
    c.data[cc++] = a.data[ca++];
  }
  for (; cb < b.terms;) {
    c.data[cc++] = b.data[cb++];
  }
  c.terms = cc;
  return c;
}

int main(void) {
  SparseMatrix m1 = {
    {
      {0, 0, 1},
      {1, 1, 1},
      {2, 1, 1},
      {3, 2, 1},
      {4, 3, 1},
      {5, 1, 2},
      {5, 3, -1},
    },
    6,
    6,
    7
  };
  SparseMatrix m2 = {
    {
      {0, 0, 1},
      {1, 0, 1},
      {2, 1, 1},
      {3, 2, 1},
      {4, 0, 1},
      {5, 0, 1}
    },
    6,
    6,
    7
  };
  SparseMatrix m3;
  m3 = sparse_matrix_add(m1, m2);
  return 0;
}
