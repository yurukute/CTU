package buoi4;

import java.util.Scanner;

public class SDSVCNTT{
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		SinhVienCNTT s = new SinhVienCNTT();
		s.nhap();
		s.in();
		
		System.out.print("\nNhap so luong sinh vien: ");
		int n = sc.nextInt();
		SinhVienCNTT list[] = new SinhVienCNTT[n];
		for(int i = 0; i < n; i++){
			System.out.println("Nhap thong tin sinh vien thu " + (i+1) + ": ");
			list[i] = new SinhVienCNTT();
			list[i].nhap();
		}
		sc.nextLine();
		System.out.print("Nhap email sinh vien can tim: ");
		String str = new String(sc.nextLine());
		boolean found = false;
		for(int i = 0; i < n && !found; i++){
			if(str.equals(list[i].getEmail())){
				System.out.println("Tai khoan ELCIT cua sinh vien la: " + list[i].getTkhoan());
				System.out.println("Ket qua hoc tap cua sinh vien: " + list[i].diemTB());
				found = true;
			}
		}
		if(!found)
			System.out.println("Khong tim thay");
	}
}
