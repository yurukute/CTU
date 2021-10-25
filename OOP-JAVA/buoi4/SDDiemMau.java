package buoi4;

import java.util.Scanner;

public class SDDiemMau{
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		DiemMau A = new DiemMau(5, 10, "trang");
		System.out.println("Toa do diem A: " + A);
		DiemMau B = new DiemMau();
		System.out.print("Nhap toa do diem B: ");
		B.nhap();
		System.out.println("Toa do diem B: " + B);
		B.doiDiem(10, 8);
		System.out.println("Toa do diem B sau khi doi: " + B);
		B.GanMau("vang");
		System.out.println("Toa do diem B sau khi gan mau: " + B);
	}
}
