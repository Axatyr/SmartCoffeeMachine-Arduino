package GUI;

import eiot.*;
import State;

public class ChannelListener extends Thread {

	CommChannel channel;
	View view;
	Scanner scanner = new Scanner(System.in);
	
	public ChannelListener (SerialCommChannel channel, View view) throws Exception {
		this.view = view;
		this.channel = channel;
	}
	
	public void run(){
		while (true){
			try {
				String msg = channel.receiveMsg();
				if(msg == "Working"){
					state.setState("Working");
				} else if (msg == "Idle") {
					state.setState("Idle");
				} else if (msg == "Assistance"){
					state.setState("Assistance");
				} else if (msg == "SelfTestPassed") {
					selfTestPassed++;
				} else if (msg.contains("Coffee")){
					input = scanner.nextLine();
					coffee = Integer.parseInt(input.replaceAll("[^0-9]", ""));
				} else if (msg.contains("Chocolate")){
					input = scanner.nextLine();
					chocolate = Integer.parseInt(input.replaceAll("[^0-9]", ""));
				} else if (msg.contains("Tea")){
					input = scanner.nextLine();
					tea = Integer.parseInt(input.replaceAll("[^0-9]", ""));
				}
				
				view.setInfo(msg);
			} catch (Exception ex){
				ex.printStackTrace();
			}
		}
	}

}