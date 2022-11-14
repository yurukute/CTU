package Bookings;

import org.testng.annotations.AfterTest;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Test;

public class BookFlight {

	@BeforeMethod
	public void BeforeMethodTestcase(){
		System.out.println("This code will be run before every testcase");
	}
	
	@BeforeMethod
	public void AfterMethodTestcase(){
		System.out.println("This code will be run after every testcase");
	}
	
	@Test
	public void BookFlight_RoundTrip_Testcase1(){
		System.out.println("TestCase1");
	}
	
	@Test(dependsOnMethods={"BookFlight_RoundTrip_Testcase1"})
	public void BookFlight_RoundTrip_Testcase2(){
		System.out.println("TestCase2");
	}
	
	@BeforeTest
	public void Beforetesttestcases(){
		System.out.println("This should be first");
	}
	
	@AfterTest
	public void Aftertesttestcases(){
		System.out.println("This should be last");
	}

	@Test
	public void BookFlight_OneWay_Testcase3(){
		System.out.println("TestCase3");
	}
	
	@Test(enabled=false)
	public void BookFlight_OneWay_Testcase4(){
		System.out.println("TestCase4");
	}
}
