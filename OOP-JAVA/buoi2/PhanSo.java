package buoi2;

import java.util.Scanner;
    
public class PhanSo {
    private int tu, mau;

    public PhanSo(){
		tu  = 0;
		mau = 1;
    }

    public PhanSo(int a, int b){
		tu  = a;
		mau = b;
    }

    public void nhap(){
    	Scanner sc = new Scanner(System.in);
    	System.out.print("Tu so = ");
    	tu = sc.nextInt();
    	do{
			System.out.print("Mau so = ");
			mau = sc.nextInt();
			if(mau == 0)
				System.out.println("Mau khong the bang 0!");
    	} while (mau == 0);
    }

    public void in(){	
		if(mau < 0) tu = -tu;		
		// boolean dau = false;
		// if(tu < 0) {
		// 	dau = true;
		// 	tu = -tu;
		// }
		// for(int i = tu; i > 1; i--) {
		// 	if(mau % i == 0 && tu % i == 0) {
		// 		mau /= i;
		// 		tu /= i;
		// 		break;
		// 	}
		// }
		// if(dau) tu = -tu;
		System.out.println(tu == 0 ? 0 : mau == 1 ? tu : tu + "/" + mau);
    }

    public void nghichDao(){
		int t	= tu;
		tu	= mau;
		mau	= t;
    }

    public PhanSo giatriNghichDao(){
		return new PhanSo(mau, tu); 
    }
    
    public double giaTri(){
		return (double) tu / mau;
    }

    boolean lonHon(PhanSo a){
		return a.mau * tu > a.tu * mau;
    }

    PhanSo cong(PhanSo a){
		return new PhanSo(a.mau * tu + a.tu * mau, mau * a.mau);
    }

    PhanSo tru(PhanSo a){
		return new PhanSo(a.mau * tu - a.tu * mau, mau * a.mau);
    }

    PhanSo nhan(PhanSo a){
		return new PhanSo(tu * a.tu, mau * a.mau);
    }

    PhanSo chia(PhanSo a){
		return nhan(a.giatriNghichDao());
    }

    PhanSo cong(int a){
		return new PhanSo(tu + mau * a, mau);
    }

    PhanSo tru(int a){
		return new PhanSo(tu - mau * a, mau);
    }

    PhanSo nhan(int a){
		return new PhanSo(tu * a, mau);
    }

    PhanSo chia(int a){
		return new PhanSo(tu, mau * a);
    }
}
