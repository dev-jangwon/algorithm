# include <cstdio>
# include <cstring>
# include <iostream>
# include <string>

using namespace std;

int add(int S, int x);
int remove(int S, int x);
int check(int S, int x);
int toggle(int S, int x);
int all();
int empty();

int main(void) {
	int M, S = 0, x;
	char op[100];
	scanf("%d", &M);
	while(M--) {
		scanf("%s %d", op, &x);
		if (!strcmp(op, "add")) {
			S = add(S, x);
		} else if (!strcmp(op, "remove")) {
			S = remove(S, x);
		} else if (!strcmp(op, "check")) {
			printf("%d\n", check(S, x));
		} else if (!strcmp(op, "toggle")) {
			S = toggle(S, x);
		} else if (!strcmp(op, "all")) {
			S = all();
		} else if (!strcmp(op, "empty")) {
			S = empty();
		}
	}
	return 0;
}

int add(int S, int x) {
	return S | (1 << (x - 1));
}

int remove(int S, int x) {
	return S & ~(1 << (x - 1));
}

int check(int S, int x) {
	if (S & (1 << (x - 1))) {
		return 1;
	} else {
		return 0;
	}
}

int toggle(int S, int x) {
	return S ^ (1 << (x - 1));
}

int all() {
	return (1 << 20) - 1;
}

int empty() {
	return 0;
}
