#include<stdio.h>

int main() {
  FILE *fp;
  float a = 0.00001, b = 0.000234, c = 12392103.32;

  fp = fopen("xxx.txt", "w");
  fwrite(&a, sizeof(float), 1, fp);
  fwrite(&b, sizeof(float), 1, fp);
  fwrite(&c, sizeof(float), 1, fp);

  fclose(fp);
  return 0;
}
