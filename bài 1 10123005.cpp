#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
  int* arr;
  int n;
  
  
  
 void Nhap_Mang()
{
  printf("\n Nhap N:");
  scanf("%d", &n); 
  int i;
  
  arr = (int*)malloc(n * sizeof(int));
  for (i=0; i<= sizeof (arr)/ sizeof(int); i++);
  {
  	printf("Nhap phan tu thu %d", i);
    scanf("%d", &arr[i]);
  }
}
int main()
{
}


