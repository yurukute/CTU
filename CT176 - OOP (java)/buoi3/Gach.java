package buoi3;

import java.util.Scanner;

public class Gach {
    private String maso, mausac;
    private int solg, cdai, cngang;
    private long gia;
    
    public Gach() {
		maso = mausac = new String();
		solg = cdai = cngang = 0;
		gia = 0;
    }
    
    public Gach(String maso1, String mausac1, int solg1, int cdai1, int cngang1, long gia1) {
		maso	= maso1;
		mausac	= mausac1;
		solg	= solg1;
		cdai	= cdai1;
		cngang	= cngang1;
		gia	= gia1;
    }

    public Gach(Gach s){
		maso	= new String(s.maso);
		mausac	= new String(s.mausac);
		solg	= s.solg;
		cdai	= s.cdai;
		cngang	= s.cngang;
		gia	= s.gia;
    }
    
    public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("\t- Ma so: ");	maso	= sc.nextLine();
		System.out.print("\t- Mau sac: ");	mausac	= sc.nextLine();
		System.out.print("\t- So luong: ");	solg	= sc.nextInt();
		System.out.print("\t- Chieu dai: ");	cdai   	= sc.nextInt();
		System.out.print("\t- Chieu ngang: ");	cngang 	= sc.nextInt();
		System.out.print("\t- Gia: ");		gia    	= sc.nextLong();
    }
    
    public void in(){
		System.out.println("Hop gach ma so" + maso + ": ");       
		System.out.println("\t- Mau sac: "     + mausac);
		System.out.println("\t- So luong: "    + solg);
		System.out.println("\t- Chieu dai: "   + cdai);
		System.out.println("\t- Chieu ngang: " + cngang);
		System.out.println("\t- Gia: "         + gia);
    }
    
    public float giaBanLe(){
		return (float) (gia / solg * 1.2); 
    }
    
    public int dienTich(){
		return solg * cdai * solg * cngang;	
    }

    public int soLuongHop(int D, int N){
		return (int) Math.ceil(D*N / dienTich());
    }

    public float chiPhi(){
		return (float) gia / dienTich();
    }
}
