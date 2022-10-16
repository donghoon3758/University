package app;

import lib.Shape2D;
import lib.Shape3D;
import lib.ValuePi;

public class Box implements Shape2D, Shape3D, ValuePi,Comparable<Box>{
	double length,width,height;
	public Box(double length,double width,double height) {
		this.length=length;
		this.width=width;
		this.height=height;
	}
	@Override
	public double findvolume() {
		// TODO Auto-generated method stub
		double volume;
		volume = length*width*height;
		return volume;
	}
	@Override
	public double findarea() {
		// TODO Auto-generated method stub
		double area;
		area = width*length;
		return area;
	}

	@Override
	public int compareTo(Box o) {
		// TODO Auto-generated method stub

		if(this.length < o.length) {
			return -1;
		}else if(this.length == o.length) {
			return 0;
		}else {
			return 1;
		}
	}
	
}
