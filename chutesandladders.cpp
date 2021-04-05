#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// create a Player class that holds information
class Player
{
private:
    int currPosition;
    bool atHome;

public:
    Player();
    void canRoamFree(int currentPosition, int diceRoll);
    bool checkState();
    int getPosition();
    void move(int diceRoll);
    void printStats();
    void isChute(int currentPosition);
    void isLadder(int currentPosition);
};

Player::Player() {
    currPosition = 0;
    atHome = true;
}

// decide whether or not the Player can start moving
void Player::canRoamFree(int currentPosition, int diceRoll) {
    if(currentPosition == 0 && diceRoll == 6)
    {
        atHome = false;
        cout<<"You are free to move."<<endl;
    }
    else
    {
        cout<<"You are still at home."<<endl;
        cout<<"Roll a 6 to change states."<<endl;
    }
}

void Player::move(int diceRoll) {
    if(!atHome)
    {
        if(currPosition + diceRoll > 100)
        {
            cout<<"Must roll a "<<100-currPosition<<" or less to move forward."<<endl;
        }
        else
        {
            currPosition += diceRoll;
        }

    }
}

void Player::printStats() {
    cout<<"Current position: "<<currPosition<<endl;
    if(atHome)
    {
        cout<<"Current state: at home."<<endl;
    }
    else
    {
        cout<<"Current state: free to roam."<<endl;
    }


}

int Player::getPosition() {
    return currPosition;
}

bool Player::checkState() {
    return atHome;
}

// checks whether Player has encountered a chute
void Player::isChute(int currentPosition) {
    if(currentPosition == 7 || currentPosition == 35 || currentPosition == 96)
    {
        cout<<"Bad luck, you found a chute!"<<endl;
        if(currentPosition == 7)
        {
            currPosition -= 4;
        }
        else if(currentPosition == 35)
        {
            currPosition -= 31;
        }
        else
        {
            currPosition -= 78;
        }
    }
}

// checks whether Player has encountered a Ladder
void Player::isLadder(int currentPosition) {
    if(currentPosition == 12 || currentPosition == 25 || currentPosition == 91)
    {
        cout<<"You found a ladder!"<<endl;
        if(currentPosition == 12)
        {
            currPosition += 26;
        }
        else if(currentPosition == 25)
        {
            currPosition += 59;
        }
        else
        {
            currPosition += 9;
        }
    }

}

int main() {
    int numberOfRolls = 0;
    int continueOrNot;
    srand(time(NULL));
    int dice;
    // initialize a Player
    Player playerOne;

    // repeat until Player has reached square 100
    while(playerOne.getPosition() != 100)
    {
        cout<<endl<<"--------- Total dice rolls before this: "<<numberOfRolls<<"----------"<<endl;
        playerOne.printStats();
        cout<<"Press 1 to roll a die, press 2 to exit the game:";
        cin>>continueOrNot;
        // Allow Player to exit the game anytime
        if(continueOrNot == 2)
        {
            cout<<"You have exited the game."<<endl;
            break;
        }
        cout<<endl<<"Pressed 1, rolling the die..."<<endl;
        dice = rand() % 6 + 1;
        cout<<"You rolled a "<<dice<<endl;
        if(playerOne.checkState())
        {
            int currPos = playerOne.getPosition();
            playerOne.canRoamFree(currPos, dice);
        }
        else
        {
            playerOne.move(dice);
        }

        int place = playerOne.getPosition();
        // check for Chutes and Ladders
        playerOne.isChute(place);
        playerOne.isLadder(place);

        cout<<endl;
        playerOne.printStats();
        numberOfRolls++;
    }
    if(playerOne.getPosition() == 100)
    {
        cout<<"You won!"<<endl;
    }
    return 0;
}
