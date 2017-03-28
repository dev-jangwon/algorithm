#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100005]; // inorder array for storing locations(index) of given values.
int b[100005]; // postorder array for storing values.
int pos[100005];

void f(int il, int ir, int pl, int pr){
    if(il > ir || pl > pr){
        return;
    }
    int root = b[pr];
    printf("%d ", root);
    // il을 빼주는것에 주의할것.
    f(il, pos[root] - 1, pl, pl + pos[root] - il - 1);
    f(pos[root] + 1, ir, pl + pos[root] - il, pr - 1);
}
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    f(0, n - 1, 0, n - 1);
    return 0;
}
