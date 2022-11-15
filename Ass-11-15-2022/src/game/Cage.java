package game;

public class Cage {
	private int level;
	private int initialCapacity;
	private int upgradeCoef;
	private String name;

	public Cage(String name, int initialCapacity, int upgradeCoef) {
		this.name = name;
		this.initialCapacity = initialCapacity;
		this.upgradeCoef = upgradeCoef;
		this.level = 0;
	}

	public int getMaxCapacity() {
		return this.initialCapacity + (this.level * this.upgradeCoef);
	}

	public int getUpgradePrice() {
		return 1000 + (this.level * 800);
	}

	public void upgrade() {
		this.level += 1;
	}

	public String getName() {
		return this.name;
	}

}
