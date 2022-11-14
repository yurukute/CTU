package New;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;

public class DDTExcel {
	
	// TODO Auto-generated method stub
	WebDriver driver;  
	protected static String result;
	
	@Test(dataProvider="testdata")
	public void DemoProject(String username, String password)
	{
		try {
			System.setProperty("webdriver.gecko.driver", "Path\\to\\geckodriver.exe");
			driver = new FirefoxDriver(); 
			
			driver.get("https://elearning.ctu.edu.vn/login/index.php");
			driver.findElement(By.name("username")).sendKeys(username);
			driver.findElement(By.name("password")).sendKeys(password);
					
			driver.findElement(By.id("loginbtn")).click(); 
					
			Thread.sleep(2500);
					
			Assert.assertTrue(driver.getTitle().matches("Welcome to CTU E-learning!"), "Invalid credentials");

			System.out.println("Login successful");
			
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@AfterMethod
	void ProgramTermination()
	{
		driver.quit();
	}
	
	@DataProvider(name="testdata")
	public Object[][] TestDataFeed()
	{
		New.ReadExcelFile config = new New.ReadExcelFile("Path\\to\\ElearningLoginCredentials.xlsx");
		
		int rows = config.getRowCount(0);
		
		Object[][] credentials = new Object[rows][2];
		
		for(int i=0; i<rows; i++)
		{
			credentials[i][0] = config.getData(0, i, 0);
			credentials[i][1] = config.getData(0, i, 1);	
		}		
		return credentials;
	}
}