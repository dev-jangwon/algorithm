# include <iostream>
# include <algorithm>
# include <cstdio>

using namespace std;

struct MEMBER {
  int age;
  int order;
  char name[101];
} mem[100005];

bool cmp(MEMBER mem1, MEMBER mem2) {
  if (mem1.age < mem2.age) {
    return true;
  } else if (mem1.age == mem2.age ) {
    return mem1.order < mem2.order;
  } else {
    return false;
  }
}

int main(void) {
  int N;
  scanf("%d", &N);

  MEMBER mem[N];

  for(int i = 0; i < N; i++) {
    scanf("%d %s", &mem[i].age, mem[i].name);
    mem[i].order = i;
  }

  sort(mem, mem + N, cmp);

  for (int i = 0; i < N; i++) {
    printf("%d %s\n", mem[i].age, mem[i].name);
  }

  return 0;
}
