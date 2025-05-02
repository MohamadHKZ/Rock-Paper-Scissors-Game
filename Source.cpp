#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<climits>
#include<cstdlib>
#include<numeric>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<stack>
#include<queue>
#include<windows.h>
using namespace std;
#define ll long long
#define sortD(arr) sort(arr.rbegin(),arr.rend());
#define sortA(arr) sort(arr.begin(),arr.end());
/* {
 first for background
 second for text
        0 = Black       8 = Gray
        1 = Blue        9 = Light Blue
        2 = Green       A = Light Green
        3 = Aqua        B = Light Aqua
        4 = Red         C = Light Red
        5 = Purple      D = Light Purple
        6 = Yellow      E = Light Yellow
        7 = White       F = Bright White
}*/
int Rand(int from, int to)
{
    return(rand() % (to - from + 1) + from);
}

struct MatchInfo
{
    int PlayerWins, ComputerWins, Draws, TotalRounds;
    MatchInfo()
    {
        PlayerWins = 0;
        ComputerWins = 0;
        Draws = 0;
        TotalRounds = 0;
    }
};

enum choice { Stone = 1, Paper, Scissors };

int ValidateNumber(int from, int to, string massage, bool ClearStart = 0)
{
    int tmp;
    do
    {
        if (ClearStart)
            system("cls");
        cout << massage;
        cin >> tmp;
    } while (tmp < from || tmp > to);
    return tmp;
}

string RoundWinner(MatchInfo& Match, choice PlayerChoice, choice ComputerChoice)
{
    if ((PlayerChoice == Stone && ComputerChoice == Scissors) || (PlayerChoice == Paper && ComputerChoice == Stone) || (PlayerChoice == Scissors && ComputerChoice == Paper))
    {
        Match.PlayerWins++;
        system("color 2f");
        return "[Player]";
    }
    else if (PlayerChoice == ComputerChoice)
    {
        Match.Draws++;
        system("color 6f");
        return "[Draw]";
    }
    else
    {
        Match.ComputerWins++;
        system("color 4f");
        cout << '\a';
        return"[Computer]";
    }

}

void PlayRound(MatchInfo& Match, int OrderOfRound)
{
    choice PlayerChoice, ComputerChoice = ((choice)Rand(1, 3));
    cout << "Round [" << OrderOfRound << "] begins: \n\n";
    PlayerChoice = choice(ValidateNumber(1, 3, "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? "));
    cout << "_______________________ Round[" << OrderOfRound << "] _______________________\n\n";
    cout << "Player choice\t: " << (PlayerChoice == Stone ? "Stone" : PlayerChoice == Paper ? "Paper" : "Scissors");
    cout << endl;
    cout << "Computer choice\t: " << (ComputerChoice == Stone ? "Stone" : ComputerChoice == Paper ? "Paper" : "Scissors");
    cout << endl;
    cout << "Round Winner\t: " << RoundWinner(Match, PlayerChoice, ComputerChoice) << endl;
    cout << "________________________________________________________\n\n";
    Sleep(250);
}

void PlayRounds(MatchInfo& Match)
{
    int Rounds = ValidateNumber(1, 10, "Enter how many rounds do you want to play from 1 to 10 ?\n", 1);
    Match.TotalRounds = Rounds;
    cout << endl;
    while (Rounds--)
        PlayRound(Match, Match.TotalRounds - Rounds);
}

string FinalWinner(MatchInfo Match)
{
    if (Match.PlayerWins > Match.ComputerWins)
    {
        system("color 2f");
        return"Player";
    }
    else if (Match.PlayerWins < Match.ComputerWins)
    {
        system("color 4f");
        cout << '\a';
        return "Computer";
    }
    else
    {
        system("color 6f");
        return "Draw";
    }
}

void EndGame(MatchInfo Match)
{
    cout << "\t\t\t_____________________________________________________________\n\n";
    cout << "\t\t\t\t\t+++ G a m e  O v e r +++\n";
    cout << "\t\t\t_____________________________________________________________\n\n";
    cout << "\t\t\t____________________ [Game Results] _________________________\n\n";
    cout << "\t\t\t" << "Game rounds        : " << Match.TotalRounds << endl;
    cout << "\t\t\t" << "Player won times   : " << Match.PlayerWins << endl;
    cout << "\t\t\t" << "Computer won times : " << Match.ComputerWins << endl;
    cout << "\t\t\t" << "Draw times         : " << Match.Draws << endl;
    cout << "\t\t\t" << "Final winner       : " << FinalWinner(Match) << endl;
    cout << "\t\t\t_____________________________________________________________\n\n";

}

void StartGame()
{
    system("color 09");
    MatchInfo Match;
    char PlayAgain;
    PlayRounds(Match);
    EndGame(Match);
    cout << "Do you want to play again ? Y/N ? ";
    cin >> PlayAgain;
    if (tolower(PlayAgain) == 'y')
        StartGame();
}

int main(void)
{
    StartGame();




    return 0;
}
