#include <cstdio>

using namespace std;

//Best case = O(n)
//Worst case = O(n^2)
//Avg case = O(n^2)

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
  for (int i = n - 1; i >= 1; i--) {
    int f = 0;
    for (int j = 1; j <= i; j++) {
      if (A[j] > A[j + 1]) {
      	_swap(A + j, A + j + 1);
	f = 1;
      }
    }
    if (f == 0) break;
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", A[i], i < n ? ' ':'\n');
  return 0;
}
