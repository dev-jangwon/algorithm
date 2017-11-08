#include<iostream>

using namespace std;

int x, y;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date[7] = {0, 1, 2, 3, 4, 5, 6};

int main(void) {
  cin >> x >> y;
  int day = 0;
  for (int i = 0; i < x; i++) {
    day += month[i];
  }
  day += y;

  if (day % 7 == 1) {
    cout << "MON" << '\n';
  } else if (day % 7 == 2) {
    cout << "TUE" << '\n';
  } else if (day % 7 == 3) {
    cout << "WED" << '\n';
  } else if (day % 7 == 4) {
    cout << "THU" << '\n';
  } else if (day % 7 == 5) {
    cout << "FRI" << '\n';
  } else if (day % 7 == 6) {
    cout << "SAT" << '\n';
  } else if (day % 7 == 0) {
    cout << "SUN" << '\n';
  }

  return 0;
}
