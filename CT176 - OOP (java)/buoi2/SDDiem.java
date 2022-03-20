package buoi2;

public class SDDiem {
    public static void main(String[] args){
		Diem A = new Diem(3, 4);
		System.out.print("Toa do diem A: "); A.in();
		Diem B = new Diem();
		System.out.print("Nhap toa do diem B: "); B.nhap();
		System.out.print("Toa do diem B: "); B.in();
		Diem C = new Diem(-B.giatriX(), -B.giatriY());
		System.out.print("Toa do diem C doi xung voi B qua goc toa do: "); C.in();
		System.out.println("Khoang cach tu B den O: " + B.khoangCach());
		System.out.println("Khoang cach tu A den B: " + A.khoangCach(B));
    }    
}
