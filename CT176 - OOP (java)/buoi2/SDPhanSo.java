package buoi2;

import java.util.Scanner;

public class SDPhanSo {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
		PhanSo a = new PhanSo(3, 7);
		PhanSo b = new PhanSo(4, 9);
		System.out.print("Phan so a = "); 	 a.in();
		System.out.print("Phan so b = "); 	 b.in();
		PhanSo x = new PhanSo(), y = new PhanSo();
		System.out.println("Nhap phan so x:"); 	 x.nhap();
		System.out.println("Nhap phan so y:" );  y.nhap();
		System.out.print("Nghich dao cua x = "); x.giatriNghichDao().in();
		System.out.print("x + y = "); 		 x.cong(y).in();
		System.out.print("Nhap so phan tu n: ");
		int n = sc.nextInt();
		PhanSo[] list = new PhanSo[n];
		PhanSo sum = new PhanSo();
		PhanSo max = new PhanSo();
		for(int i = 0; i < n; i++) {
			System.out.print("Nhap phan so thu " + (i+1) + ":\n");
			list[i] = new PhanSo();
			list[i].nhap();
			sum = sum.cong(list[i]);
			if(list[i].lonHon(max))
				max = list[i];
		}
		System.out.print("Tong cua danh sach tren la: "); sum.in();
		System.out.print("Phan so lon nhat la: "); max.in();
		for(int i = 0; i < n-1; i++) {
			for(int j = i+1; j < n; j++) {
				if(list[i].lonHon(list[j])) {
					PhanSo t = list[i];
					list[i]  = list[j];
					list[j]  = t;
				}
			}
		}
		System.out.println("Danh sach sau khi da sap xep la: ");
		for(int i = 0; i < n; i++) {
			list[i].in();
		}
	
    }
}
