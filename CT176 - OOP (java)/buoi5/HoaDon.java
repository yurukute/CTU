package buoi5;

import java.util.Scanner;

public class HoaDon {
	private String		mso, tde, nvien;
	private KhachHang	khach;
	private MyDate 		nglap;
	private ChiTiet 	c[];
	private int 		slg;
	
	public HoaDon(){
		mso	  = new String();
		tde	  = new String();
		nvien = new String();
		khach = new KhachHang();
		nglap = new MyDate();
		c 	  = new ChiTiet[20];
		slg	  = 0;
	}

	public HoaDon(HoaDon s){
		mso	  = new String(s.mso);
		tde	  = new String(s.tde);
		nvien = new String(s.nvien);
		khach = new KhachHang(s.khach);
		nglap = new MyDate(s.nglap);
		c 	  = new ChiTiet[s.c.length];
		slg   = s.slg;
		for(int i = 0; i < slg; i++)
			c[i] = new ChiTiet(s.c[i]);
	}

	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so hoa don: "); 			mso   = sc.nextLine();
		System.out.print("Nhap tieu de hoa don: "); 		tde   = sc.nextLine();
		System.out.print("Nhap ten nhan vien: "); 			nvien = sc.nextLine();
		System.out.print("Nhap thoi gian lap:\n");	 		nglap.nhap();
		System.out.print("Nhap thong tin khach hang (0) hay khach hang VIP (1):\n");
		int k = sc.nextInt();
		if(k == 0)
			khach = new KhachHang();
		else khach = new KhachHangVIP();
		khach.nhap();
		System.out.print("Nhap so luong mua hang: ");		slg = sc.nextInt();
		System.out.print("Nhap chi tiet cua hoa don:\n");
		for(int i = 0; i < slg; i++){
			System.out.print("Nhap thong tin cua mon hang thu " + (i+1) + "\n");
			c[i] = new ChiTiet();
			c[i].nhap();
		}
	}

	public void in(){
		System.out.print("Ma so: " + mso + "\n" + nglap);
		System.out.print("\n\t\t" + tde);
		System.out.print("\nNhan vien: " + nvien);
		System.out.print("\nKhach mua hang: " + khach);
		System.out.print("\nChi tiet hoa don: \n");		
		for(int i = 0; i < slg; i++){
			System.out.println("\t+ " + c[i]);
		}
		System.out.println("\nTong so tien: " + tong());				
	}

	public float tong(){
		float tong = 0;
		for(int i = 0; i < slg; i++){
			tong += c[i].thanhTien();
		}
		return tong - tong*khach.lay_tLeGiam();
	}
}
