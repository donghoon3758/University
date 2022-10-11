
public class HourlyEmployee extends Employee{
	private double basicPay;
	private double payRate;
	private int hoursWorked;
	private String contractexpdate;
	private double monthlyPay;
	public HourlyEmployee(String name,String address,String department,String contractexpdate,double basicPay,double payRate)
	{
		super(name,address,department);
		this.basicPay=basicPay;
		this.payRate=payRate;
		this.contractexpdate=contractexpdate;
	}
	@Override
	public double pay() {
		return monthlyPay=basicPay+hoursWorked*payRate;
	}
	
public void addHours(int add) {
	hoursWorked=hoursWorked+add;
}
@Override
public String toString() {
	String str2 = String.format("이름:%s\n주소:%s\n소속부서:%s\n시간당임금:%2.1f\n근무시간:%d", name,address,department,payRate,hoursWorked);
	return str2;
}
}
