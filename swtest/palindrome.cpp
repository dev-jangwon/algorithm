#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main(void) {
  int T;
  char str[11];
  char str2[11];
  char check[12];
  scanf("%d ", &T);
  int temp;
  while(T--) {
    //cin.ignore();
    fgets(str, 10, stdin);
    //cout << atoi(str) << '\n';
    int size = (int)strlen(str) - 1;
    for (int i = 0; i < size; i++) {
      str2[i] = str[size - i - 1];
    }
    int result = atoi(str) + atoi(str2);
    cout << atoi(str) << ", " << atoi(str2) << ", " << result << '\n';
    int cnt = 0;
    temp = result;
    while(temp!=0) {
      check[cnt] = temp % 10;
      temp /= 10;
      cnt++;
    }
    int start = 0;
    int end = cnt - 1;
    int flag = 0;
    while(start <= end) {
      if (check[start] != check[end]) {
        flag = 1;
        break;
      } else {
        start++;
        end--;
      }
    }
    if (flag == 1) {
      printf("no\n");
    } else {
      printf("yes\n");
    }
  }
  return 0;
}
