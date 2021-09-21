package buoi2;

import java.util.Scanner;

public class Date {
    private int ngay, thang, nam;

    public Date() {
	ngay 	= 1;
	thang 	= 1;
	nam 	= 1;
    }

    public Date(int ngay1, int thang1, int nam1) {
	ngay 	= ngay1;
	thang 	= thang1;
	nam 	= nam1;
    }

    public void nhap() {
	Scanner sc = new Scanner(System.in);	
	do {
	    System.out.print("Nhap ngay: ");
	    ngay = sc.nextInt();
	    System.out.print("Nhap thang: ");
	    thang = sc.nextInt();
	    System.out.print("Nhap nam: ");
	    nam = sc.nextInt();
	    if (!hople())
		System.out.println("Vui long nhap dung dinh dang.");
	} while (!hople());
    }

    public void in() {
	System.out.println(ngay + "/" + thang + "/" + nam);
    }
    
    public boolean hople(){
	int[] max = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
	    max[1] = 29;
	return (ngay <= max[thang-1]);
    }
    
    public Date ngayHomSau() {
	Date kq = new Date(ngay, thang, nam);
	kq.ngay += 1;
	if(!kq.hople()) {
	    kq.ngay = 1;
	    kq.thang = (kq.thang == 12) ? 1 : kq.thang + 1;
	    kq.nam = (kq.thang == 1) ? kq.nam + 1 : kq.nam;
	}
	return kq;
    }
    
    public Date congNgay(int n) {
	Date kq = new Date(ngay, thang, nam);
	for(int i = 1; i <= n; i++) {
	    kq.ngay += 1;
	    if(!kq.hople()) {
		kq.ngay = 1;
		kq.thang = (kq.thang == 12) ? 1 : kq.thang + 1;
		kq.nam = (kq.thang == 1) ? kq.nam + 1 : kq.nam;
	    }
	}	
	return kq;
    }      
}

