# include <cstdio>
# include <cstring>
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

using namespace std;

int N;
int arr[10000];

bool prev_permutation(int* arr, int n) {
    int i = n-1;
    while(i > 0 && arr[i-1] <= arr[i]) {
        i-=1;
    }
    if (i <= 0) { // last
        return false;
    }

    int j = n-1;
    while(arr[j] > arr[i-1]) {
        j-=1;
    }
    swap(arr[i-1], arr[j]);
    int k = n-1;
    while(i < k) {
        swap(arr[i], arr[k]);
        i += 1;
        k -= 1;
    }
    return true;
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (prev_permutation(arr, N)) {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("-1");
    }
    printf("\n");
    return 0;
} 
