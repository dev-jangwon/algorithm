#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
  int T;
  int N, M;
  int K;
  int A, B;

  cin >> T;
  while(T--) {
    int ai[25] = {0, };
    int ai_status[25] = {-1, };
    int bi[25] = {0, };
    int bi_status[25] = {-1, };
    int tk[1005] = {0, };
    int k_status[1005] = {0, };
    int k_a[1005] = {0, };
    int k_b[1005] = {0, };
    cin >> N >> M >> K >> A >> B;
    for (int i = 0; i < N; i++) {
      cin >> ai[i];
    }
    for (int i = 0; i < M; i++) {
      cin >> bi[i];
    }
    for (int i = 0; i < K; i++) {
      cin >> tk[i];
    }


    for (int t = 0; t < 1005; t++) { // 시간의 흐름 t
      for (int i = 0; i < K; i++) { // 고객 i

        for (int j = 0; j < M; j++) { // b 완료 검사
          if (k_status[i] == 3 && bi_status[j] >= 0) {
            bi_status[j]++;
            if (bi_status[j] == bi[j]) { // b 완료
              k_status[i] = 4; // i 고객 b 검사 완료
              bi_status[j] = -1; // 창구 초기화
            }
          }
        }

        if (k_status[i] == 2) { // b 대기 고객 검사(대기)
          for (int j = 0; j < M; j++) { // b 창구 검사
            if (bi_status[j] == -1) {
              k_status[i] = 3; // 창구 배정
              bi_status[j] = 1;
              k_b[i] = j + 1;
            }
          }
        }

        for (int j = 0; j < N; j++) { // a 완료 검사
          if (k_status[i] == 1 && ai_status[j] >= 0) {
            ai_status[j]++; // 검사 진행
            if (ai_status[j] == ai[j]) { // a 완료
              k_status[i] = 2; // i 고객 a 검사 완료
              ai_status[j] = -1; // 창구 초기화
            }
          }
        }

        if (tk[i] <= t && k_status[i] == 0) { // a 대기 고객 검사
          for (int j = 0; j < N; j++) { // a 창구 검사
            if (ai_status[j] == -1) {
              k_status[i] = 1; // 창구 배정
              ai_status[j] = 1;
              k_a[i] = j + 1;
            }
          }
        }

      }
    }

    for (int i = 0; i < K; i++) {
      cout << k_a[i] << ", " << k_b[i] << '\n';
      if(k_a[i] == A && k_b[i] == B) {
        cout << i + 1 << '\n';
      }
    }

  }
  return 0;
}
