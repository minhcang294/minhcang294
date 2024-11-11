#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 int a[10][10],n;
  void docfile(){
  	FILE *f;
  	f = fopen("mtk.txt", "r");
  	if(f==NULL)
  	{
  		printf("khong co tap tin");
  	    exit(0);
	  }
  	else
  	{
  	fscanf (f, "%d",&n);
  	for( int i=1; i<=n;i++)
  	for(int j=1; j<=n;j++)
  	fscanf(f,"%d",&a[i][j]);
  
  		}
  		fclose(f);
  		  }
  		   void infile(){
  		   	for( int i=1; i<=n;i++){
         	for(int j=1; j<=n;j++)
         	printf("%d", a[i][j]);
         	printf("\n");	
         	}
        }
        void checkSymmetric(int matrix[MAX][MAX], int n) {
    int symmetric = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }
    if (symmetric) {
        printf("co HUONG \n");
    } else {
        printf("vO HUONG\n");
    }
}
  int  giadothi(int matrix[MAX][MAX], int n) {
    int allZero = 1; // Gi? s? to?n b? l? 0
    for (int i = 1; i < n; i++) {
        if (a[i][i] !=0) {
            allZero = 0; // C? ph?n t? kh?c 0
            break;
        }
    }
    return allZero;
}
    int dondothi(int matrix[MAX][MAX], int n) {
    int allLessThanOrEqualOne = 1; // Gi? s? t?t c? d?u <= 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 1) {
                allLessThanOrEqualOne = 0; // C? ph?n t? l?n hon 1
                break;
            }
        }
    }
   return allLessThanOrEqualOne;
    }
int main() {
    int n, matrix[MAX][MAX];
  		  docfile();
  		  printf("Ma tran ke:\n");
  		  infile();
  		  checkSymmetric(matrix, n);
  	if (checkSymmetric()==1)
	  {
	  	if(giadothi()==0)
	  	printf("gia do thi");
	  	else {
	  	if(dondothi()==0)
	  	printf("don do thi vo huong ");
	  	else
	  	printf(" da do thi vo huong ");
	  	}
	  	}
	  	else {
	  		if(dondothi()==1)
	  		printf("don do thi co huong");
	  		else
	  		printf(" da do thi có huong ");
	  	  
}
}
    return 0;
  		  }
