#include <stdio.h>

int main() {
  FILE *fp;
  float a, b, c;

  fp = fopen("xxx.txt", "r");
  fread(&a, sizeof(float), 1, fp);
  fread(&b, sizeof(float), 1, fp);
  fread(&c, sizeof(float), 1, fp);

  printf("a=%f b=%f c=%f\n", a, b, c);
  fclose(fp);
  return 0;
}
