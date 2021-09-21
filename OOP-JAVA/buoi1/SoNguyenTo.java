package buoi1;

import java.util.Scanner;
import java.util.Stack;

public class SoNguyenTo {
     public static Scanner sc = new Scanner(System.in);
     public static void main(String[] args) {
        int n = sc.nextInt();         
        boolean flag = n < 2 ? false : true;
        for (int i = 2; i*i <= n; i++){
            if (n % i == 0) {
                flag = false;
                break;
            }
        }
        System.out.println(flag ? "n là số nguyên tố" : "n không là số nguyên tố");        
        Stack<Integer> st = new Stack<Integer>();
        for(; n > 0; n /=2) {
            st.push(n % 2);
        }
        for(; !st.empty(); System.out.print(st.pop()));        
    }
}
