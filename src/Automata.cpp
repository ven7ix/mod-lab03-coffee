#include "Automata.h"
#include <iostream>
#include <thread>
#include <chrono>

std::string Automata::get_state() {
	switch (state) {
	case OFF:
		return "OFF";
	case WAIT:
		return "WAITING";
	case ACCEPT:
		return "ACCEPT";
	case CHECK:
		return "CHECK";
	case COOK:
		return "COOK";
	default:
		return "UNKNOWN";
	}
}

void Automata::on() {
	switch (state) {
	case OFF:
		state = WAIT;
		std::cout << "AUTOMATA TURNED ON" << std::endl;
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE: " << get_state() << std::endl;
		break;
	}
}

void Automata::off() {
	switch (state) {
	case WAIT:
		state = OFF;
		std::cout << "AUTOMATA TURNED OFF" << std::endl;
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE: " << get_state() << std::endl;
		break;
	}
}

void Automata::coin(double shekelz) {
	switch (state) {
	case WAIT:
	case ACCEPT:
		state = ACCEPT;
		if (shekelz < 0) {
			return;
		}

		cash += shekelz;
		std::cout << "AUTOMATA GAINED " << shekelz << " MONEY AMOUNT. AUTOMATA TOTAL CASH: " << cash << std::endl;
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE: " << get_state() << std::endl;
		break;
	}
}

void Automata::cancel() {
	switch (state) {
	case ACCEPT:
	case CHECK:
		state = WAIT;
		std::cout << "AUTOMATA CANCELED YOUR MONEY" << std::endl;
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE: " << get_state() << std::endl;
		break;
	}
}

void Automata::choice(unsigned int menu_item) {
	switch (state) {
	case ACCEPT:
		if (menu_item >= menu.size()) {
			std::cout << "SUCH ITEM DOES NOT EXISTS" << std::endl;
			return;
		}

		state = CHECK;

		current_menu_item_index = menu_item;

		std::cout << "AUTOMATA ACCEPTED YOUR CHOICE" << std::endl;
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE: " << get_state() << std::endl;
		break;
	}
}

bool Automata::check() {
	switch (state) {
	case CHECK:
		if (menu[current_menu_item_index].price > cash) {
			std::cout << "YOU ARE TOO POOR" << std::endl;
			return false;
		}

		std::cout << "AUTOMATA ACCEPTED YOUR MONEY" << std::endl;

		cash -= menu[current_menu_item_index].price;
		cook();
		return true;
	default:
		std::cout << "AUTOMATA CANT CHECK MENU IN STATE: " << get_state() << std::endl;
		return false;
	}
}

void Automata::cook() {
	switch (state) {
	case CHECK:
		state = COOK;
		std::cout << "AUTOMATA STARTED COOKING" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		finish();
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE : " << get_state() << std::endl;
		break;
	}
}

void Automata::finish() {
	switch (state) {
	case COOK:
		if (cash > 0) {
			std::cout << "YOUR LEFTOVER SHEKELZ: " << cash << std::endl;
			cash = 0;
		}

		state = WAIT;
		std::cout << "AUTOMATA FINISHED COOKING" << std::endl;
		break;
	default:
		std::cout << "AUTOMATA STATE CANT CHANGE FROM STATE : " << get_state() << std::endl;
		break;
	}
}