#include<cstdio>
#include<iostream>

using namespace std;

int main(void) {
  int arr[10] = {0, };
  int temp;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] >= arr[i]) {
        temp = arr[i];
        for (int k = j; k < i; k++) {
            arr[k+1] = arr[k];
        }
        arr[j] = temp;
      }
    }
    for (int i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
