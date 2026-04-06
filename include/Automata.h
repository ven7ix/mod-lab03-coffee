#pragma once

#include <string>
#include <vector>

enum AUTOMATA_STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

struct Item {
	std::string name;
	double price;
};

class Automata {
public:
	void on();
	void off();
	void coin(double shekelz);
	void cancel();
	void choice(unsigned int menu_item);
	bool check();
	void cook();
	void finish();
	std::string get_state();
	double get_cash() const;
private:
	AUTOMATA_STATES state = OFF;
	double cash = 0;
	std::vector<Item> menu = { { "coffee", 10 }, { "tea", 20 }, { "water", 5 } };
	unsigned int current_menu_item_index = 0;
};
