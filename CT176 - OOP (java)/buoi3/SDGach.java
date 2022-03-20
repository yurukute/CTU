package buoi3;

import java.util.Scanner;

public class SDGach {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
		int n;
		System.out.print("Nhap n: "); n = sc.nextInt();
		Gach[] list = new Gach[n];
		for(int i = 0; i < n; i++){
			System.out.print("Nhap thong tin hop gach thu " + (i+1) + ": ");
			list[i].nhap();
		}
		System.out.println("Cac loai gach vua nhap la: ");	
		for(int i = 0; i < n; i++){
			list[i].in();
		}
		Gach min = new Gach(list[0]);
		for(int i = 1; i < n; i++){
			if(list[i].chiPhi() < min.chiPhi()){
				min = new Gach(list[i]);
			}
		}
		System.out.println("Loai gach co chi phi lot thap nhat la: ");
		min.in();
		for(int i = 0; i < n; i++){
			list[i].in();
			System.out.println("Chi phi lot dien tich 5x20 la: " + (list[i].chiPhi() * 5 * 20 * list[i].soLuongHop(5, 20)));
		}
    }
}
