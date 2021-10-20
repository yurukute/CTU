package buoi1;

import java.util.Scanner;

public class TachTen{
    public static String layTen(String hoten){
		hoten = hoten.trim();
		return hoten.substring(hoten.lastIndexOf(" ") + 1);
    }
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
		String hoten = sc.nextLine();
		System.out.print(layTen(hoten));
    }
}
