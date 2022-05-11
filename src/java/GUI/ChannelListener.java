package GUI;

import eiot.*;

import java.util.Scanner;

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
					;
					view.state.setState("Working");
				} else if (msg == "Idle") {
					view.state.setState("Idle");
				} else if (msg == "Assistance"){
					view.state.setState("Assistance");
				} else if (msg == "SelfTestPassed") {
					view.selfTestPassed++;
				} else if (msg.contains("Coffee")){
					String input = scanner.nextLine();
					view.coffee = Integer.parseInt(input.replaceAll("[^0-9]", ""));
				} else if (msg.contains("Chocolate")){
					String input = scanner.nextLine();
					view.chocolate = Integer.parseInt(input.replaceAll("[^0-9]", ""));
				} else if (msg.contains("Tea")){
					String input = scanner.nextLine();
					view.tea = Integer.parseInt(input.replaceAll("[^0-9]", ""));
				}
				
			} catch (Exception ex){
				ex.printStackTrace();
			}
		}
	}

}