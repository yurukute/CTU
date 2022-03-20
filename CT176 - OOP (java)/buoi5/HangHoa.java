package buoi5;

import java.util.Scanner;

public class HangHoa {
	private String mso, ten, nsxuat;

	public HangHoa(){
		mso = new String();
		ten = new String();
		nsxuat = new String();
	}

	public HangHoa(String _mso, String _ten, String _nsxuat){
		mso = new String(_mso);
		ten = new String(_ten);
		nsxuat = new String(_nsxuat);
	}

	public HangHoa(HangHoa s){
		mso = new String(s.mso);
		ten = new String(s.ten);
		nsxuat = new String(s.nsxuat);
	}

	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so hang hoa: "); 	mso = sc.nextLine();
		System.out.print("Nhap ten hang hoa: "); 	ten = sc.nextLine();
		System.out.print("Nhap ten nha san xuat: "); 	nsxuat = sc.nextLine();
	}

	public void in(){
		System.out.print("[" + mso + " - " + ten + " - " + nsxuat + "]");
	}

	public String toString(){
		return "[" + mso + " - " + ten + " - " + nsxuat + "]";
	}
	
}
