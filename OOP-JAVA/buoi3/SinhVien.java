package buoi3;

import java.util.Scanner;

import buoi2.Date;

public class SinhVien {
    private String mssv, hten;
    private Date nsinh;

    private int slg, max;
    private String tenHP[], diemHP[];

    public SinhVien(){
		mssv	= new String();
		hten	= new String();
		nsinh	= new Date();
		slg	= 0;
		max	= 25;
		tenHP	= new String[max]; 
		diemHP	= new String[max];
    }

    public SinhVien(SinhVien s){
		mssv	= new String(s.mssv);
		hten	= new String(s.hten);
		nsinh	= new Date(s.nsinh);
		slg	= s.slg;
		max	= s.max;
		tenHP	= new String[max]; 
		diemHP	= new String[max];
		for(int i = 0; i < slg; i++){
			tenHP[i]  = new String(s.tenHP[i]);
			diemHP[i] = new String(s.diemHP[i]);
		}
    }
    
    public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("MSSV: "); 	 mssv = sc.nextLine();
		System.out.print("Ho va ten: "); hten = sc.nextLine();
		System.out.print("Ngay sinh: "); nsinh.nhap();
		System.out.print("So luong hoc phan dang ky:"); slg = sc.nextInt();
		sc.nextLine();
		for(int i = 0; i < slg; i++){	    
			System.out.print("Ten hoc phan thu " + (i+1) + ": ");
			tenHP[i] = sc.nextLine();
		}
    }

    public void nhapDiem(){
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < slg; i++){
			System.out.print("Nhap diem cho hoc phan " + tenHP[i] + ": ");
			diemHP[i] = sc.nextLine();		
		}
    }

	public void in(){
		System.out.print(mssv + " - " + hten + " - " + nsinh.toString());
	}
	
    public String toString(){
		return mssv + " - " + hten + " - " + nsinh.toString();
    }

    public float diemTB(){
		int sum = 0;
		for(int i = 0; i < slg; i++){
			switch (diemHP[i]){
			case "A":
				sum += 4;
				break;
			case "B+":
				sum += 3.5;
				break;
			case "B":
				sum += 3;
				break;
			case "C+":
				sum += 2.5;
				break;
			case "C":
				sum += 2.0;
				break;
			case "D+":
				sum += 1.5;
				break;
			case "D":
				sum += 1.0;
				break;
			default: break;
			}
		}
		return (float) sum / slg;	
    }

    public void themHP(String HP){
		if(slg == max)
			System.out.println("Qua so luong hoc phan toi da");
		else{
			for(int i = 0; i < slg; i++){
				if(tenHP[i].equals(HP)){
					System.out.println("Hoc phan da ton tai");
					return;
				}		    
			}
			tenHP[slg] = new String(HP);
			slg++;
		}
    }

    public void xoaHP(String HP){
		for(int i = 0; i < slg; i++){
			if(tenHP[i].equals(HP)){
				for(int j = i; j < slg-1; j++){
					tenHP[j] = new String(tenHP[j+1]);
				}
				slg--;
				return;
			}
		}
		System.out.print("Chua dang ky hoc phan");
    }
    
    public String ten() {
		hten = hten.trim();
		return hten.substring(hten.lastIndexOf(" ") + 1);
    }
}
