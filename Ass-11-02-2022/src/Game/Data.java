package Game;

import Utils.Log;

public class Data extends Log {
	public int bal;
	public int shoeLv;
	public int leashLv;

	public Data(int bal, int shoeLv, int leashLv) {
		this.bal = bal;
		this.shoeLv = shoeLv;
		this.leashLv = leashLv;
	}

	public void print() {
		log("Balance: " + this.bal);
		log("Shoe Level: " + this.shoeLv);
		log("Leash Level: " + this.leashLv);
	}
}
