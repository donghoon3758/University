import java.awt.*;

import javax.swing.*;


class WelcomPanel extends JPanel{
	private JLabel message;
	public WelcomPanel() {
		message = new JLabel("�ڹ� ���ڿ� ���Ű��� ȯ���մϴ�.");
		add(message);
	}
}
class TypePanel extends JPanel{
	String[] set = {"�޺�","��������","�Ұ��"};
	public TypePanel() {
		setLayout(new GridLayout(1,2));
		JComboBox setList = new JComboBox(set);
		setList.setSelectedIndex(0);

		add(new JLabel(" ����"));
		add(setList);
	}
}
class ToppingPanel extends JPanel{
	private JRadioButton pepper, cheese,peperoni,bacon;
	private ButtonGroup bg;
	public ToppingPanel() {
		GridLayout grid1 = new GridLayout(4,1);
		setLayout(grid1);
		JCheckBox pepper=new JCheckBox("�Ǹ�");
		JCheckBox cheese=new JCheckBox("ġ��");
		JCheckBox peperoni=new JCheckBox("���۷δ�");
		JCheckBox bacon=new JCheckBox("������");
		bg=new ButtonGroup();
		bg.add(pepper);
		bg.add(cheese);
		bg.add(peperoni);
		bg.add(bacon);
		setBorder(BorderFactory.createTitledBorder("�߰�����"));
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
		JLabel sizeLabel = new JLabel("������");
		add(sizeLabel);
		add(sizeList);
	}
}
class Amount extends JPanel{
	public Amount() {
		setLayout(new GridLayout(2,1));
		add(new JLabel("�ֹ������Է�"));
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
		setTitle("201724526_�̵���");
		
		order_button=new JButton("�ֹ�");
		cancle_button=new JButton("���");
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
