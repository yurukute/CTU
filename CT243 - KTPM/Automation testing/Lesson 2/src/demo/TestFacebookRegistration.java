package demo;

import java.util.List;
import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;

public class TestFacebookRegistration {
	
	public static void main(String[] args) {
		System.setProperty("webdriver.gecko.driver", "Path\\to\\geckodriver.exe");
		WebDriver driver = new FirefoxDriver();
		driver.get("https://vi-vn.facebook.com/");
		driver.manage().window().maximize();
		
		driver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
		driver.manage().timeouts().pageLoadTimeout(30, TimeUnit.SECONDS);
		
		//driver.findElement(By.xpath("//*[text()='Tạo tài khoản mới']")).click();
		driver.findElement(By.linkText("Tạo tài khoản mới")).click();;
		
		driver.findElement(By.name("lastname")).sendKeys("Lê");
		driver.findElement(By.name("firstname")).sendKeys("Dương");
		
		List <WebElement> gender = driver.findElements(By.name("sex"));
		gender.get(0).click();
		
		//Select day
		Select sel1 = new Select(driver.findElement(By.id("day")));
		sel1.selectByIndex(5);
		//Select month
		Select sel2 = new Select(driver.findElement(By.id("month")));
		sel2.selectByIndex(3);
		//Select year
		Select sel3 = new Select(driver.findElement(By.id("year")));
		sel3.selectByValue("2000");
		
		driver.findElement(By.name("websubmit")).click();
		
		//click on a link to go to next page
		driver.findElement(By.linkText("Tìm hiểu thêm")).click();
		
		//back
		driver.navigate().back();
		//quit
		driver.quit();
	}

}
