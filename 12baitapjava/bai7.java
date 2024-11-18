package BTHjava;
import java.util.Scanner;
public class bai7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập số lượng phần tử của mảng
        System.out.print("Nhập số lượng phần tử trong mảng: ");
        int n = scanner.nextInt();

        // Khởi tạo mảng với số phần tử đã nhập
        int[] array = new int[n];

        // Nhập các phần tử của mảng
        System.out.println("Nhập các phần tử của mảng:");
        for (int i = 0; i < n; i++) {
            System.out.print("Phần tử " + (i+1 ) + ": ");// i=0 + 1=1 phan tử =1 2 3 
            array[i] = scanner.nextInt();
        }

        // In ra các số chẵn trong mảng
        System.out.println("Các số chẵn trong mảng là:");
        for (int i = 0; i < n; i++) {
            if (array[i] % 2 == 0) {
                System.out.print(array[i]+ " ");// dấu cách giúp các số có khoảng trắng
            }
        }

        scanner.close();
    }
}
