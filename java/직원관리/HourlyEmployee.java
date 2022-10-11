
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
	String str2 = String.format("�̸�:%s\n�ּ�:%s\n�ҼӺμ�:%s\n�ð����ӱ�:%2.1f\n�ٹ��ð�:%d", name,address,department,payRate,hoursWorked);
	return str2;
}
}
