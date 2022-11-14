package AssertionDemo;

import org.testng.Assert;
import org.testng.annotations.Test;

public class AssertionScript2 {

	@Test
	public void test1(){
		String str = "Khoa CNTT";
		Assert.assertTrue(str.contains("KT"), "Name are not matching");
	}
	
	@Test
	public void test2(){
		Assert.assertTrue(false);
	}
	
}
