import java.util.Scanner;

public class bai2{
    public static void main(String[] args) {       
        Scanner scanner = new Scanner(System.in);
        System.out.print("nhap gia tri a=");
        double a = scanner.nextDouble();
        System.out.print("nhap gia tri b=");
        double b = scanner.nextDouble();
        if(a!=0){
        double x = -b/a;
        System.out.print(" nghiem cua phuong trinh la: "+x);
 }else {
    if(b==0){
    System.out.print("phuong trinh co vo so nghiem");
    }else{
        System.out.print("phuong trinh vo nghiem");
    }
 }
 scanner.close();
    }
}