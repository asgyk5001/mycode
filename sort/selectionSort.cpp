#include <cstdio>

using namespace std;

//Avg, Best, Worst cases are O(n^2)

void _swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main () {
  int A[105], n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", A + i);
  for (int i = 1; i < n; i++) {
    int x = i;
    for (int j = i + 1; j <= n; j++) {
      if (A[j] < A[x]) {
	x = j;
      }
    }
    if (x != i)
      _swap(A + i, A + x);
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", A[i], i < n ? ' ':'\n');
  return 0;
}
