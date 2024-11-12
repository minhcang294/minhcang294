import java.util.Scanner;
import javax.lang.model.util.ElementScanner14;
public class bai2{
public static void main(String[]args){
Scanner scanner = new Scanner(System.in);
System.out.print("nhap a=");
int a = scanner.nextInt();
System.out.print("nhap b=");
int b = scanner.nextInt();
if(a>b){
    System.out.print("so lon nhat la "+a);

}else if(b>a){
    System.out.print("so lon nhat la "+b);

}else{
    System.out.print("hai so bang nhau"+a);

}
 scanner.close();
}
}