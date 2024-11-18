package BTHjava;
import java.util.Scanner;

public class bai8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;

        while (true) {
            System.out.print("Nhập một số nguyên: ");
            int number = scanner.nextInt();

            // Kiểm tra nếu số vừa nhập chia hết cho 4
            if (number % 4 == 0) {
                System.out.println("Gặp số chia hết cho 4: " + number);
                break; // Thoát khỏi vòng lặp
            }

            // Cộng dồn số vào tổng
            sum += number;
        }

        System.out.println("Tổng các số đã nhập trước đó là: " + sum);
        scanner.close();
    }
}
