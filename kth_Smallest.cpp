#include <cstdio>
#include <algorithm>
#include <climits>

//Linear Time
//Worst case time is also Linear

using namespace std;

void _swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int _partition (int A[], int l, int r, int x) {

  int i;
  for(i = l; i < r; i++)
    if (A[i] == x)
      break;
  _swap(A + i, A + r);
  i = l - 1;
  for (int j = l; j <= r - 1; j++) {
    if (A[j] <= x) {
      i++;
      _swap(A + i, A + j);
    }
  }
  _swap(A + r, A + i + 1);
  return i + 1;
}

int findMedian(int A[], int n) {
  sort(A, A + n);
  return A[n / 2];
}

int kthSmallest(int A[], int l, int r, int k) {
  if (k > 0 && k <= r - l + 1) {
    int n = r - l + 1;
    int i, median[(n + 4) / 5];
    for (i = 0; i < n / 5; i++) {
      median[i] = findMedian(A + l + i * 5, 5);
    }
    if (i * 5 < n) {
      median[i] = findMedian(A + l + i * 5, n % 5);
      i++;
    }
    int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);
    int q = _partition(A, l, r, medOfMed);
    if (q - l + 1 == k) return A[q];
    else if (q - l + 1 > k) return kthSmallest(A, l, q - 1, k);
    else return kthSmallest(A, q + 1, r, k - (q - l + 1));
  }
  return INT_MAX; //2^31 - 1
}

int main () {
  freopen("1.in", "r", stdin);
  int n, k, A[15];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  printf("%d'th smallest element is %d\n", k, kthSmallest(A, 0, n - 1, k));
  sort(A, A + n);
  for (int i = 0; i < n; i++) printf("%d%c", A[i], i < n ? ' ':'\n');
  return 0;
}
