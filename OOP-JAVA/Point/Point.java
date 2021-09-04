public class Point{
	private int x, y;
	public Point(){
		x = 0;
		y = 1;
	}
	public Point(int x1, int y1){
		x = x1;
		y = y1;
	}
	public void read(){
		x = MyUtil.scanner.nextInt();
		y = MyUtil.scanner.nextInt();
	}
	public void print(){
		System.out.println("(" + x + ", " + y + ")");
	}
	public void move(int dx, int dy){
		x += dx;
		y += dy;
	}
	public int getX(){
		return x;	   
	}
	public int getY(){
		return y;
	}
	public double distance(){
		return Math.sqrt((x * x) + (y * y));
	}
	public double distance(Point P){
		return Math.sqrt(Math.pow(x - P.getX(), 2) + Math.pow(y - P.getY(), 2));
	}
}