package GUI;

public class Products {

	private int tea;
	private int chocolate;
	private int coffee;
	
	public Products(int tea, int chocolate, int coffee) {
		this.tea = tea;
		this.chocolate = chocolate;
		this.coffee = coffee;
	}
	
	public int getTea() {
		return tea;
	}
	public void setTea(int tea) {
		this.tea = tea;
	}
	
	public int getChocolate() {
		return chocolate;
	}
	public void setChocolate(int chocolate) {
		this.chocolate = chocolate;
	}
	
	public int getCoffee() {
		return coffee;
	}
	public void setCoffee(int coffee) {
		this.coffee = coffee;
	}
	
}
