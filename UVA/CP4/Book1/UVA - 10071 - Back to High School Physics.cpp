#include <stdio.h>

int main(void) {
  int v;
  int t;

  while (scanf("%d %d\n", &v, &t) != EOF) {
    printf("%d\n", (v * t) << 1);
  }

  return 0;
}
