// Copyright 2026 Andrew

#include <gtest/gtest.h>
#include "Automata.h"
#include <iostream>

TEST(AutomataTest, OnChangesStateToWait) {
    Automata automata;
    std::cout << automata.get_state() << std::endl;

    automata.on();

    EXPECT_EQ("WAIT", automata.get_state());
}

TEST(AutomataTest, ChoiceWithoutCoinDoesNothing) {
    Automata automata;
    automata.on();
    automata.choice(1);

    EXPECT_EQ("WAIT", automata.get_state());
}

TEST(AutomataTest, ChoiceWithZeroCoinGoesToCheck) {
    Automata automata;
    automata.on();
    automata.coin(0);
    automata.choice(1);

    EXPECT_EQ("CHECK", automata.get_state());
}

TEST(AutomataTest, InvalidChoiceStaysInAccept) {
    Automata automata;
    automata.on();
    automata.coin(0);
    automata.choice(10);

    EXPECT_EQ("ACCEPT", automata.get_state());
}

TEST(AutomataTest, CancelAfterChoiceReturnsToWait) {
    Automata automata;
    automata.on();
    automata.coin(0);
    automata.choice(1);
    automata.cancel();

    EXPECT_EQ("WAIT", automata.get_state());
}

TEST(AutomataTest, CoinAddsToCash) {
    Automata automata;
    automata.on();
    automata.coin(10);

    EXPECT_EQ(10, automata.get_cash());
}

TEST(AutomataTest, NegativeCoinIgnored) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(-5);

    EXPECT_EQ(10, automata.get_cash());
}

TEST(AutomataTest, CoinAfterOnWithParameter) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(0);

    EXPECT_EQ(10, automata.get_cash());
}

TEST(AutomataTest, CheckReturnsFalseWhenInsufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(0);
    automata.choice(1);

    EXPECT_EQ(false, automata.check());
}

TEST(AutomataTest, CheckReturnsTrueWhenEnoughFunds) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(1);

    EXPECT_EQ(true, automata.check());
}
