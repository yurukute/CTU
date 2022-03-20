package buoi3;

import java.util.Scanner;

public class SDSinhVien {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
		SinhVien a = new SinhVien();
		a.nhap();
		a.nhapDiem();
		a.themHP("LTHDT");
		System.out.println(a);	
		System.out.print("Nhap so sinh vien: ");
		int n = sc.nextInt();
		SinhVien list[] = new SinhVien[n];
		for(int i = 0; i < n; i++){	    
			list[i] = new SinhVien();
			System.out.println("Nhap thong tin sinh vien thu " + (i+1) +": ");
			list[i].nhap();
			list[i].nhapDiem();
		}
		SinhVien max = new SinhVien(list[0]);
		System.out.println("Cac sinh vien bi canh bao hoc vu: ");
		for(int i = 0; i < n; i++){
			if(list[i].diemTB() < 1.0)
				System.out.println(list[i]);
			if(list[i].diemTB() > max.diemTB())
				max = new SinhVien(list[i]);
		}
		System.out.println("Sinh vien co diem trung binh cao nhat la: " + max);
		for(int i = 0; i < n-1; i++){
			for(int j = i; j < n; j++){
				if(list[i].ten().compareTo(list[j].ten()) > 0) {
					SinhVien tam = list[i];
					list[i] = list[j];
					list[j] = tam;
				}
			}
		}	
		System.out.println("Danh sach sau khi sap xep: ");
		for(int i = 0; i < n; i++) {
			System.out.println(list[i]);
		}
    }
}
