package BTHjava;
import java.util.Scanner;

public class bai10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập giá trị m và n
        System.out.print("Nhập m: ");
        int m = scanner.nextInt();

        System.out.print("Nhập n: ");
        int n = scanner.nextInt();

        // Tính m^n
        long result = power(m, n);

        // Hiển thị kết quả
        System.out.println(m + " mũ " + n + " = " + result);

        scanner.close();
    }

    // Hàm tính m^n
    public static long power( int base, int exponent) {   // base cơ số, exponent số mũ
        long result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;  // result= result*base và gán lại cho result
        }
        return result;
    }
}
