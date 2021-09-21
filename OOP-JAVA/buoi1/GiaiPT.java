package buoi1;

public class GiaiPT {
    public static void GiaiPTBac1(float a, float b){
        System.out.print(a == 0 ? b == 0 ? "Vô số nghiệm" : "Vô nghiệm" : "x =" + (-b/a));
    }
    public static void GiaiPTBac2(float a, float b, float c){
        if(a == 0)
            GiaiPTBac1(b, c);
        else{
            float delta = b*b - 4*a*c, x1, x2;
            if(delta > 0){
                x1 = (float) ((-b + Math.sqrt(delta)) / (2*a));
                x2 = (float) ((-b - Math.sqrt(delta)) / (2*a));
                System.out.print("x1 = " + x1 + ", x2 = " + x2);
            }
            else if (delta == 0){
                System.out.print("x1 = x2 = " + (-b/(2*a)));
            }
            else System.out.print("Vô nghiệm");
        }
    }
}
