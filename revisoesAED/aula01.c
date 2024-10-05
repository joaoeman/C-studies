#include <stdio.h>

typedef struct {
  int num;
  int dem;
} racional;

int mmc(int a, int b) {
  int maior = a > b ? a : b;
  while (1) {
    if (maior % a == 0 && maior % b == 0)
      return maior;
    maior++;
  }
}
void soma(racional *p, racional *q, racional *l, int maior) {
  p->dem = maior;
  p->num = maior / q->dem * q->num + maior / l->dem * l->num;
}
void igual(racional *q, racional *l) {
  if (q->dem == l->dem && q->num == q->num)
    printf("iguais\n");
  else
    printf("Diferentes\n");
}
int main() {
  racional q, p, l;
  int maior;

  scanf("%d %d %d %d", &q.num, &q.dem, &l.num, &l.dem);

  maior = mmc(q.dem, l.dem);
  soma(&p, &q, &l, maior);

  printf("%d\n%d\n", p.num, p.dem);
  igual(&q, &l);
}
