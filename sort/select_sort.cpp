#include<cstdio>
#include<iostream>

using namespace std;

int main(void) {
  int arr[10] = {0, };
  int max, idx, temp;

  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 9; i >= 0; i--) {
    max = -1;
    idx = -1;
    for (int j = 0; j <= i; j++) {
      if (arr[j] >= max) {
        max = arr[j];
        idx = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[idx];
    arr[idx] = temp;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
