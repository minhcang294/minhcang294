package BTHjava;
import java.util.Scanner;

public class bai12 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập N từ người dùng
        System.out.print("Nhập N (số nguyên dương): ");
        int N = scanner.nextInt();

        if (N < 1) {
            System.out.println("Vui lòng nhập một số nguyên dương lớn hơn hoặc bằng 1!");
            return;
        }

        // Tính tổng S
        long S = 0;
        for (int i = 1; i <= N; i++) {
            S += factorial(i); // Tính i! và cộng vào S
        }

        // Hiển thị kết quả
        System.out.println("Tổng S = 1! + 2! + ... + " + N + "! là: " + S);

        scanner.close();
    }

    // Hàm tính giai thừa của một số
    public static long factorial(int num) {
        long fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i; // Nhân dần từ 1 đến num
        }
        return fact;
    }
}
