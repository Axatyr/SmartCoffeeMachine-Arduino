package GUI;

import javax.swing.SwingUtilities;

class Main   {

	static View view = null;

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