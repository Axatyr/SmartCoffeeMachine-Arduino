package GUI;

import javax.swing.SwingUtilities;

class Main   {

	static View view = null;
	State state = new State("Idle");
	int selfTestPassed = 0;
	int coffee = 0;
	int chocolate = 0;
	int tea = 0;

	public static void main(String[] args) throws Exception {	
		SwingUtilities.invokeAndWait(() -> {
			view = new View();
			
		});
		
		Controller contr = new Controller("COM8",view);
		view.registerController(contr);
		SwingUtilities.invokeLater(() -> {
			view.setVisible(true);
		});
	}
}