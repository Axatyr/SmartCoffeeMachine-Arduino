package GUI;

import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.Thread.State;

import javax.swing.*;


class View extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 4878670195988389337L;

	private JButton refill;
	private JButton recover;
	private JTextField infoTextState;
	private JTextField infoState;
	private JTextField infoTextTest;
	private JTextField infoTest;
	private JTextField infoCoffee;
	private JTextField infoChocolate;
	private JTextField infoTea;
	
	
	StateMachine state = new StateMachine("Idle");
	int selfTestPassed = 0;
	int coffee = 0;
	int chocolate = 0;
	int tea = 0;
	
	public View(){
		super("View");
		setSize(400,140);
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.X_AXIS));

		mainPanel.add(Box.createRigidArea(new Dimension(20,0)));

		//Button per refill
		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.Y_AXIS));	    
		refill = new JButton("Refill product");
		recover = new JButton("Recover machine");
		buttonPanel.add(refill);   
		buttonPanel.add(recover);  
		mainPanel.add(buttonPanel);
		
		// State machine and self-test
		JPanel statePanel = new JPanel();
		statePanel.setLayout(new BoxLayout(statePanel, BoxLayout.Y_AXIS)); //BoxLayout.LINE_AXIS
		infoTextState = new JTextField("State machine: ");
		infoState = new JTextField(state.getState());
		infoTextTest = new JTextField("Status self-test");
		infoTest = new JTextField(selfTestPassed);
		infoState.setPreferredSize(new Dimension(200,15));
		infoState.setEditable(false);
		infoTextState.setPreferredSize(new Dimension(200,15));
		infoTextState.setEditable(false);
		infoTest.setPreferredSize(new Dimension(200,15));
		infoTest.setEditable(false);
		infoTextTest.setPreferredSize(new Dimension(200,15));
		infoTextTest.setEditable(false);
		statePanel.add(infoTextState);
		statePanel.add(infoState);
		statePanel.add(infoTest);
		statePanel.add(infoTextTest);
		mainPanel.add(statePanel);

		// Product info
		JPanel productPanel = new JPanel();
		productPanel.setLayout(new BoxLayout(productPanel, BoxLayout.X_AXIS));	    
		infoCoffee = new JTextField("Coffe: " + coffee);
		infoChocolate = new JTextField("Chocolate: " + chocolate);
		infoTea = new JTextField("Tea: " + tea);
		infoCoffee.setPreferredSize(new Dimension(200,15));
		infoCoffee.setEditable(false);
		infoChocolate.setPreferredSize(new Dimension(200,15));
		infoChocolate.setEditable(false);
		infoTea.setPreferredSize(new Dimension(200,15));
		infoTea.setEditable(false);
		productPanel.add(infoCoffee);
		productPanel.add(infoChocolate);
		productPanel.add(infoTea);	
		mainPanel.add(productPanel);

		this.getContentPane().add(mainPanel);

		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent ev){
				System.exit(-1);
			}
		});
	}

	public void registerController(Controller contr){
		refill.addActionListener(contr);
	}
}