#include <iostream>
#include <vector>
#include <limits.h>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

class card() {
  private:
    int value;
    string suit;
  public:
    card() {                               // default constructor
      this->value = 0;
      this->suit = "Joker";
    }
    card(int value, string suit) {       // This constructor is the one I intend to use; receive card value and suit for initializing each card in the deck
      this->value = value;
      this->suit = suit;
    }
    ~card() {}                          // destructor is just in case I need it later
    void textCard() {                  // Text verson of card display, used for initial debugging
      cout << this->value << " of " << this->suit << endl;
    }
    void asciiCard() {                // The real enchirito. Likely improvable, but it works! It displays the ascii art card #rendering
      cout << "--------------" << endl;
      if (this->value == 1) {
        cout << "|          A |" << endl;
      }
      else if (this->value == 10) {
        cout << "|         10 |" << endl;
      }
      else if (this->value == 11) {
        cout << "|          J |" << endl;
      }
      else if (this->value == 12) {
        cout << "|          Q |" << endl;
      }
      else if (this->value == 13) {
        cout << "|          K |" << endl;
      }
      else {
        cout << "          " << this->value << " |" << endl;
      }
      cout << "|            |" << endl
           << "|            |" << endl;
      if (this->suit == "Hearts") {
        cout << "|   Hearts   |" << endl;
      }
      else if (this->suit == "Spades") {
        cout << "|   Spades   |" << endl;
      }
      else if (this->suit == "Diamonds") {
        cout << "|  Diamonds  |" << endl;
      }
      else if (this->suit == "Clubs") {
        cout << "|    Club    |" << endl;          // still debating on Club with 4 spaces on each side or Clubs with 3 spaces before and 4 after.  BUT I intend to replace the words in the ascii with the actual symbols so it may not even matter soon enough
      }
      cout << "|            |" << endl
           << "|            |" << endl;
      if (this->value == 1) {
        cout << "| A          |" << endl;
      }
      else if (this->value == 10) {
        cout << "| 10         |" << endl;
      }
      else if (this->value == 11) {
        cout << "| J          |" << endl;
      }
      else if (this->value == 12) {
        cout << "| Q          |" << endl;
      }
      else if (this->value == 13) {
        cout << "| K          |" << endl;
      }
      else {
        cout << "| " << this->value << "          |" << endl;
      }
      cout << "--------------" << endl;
    }
    int getCardValue() {                        // getter for value
      return this->value;
    }
    string getCardSuit() {                      // getter for suit
      return this->suit
    }
};
