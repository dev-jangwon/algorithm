# include <iostream>
# include <bitset>

using namespace std;

int main(void) {
  bitset<100000> A;
  bitset<100000> B;
  bitset<100000> result;

  cin >> A >> B;

  result = A & B;
  cout << result << endl;
  result = A | B;
  cout << result << endl;
  result = A ^ B;
  cout << result << endl;
  result = ~A;
  cout << result << endl;
  result = ~B;
  cout << result << endl;

  return 0;
}
