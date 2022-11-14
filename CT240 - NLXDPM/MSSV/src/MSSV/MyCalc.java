/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MSSV;
/**
 *
 * @author student
 */
public class MyCalc {
    public int add(int a, int b){
        return a + b;
    }
    public int mul(int a, int b){
        return a*b;
    }
    public int sub(int a, int b){
        return a - b;
    }  
    public int div(int a, int b){
        if (b == 0) {
            throw new ArithmeticException("divide by zero");
        }
        return a/b;
    }
    public int min(int a, int b){
        return a < b ? a : b;
    }
    public int max(int a, int b){
        return a > b ? a : b;
    }
    public Boolean equals(int a, int b){
        return a == b;
    }
    public int mux(int x, int n){
        int res = 1;
        for(int i = 0; i < n; i++){
            res*=x;
        }
        return res;
    }
    public int qrt(int x){
        return x*x;
    }
    public int progression(int x, int d, int n){
        return x + (n-1)*d;
    }
    public int sumProgression(int x, int d, int n){       
        return n*x + n*(n-1)*d/2;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
