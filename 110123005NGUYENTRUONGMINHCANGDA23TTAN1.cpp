#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 struct HocSinh {
 	char MaHS[10];
 	char TenHS[50];
 	char GioiTinh[5];
 	int NamSinh;
 	float DiemTBHK1;
 	float DiemTBHK2;
 	float KQCaNam;
	};
void NhapMang(int A[], int n){
	printf("Nhap mang mot chieu A:\n");
	
	int i;
 	for(i=0; i<n; i++);{
	 	printf("Nhap phan tu thu:");
	 	scanf("%d", &A[i]);
 	}
}


  
 int TinhTong(int A[], int n){
 int tong=0;
 int i;
 for(i=0; i<n; i++);{
 	tong+=A[i];
 	}
 	return tong;
 	}
 	
 	 
 	void NhapDanhSachHocSinh(struct HocSinh ds[], int n){
 		printf("Nhap danh sach hoc sinh:\n");
 		for(int i=0; i<n; i++){
 			printf("Nhap thong tin cho hoc sinh thu %d:\n", i+1);
 			printf("Ma hoc sinh:");
 			scanf("%s", ds[i].MaHS);
 			printf("Ten hoc sinh");
 		    scanf("%s", ds[i].TenHS);
 		    printf("Gioi tinh:");
 		    scanf("%s",ds[i].GioiTinh);
 		    printf("Nam sinh:");
 		    scanf("%d", &ds[i].NamSinh);
 		    printf("Diem TBHK1:");
 		    scanf("%f", ds[i].DiemTBHK1);
 		    printf("Diem TBHK2:");
 		    scanf("%f", ds[i].DiemTBHK2);
 		    ds[i].KQCaNam=(ds[i].DiemTBHK1+ds[i].DiemTBHK2*2)/3;
 		    }
 		}
 		
 		
 		void InDanhSachHocSinh(struct HocSinh ds[], int n){
 		    printf("Danh sach hoc sinh vua nhap:\n");
 		    int i;
 		    for (i=0; i<n; i++)
 		    {
		    	printf("Ma HS:%s, Ten HS:%s, Gioi tinh:%s, Nam sinh: %d, Diem TBHK1: %2f, Diem TBHK2: %2f, KQ Ca Nam: %2f\n",ds[i].MaHS, ds[i].TenHS, ds[i].GioiTinh, ds[i].NamSinh, ds[i].DiemTBHK1, ds[i].DiemTBHK2, ds[i].KQCaNam);
 		    }
 
		}
		
		
		
int main(){
	int choice, n;
	printf("Nhap so luong phan tu mang A:");
	scanf("%d", &n);
	int A[n];
	struct HocSinh dsHocSinh[n];
	do{
	
	
		printf("\n************************************\n");
		printf("*1. Nhap mang mot chieu A\n");
		printf("*2. Tinh tong cac phan tu cua mang A\n");
		printf("*3. Nhap danh sach hoc sinh\n");
		printf("4. In danh sach hoc sinh\n");
		printf("*0. Thoat\n");
		printf("*************************\n");
		printf("Nhap lua chon:");
		scanf("%d", &choice);
		switch(choice){
			case 1: NhapMang(A, n);
			break;
			case 2: printf("Tong cac phan tu cua mang A la: %d\n");
			TinhTong(A, n);
			break;
			case 3: NhapDanhSachHocSinh(dsHocSinh, n);
			break;
			case 4: InDanhSachHocSinh(dsHocSinh, n);
			break;
			case 0:
			exit(1);
			default:
				
			printf("\n Khong co chuc nang nay !");
			printf("\n An phim bat ki de tiep tuc!");
			getch();
			break;
			
			}
	} 
	   while(choice !=0);
	   return 0;
}
     
   
				
 		    
 			
 			
 		
 	
