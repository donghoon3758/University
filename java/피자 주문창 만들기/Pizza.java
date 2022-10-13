import java.awt.*;

import javax.swing.*;


class WelcomPanel extends JPanel{
	private JLabel message;
	public WelcomPanel() {
		message = new JLabel("자바 피자에 오신것을 환영합니다.");
		add(message);
	}
}
class TypePanel extends JPanel{
	String[] set = {"콤보","포테이토","불고기"};
	public TypePanel() {
		setLayout(new GridLayout(1,2));
		JComboBox setList = new JComboBox(set);
		setList.setSelectedIndex(0);

		add(new JLabel(" 종류"));
		add(setList);
	}
}
class ToppingPanel extends JPanel{
	private JRadioButton pepper, cheese,peperoni,bacon;
	private ButtonGroup bg;
	public ToppingPanel() {
		GridLayout grid1 = new GridLayout(4,1);
		setLayout(grid1);
		JCheckBox pepper=new JCheckBox("피망");
		JCheckBox cheese=new JCheckBox("치즈");
		JCheckBox peperoni=new JCheckBox("페퍼로니");
		JCheckBox bacon=new JCheckBox("베이컨");
		bg=new ButtonGroup();
		bg.add(pepper);
		bg.add(cheese);
		bg.add(peperoni);
		bg.add(bacon);
		setBorder(BorderFactory.createTitledBorder("추가토핑"));
		add(pepper);
		add(cheese);
		add(peperoni);
		add(bacon);
	}
}
class SizePanel extends JPanel{
	String[] size = {"small","medium","large"};

	public SizePanel() {
		setLayout(new GridLayout(1,2));
		JComboBox sizeList = new JComboBox(size);
		sizeList.setSelectedIndex(0);
		JLabel sizeLabel = new JLabel("사이즈");
		add(sizeLabel);
		add(sizeList);
	}
}
class Amount extends JPanel{
	public Amount() {
		setLayout(new GridLayout(2,1));
		add(new JLabel("주문수량입력"));
		add(new JTextField(""));
	}
}

class MyFrame extends JFrame{
	private JButton order_button, cancle_button;
	private JPanel down_panel,center_panel;
	private JTextField text;
	WelcomPanel welcom_panel=new WelcomPanel();
	TypePanel typePanel=new TypePanel();
	ToppingPanel toppingPanel=new ToppingPanel();
	SizePanel sizePanel=new SizePanel();
	Amount amount = new Amount(); 
	MyFrame(){
		JFrame frame = new JFrame();
		this.setSize(500,200);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("201724526_이동훈");
		
		order_button=new JButton("주문");
		cancle_button=new JButton("취소");
		text=new JTextField();
		text.setEditable(false);
		text.setColumns(6);
		
		down_panel=new JPanel();
		down_panel.add(order_button);
		down_panel.add(cancle_button);
		down_panel.add(text);
		
	    center_panel = new JPanel();
	    center_panel.add(toppingPanel);
	    center_panel.add(amount);
	    
		sizePanel.setPreferredSize(new Dimension(120,10));
		typePanel.setPreferredSize(new Dimension(100,20));
		toppingPanel.setPreferredSize(new Dimension(100,90));
		amount.setPreferredSize(new Dimension(100,50));
		setLayout(new BorderLayout());
		add(welcom_panel,BorderLayout.NORTH);
		add(down_panel,BorderLayout.SOUTH);
		add(sizePanel,BorderLayout.EAST);
		add(typePanel,BorderLayout.WEST);
		add(center_panel,BorderLayout.CENTER);
		setVisible(true);
	}
}
public class Pizza {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame mf=new MyFrame();
	}

}
