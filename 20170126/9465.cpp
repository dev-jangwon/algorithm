#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<pair<int, int> > score;
int memo[100001][3];

int solve(int index, int check) {
	if (index > N) {
		return 0;
	}

	int &ret = memo[index][check];

  if (ret != -1) {
		return ret;
	}

	ret = 0;

	int first = score[index].first;
	int second = score[index].second;

	ret = solve(index + 1, 0); //선택 X

	// check == 0일 경우 index에서 선택 x
	// index + 1에서 first, second, X선택가능
	if (check == 0) {
		ret = max(solve(index + 1, 2) + first, ret);
		ret = max(solve(index + 1, 1) + second, ret);
	}
	// check == 1일 경우 index에서 first 선택
	// index + 1에서 second 혹은 X
	if (check == 1) {
		ret = max(ret, solve(index + 1, 2) + first);
	}
	// check == 2일 경우 index에서 second선택
	// index + 1에서 first 혹은 X
	if (check == 2) {
		ret = max(ret, solve(index + 1, 1) + second);
	}

	return ret;
}
int main(void) {
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		score.clear();

		//1~N열 사용
		score.resize(N + 1);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &score[i].first);
		}

		memo[0][0] = memo[0][1] = memo[0][2] = -1;

		for (int i = 1; i <= N; i++) {
			scanf("%d",&score[i].second);
			for (int j = 0; j < 3; j++) {
				memo[i][j] = -1;
			}
		}
		int answer = solve(0, 0);
		printf("%d\n", answer);
	}
}
