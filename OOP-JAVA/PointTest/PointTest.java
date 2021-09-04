public class PointTest{
	public static void main(String[] args){
		Point A = new Point(3, 4);
		A.print();
		Point B = new Point();
		B.read();
		B.print();
		Point C = new Point(-B.getX(), -B.getY());
		C.print();
		System.out.println(B.distance());
		System.out.println(A.distance(B));
	}
}