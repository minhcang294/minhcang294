package BTHjava;
import java.util.Scanner;
public class bai6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhập số phần tử của mảng: ");
        int n = scanner.nextInt();
        int[] array = new int[n];
        System.out.print("nhap cac phan tu cua mang:");
        for (int i = 0;i<n;i++) {
        	System.out.print("  nhap phan tu thu "+( i + 1)+":");
        	array[i]= scanner.nextInt();  	
        }
        int max = timmax(array);
        System.out.print("so nguyen lon nhat la   "+max);
        scanner.close();
         }
    public static int timmax(int[]array) {
    	int max = array[0];      
    	for(int i=1;i<array.length;i++) {  // array.lenght đếm số luong phần tử 
    		if(array[i]>max) {
    			max=array[i];
    		}
    	}
    	return max;
    }

}