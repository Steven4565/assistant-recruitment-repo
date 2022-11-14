package Game;

import java.util.Stack;

import Utils.Validator;
import Utils.Log;
import Utils.Utils;
import Utils.PrintUtils;

public class Gameplay extends Log {

	Stack<Card> deck;
	Player player;
	Player dealer;
	public int bet;

	public Gameplay() {
		this.deck = new Stack<Card>();
		this.deck.addAll(GameUtils.generateDeck());
		this.player = new Player();
		this.dealer = new Player();

		// initialize player and dealer's decks
		this.player.hit(deck);
		this.player.hit(deck);

		this.dealer.hit(deck);
		this.dealer.hit(deck);

		// get player bet
		this.bet = Validator.getInputInt(1, 100, "Input your bet [1 - 100]");
	}

	public boolean start() {
		String[] options = { "Hit", "Stand" };

		int action;
		do {
			render(false);

			// get player's actions
			log("Choose your move");
			PrintUtils.printMenu(options);
			action = Validator.getInputInt(1, 2, "Choose [1 - 2]");

			if (action == 1) {
				player.hit(deck);
			}
		} while (action == 1);

		if (dealer.getDeckValue() < 17) {
			dealer.hit(deck);
		}

		render(true);
		checkWin();
		Utils.getEnter();

		return true;
	}

	private void render(boolean revealDealer) {
		// render
		log("");
		log("Dealer's cards: ");
		if (revealDealer) {
			this.dealer.printCards();
		} else {
			log(this.dealer.deck.get(0).sprite + " | ??");
		}
		log("Player's cards: ");
		this.player.printCards();
		log("========================================");
	}

	private void checkWin() {
		int playerVal = this.player.getDeckValue();
		int dealerVal = this.dealer.getDeckValue();

		log("Player's score: " + playerVal);
		log("Dealer's score: " + dealerVal);

		boolean playerBust = playerVal > 21;
		boolean dealerBust = dealerVal > 21;

		// win = 1 -> player wins win = 0 -> draw win = -1 -> player loses
		int win;

		// check if anyone has busted
		if (dealerBust && playerBust) {
			win = 0;
			log("Both parties busted, it's a tie");
		} else if (dealerBust) {
			win = 1;
			log("Dealer busted");
		} else if (playerBust) {
			win = -1;
			log("Player busted");
		} else if (playerVal == dealerVal) { // if nobody busted, check who got higher score
			win = 0;
			log("Both parties have the same scores");
		} else if (playerVal > dealerVal) {
			win = 1;
			log("The player got more score");
		} else {
			log("The dealer got more score");
			win = -1;
		}

		// modify the bet
		if (win == 1) {
			this.bet *= 2;
			log("You won " + this.bet);
		} else if (win == -1) {
			this.bet *= -1;
			log("You lost " + this.bet * -1);
		} else if (win == 0) {
			this.bet = 0;
			log("It's a tie, you got nothing");
		}
	}

}
