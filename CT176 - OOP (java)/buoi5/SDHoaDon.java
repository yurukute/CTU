package buoi5;

import java.util.Scanner;

public class SDHoaDon {
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		HoaDon s = new HoaDon();
		s.nhap();
		s.in();
		System.out.print("\nNhap so luong hoa don: ");
		int n = sc.nextInt();
		HoaDon list[] = new HoaDon[n];
		for(int i = 0; i < n; i++){
			System.out.println("Nhap hoa don thu " + (i+1) + ":");
			list[i] = new HoaDon();
			list[i].nhap();			
		}
		for(int i = 0; i < n; i++){
			System.out.println("\nHoa don thu " + (i+1) + ":");
			list[i].in();
		}
	}
}
