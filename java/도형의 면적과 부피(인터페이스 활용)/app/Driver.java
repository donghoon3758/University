package app;
import java.util.Scanner;
public class Driver
{
	public static void setError(double height)throws heightException {
		if(height<=0) {
			throw new heightException("���̴� 0������ �� ����");
		}
	}
	
	public static void main(String args[])
	{
		double length,width,height;
		Sphere sphere = new Sphere(2);
		Sphere sphere1 = new Sphere(2);
		if(sphere.compareTo(sphere1)==0) {
			System.out.println("ũ�Ⱑ ����.");
		}else if(sphere.compareTo(sphere1)==1) {
			System.out.println("ù ��° ���� �� ũ��.");
		}else if(sphere.compareTo(sphere1)==-1) {
			System.out.println("�� ��° ���� �� ũ��.");
		}
		Box box = new Box(2, 3, 4);
		System.out.println("���� ���̴� " + sphere.findarea() + "�̴�.");
		System.out.println("���� ���Ǵ� " + sphere.findvolume() + "�̴�.");
		System.out.println("�ڽ��� �ٴ��� ������ " + box.findarea() + "�̴�.");
		System.out.println("�ڽ��� ���Ǵ� " + box.findvolume() + "�̴�.");
		try (Scanner scan = new Scanner(System.in)) {
			System.out.print("���� :");
			length=scan.nextDouble();
			System.out.print("���� :");
			width=scan.nextDouble();
			System.out.print("���� :");
			height=scan.nextDouble();
		}
		try {
		setError(height);
		Box box2 = new Box(length,width,height);
		System.out.println("�ڽ��� �ٴ��� ������ " + box2.findarea() + "�̴�.");
		System.out.println("�ڽ��� ���Ǵ� " + box2.findvolume() + "�̴�.");
		}catch(heightException e)
		{
			System.out.println("���̰� 0������ �� ����");
		}
	}
}
