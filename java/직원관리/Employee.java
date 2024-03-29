
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
		String str = String.format("捞抚:%s\n林家:%s\n家加何辑:%s", name,address,department);
		return str;
	}
	
}
