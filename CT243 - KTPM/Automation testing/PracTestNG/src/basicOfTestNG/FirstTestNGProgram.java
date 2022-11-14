package basicOfTestNG;

import org.testng.Assert;
import org.testng.annotations.Test;

public class FirstTestNGProgram {

	@Test(priority=2)
	public void tcl(){
		Assert.assertEquals(12, 14);
		System.out.println("My first TestNG Testcase");
	}
	
	@Test(priority=3)
	public void tc2(){
		System.out.println("My first TestNG Testcase");
	}
	
	@Test(priority=1)
	public void tc3(){
		System.out.println("My first TestNG Testcase");
	}
}
