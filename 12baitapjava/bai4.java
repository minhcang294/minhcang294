package BTHjava;

import java.util.Scanner;

public class bai4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhập một số nguyên dương N: ");
        int N = scanner.nextInt();
        
        if (N < 0) {
            System.out.println("Không thể tính giai thừa cho số âm.");
        } else {
            long giaithua = giatri(N);
            System.out.println("Giai thừa của " + N + " là: " + giaithua);
        }   
        scanner.close();
    } 
    public static long giatri(int N) {
        long result = 1;
        for (int i = 1; i <= N; i++) {
            result *= i; 
        }
        return result;
    }
}
