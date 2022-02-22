#include <cstdio>

using namespace std;

int main () {
  freopen("1.in", "r", stdin);
  int C[15], B[105], A[105], k = 10, n = 15;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", B + i);
  for (int i = 0; i <= k; i++) C[i] = 0;
  for (int i = 1; i <= n; i++) printf("%d%c", B[i], i < n ? ' ':'\n');
  for (int i = 1; i <= n; i++) C[B[i]]++;
  for (int i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
  for (int i = n; i >= 1; i--) {
    A[C[B[i]]] = B[i];
    C[B[i]]--;
  }
  for (int i = 1; i <= n; i++) printf("%d%c", A[i], i < n ? ' ':'\n');
  return 0;
}
