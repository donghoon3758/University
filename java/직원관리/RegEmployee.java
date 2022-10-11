
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
		String str1=String.format("이름:%s\n주소:%s\n소속부서:%s\n직원번호:%d\n직급:%s\n연봉:%5.1f\n보너스 지급율:%2.1f", name,address,department,empNumber,rank,yearlySalary,bonusRate);
	return str1;
	}
}
