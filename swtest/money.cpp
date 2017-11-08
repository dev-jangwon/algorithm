#include<iostream>
#include<vector>

using namespace std;

int main(void) {
  int count;
  vector<int> items;
  vector<int> c;
  int price;
  int payed;
  int rest;

  cin >> count;
  items.resize(count);
  c.resize(count);
  for (int i = 0; i < count; i++) {
    cin >> items[i];
    c[i] = 0;
  }
  cin >> price;
  cin >> payed;

  rest = payed - price;
  do {
    for (int i = 0; i < items.size(); i++) {
      if (rest >= items[i]) {
        rest = rest - items[i];
        c[i]++;
        break;
      }
    }
  } while(rest != 0);
  for (int i = 0; i < c.size(); i++) {
    cout << c[i] << ' ';
  }
  return 0;
}
