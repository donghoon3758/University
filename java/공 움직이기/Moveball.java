import java.awt.*;
import javax.swing.*;

class Ball{
	private int x = 100;
	private int y = 100;
	private int size = 30;
	private int xSpeed = 10;
	private int ySpeed = 10;
	private int speed = 10;
	public void draw(Graphics g) {
		g.setColor(Color.red);
		g.fillOval(x, y, size, size);
		}
		public void update() {
			x+=xSpeed;
			y+=ySpeed;
			if((x+50) >= Moveball.BOARD_WIDTH) {
				xSpeed=-xSpeed;
				if(y >= Moveball.BOARD_HEIGHT) {ySpeed=-ySpeed;}
			}
			if((y+50) >= Moveball.BOARD_HEIGHT) {
				ySpeed=-ySpeed;
				if(x >= Moveball.BOARD_WIDTH) {xSpeed=-xSpeed;}
			}
			if(x < 0) {
				xSpeed=-xSpeed;
				if(y >= Moveball.BOARD_HEIGHT) {ySpeed=-ySpeed;}
			}
			if(y < 0) {
				ySpeed =-ySpeed;
				if(x >= Moveball.BOARD_WIDTH) {xSpeed=-xSpeed;}
			}
		}
}

public class Moveball extends JPanel {
	static final int BOARD_WIDTH = 600;
	static final int BOARD_HEIGHT = 300;
	private Ball ball = new Ball();
	public Moveball() {
		this.setBackground(Color.YELLOW);
		Runnable task=()->{
			while(true) {
				ball.update();
				repaint();
				try {
					Thread.sleep (50);
				}catch(InterruptedException e) {
				}
			}
		};
		Thread th = new Thread(task);
		th.start();
		//람다식을 이용하여서 Runnable 객체를 생성한다.
		//무한루프를 돌면서 공의 위치를 변경하고 화면에 다시 그린다. 50 밀리초동안 쉰다.
		// 스레드 객체를 생성하고 스레드를 실행시킨다.
	}
	
@Override
	protected void paintComponent(Graphics g) {
	super.paintComponent(g);
	ball.draw(g);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame frame = new JFrame();
		frame.setSize(Moveball.BOARD_WIDTH, Moveball.BOARD_HEIGHT);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.add(new Moveball());
		frame.setResizable(false);
	}

}
