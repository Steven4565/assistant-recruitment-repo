package game.dishes;

public abstract class Dish {

	public String name;
	public int price;
	public boolean served = false;

	public Dish(String name, int price) {
		this.name = name;
		this.price = price;
	}

	public void serve() {
		this.served = true;
	}

}
