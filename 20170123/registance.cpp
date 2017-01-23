# include <iostream>
# include <map>
# include <string>

using namespace std;

int main(void) {
  map<string, pair<string, int>> registance{
    {"black", make_pair("0", 1)},
    {"brown", make_pair("1", 10)},
    {"red", make_pair("2", 100)},
    {"orange", make_pair("3", 1000)},
    {"yellow", make_pair("4", 10000)},
    {"green", make_pair("5", 100000)},
    {"blue", make_pair("6", 1000000)},
    {"violet", make_pair("7", 10000000)},
    {"grey", make_pair("8", 100000000)},
    {"white", make_pair("9", 1000000000)},
  };

  string first, second, third;

  cin >> first >> second >> third;

  long long result = stoll(registance[first].first + registance[second].first) * registance[third].second;
  cout << result;

  return 0;
}
