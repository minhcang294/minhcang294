package BTHjava;
import java.util.Scanner;

public class bai11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập N từ người dùng
        System.out.print("Nhập N (số lẻ lớn nhất trong dãy): ");
        int N = scanner.nextInt();

        // Kiểm tra nếu N không phải số lẻ
        if (N % 2 == 0) {
            System.out.println("Vui lòng nhập một số lẻ!");
            return; // Thoát chương trình nếu N không hợp lệ
        }

        // Tính tổng S
        int S = 0;
        for (int i = 1; i <= N; i += 2) {
            S += i; // Cộng các số lẻ vào S
        }

        // Hiển thị kết quả
        System.out.println("Tổng S = 1 + 3 + 5 + ... + " + N + " là: " + S);

        scanner.close();
    }
}
