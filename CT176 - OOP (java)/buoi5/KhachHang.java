package buoi5;

import java.util.Scanner;

public class KhachHang {
	private String cccd, hten, dchi;

	public KhachHang(){
		cccd = new String();
		hten = new String();
		dchi = new String();
	}

	public KhachHang(KhachHang s){
		cccd = new String(s.cccd);
		hten = new String(s.hten);
		dchi = new String(s.dchi);
	}

	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so can cuoc cong dan: "); 	cccd = sc.nextLine();
		System.out.print("Nhap ho ten: "); 					hten = sc.nextLine();
		System.out.print("Nhap dia chi: ");					dchi = sc.nextLine();
	}

	public void in(){
		System.out.print("[" + cccd + " - " + hten + " - " + dchi + "]");
	}

	public String toString(){
		return "[" + cccd + " - " + hten + " - " + dchi + "]";
	}

	public float lay_tLeGiam(){
		return 0;
	}
}
