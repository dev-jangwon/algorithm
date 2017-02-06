# include <iostream>
# include <string>

using namespace std;

int main(void) {
  string input;
  cin >> input;
  int len = input.size();

  for (int i = 0;i < len; i++) {
    int octa_num = input[i] - '0';
    int output[3] = {0, 0, 0};
    int idx = 2;

    while(octa_num != 0) {
      output[idx] = octa_num % 2;
      octa_num /= 2;
      idx--;
    }

    if (i == 0) {
        if (output[0] == 0) {
          if (output[1] == 0) {
            cout << output[2];
          } else {
            cout << output[1] << output[2];
          }
        } else {
          cout << output[0] << output[1] << output[2];
        }
    } else {
      cout << output[0] << output[1] << output[2];
    }
  }
  return 0;
}
