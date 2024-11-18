package BTHjava;
import java.util.Scanner;
public class bai3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
      System.out.print("nhap gia tri N=  ");
      int N = scanner.nextInt();
      if(kiemtra(N)) {
    System.out.print(N+" la so nguyen to");
      }else {
    	  System.out.print(N+ "khong la so nguyen to");
      }
         
    scanner.close();
}
    public static boolean kiemtra(int N){
    	if(N<=2) {
    	return false;
    	}
     for(int i=2;i<=Math.sqrt(N);i++) {
    	 if(N % i==0) {
    		return false; 
    	 }
     }
    	return true; 
    }  
}
        