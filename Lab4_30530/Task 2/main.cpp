// Task 2
//  Dynamic Array :
//  An online gaming platform maintains a dynamic leaderboard that expands as new players join.
//  Implement a dynamic array to store player scores and efficiently resize the leaderboard as needed.

// Requirements:
// • Implement a dynamically resizing array.
// • Support efficient score updates.
// • Ensure optimal resizing strategy.

#include <iostream>
#include <string>
using namespace std;

class Leaderboard
{
private:
    string *playerName;
    int *score;
    int capacity;
    int size;

public:
    Leaderboard(int size = 1)
    {
        playerName = new string[size];
        score = new int[size];
        capacity = size;
        this->size = 0;
    };

    ~Leaderboard()
    {
        delete[] playerName;
        delete[] score;
    };

    void addPlayer(string name, int score)
    {
        if (this->size == capacity)
        {
            resize();
        }
        playerName[this->size] = name;
        this->score[this->size] = score;
        this->size++;
    };

    void resize()
    {
        string *newPlayerName = new string[capacity * 2];
        int *newScore = new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newPlayerName[i] = playerName[i];
            newScore[i] = score[i];
        }
        delete[] playerName;
        delete[] score;
        playerName = newPlayerName;
        score = newScore;
        capacity *= 2;
    };

    void updateScore(string name, int newScore)
    {
        for (int i = 0; i < size; i++)
        {
            if (playerName[i] == name)
            {
                score[i] = newScore;
                break;
            }
        }
    };

    void printLeaderboard()
    {
        for (int i = 0; i < size; i++)
        {
            cout << playerName[i] << " : " << score[i] << endl;
        }
    };
};

int main()
{
    Leaderboard leaderboard;
    leaderboard.addPlayer("Alice", 100);
    leaderboard.addPlayer("Bob", 200);
    leaderboard.addPlayer("Charlie", 300);
    leaderboard.addPlayer("David", 400);
    leaderboard.addPlayer("Eve", 500);
    leaderboard.printLeaderboard();
    cout << endl;

    leaderboard.updateScore("Bob", 250);
    leaderboard.printLeaderboard();
    cout << endl;

    leaderboard.addPlayer("Frank", 600);
    leaderboard.printLeaderboard();
    cout << endl;

    leaderboard.updateScore("Alice", 150);
    leaderboard.printLeaderboard();
    cout << endl;

    return 0;
}