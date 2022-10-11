
public class RegEmployee extends Employee {
	private int empNumber;
	private String rank;
	private double yearlySalary;
	private double bonusRate;
	private double payCheque;
	
	
	public RegEmployee(String name, String address, String department, int empNumber, String rank, double yearlySalary, double bonusRate)
	{
		super(name,address,department);
		this.empNumber=empNumber;
		this.rank=rank;
		this.yearlySalary=yearlySalary;
		this.bonusRate=bonusRate;
	}

	@Override
	public double pay() {
	    return payCheque = yearlySalary*bonusRate;
	}

	@Override
public String toString() {
		String str1=String.format("�̸�:%s\n�ּ�:%s\n�ҼӺμ�:%s\n������ȣ:%d\n����:%s\n����:%5.1f\n���ʽ� ������:%2.1f", name,address,department,empNumber,rank,yearlySalary,bonusRate);
	return str1;
	}
}
