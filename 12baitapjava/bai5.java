 package BTHjava;
 import java.util.Scanner;
 public class bai5 {
 public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in);
   System.out.print("nhap gia tri a=");
   double a = scanner.nextDouble();
   System.out.print("nhap gia tri b=");
   double b = scanner.nextDouble();
   System.out.print("nhap gia tri c=");
   double c = scanner.nextDouble();
   if(a==0) {
 System.out.print("khong phai la phuong trinh bac 2");	  
   }else {
	   double delta = b*b-4*a*c;
	   System.out.print("Delta="+delta);
	    
   if (delta > 0){
   double x1 =(-b+Math.sqrt(delta))/(2*a);
   double x2 =(-b-Math.sqrt(delta))/(2*a);
    System.out.print("nghiem cua phuong trinh la");
    System.out.print("x1="+x1);
    System.out.print("x2="+x2);
    }else if (delta==0) {
    	double x = (-b/(2*a));
    	System.out.print("phuong trinh co mot nghiem kep la x="+x );
    }else {
    	System.out.print("phuong trinh khong co nghiem thuc");
    }
   }
   scanner.close();
	}
    
} 
 