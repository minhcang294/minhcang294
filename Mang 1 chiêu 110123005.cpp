#include<stdio.h>
#include<conio.h>
#include<math.h>

 void xuatMang();
 void timmax();
 void tinhtich();
 void tongvademsnt();
 void timvitri();
 void sapxep();
 
 int a[10], n, i;
  
  
 int main()
 {
 printf("nhap so phan tu cua mang:");
 scanf("&d",&n);
 
 for(i=0; i<n; i++)
 {
 	printf("nhap phan tu thu a[%d]:",i);
 	scanf("%d",&a[i]);
 	}
   
   
  xuatmang();
  timmax();
  tinhtich();
  tongvademsnt();
  timvitri();
  sapxep();
 }
 
 
  
  
  
 void xuatMang()
{
  printf("\n mang vua nhap la:");
  for(i=0;i<n;i++) 
  {
    printf("%d", &a[i]);
  }
}
    
     
  
  void timmax(){
  int max, j=1;
  max=a[0];
  for(i=0; i,n; i++){
  if(a[j]>a[i]){
  	max=a[j], j++;
  	}
  printf("\n gia tri lon nhat la: %d", max );
 	}
 
   
   void tinhtich(){
   	int tich=1;
   	for(i=0;i<n;i++)
   	tich=tich*a[i];
   	printf("\ntich cac gia tri la: %d, tich");
   	}
   
   void tongvademsnt(){
   	int dem=0, tong=o, j;
   	for(i=0;i<n;i++){
   		if(a[i]%i==0){
   			tong+=a[i];
   			dem++;
   			}
   			}
   			}
 printf("\n tong snt cua mang la: %d", tong);
  printf("\n trong mang co %d snt",dem);
  }




  void timvitri(){
  	int x, t=0
   printf("\n nhap vao gia tri x:");
  	scanf("&d",&x);
  	
  	
  	for(i=0;i<n;i++){
  	iff](x==a[i]){
  		printf(" vi tri cua x la a[%d]", i);
  		t++;
    }
  	}
    if(t==0)
    printf("\n x khong ton tai !");
  }



void chen(){
  	n=n=1;
  	int y, z;
  	printf("\n nhap gia tri can chen la:");
  	scanf("%d",&y);
  	printf("\n nhap vi tri can chem:")
  	scanf("%d",&z);
  	for(i=n_1;i>z;i--){
  		a[i]=a[i-1];
  		a[z]=y;
  		
  	}
  	
  }
   void timandxoae(){
   	int e;
   	printf("\n nhap gia tri can xoa:");
   	scanf("%d", &e);
   }
