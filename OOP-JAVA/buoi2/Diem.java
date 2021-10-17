package buoi2;

import java.util.Scanner;

public class Diem {
    private int x, y;
    
    public Diem(){
		x = 0;
		y = 0;
    }
    public Diem(int x1, int y1){
		x = x1;
		y = y1;
    }
    public Diem(Diem s){
		x = s.x;
		y = s.y;
    }
    public void nhap(){
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		y = sc.nextInt();	
    }
    public void in(){
		System.out.println("(" + x + ", " + y + ")");
    }
    public void in(String s){
		System.out.println(s);
		System.out.println("(" + x + ", " + y + ")");
    }
    
    public String toString(){
		return "(" + x + ", " + y + ")";
    }
    public void doiDiem(int dx, int dy){
		x += dx;
		y += dy;
    }
    public int giatriX(){
		return x;	   
    }
    public int giatriY(){
		return y;
    }
    public double khoangCach(){
		return Math.sqrt((x * x) + (y * y));
    }
    public double khoangCach(Diem d){
		return Math.sqrt(Math.pow(x - d.giatriX(), 2) + Math.pow(y - d.giatriY(), 2));
    }    
}
