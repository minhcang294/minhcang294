package BTHjava;

public class bai9 {
    public static void main(String[] args) {
        int M = 2;
        int N = 7;

        System.out.println("Các số nguyên tố từ " + M + " đến " + N + ":");
        for (int i = M; i <= N; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }

    // Hàm kiểm tra số nguyên tố
    public static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
