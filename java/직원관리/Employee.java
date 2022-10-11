
public abstract class Employee {
	protected String name;
	protected String address;
	protected String department;
	public Employee(String name, String address, String department)
	{
		this.name=name;
		this.address=address;
		this.department=department;
	}
	public abstract double pay();
	@Override
	public String toString() {
		String str = String.format("�̸�:%s\n�ּ�:%s\n�ҼӺμ�:%s", name,address,department);
		return str;
	}
	
}
