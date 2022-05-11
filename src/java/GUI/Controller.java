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
	
	// Button Refill
	public void onRefill(ActionEvent ev){
		  try {
			  channel.sendMsg("MSG_REFILLED");
		  } catch (Exception ex){
			  ex.printStackTrace();
		  }
	 
	}

	// Button Recover
	public void onRecover(ActionEvent ev){
		try {
			channel.sendMsg("MSG_RECOVER");
		} catch (Exception ex){
			ex.printStackTrace();
		}
   
  }
	
}