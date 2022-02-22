#include <cstdio>

using namespace std;

// best O(n)
// worst O(n^2)
// avg O(n^2)

int main () {
  int A[105], n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", A + i);
  for (int i = 2; i <= n; i++) {
    int j = i - 1;
    int x = A[i];
    while (j > 0 && x < A[j]) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", A[i], i < n ? ' ':'\n');
  return 0;
}
