// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(test_suite_name, test_name) {
	Automata automata;
	std::cout << automata.get_state() << std::endl;

	automata.on();

	EXPECT_EQ("WAIT", automata.get_state());
}
