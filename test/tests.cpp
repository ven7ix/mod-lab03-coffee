#include <gtest/gtest.h>
#include "Automata.h"

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();

	EXPECT_EQ("WAIT", automata.get_state());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.choice(1);

	EXPECT_EQ("WAIT", automata.get_state());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(1);

	EXPECT_EQ("CHECK", automata.get_state());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(10);

	EXPECT_EQ("ACCEPT", automata.get_state());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(1);
	automata.cancel();

	EXPECT_EQ("WAIT", automata.get_state());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(10);

	EXPECT_EQ(10, automata.get_cash());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(10);
	automata.coin(-5);

	EXPECT_EQ(10, automata.get_cash());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on(10);
	automata.coin(0);

	EXPECT_EQ(10, automata.get_cash());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(0);
	automata.choice(1);

	EXPECT_EQ(false, automata.check());
}

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();
	automata.coin(100);
	automata.choice(1);

	EXPECT_EQ(true, automata.check());
}
