package buoi4;

import java.util.Scanner;

import buoi2.Diem;

public class DiemMau extends Diem{
    private String mau;

	DiemMau(){
		super();
		mau = new String();
	}
	
	DiemMau(int x, int y, String mau){
		super(x, y);
		mau = new String(mau);
	}

	DiemMau(DiemMau dm){
		super((Diem) dm);
		mau = new String(dm.mau); 
	}
	
	public void GanMau(String mau){
		mau = new String(mau);
	}

	public void nhap(){
		super.nhap();
		System.out.print("Nhap mau: ");
		Scanner sc = new Scanner(System.in);		
		mau = sc.nextLine();
	}

	public void in(){
		super.in();
		System.out.print(", voi mau: " + mau);
	}
 
	public void in(String s){
		super.in(s);
		System.out.print(", voi mau: " + mau);		
	}

	public String toString(){		
		return super.toString() + ", voi mau: " + mau;
	}
}
