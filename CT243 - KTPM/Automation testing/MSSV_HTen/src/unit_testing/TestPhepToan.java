package unit_testing;

import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;

import thuvien.tinhtoan.PhepTinh;

public class TestPhepToan {
	unit_testing.ReadExcelFile testdata = new ReadExcelFile("../../TestData.xlsx");
	
	@Test(dataProvider="congdata")
	public void TestCong(float a, float b, float result){
		Assert.assertEquals(PhepTinh.Op('+', a, b), result);
		System.out.println("	Tinh toan dung.");
	}
	
	@Test(dataProvider="trudata")
	public void TestTru(float a, float b, float result){
		Assert.assertEquals(PhepTinh.Op('-', a, b), result);
		System.out.println("	Tinh toan dung.");
	}
	
	@Test(dataProvider="nhandata")
	public void TestNhan(float a, float b, float result){
		Assert.assertEquals(PhepTinh.Op('*', a, b), result);
		System.out.println("	Tinh toan dung.");
	}
	
	@BeforeMethod
	public void BeforeTest(){
		System.out.println("Before testcase");
	}
	@AfterMethod
	public void AfterTest(){
		System.out.println("After testcase");
	}
	
	@DataProvider(name="congdata")
	public Object[][] CongData(){
		int rows = testdata.getRowCount(0);
		Object[][] pheptinh = new Object[rows][3];
		for(int i=0; i<rows; i++)
		{
			pheptinh[i][0] = (float) testdata.getData(0, i, 0);
			pheptinh[i][1] = (float) testdata.getData(0, i, 1);
			pheptinh[i][2] = (float) testdata.getData(0, i, 2);
		}
		return pheptinh;
	}
	
	@DataProvider(name="trudata")
	public Object[][] TruData(){
		int rows = testdata.getRowCount(1);
		Object[][] pheptinh = new Object[rows][3];
		for(int i=0; i<rows; i++)
		{
			pheptinh[i][0] = (float) testdata.getData(1, i, 0);
			pheptinh[i][1] = (float) testdata.getData(1, i, 1);
			pheptinh[i][2] = (float) testdata.getData(1, i, 2);
		}
		return pheptinh;
	}
	
	@DataProvider(name="nhandata")
	public Object[][] NhanData(){
		int rows = testdata.getRowCount(2);
		Object[][] pheptinh = new Object[rows][3];
		for(int i=0; i<rows; i++)
		{
			pheptinh[i][0] = (float) testdata.getData(2, i, 0);
			pheptinh[i][1] = (float) testdata.getData(2, i, 1);
			pheptinh[i][2] = (float) testdata.getData(2, i, 2);
		}
		return pheptinh;
	}
}
