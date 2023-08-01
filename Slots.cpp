#include <iostream>
#include <limits>

using namespace std;

int getRandom (int min, int max) {
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do {
        x = rand ();
    } while (x >= RAND_MAX - remainder);
    return min + x % n;
}

int getTumble (long wallet) {
    wallet -= 1000;
    int totalWins = 0; 
    short totalOnes = 0; short totalTwos = 0; short totalThrees = 0; short totalFours = 0; short totalFives = 0; 
    short totalSixes = 0; short totalSevens = 0; short totalEights = 0; short totalNines = 0; short totalTens = 0;
    short valueOfOnes = 1; short valueOfTwos = 2; short valueOfThrees = 3; short valueOfFours = 4; short valueOfFives = 5;
    short valueOfSixes = 6; short valueOfSevens = 8; short valueOfEights = 10; short valueOfNines = 15; short valueOfTens = 60;
    int tumble[5][6] = {{0, 1, 2, 3, 4, 5}, {6, 7, 8, 9, 10, 11}, {12, 13, 14, 15, 16, 17},
                        {18, 19, 20, 21, 22, 23}, {24, 25, 26, 27, 28, 29}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            int k = getRandom (1, 1000);
            if (k <= 1000 && k >= 992) {  // 10/1000
                cout << "$ ";
                tumble[i][j] = 10;
                totalTens++;
            }
            else if (k <= 991 && k >= 953) { // 40/1000
                cout << "9 ";
                tumble[i][j] = 9;
                totalNines++;
            }
            else if (k <= 952 && k >= 895) { // 59/1000
                cout << "8 ";
                tumble[i][j] = 8;
                totalEights++;
            }
            else if (k <= 894 && k >= 816) { // 80/1000
                cout << "7 ";
                tumble[i][j] = 7;
                totalSevens++;
            }
            else if (k <= 815 && k >= 705) { // 112/1000
                cout << "6 ";
                tumble[i][j] = 6;
                totalSixes++;
            }
            else if (k <= 704 && k >= 593) { // 113/1000
                cout << "5 ";
                tumble[i][j] = 5;
                totalFives++;
            }
            else if (k <= 592 && k >= 461) { // 133/1000
                cout << "4 ";
                tumble[i][j] = 4;
                totalFours++;
            }
            else if (k <= 460 && k >= 321) { // 141/1000
                cout << "3 ";
                tumble[i][j] = 3;
                totalThrees++;
            }
            else if (k <= 320 && k >= 165) { // 155/1000
                cout << "2 ";
                tumble[i][j] = 2;
                totalTwos++;
            }
            else {
                cout << "1 ";                // 163/1000
                tumble[i][j] = 1;
                totalOnes++;
            }
        }
        cout << endl;
    }
    
    if (totalOnes >= 4) {
        int totalOnesWins = 0;
        totalOnesWins += ((valueOfOnes + (totalOnes + totalOnes)) * totalOnes);
        cout << "1(" << totalOnes << ") = $" << totalOnesWins << ", ";
        totalWins += totalOnesWins;
    }

    if (totalTwos >= 4) {
        int totalTwosWins = 0;
        totalTwosWins += ((valueOfTwos + (totalTwos * valueOfTwos)) * totalTwos);
        cout << "2(" << totalTwos << ") = $" << totalTwosWins << ", ";
        totalWins += totalTwosWins;
    }

    if (totalThrees >= 4) {
        int totalThreesWins = 0;
        totalThreesWins += ((valueOfThrees + (totalThrees * valueOfThrees)) * totalThrees);
        cout << "3(" << totalThrees << ") = $" << totalThreesWins << ", ";
        totalWins += totalThreesWins;
    }

    if (totalFours >= 4) {
        int totalFoursWins = 0;
        totalFoursWins += ((valueOfFours + (totalFours * valueOfFours)) * totalFours);
        cout << "4(" << totalFours << ") = $" << totalFoursWins << ", ";
        totalWins += totalFoursWins;
    }

    if (totalFives >= 4) {
        int totalFivesWins = 0;
        totalFivesWins += ((valueOfFives * (totalFives + valueOfFives)) * totalFives);
        cout << "5(" << totalFives << ") = $" << totalFivesWins << ", ";
        totalWins += totalFivesWins;
    }

    if (totalSixes >= 4) {
        int totalSixesWins = 0;
        totalSixesWins += ((valueOfSixes * (totalSixes + valueOfSixes)) * totalSixes);
        cout << "6(" << totalSixes << ") = $" << totalSixesWins << ", ";
        totalWins += totalSixesWins;
    }

    if (totalSevens >= 4) {
        int totalSevensWins = 0;
        totalSevensWins += ((valueOfSevens * (totalSevens * valueOfSevens)) * totalSevens);
        cout << "7(" << totalSevens << ") = $" << totalSevensWins << ", ";
        totalWins += totalSevensWins;
    }

    if (totalEights >= 4) {
        int totalEightsWins = 0;
        totalEightsWins += ((valueOfEights * (totalEights * valueOfEights)) * totalEights);
        cout << "8(" << totalEights << ") = $" << totalEightsWins << ", ";
        totalWins += totalEightsWins;
    }

    if (totalNines >= 4) {
        int totalNinesWins = 0;
        totalNinesWins += ((valueOfNines * (totalNines * valueOfNines)) * totalNines);
        cout << "9(" << totalNines << ") = $" << totalNinesWins << ", ";
        totalWins += totalNinesWins;
    }

    if (totalTens >= 4) {
        int totalTensWins = 0;
        totalTensWins += (valueOfTens * (totalTens + valueOfTens + (100 * totalTens)));
        cout << "$(" << totalTens << ") = $" << totalTensWins;
        totalWins += totalTensWins;
    }

    wallet += totalWins;
    cout << "\n\nWin: $" << totalWins << endl;
    int n = 0;

    for (;;) {
        cout << "Total in bank: $" << wallet << endl;
        cout << "\n1. Spin again? (Pay $1,000)\n2. Quit\n" << flush;
        cin >> n;

        if (cin.fail ()) {
            cout << "\nSorry, I cannot read that. Please try again." << endl;
            cin.clear ();
            cin.ignore(numeric_limits<streamsize>::max (), '\n');
            continue;
        }

        if (n < 1 || n > 2) {
            cout << "\nSorry, the number is out of range." << endl;
            continue;
        }

        if (n == 1) {
            if (wallet >= 1000) {
                totalWins = 0;
                getTumble (wallet);
            }
            else {
                cout << "\nInsufficient funds! You have lost! Restart game to start a new wallet\n\n";
            }
        }
        break;
    }
    return wallet;
}

int main () {
    int n = 0;
    long wallet = 10000;

    for (;;) {
        cout << "Enter one of the following task numbers: \n 1. Spin the slot! (Pay $1,000) \n 2. Quit game \n" << flush;
        cin >> n;

        if (cin.fail ()) {
            cout << "Sorry, I cannot read that. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max (), '\n');
            continue;
        }

        if (n < 1 || n > 2) {
            cout << "Sorry, the number is out of range." << endl;
            continue;
        }

        if (n == 1) {
            getTumble (wallet);
        }
        break;
    }
}