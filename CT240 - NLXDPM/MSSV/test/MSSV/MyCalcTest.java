/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MSSV;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author student
 */
public class MyCalcTest {
    
    public MyCalcTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of add method, of class MyCalc.
     */
    @Test
    public void testAdd() {
        System.out.println("add");
        int a = 1;
        int b = 2;
        MyCalc instance = new MyCalc();
        int expResult = 3;
        int result = instance.add(a, b);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of mul method, of class MyCalc.
     */
    @Test
    public void testMul() {
        System.out.println("mul");
        int a = 2;
        int b = 5;
        MyCalc instance = new MyCalc();
        int expResult = 10;
        int result = instance.mul(a, b);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of sub method, of class MyCalc.
     */
    @Test
    public void testSub() {
        System.out.println("sub");
        int a = 3;
        int b = 2;
        MyCalc instance = new MyCalc();
        int expResult = 1;
        int result = instance.sub(a, b);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of div method, of class MyCalc.
     */
    @Test
    public void testDiv() {
        System.out.println("div");
        int a = 4;
        int b = 2;
        MyCalc instance = new MyCalc();
        int expResult = 2;
        int result = instance.div(a, b);
        assertEquals(expResult, result);
        try {
            instance.div(1,0);
        }
        catch (Exception e){
            assertEquals(e.getMessage(), "divide by zero"); 
        }
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of min method, of class MyCalc.
     */
    @Test
    public void testMin() {
        System.out.println("min");
        int a = 1;
        int b = 2;
        MyCalc instance = new MyCalc();
        int expResult = 1;
        int result = instance.min(a, b);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of max method, of class MyCalc.
     */
    @Test
    public void testMax() {
        System.out.println("max");
        int a = 1;
        int b = 9;
        MyCalc instance = new MyCalc();
        int expResult = 9;
        int result = instance.max(a, b);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of equals method, of class MyCalc.
     */
    @Test
    public void testEquals() {
        System.out.println("equals");
        int a = 2;
        int b = 2;
        MyCalc instance = new MyCalc();
        Boolean expResult = true;
        Boolean result = instance.equals(a, b);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of mux method, of class MyCalc.
     */
    @Test
    public void testMux() {
        System.out.println("mux");
        int x = 2;
        int n = 5;
        MyCalc instance = new MyCalc();
        int expResult = 32;
        int result = instance.mux(x, n);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of sqrt method, of class MyCalc.
     */
    @Test
    public void testQrt() {
        System.out.println("sqrt");
        int x = 12;
        MyCalc instance = new MyCalc();
        int expResult = 144;
        int result = instance.qrt(x);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of progression method, of class MyCalc.
     */
    @Test
    public void testProgression() {
        System.out.println("progression");
        int x = 1;
        int d = 1;
        int n = 5;
        MyCalc instance = new MyCalc();
        int expResult = 5;
        int result = instance.progression(x, d, n);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of sumProgression method, of class MyCalc.
     */
    @Test
    public void testSumProgression() {
        System.out.println("sumProgression");
        int x = 1;
        int d = 1;
        int n = 10;
        MyCalc instance = new MyCalc();
        int expResult = 55;
        int result = instance.sumProgression(x, d, n);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of main method, of class MyCalc.
     */
    @Test
    public void testMain() {
        System.out.println("main");
        String[] args = null;
        MyCalc.main(args);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
