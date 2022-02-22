#include <cstdio>
#include <climits>

using namespace std;

void _swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void quickSort(int A[], int p, int r) {
  if (p < r) {
    int x = A[p];
    int i = p, j = r + 1;
    do {
      do {
	i++;
      } while (A[i] < x);
      do {
	j--;
      } while (A[j] > x);
      if (i < j)
	_swap(A + i, A + j);
    } while (i < j);
    _swap(A + p, A + j);
    quickSort(A, p, j - 1);
    quickSort(A, j + 1, r);
  }
}

int main () {
  int n, A[105];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", A + i);
  A[n] = INT_MAX;
  quickSort(A, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d%c", A[i], i < n - 1 ? ' ':'\n');
  return 0;
}
