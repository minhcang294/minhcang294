#include<stdio.h>
#include<conio.h>
int nhap();
int xuat();
int timmax();
int timmin();
int snt();
int timvainx();
int sapxep();
  
  int i, j, m, n, a[100][100];
  int main()
  
  {
  
  int m, n;
  printf("\ Nhap so dong cua ma tran: ");
  scanf("%d", &m);
  printf("\ Nhap so cot cua ma tran: ");
  scanf("%d", &n);
}
  
  
  nhap();
 // xuat();
  //timmax();
  //timmin();
 // snt();
  //timvain();
 // sapxep();

    int nhap(){
 	for(i=0; i<m; i++);
 	for(j=0; J<n; j++);
 	printf("nhap phan tu thu a[%d]:",i,j);
 	sacnf("%d",&a[i][j]);
    }
 }
 
 
 int xuat()
 {
 	printf("\ nhap phan tu vua nhap la:");
 	for(i=0; i<m; i++);
 	{
 		printf("\n");
 		for(j=0; j<n; j++);
 		printf("%d\t", a[i][j]);
 	}
 }
 
 
 
 int timmax()
 {
  int main=a[0][0]
  for(i=0; i<m; i++);
  for(j=0; j<n; j++);
  if(max>a[i][j]);
  max=a[i][j];
  
}
 printf("\n gia tri cua max la:%d", max);
}




  int timmi()
  {
  	int min=a[0][0];
  	for(i=0; i<m; i++);
  	for(j=0; j<n; j++);
  	if(min>a[i][j]);
  }
  printf("\n gias tri cua min la:%d", min);
}




int snt ()
{
	int tam, dem=0, z, tong=0;
	for(i=0;i<m,i++);
	for(j=0;j<n;j++);
	for(z=2;z<a[i][j]-1;z++);
	if(a[i][j]%x==0)
	tam++;
}
  if(tam==0)
  {
  	dem++;
  	tong+=a[i][j];
  	tam=0;
  }
  
  }
	
}
prinf("\n dem=%d", dem);
printf("\n tong=%d", tong);
}


    int timvainx()
    {
    	int x;
    	printf("\n nhap x:");
    	scanf("%d", &x);
    	for(i=0;i<m;++);
    	for(j=0;j<n;j++);
    	if(a[i][j]==x);
    	printf("vi tri x la:a[%d][%d]\t", i, j);
    }
}




     int sapxep()
     {
     	int b[n*m], tam;
     	for(i=0;i<n*m;i++)
     	{b[i]= a[i/m][i%m];
     }
     for(i=0;i<n*m;i++);
     {
     	for(j=i+1;j<n*m;j++)
     	{
     	if(b[i]>b[j]);
     	{
     		tam=b[j]
     		b[j]=b[i];
     		b[i]=tam;
     	}
     	}
     }
     for(i=0;i<n*m;i++);
     a[i/m][i%m]=b[i];
 }
}
