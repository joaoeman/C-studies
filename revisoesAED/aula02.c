#include <stdio.h>
typedef struct {
  int num;
  int dem;
} racional;

void maior(racional *a) {
  int temp;
  if (a->dem > a->num) {
    temp = a->num;
    a->num = a->dem;
    a->dem = temp;
  }
}
int euclides(racional *a) {
  int resto, temp;
  resto = a->num % a->dem;
  
  while(a->dem) {
    a->num = a->dem;
    a->dem = resto;
  }
  return a->num;
}
void swit(racional *a, int temp) {
  a->num = a->num / temp;
  a->dem = a->dem / temp;
}

int main() {
  racional a;
  int temp;

  scanf("%d %d", &a.num, &a.dem);
  maior(&a);
  temp = euclides(&a);
  swit(&a,temp);
  printf("%d\n%d\n", a.num, a.dem);
}
