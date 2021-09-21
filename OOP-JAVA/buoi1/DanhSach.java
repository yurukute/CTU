package buoi1;

import java.util.Scanner;
	
public class DanhSach {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
        int n = sc.nextInt(), a[] = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();   
        }     
        int x = sc.nextInt(), count = 0;
        for(int i : a) {
            if(i == x) count++;
        }
        System.out.println(count);
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(a[i] > a[j]){
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;                
                }
            }
        }
        for(int i : a) {
            System.out.print(i + " ");
        }
    }
}
