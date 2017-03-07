#include <iostream>

using namespace std;

int tree[27][2];

void preorder(int x) {
	if (x == -1) {
    return;
  }

	cout << (char)(x + 'A');

	preorder(tree[x][0]);
	preorder(tree[x][1]);
}

void inorder(int x) {
	if (x == -1) {
    return;
  }

	inorder(tree[x][0]);
	cout << (char)(x + 'A');
	inorder(tree[x][1]);
}

void postorder(int x) {
	if (x == -1) {
    return;
  }

	postorder(tree[x][0]);
	postorder(tree[x][1]);
	cout << (char)(x + 'A');
}

int main() {
	int N;
	char root, left, right;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> root >> left >> right;

    root -= 'A';
		if (left == '.') {
			tree[root][0] = -1;
		} else {
			tree[root][0] = left - 'A';
		}
		if (right == '.') {
			tree[root][1] = -1;
		} else {
			tree[root][1] = right - 'A';
		}
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

  return 0;
}
