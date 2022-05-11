package GUI;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import eiot.SerialCommChannel;

public class Controller implements ActionListener {
	
	SerialCommChannel channel;
	View view;
	
	public Controller(String port, View view) throws Exception {
		this.view = view;
		channel = new SerialCommChannel(port,9600);
		new ChannelListener(channel,view).start();		
	}

	@Override
	public void actionPerformed(ActionEvent ev) {
		try {
			  if (ev.getActionCommand().equals("Refill product")){
				  channel.sendMsg("MSG_REFILLED");
			  }
			  if (ev.getActionCommand().equals("Recover machine")) {
				  channel.sendMsg("MSG_RECOVER");
			  }
		  } catch (Exception ex){
			  ex.printStackTrace();
		  }
	}
	
}