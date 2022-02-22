#include <cstdio>

using namespace std;

void _swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(A, p, r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      _swap(A + i, A + j);
    }
  }
  _swap(A + i + 1, A + r);
  return i + 1;
}

void quickSort(int A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

int main () {
  int n, A[105];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &n);
  quickSort(A, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d%c", A[i], i < n - 1 ? ' ':'\n');
  return 0;
}
