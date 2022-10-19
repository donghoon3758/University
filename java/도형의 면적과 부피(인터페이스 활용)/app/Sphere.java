package app;
import lib.Shape3D;
import lib.Shape2D;
import lib.ValuePi;
public class Sphere implements Shape2D, Shape3D, ValuePi,Comparable<Sphere>{
	double radius;
	public Sphere(double radius) {
		this.radius=radius;
	}
	@Override
	public double findvolume() {
		// TODO Auto-generated method stub
		return radius*radius*radius*pi*(double)4/(double)3;
	}
	@Override
	public double findarea() {
		// TODO Auto-generated method stub
		return radius*radius*pi;
	}
	@Override
	public int compareTo(Sphere o) {
		// TODO Auto-generated method stub

		if(this.radius < o.radius) {
			return -1;
		}else if(this.radius == o.radius) {
			return 0;
		}else {
			return 1;
		}	
	}
}
