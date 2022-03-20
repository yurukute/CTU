package buoi4;

import java.util.Scanner;

import buoi2.Diem;

public class DiemMau extends Diem{
    private String mau;

	public DiemMau(){
		super();
		mau = new String();
	}
	
	public DiemMau(int x, int y, String maumoi){
		super(x, y);
		mau = new String(maumoi);
	}

	public DiemMau(DiemMau dm){
		super((Diem) dm);
		mau = new String(dm.mau); 
	}
	
	public void GanMau(String maumoi){
		mau = new String(maumoi);
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
