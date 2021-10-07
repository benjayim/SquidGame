#include <iostream>
using namespace std;

double CalculateProbability(unsigned int numSteps, unsigned int numPlayers)
{
    // If everyone's dead, you lose!
    if (numPlayers == 0)
    {
        return 0;
    }

    // If there are no steps left, you win!
    if (numSteps == 0)
    {
        return 1;
    }

    // You choose wrong -> One less player (cuz you dead), one less step (since the next player can deduce the right step)
    // You choose right -> One less step, same number of players
    return ((0.5 * CalculateProbability(numSteps - 1, numPlayers - 1)) + (0.5 * CalculateProbability(numSteps - 1, numPlayers)));
}

int main()
{
    const unsigned int numSteps = 18;
    
    for (unsigned int playerNum = 0; playerNum <= 16; playerNum++)
    {
        cout << playerNum << ": " << CalculateProbability(numSteps, playerNum) << endl;
    }

    return 0;
}
