# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

struct STUDENT {
  char name[101];
  int korean;
  int english;
  int math;
} student[100005];

bool cmp(STUDENT st1, STUDENT st2) {
  if (st1.korean > st2.korean) {
    return true;
  } else if ((st1.korean == st2.korean) && (st1.english) != (st2.english)) {
    return st1.english < st2.english;
  } else if ((st1.korean == st2.korean) && (st1.english == st2.english) && (st1.math != st2.math)) {
    return st1.math > st2.math;
  } else if ((st1.korean == st2.korean) && (st1.english == st2.english) && (st1.math == st2.math)) {
    return strcmp(st1.name, st2.name) < 0 ? true : false;
  } else {
    return false;
  }
}

int main(void) {
  int N;
  scanf("%d", &N);

  STUDENT st[N];

  for (int i = 0; i < N; i++) {
    scanf("%s %d %d %d", st[i].name, &st[i].korean, &st[i].english, &st[i].math);
  }

  sort(st, st + N, cmp);

  for (int i = 0; i < N; i++) {
    printf("%s\n", st[i].name);
  }

  return 0;
}
