package AssertionDemo;

import org.testng.Assert;
import org.testng.annotations.Test;

public class AssertionScript {

	@Test
	public void test1(){
		System.out.println("Testcase 1 started");
		Assert.assertEquals(12, 13);
		System.out.println("Testcase 1 completed");
	}
	
	@Test
	public void test2(){
		System.out.println("Testcase 2 started");
		Assert.assertEquals(12, 13, "Dropdown count does not match. Please check it with developer!");
		System.out.println("Testcase 2 completed");
	}
	
	@Test
	public void test3(){
		System.out.println("Testcase 3 started");
		Assert.assertEquals(12, 12, "Dropdown count does not match. Please check it with developer!");
		System.out.println("Testcase 3 completed");
	}
}
