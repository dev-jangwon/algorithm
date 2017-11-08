#include <cstdio>

void merge_sort(int array[], int left, int right);
void merge(int num[], int left, int mid, int right);

const int ITEMSIZE = 100;
int result[ITEMSIZE];

int main(void) {
  int array[ITEMSIZE] = {3, 8, 0, 2, 1, 4};
  merge_sort(array, 0, ITEMSIZE-1);
  return 0;
}

void merge_sort(int array[], int left, int right) {
  int mid;
  if (left < right) {
    mid = (left + right) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid+1, right);
    merge(array, left, mid, right);
  }
}

void merge(int array[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = left;
  int m;

  int tempArray[ITEMSIZE];

  while(i<= mid && j <= right) {
    if (array[i] < array[j]) {
      tempArray[k] = array[i];
      i++;
    } else {
      tempArray[k] = array[j];
      j++;
    }
    k++;
  }

  if (i > mid) {
    for (m = j; m <= right; m++) {
      tempArray[k] = array[m];
      k++;
    }
  } else {
    for (m = i; m <= mid; m++) {
      tempArray[k] = array[m];
      k++;
    }
  }

  for (m = left; m <= right; m++) {
    array[m] = tempArray[m];
  }
}
