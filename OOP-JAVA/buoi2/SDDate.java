package buoi2;

import java.util.Scanner;

public class SDDate {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
		Date today = new Date();
		today.nhap();
		System.out.print("Ngay da nhap la: "); today.in();
		System.out.print("Ngay hom sau cua ngay da nhap la: "); 
		today.ngayHomSau().in();
		System.out.print("Nhap so ngay can cong them: ");
		int n = sc.nextInt();
		System.out.print("Ngay da nhap cong them " + n + " ngay la: ");
		today.congNgay(n).in();
    }
}
