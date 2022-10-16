package app;
import java.util.Scanner;
public class Driver
{
	public static void setError(double height)throws heightException {
		if(height<=0) {
			throw new heightException("길이는 0이하일 수 없음");
		}
	}
	
	public static void main(String args[])
	{
		double length,width,height;
		Sphere sphere = new Sphere(2);
		Sphere sphere1 = new Sphere(2);
		if(sphere.compareTo(sphere1)==0) {
			System.out.println("크기가 같다.");
		}else if(sphere.compareTo(sphere1)==1) {
			System.out.println("첫 번째 구가 더 크다.");
		}else if(sphere.compareTo(sphere1)==-1) {
			System.out.println("두 번째 구가 더 크다.");
		}
		Box box = new Box(2, 3, 4);
		System.out.println("원의 넓이는 " + sphere.findarea() + "이다.");
		System.out.println("구의 부피는 " + sphere.findvolume() + "이다.");
		System.out.println("박스의 바닥의 면적은 " + box.findarea() + "이다.");
		System.out.println("박스의 부피는 " + box.findvolume() + "이다.");
		try (Scanner scan = new Scanner(System.in)) {
			System.out.print("가로 :");
			length=scan.nextDouble();
			System.out.print("세로 :");
			width=scan.nextDouble();
			System.out.print("높이 :");
			height=scan.nextDouble();
		}
		try {
		setError(height);
		Box box2 = new Box(length,width,height);
		System.out.println("박스의 바닥의 면적은 " + box2.findarea() + "이다.");
		System.out.println("박스의 부피는 " + box2.findvolume() + "이다.");
		}catch(heightException e)
		{
			System.out.println("높이가 0이하일 수 없음");
		}
	}
}
