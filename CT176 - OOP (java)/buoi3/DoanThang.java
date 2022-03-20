package buoi3;

import buoi2.Diem;

public class DoanThang {
    private Diem d1, d2;

    public DoanThang (){
		d1 = new Diem();
		d2 = new Diem();
    }

    public DoanThang(Diem x, Diem y){
		d1 = x;
		d2 = y;
    }

    public DoanThang(int ax, int ay, int bx, int by){
		d1 = new Diem(ax, ay);
		d2 = new Diem(bx, by);
    }

    public DoanThang(DoanThang s){
		d1 = new Diem(s.d1);
		d2 = new Diem(s.d2);
    }
    
    public void nhap(){	
		System.out.print("Nhap toa do diem dau: ");
		d1 = new Diem();
		d1.nhap();
		System.out.print("Nhap toa do diem cuoi: ");
		d2 = new Diem();
		d2.nhap();       
    }

    public void in(){
		System.out.print("[" + d1 + "; " + d2 + "]");
    }

    public void in(String s){
		System.out.println(s);
		System.out.print("[" + d1 + "; " + d2 + "]");
    }

    public String toString(){
		return "[" + d1 + "; " + d2 + "]";
    }

    public void tinhTien(int dx, int dy){
		d1.doiDiem(dx, dy);
		d2.doiDiem(dx, dy);
    }

    public double doDai(){
		return d1.khoangCach(d2);
    }

    public int goc(){
		int res = (int) Math.toDegrees((Math.atan2(d2.giatriY() - d1.giatriY(), d2.giatriX() - d1.giatriX())));
		return res < 0 ? res + 360 : res ;
    }
}
