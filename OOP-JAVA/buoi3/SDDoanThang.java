package buoi3;

import buoi2.Diem;

public class SDDoanThang{
    public static void main(String[] args){
		Diem A = new Diem(2, 5);
		System.out.println("Diem A: " + A);
		Diem B = new Diem(20, 35);
		System.out.println("Diem B: " + B);
		DoanThang AB = new DoanThang(A, B);
		System.out.println("Toa do doan thang AB: " + AB);
		AB.tinhTien(5, 3);
		System.out.println("Toa do doan thang AB (sau khi tinh tien): " + AB);	
		DoanThang CD = new DoanThang();
		CD.nhap();
		System.out.println("Toa do doan thang CD: " + CD);
		System.out.println("Do dai cua doan thang CD la: " + CD.doDai());
		System.out.println("Goc cua CD voi truc hoanh la: " + CD.goc());
    }
}
