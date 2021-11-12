package buoi5;

import java.util.Scanner;

public class ChiTiet {
	private int sluong;
	private float dgia;
	private HangHoa h;

	public ChiTiet(){
		sluong = 0;
		dgia   = 0.0f;
		h	   = new HangHoa();
	}

	public ChiTiet(ChiTiet s){
		sluong = s.sluong;
		dgia   = s.dgia;
		h	   = s.h;
	}

	public void nhap(){
		h.nhap();
		Scanner sc = new Scanner(System.in);		
		System.out.print("Nhap so luong: "); sluong = sc.nextInt();
		System.out.print("Nhap don gia: ");  dgia   = sc.nextFloat();
	}

	public void in(){
		h.in();
		System.out.println(", so luong: " + sluong + ", don gia: " + dgia);
	}

	public String toString(){
		return h + ", so luong: " + sluong + ", don gia: " + dgia;
	}

	public float thanhTien(){
		return sluong*dgia;
	}
}
