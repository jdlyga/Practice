#include <iostream>
#include <deque>

using namespace std;

class card
{
  public:

    enum suit {CLUBS=1, HEARTS, SPADES, DIAMONDS};
    enum value {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    card(value v, suit s) : myValue(v), mySuit(s) {};
    ~card() {};
    value getValue() {return myValue;};
    string getValueStr()
    {
      switch(myValue)
      {
        case ACE:
          return "Ace";
        case TWO:
          return "2";
        case THREE:
          return "3";
        case FOUR:
          return "4";
        case FIVE:
          return "5";
        case SIX:
          return "6";
        case SEVEN:
          return "7";
        case EIGHT:
          return "8";
        case NINE:
          return "9";
        case TEN:
          return "10";
        case JACK:
          return "Jack";
        case QUEEN:
          return "Queen";
        case KING:
          return "King";
      }
    }

    string getSuitStr()
    {
      switch(mySuit)
      {
        case CLUBS:
          return "Clubs";
        case HEARTS:
          return "Hearts";
        case SPADES:
          return "Spades";
        case DIAMONDS:
          return "Diamonds";
      }
    }
    suit getSuit() {return mySuit;};

  private:

    value myValue;
    suit mySuit;
};

class deck
{
  public:

    deck()
    {
      for (int s = card::CLUBS; s <= card::DIAMONDS; s++)
      {
        for (int v = card::ACE; v <= card::KING; v++)
        {
          card newCard((card::value)v, (card::suit)s);
          cards.push_back(newCard);
        }
      }
    }

    ~deck() {};

    int numCards() {return cards.size();};
    void printCards()
    {
      for (card c : cards)
      {
        cout << c.getValueStr() << " of " << c.getSuitStr() << endl;
      }
    }

  private:

    std::deque<card> cards;
};


class hand
{
  public:

    hand() {};
    ~hand() {};

    addCard(card c) {cards.push_back(c);};
    clearCards() {cards.clear();};

    int getValue()
    {
      int sum = 0;
      int numAces = 0;
      for (card c : cards)
      {
        if (c.getValue() >= card::TWO && c.getValue() <= card::TEN)
        {
          sum += c.getValue();
        }
        else if (c.getValue() > card::TEN)
        {
          sum += 10;
        }
        else //ace
        {
          numAces++;
          sum += 11;
        }
      }

      //convert aces from 11 to 1
      while (sum > 21 && numAces > 0)
      {
        sum -= 10;
        numAces--;
      }

      return sum;
    }


  private:

    std::deque<card> cards;
};


int main()
{
  deck myDeck;
  cout << myDeck.numCards() << endl;
  myDeck.printCards();

  card c1(card::TEN, card::CLUBS);
  card c2(card::FIVE, card::DIAMONDS);
  card c3(card::ACE, card::HEARTS);

  hand myHand;
  myHand.addCard(c1);
  myHand.addCard(c2);
  myHand.addCard(c3);

  cout << "Hand Value: " << myHand.getValue() << endl;

  return 0;
}
