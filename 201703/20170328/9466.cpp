#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

#define MAX 100010

int nChoice[MAX];
int nTeam[MAX];
int nCycle[MAX];
int nTestcase;
int nStudent;
int nCnt;

bool DFS(int start, int choice);

int main() {
	cin >> nTestcase;
	while (nTestcase--) {
		cin >> nStudent;
		for (int i = 1; i <= nStudent; i++)
			scanf("%d", &nChoice[i]);

		for (int i = 1; i <= nStudent; i++)
			DFS(i, nChoice[i]);

		for (int i = 1; i <= nStudent; i++)
			if (nTeam[i] != 1) nCnt++;
		cout << nCnt << endl;

		memset(nChoice, 0, sizeof(int)*MAX);
		memset(nTeam, 0, sizeof(int)*MAX);
		nCnt = 0;
	}
}

bool DFS(int start, int choice) {
	if (nTeam[choice] == 0 || (nTeam[choice] == -1 && nCycle[choice])) {
		nTeam[choice] = 1;
		if (start == choice) return true;

		if (!DFS(start, nChoice[choice])) {
			nTeam[choice] = -1;
			return false;
		} else {
      return true;
    }
	}
	nCycle[choice] = 1;
	return false;
}
