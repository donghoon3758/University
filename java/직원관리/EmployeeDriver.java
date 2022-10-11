/* EmployeeDriver.java
Employee, RegEmployee, TempEmployee, HourlyEmployee�� Intern Ŭ������ �����ϴ�
����̹� ���α׷��̴�.*/
class EmployeeDriver
{
Employee[] employeeList;
//-----------------------------------------------------------------
// �������� ����� �����
//-----------------------------------------------------------------
public EmployeeDriver()
{
employeeList = new Employee[4];
employeeList[0] = new RegEmployee ("����", "���ҹ� 123", "������", 9352345, "�̻�", 7000.0, 1.4);
employeeList[1] = new RegEmployee ("����", "��ġ 456", "�λ�", 9874321, "����", 4000.0, 1.2);
employeeList[2] = new HourlyEmployee ("����", "���� 678", "��ȹ", "07-07-31", 2000.0, 10.0);
employeeList[3] = new HourlyEmployee ("����", "�Ż� 987", "�ѹ�", "08-12-31", 1600.0, 5.0);
((HourlyEmployee)employeeList[2]).addHours (30);
((HourlyEmployee)employeeList[3]).addHours (40);
((HourlyEmployee)employeeList[2]).addHours (50);
((HourlyEmployee)employeeList[3]).addHours (60);
((HourlyEmployee)employeeList[2]).addHours (20);
((HourlyEmployee)employeeList[3]).addHours (30);
}
//-----------------------------------------------------------------
// ��� �����鿡�� ������ �����Ѵ�
//-----------------------------------------------------------------
public void payday ()
{
double amount;
for (int count=0; count < employeeList.length; count++)
{
System.out .println (employeeList[count]);
amount = employeeList[count].pay(); // polymorphic
System.out .println ("���޾�: " + amount);
System.out .println ("-----------------------------------");
}
}
//-----------------------------------------------------------------
// ȸ���� �������� ����� �׵鿡�� ������ �����Ѵ�.
//-----------------------------------------------------------------
public static void main (String[] args)
{
EmployeeDriver personnel = new EmployeeDriver();
personnel.payday();
}
}