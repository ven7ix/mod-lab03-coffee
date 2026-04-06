#include <gtest/gtest.h>
#include "Automata.h"

TEST0(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();

	EXPECT_EQ("WAIT", automata.get_state());
}

TEST1(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.choice(1);

	EXPECT_EQ("WAIT", automata.get_state());
}

TEST2(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(1);

	EXPECT_EQ("CHECK", automata.get_state());
}

TEST3(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(10);

	EXPECT_EQ("ACCEPT", automata.get_state());
}

TEST4(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(1);
	automata.cancel();

	EXPECT_EQ("WAIT", automata.get_state());
}

TEST5(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(10);

	EXPECT_EQ(10, automata.get_cash());
}

TEST6(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(10);
	automata.coin(-5);

	EXPECT_EQ(10, automata.get_cash());
}

TEST7(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on(10);
	automata.coin(0);

	EXPECT_EQ(10, automata.get_cash());
}

TEST8(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(1);

	EXPECT_EQ(false, automata.check());
}

TEST9(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(100);
	automata.choice(1);

	EXPECT_EQ(true, automata.check());
}
