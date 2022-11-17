package game.dishes;

public abstract class DishType {
	public int prepTime;
	int price;
	String name;

	public DishType(String name, int price, int prepTime) {
		this.name = name;
		this.price = price;
		this.prepTime = prepTime;
	}

}
