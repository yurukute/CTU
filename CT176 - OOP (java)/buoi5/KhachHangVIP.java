package buoi5;

import java.util.Scanner;

public class KhachHangVIP extends KhachHang {
	private float tLeGiam;
	private MyDate d;
	
	public KhachHangVIP(){
		super();
		tLeGiam = 0;
		d = new MyDate();
	}
	
	public KhachHangVIP(KhachHangVIP s){
		super(s);
		tLeGiam = s.tLeGiam;
		d = new MyDate(s.d);
	}

	public void nhap(){
		super.nhap();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ti le mien giam: "); 		tLeGiam = sc.nextFloat();
		System.out.print("Nhap thoi gian tro thanh VIP: "); d.nhap();
	}

	public void in(){
		super.in();
		System.out.print(", ti le mien giam: " + tLeGiam + ", thoi gian tro thanh VIP: " + d);
	}

	public String toString(){
		return super.toString() + ", ti le mien giam: " + tLeGiam + ", thoi gian tro thanh VIP: " + d;
	}

	public float lay_tLeGiam(){
		return tLeGiam;
	}
}
