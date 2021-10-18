#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

char Board[7][7];

void initBoard()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            Board[i][j] = '-';
        }
    }
}

int getFile(char c)
{
    vector<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int count = 0;
    for (char state : alpha)
    {
        if (state == c)
        {
            return count;
        }
        else
        {
            count++;
        }
    }
    return 0; // ignore warning -> will never reach this point
}

void printBoard(char Board[7][7])
{
    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 7; j++)
        {
            if (j != 6)
            {
                cout << Board[i][j] << " ";
            }
            else
            {
                cout << Board[i][j];
            }
        }
        cout << endl;
    }
}

int getRank(char r)
{
    vector<char> ranks = {'1', '2', '3', '4', '5', '6', '7'};
    int count = 0;

    for (char key : ranks)
    {
        if (key == r)
        {
            return (6 - count);
        }
        else
        {
            count++;
        }
    }

    return 0; // doesnt matter
}

void setBoard(map<char, string> pieces)
{
    for (auto locations : pieces)
    {
        char piece = locations.first;
        string states = locations.second;
        if (piece != 'x' && piece != 'y')
        {
            for (int i = 0; i <= states.length() - 2; i = i + 3)
            {
                char f = states[i];
                int rank = getRank(states[i + 1]);
                int file = getFile(f);
                Board[rank][file] = locations.first;
            }
        }
    }
    // printBoard(Board);
}

void PrintPositions(map<char, string> pieces)
{
    bool white = false;
    bool black = false;

    white = pieces.find('P') != pieces.end();
    black = pieces.find('p') != pieces.end();

    if (white)
    {
        cout << "white pawn: " << pieces['P'] << endl;
    }
    else
    {
        cout << "white pawn:" << endl;
    }
    if (black)
    {
        cout << "black pawn: " << pieces['p'] << endl;
    }
    else
    {
        cout << "black pawn:" << endl;
    }

    white = pieces.find('S') != pieces.end();
    black = pieces.find('s') != pieces.end();

    if (white)
    {
        cout << "white superpawn: " << pieces['S'] << endl;
    }
    else
    {
        cout << "white superpawn:" << endl;
    }
    if (black)
    {
        cout << "black superpawn: " << pieces['s'] << endl;
    }
    else
    {
        cout << "black superpawn:" << endl;
    }

    white = pieces.find('G') != pieces.end();
    black = pieces.find('g') != pieces.end();

    if (white)
    {
        cout << "white giraffe: " << pieces['G'] << endl;
    }
    else
    {
        cout << "white giraffe:" << endl;
    }
    if (black)
    {
        cout << "black giraffe: " << pieces['g'] << endl;
    }
    else
    {
        cout << "black giraffe:" << endl;
    }

    white = pieces.find('M') != pieces.end();
    black = pieces.find('m') != pieces.end();

    if (white)
    {
        cout << "white monkey: " << pieces['M'] << endl;
    }
    else
    {
        cout << "white monkey:" << endl;
    }
    if (black)
    {
        cout << "black monkey: " << pieces['m'] << endl;
    }
    else
    {
        cout << "black monkey:" << endl;
    }

    white = pieces.find('E') != pieces.end();
    black = pieces.find('e') != pieces.end();

    if (white)
    {
        cout << "white elephant: " << pieces['E'] << endl;
    }
    else
    {
        cout << "white elephant:" << endl;
    }
    if (black)
    {
        cout << "black elephant: " << pieces['e'] << endl;
    }
    else
    {
        cout << "black elephant:" << endl;
    }

    white = pieces.find('L') != pieces.end();
    black = pieces.find('l') != pieces.end();

    if (white)
    {
        cout << "white lion: " << pieces['L'] << endl;
    }
    else
    {
        cout << "white lion:" << endl;
    }
    if (black)
    {
        cout << "black lion: " << pieces['l'] << endl;
    }
    else
    {
        cout << "black lion:" << endl;
    }

    white = pieces.find('C') != pieces.end();
    black = pieces.find('c') != pieces.end();

    if (white)
    {
        cout << "white crocodile: " << pieces['C'] << endl;
    }
    else
    {
        cout << "white crocodile:" << endl;
    }
    if (black)
    {
        cout << "black crocodile: " << pieces['c'] << endl;
    }
    else
    {
        cout << "black crocodile:" << endl;
    }

    white = pieces.find('Z') != pieces.end();
    black = pieces.find('z') != pieces.end();

    if (white)
    {
        cout << "white zebra: " << pieces['Z'] << endl;
    }
    else
    {
        cout << "white zebra:" << endl;
    }
    if (black)
    {
        cout << "black zebra: " << pieces['z'] << endl;
    }
    else
    {
        cout << "black zebra:" << endl;
    }

    if (pieces['x'] == "w")
    {
        cout << "side to play: "
             << "white" << endl;
    }
    else
    {
        cout << "side to play: "
             << "black" << endl;
    }
}

map<char, string> Sort(map<char, string> pieces)
{
    vector<string> states;
    string fen;

    for (auto entry : pieces)
    {
        string s = entry.second; // getting the string value of the map -> positions of each piece
        string res = "";

        if (s.length() != 2) // if there are multiple positions where the piece is found
        {
            for (int i = 0; i < s.length() - 1; i += 3) // loop through all the positions increment by 3 to get to next position
            {
                res += s[i];
                res += s[i + 1];
                states.push_back(res); // push each position to the vector to be sorted
                res = "";              // reset to get the next position
            }

            sort(states.begin(), states.end()); // sort the vector of positions

            for (int i = 0; i < states.size(); i++) // loop through the vector of positions for each piece
            {
                if (i == 0) // if its the first position dont add a space at the front
                {
                    fen += states[i];
                }
                else // concatenate with space and then the next position
                {
                    fen += " " + states[i];
                }
            }
            pieces[entry.first] = fen; // replace the positions of the map with each piece with their correctly sorted positions
            fen = "";                  // reset the string for next piece
            states.clear();            // clear the vector for the next piece
        }
    } // end for

    return pieces; // return the pieces map with their sorted positions
}

map<char, string> getLocations(string line) // function to find all the positions of each piece in the game
{
    map<char, string> pieces;
    int i = 0;
    char file = 'a'; // columns are called files
    int rank = 7;    // rows are called ranks
    char player;     // which players turn it is
    string N;

    for (i; i < line.length(); i++) // loop through entire FEN
    {
        if (line[i] == ' ') // if we reach the end of the string then break
        {
            break;
        }
        if (!isalpha(line[i]) && line[i] != '/') // if if is a digit (empty space) -> convert digit to int and
        {                                        // adjust the file accordingly
            file += (line[i] - '0');
        }
        else if (line[i] == '/') // else if we encounter a slash
        {                        // move to the next (lower) rank
            rank--;
            file = 'a'; // new rank so reset to the first file
        }
        else
        {
            string result = file + to_string(rank); // get the position of the piece

            if (pieces.count(line[i])) // if this piece is already in the map
            {
                pieces[line[i]] += " " + result; // just add its new positions
            }
            else
            {
                pieces[line[i]] += result; // if not -> insert it into the map with the associated position
            }

            file++; // move to the next file
        }
    }

    for (i + 1; i < line.length(); i++) // read the rest of the string (AFTER READING POSITIONS)
    {
        if (line[i] != ' ') // if not blank -> i.e. char present
        {
            if (isalpha(line[i])) // if its a character -> B/W
            {
                player = line[i]; // set the player
            }
            else
            {
                N += line[i]; // else set the move number
            }
        }
    }

    pieces = Sort(pieces); // sort pieces alphabetically
    pieces['x'] = player;  // set the current player
    pieces['y'] = N;       // set the move number

    return pieces;
}

char genRank(int rank)
{
    rank = 7 - rank;
    char r = '0' + rank;
    return r;
}

char genFile(int file)
{
    char f;

    if (file == 0)
    {
        f = 'a';
    }
    else if (file == 1)
    {
        f = 'b';
    }
    else if (file == 2)
    {
        f = 'c';
    }
    else if (file == 3)
    {
        f = 'd';
    }
    else if (file == 4)
    {
        f = 'e';
    }
    else if (file == 5)
    {
        f = 'f';
    }
    else
    {
        f = 'g';
    }

    return f;
}

vector<string> genLion(map<char, string> pieces) // double check due to failing test cases
{
    vector<string> moves;
    string player = pieces['x']; // which player turn

    if (player == "w") // whites turn
    {
        string states = pieces['L'];

        int rank = getRank(states[1]);
        int file = getFile(states[0]);

        //check if we can move left
        if (file >= 3 && file <= 4)
        {
            if (Board[rank][file - 1] == '-' || islower(Board[rank][file - 1])) // valid move
            {
                // Board[rank][file - 1] = 'L';
                char r = genRank(rank);
                char f = genFile(file - 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (file < 4 && file > 1) // check if we can move right
        {
            if (Board[rank][file + 1] == '-' || islower(Board[rank][file + 1])) // space is free
            {
                // Board[rank][file + 1] = 'L';
                char r = genRank(rank);
                char f = genFile(file + 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank <= 6 && rank > 4) // check if we can move up
        {
            if (Board[rank - 1][file] == '-' || islower(Board[rank - 1][file])) //free space
            {
                //Board[rank - 1][file] = 'L';
                char r = genRank(rank - 1);
                char f = genFile(file);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank <= 5 && rank >= 4) // can we move down
        {
            if (Board[rank + 1][file] == '-' || islower(Board[rank + 1][file]))
            {
                //Board[rank + 1][file] = 'L';
                char r = genRank(rank + 1);
                char f = genFile(file);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (file > 2 && file <= 4 && rank > 4 && rank <= 6) // can move diag up ()
        {
            if (Board[rank - 1][file - 1] == '-' || islower(Board[rank - 1][file - 1])) // move diag left
            {
                //Board[rank - 1][file - 1] = 'L';
                char r = genRank(rank - 1);
                char f = genFile(file - 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (file >= 2 && file < 4 && rank > 4 && rank <= 6) // diag up(right)
        {
            if (Board[rank - 1][file + 1] == '-' || islower(Board[rank - 1][file + 1]))
            {
                //Board[rank - 1][file + 1] = 'L';
                char r = genRank(rank - 1);
                char f = genFile(file + 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank >= 4 && rank < 6 && file > 2 && file <= 4) // diag down(left)
        {
            if (Board[rank + 1][file - 1] == '-' || islower(Board[rank + 1][file - 1]))
            {
                // Board[rank + 1][file - 1] = 'L';
                char r = genRank(rank + 1);
                char f = genFile(file - 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank >= 4 && rank < 6 && file >= 2 && file < 4) // diag down(right)
        {
            if (Board[rank + 1][file + 1] == '-' || islower(Board[rank + 1][file + 1]))
            {
                //Board[rank + 1][file + 1] = 'L';
                char r = genRank(rank + 1);
                char f = genFile(file + 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank == 4 && file >= 2 && file <= 4) // we are at the river border -> check if we can catch opposing lion
        {
            if (Board[rank - 2][file] == 'l') // opposition lion present
            {
                Board[rank - 2][file] = '*';
                char r = genRank(rank - 2);
                char f = genFile(file);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
            if (file >= 3 && file <= 4)
            {
                if (Board[rank - 2][file - 2] == 'l' && Board[rank - 1][file - 1] == '-')
                {
                    Board[rank - 2][file - 2] = '*';
                    char r = genRank(rank - 2);
                    char f = genFile(file - 2);
                    string pos = states;
                    pos += f;
                    pos += r;
                    moves.push_back(pos);
                }
            }
            if (file >= 2 && file <= 3)
            {
                if (Board[rank - 2][file + 2] == 'l' && Board[rank - 1][file + 1] == '-')
                {
                    Board[rank - 2][file + 2] = '*';
                    char r = genRank(rank - 2);
                    char f = genFile(file + 2);
                    string pos = states;
                    pos += f;
                    pos += r;
                    moves.push_back(pos);
                }
            }
        }

        for (int i = rank - 1; i >= 0; i--)
        {

            if (Board[i][file] != '-')
            {
                if (Board[i][file] == 'l')
                {
                    char f = genFile(file);
                    char r = genRank(i);
                    string pos = states;
                    pos += f;
                    pos += r;
                    moves.push_back(pos);
                }
                else
                {
                    break;
                }
            }
        }

        //printBoard(Board);
        sort(moves.begin(), moves.end());
        return moves;
    }
    else // player is black
    {
        string states = pieces['l'];

        int rank = getRank(states[1]);
        int file = getFile(states[0]);

        //check if we can move left
        if (file >= 3 && file <= 4)
        {
            if (Board[rank][file - 1] == '-' || isupper(Board[rank][file - 1])) // valid move
            {
                //Board[rank][file - 1] = 'l';
                char r = genRank(rank);
                char f = genFile(file - 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (file < 4 && file > 1) // check if we can move right
        {
            if (Board[rank][file + 1] == '-' || isupper(Board[rank][file + 1])) // space is free
            {
                //Board[rank][file + 1] = 'l';
                char r = genRank(rank);
                char f = genFile(file + 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank <= 2 && rank > 0) // check if we can move up
        {
            if (Board[rank - 1][file] == '-' || isupper(Board[rank - 1][file])) //free space
            {
                //Board[rank - 1][file] = 'l';
                char r = genRank(rank - 1);
                char f = genFile(file);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank <= 1 && rank >= 0) // can we move down
        {
            if (Board[rank + 1][file] == '-' || isupper(Board[rank + 1][file]))
            {
                //Board[rank + 1][file] = 'l';
                char r = genRank(rank + 1);
                char f = genFile(file);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (file > 2 && file <= 4 && rank > 0 && rank <= 2) // can move diag up ()
        {
            if (Board[rank - 1][file - 1] == '-' || isupper(Board[rank - 1][file - 1])) // move diag left
            {
                //Board[rank - 1][file - 1] = 'l';
                char r = genRank(rank - 1);
                char f = genFile(file - 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (file >= 2 && file < 4 && rank > 0 && rank <= 2) // diag up(right)
        {
            if (Board[rank - 1][file + 1] == '-' || isupper(Board[rank - 1][file + 1]))
            {
                //Board[rank - 1][file + 1] = 'l';
                char r = genRank(rank - 1);
                char f = genFile(file + 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank >= 0 && rank < 2 && file > 2 && file <= 4) // diag down(left)
        {
            if (Board[rank + 1][file - 1] == '-' || isupper(Board[rank + 1][file - 1]))
            {
                //Board[rank + 1][file - 1] = 'l';
                char r = genRank(rank + 1);
                char f = genFile(file - 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank >= 0 && rank < 2 && file >= 2 && file < 4) // diag down(right)
        {
            if (Board[rank + 1][file + 1] == '-' || isupper(Board[rank + 1][file + 1]))
            {
                //Board[rank + 1][file + 1] = 'l';
                char r = genRank(rank + 1);
                char f = genFile(file + 1);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
        }
        if (rank == 2 && file >= 2 && file <= 4) // we are at the river border -> check if we can catch opposing lion
        {
            if (Board[rank - 2][file] == 'L') // opposition lion present
            {
                //Board[rank - 2][file] = '*';
                char r = genRank(rank - 2);
                char f = genFile(file);
                string pos = states;
                pos += f;
                pos += r;
                moves.push_back(pos);
            }
            if (file >= 3 && file <= 4)
            {
                if (Board[rank + 2][file - 2] == 'L' && Board[rank + 1][file - 1] == '-')
                {
                    // Board[rank + 2][file - 2] = '*';
                    char r = genRank(rank + 2);
                    char f = genFile(file - 2);
                    string pos = states;
                    pos += f;
                    pos += r;
                    moves.push_back(pos);
                }
            }
            if (file >= 2 && file <= 3)
            {
                if (Board[rank + 2][file + 2] == 'L' && Board[rank + 1][file + 1] == '-')
                {
                    //Board[rank + 2][file + 2] = '*';
                    char r = genRank(rank - 2);
                    char f = genFile(file + 2);
                    string pos = states;
                    pos += f;
                    pos += r;
                    moves.push_back(pos);
                }
            }
        }

        for (int i = rank + 1; i <= 6; i++)
        {

            if (Board[i][file] != '-')
            {

                if (Board[i][file] == 'L')
                {
                    char r = genRank(i);
                    char f = genFile(file);
                    string pos = states;
                    pos += f;
                    pos += r;
                    moves.push_back(pos);
                }
                else
                {
                    break;
                }
            }
        }

        printBoard(Board);
        sort(moves.begin(), moves.end());
        return moves;
    }
}

vector<string> genZebra(map<char, string> pieces) // change return type
{
    vector<string> moves;
    string player = pieces['x']; // get the correct player turn

    if (player == "w") // whites turn
    {
        string states = pieces['Z'];
        if (states.length() != 0)
        {
            int file = getFile(states[0]);
            int rank = getRank(states[1]);

            if (rank <= 6 && rank >= 2) // we can move vert. up
            {
                if (file >= 1) // can move left
                {
                    if (Board[rank - 2][file - 1] == '-' || islower(Board[rank - 2][file - 1])) // space available
                    {
                        //Board[rank - 2][file - 1] = 'Z';
                        char f = genFile(file - 1);
                        char r = genRank(rank - 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file <= 5) // can move right
                {
                    if (Board[rank - 2][file + 1] == '-' || islower(Board[rank - 2][file + 1])) // free/ capture
                    {
                        //Board[rank - 2][file + 1] = 'Z';
                        char f = genFile(file + 1);
                        char r = genRank(rank - 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
            if (rank >= 0 && rank <= 4) // can move vert. down
            {
                if (file >= 1) // can move left
                {
                    if (Board[rank + 2][file - 1] == '-' || islower(Board[rank + 2][file - 1]))
                    {
                        //Board[rank + 2][file - 1] = 'Z';
                        char f = genFile(file - 1);
                        char r = genRank(rank + 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file <= 5) // can move right
                {
                    if (Board[rank + 2][file + 1] == '-' || islower(Board[rank + 2][file + 1]))
                    {
                        //Board[rank + 2][file + 1] = 'Z';
                        char f = genFile(file + 1);
                        char r = genRank(rank + 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
            // check horizontal
            if (file >= 0 && file <= 4) // can move horiz. right
            {
                if (rank >= 1) // can move up
                {
                    if (Board[rank - 1][file + 2] == '-' || islower(Board[rank - 1][file + 2]))
                    {
                        //Board[rank - 1][file + 2] = 'Z';
                        char f = genFile(file + 2);
                        char r = genRank(rank - 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank <= 5) // can move down
                {
                    if (Board[rank + 1][file + 2] == '-' || islower(Board[rank + 1][file + 2]))
                    {
                        //Board[rank + 1][file + 2] = 'Z';
                        char f = genFile(file + 2);
                        char r = genRank(rank + 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
            if (file <= 6 && file >= 2) // can move horiz. left
            {
                if (rank >= 1) // can move up
                {
                    if (Board[rank - 1][file - 2] == '-' || islower(Board[rank - 1][file - 2]))
                    {
                        //Board[rank - 1][file - 2] = 'Z';
                        char f = genFile(file - 2);
                        char r = genRank(rank - 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank <= 5) // can move down
                {
                    if (Board[rank + 1][file - 2] == '-' || islower(Board[rank + 1][file - 2]))
                    {
                        //Board[rank + 1][file - 2] = 'Z';
                        char f = genFile(file - 2);
                        char r = genRank(rank + 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }

            //printBoard(Board);
            sort(moves.begin(), moves.end());
            return moves;
        }
        else
        {
            return moves;
        }
    }
    else // player is black
    {
        string states = pieces['z'];

        if (states.length() != 0)
        {
            int file = getFile(states[0]);
            int rank = getRank(states[1]);

            if (rank <= 6 && rank >= 2) // we can move vert. up
            {
                if (file >= 1) // can move left
                {
                    if (Board[rank - 2][file - 1] == '-' || isupper(Board[rank - 2][file - 1])) // space available
                    {
                        //Board[rank - 2][file - 1] = 'Z';
                        char f = genFile(file - 1);
                        char r = genRank(rank - 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file <= 5) // can move right
                {
                    if (Board[rank - 2][file + 1] == '-' || isupper(Board[rank - 2][file + 1])) // free/ capture
                    {
                        //Board[rank - 2][file + 1] = 'Z';
                        char f = genFile(file + 1);
                        char r = genRank(rank - 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
            if (rank >= 0 && rank <= 4) // can move vert. down
            {
                if (file >= 1) // can move left
                {
                    if (Board[rank + 2][file - 1] == '-' || isupper(Board[rank + 2][file - 1]))
                    {
                        //Board[rank + 2][file - 1] = 'Z';
                        char f = genFile(file - 1);
                        char r = genRank(rank + 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file <= 5) // can move right
                {
                    if (Board[rank + 2][file + 1] == '-' || isupper(Board[rank + 2][file + 1]))
                    {
                        //Board[rank + 2][file + 1] = 'Z';
                        char f = genFile(file + 1);
                        char r = genRank(rank + 2);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
            // check horizontal
            if (file >= 0 && file <= 4) // can move horiz. right
            {
                if (rank >= 1) // can move up
                {
                    if (Board[rank - 1][file + 2] == '-' || isupper(Board[rank - 1][file + 2]))
                    {
                        //Board[rank - 1][file + 2] = 'Z';
                        char f = genFile(file + 2);
                        char r = genRank(rank - 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank <= 5) // can move down
                {
                    if (Board[rank + 1][file + 2] == '-' || isupper(Board[rank + 1][file + 2]))
                    {
                        //Board[rank + 1][file + 2] = 'Z';
                        char f = genFile(file + 2);
                        char r = genRank(rank + 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
            if (file <= 6 && file >= 2) // can move horiz. left
            {
                if (rank >= 1) // can move up
                {
                    if (Board[rank - 1][file - 2] == '-' || isupper(Board[rank - 1][file - 2]))
                    {
                        //Board[rank - 1][file - 2] = 'Z';
                        char f = genFile(file - 2);
                        char r = genRank(rank - 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank <= 5) // can move down
                {
                    if (Board[rank + 1][file - 2] == '-' || isupper(Board[rank + 1][file - 2]))
                    {
                        //Board[rank + 1][file - 2] = 'Z';
                        char f = genFile(file - 2);
                        char r = genRank(rank + 1);
                        string pos = states;
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }

            //printBoard(Board);
            sort(moves.begin(), moves.end());
            return moves;
        }
        else
        {
            return moves;
        }
    }
}

vector<string> genElephant(map<char, string> pieces)
{
    vector<string> moves;
    string player = pieces['x'];

    if (player == "w") // its whites turn
    {
        string states = pieces['E'];
        if (states.length() != 0) // if the elephant is present
        {
            for (int i = 0; i < states.length() - 1; i = i + 3)
            {
                int file = getFile(states[i]);
                int rank = getRank(states[i + 1]);

                if (file > 0) // check left move (1 jump)
                {
                    if (Board[rank][file - 1] == '-' || islower(Board[rank][file - 1])) // available
                    {
                        char f = genFile(file - 1);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file > 1) // check left move (2 jumps)
                {
                    if (Board[rank][file - 2] == '-' || islower(Board[rank][file - 2]))
                    {
                        char f = genFile(file - 2);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file < 6) // check right move (1 jump)
                {
                    if (Board[rank][file + 1] == '-' || islower(Board[rank][file + 1]))
                    {
                        char f = genFile(file + 1);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file < 5) //right move(2 jumps)
                {
                    if (Board[rank][file + 2] == '-' || islower(Board[rank][file + 2]))
                    {

                        char f = genFile(file + 2);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 0) // check up -> 1 jump
                {
                    if (Board[rank - 1][file] == '-' || islower(Board[rank - 1][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank - 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 1) // up -> 2 jumps
                {
                    if (Board[rank - 2][file] == '-' || islower(Board[rank - 2][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank - 2);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 6) // down -> 1 jump
                {
                    if (Board[rank + 1][file] == '-' || islower(Board[rank + 1][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank + 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 5) // down -> 2 jumps
                {
                    if (Board[rank + 2][file] == '-' || islower(Board[rank + 2][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank + 2);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
        }
        else // no elephants present
        {
            return moves;
        }

        //printBoard(Board);
        sort(moves.begin(), moves.end());
        return moves;
    }
    else // blacks turn
    {
        string states = pieces['e'];
        if (states.length() != 0) // if the elephant is present
        {
            for (int i = 0; i < states.length() - 1; i = i + 3)
            {
                int file = getFile(states[i]);
                int rank = getRank(states[i + 1]);

                if (file > 0) // check left move (1 jump)
                {
                    if (Board[rank][file - 1] == '-' || isupper(Board[rank][file - 1])) // available
                    {
                        char f = genFile(file - 1);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file > 1) // check left move (2 jumps)
                {
                    if (Board[rank][file - 2] == '-' || isupper(Board[rank][file - 2]))
                    {
                        char f = genFile(file - 2);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file < 6) // check right move (1 jump)
                {
                    if (Board[rank][file + 1] == '-' || isupper(Board[rank][file + 1]))
                    {
                        char f = genFile(file + 1);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (file < 5) //right move(2 jumps)
                {
                    if (Board[rank][file + 2] == '-' || isupper(Board[rank][file + 2]))
                    {

                        char f = genFile(file + 2);
                        char r = genRank(rank);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 0) // check up -> 1 jump
                {
                    if (Board[rank - 1][file] == '-' || isupper(Board[rank - 1][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank - 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 1) // up -> 2 jumps
                {
                    if (Board[rank - 2][file] == '-' || isupper(Board[rank - 2][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank - 2);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 6) // down -> 1 jump
                {
                    if (Board[rank + 1][file] == '-' || isupper(Board[rank + 1][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank + 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 5) // down -> 2 jumps
                {
                    if (Board[rank + 2][file] == '-' || isupper(Board[rank + 2][file]))
                    {

                        char f = genFile(file);
                        char r = genRank(rank + 2);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
        }
        else // no elephants present
        {
            return moves;
        }

        //printBoard(Board);
        sort(moves.begin(), moves.end());
        return moves;
    }
}

vector<string> genPawn(map<char, string> pieces)
{
    vector<string> moves;
    string player = pieces['x'];

    if (player == "w")
    {
        string states = pieces['P'];

        if (states.length() != 0)
        {
            for (int i = 0; i < states.length() - 1; i = i + 3)
            {
                int file = getFile(states[i]);
                int rank = getRank(states[i + 1]);

                if (rank > 0) // we can move straight up
                {
                    if (Board[rank - 1][file] == '-' || islower(Board[rank - 1][file]))
                    {
                        char f = genFile(file);
                        char r = genRank(rank - 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 0 && file > 0) // we can move diag left
                {
                    if (Board[rank - 1][file - 1] == '-' || islower(Board[rank - 1][file - 1]))
                    {
                        char f = genFile(file - 1);
                        char r = genRank(rank - 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 0 && file < 6) // diag right
                {
                    if (Board[rank - 1][file + 1] == '-' || islower(Board[rank - 1][file + 1]))
                    {
                        char f = genFile(file + 1);
                        char r = genRank(rank - 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 3) // we have passed the river
                {
                    if (Board[rank + 1][file] == '-') // move 1 back
                    {
                        char f = genFile(file);
                        char r = genRank(rank + 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                    if (Board[rank + 2][file] == '-' && Board[rank + 1][file] == '-')
                    {
                        char f = genFile(file);
                        char r = genRank(rank + 2);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
        }
        else // none present
        {
            return moves;
        }
        //printBoard(Board);
        sort(moves.begin(), moves.end());
        return moves;
    }
    else // blacks turn
    {
        string states = pieces['p'];

        if (states.length() != 0)
        {
            for (int i = 0; i < states.length() - 1; i = i + 3)
            {
                int file = getFile(states[i]);
                int rank = getRank(states[i + 1]);

                if (rank > 0) // we can move straight down
                {
                    if (Board[rank + 1][file] == '-' || isupper(Board[rank + 1][file]))
                    {
                        char f = genFile(file);
                        char r = genRank(rank + 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 6 && file > 0) // we can move diag left
                {
                    if (Board[rank + 1][file - 1] == '-' || isupper(Board[rank + 1][file - 1]))
                    {
                        char f = genFile(file - 1);
                        char r = genRank(rank + 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank < 6 && file < 6) // diag right
                {
                    if (Board[rank + 1][file + 1] == '-' || isupper(Board[rank + 1][file + 1]))
                    {
                        char f = genFile(file + 1);
                        char r = genRank(rank + 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
                if (rank > 3) // we have passed the river
                {
                    if (Board[rank - 1][file] == '-') // move 1 back
                    {
                        char f = genFile(file);
                        char r = genRank(rank - 1);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                    if (Board[rank - 2][file] == '-' && Board[rank - 1][file] == '-')
                    {
                        char f = genFile(file);
                        char r = genRank(rank - 2);
                        string pos = "";
                        pos += states[i];
                        pos += states[i + 1];
                        pos += f;
                        pos += r;
                        moves.push_back(pos);
                    }
                }
            }
        }
        else // none present
        {
            return moves;
        }
        //printBoard(Board);
        sort(moves.begin(), moves.end());
        return moves;
    }
}

int main()
{
    vector<string> states;
    int n;

    cin >> n;     // number of FEN's to accept
    cin.ignore(); // remove cin bug

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        states.push_back(line); // adding the FEN to collection of states
    }

    int count = 0;
    int map_size = states.size();

    map<char, string> positions;
    vector<string> move_states;
    for (string key : states) // for each state of the game
    {
        initBoard();                   // initialize board
        positions = getLocations(key); // Get the positions of all the pieces
        //PrintPositions(positions); DEBUG
        //count++;

        setBoard(positions);
        // printBoard(Board);

        move_states = genPawn(positions);

        int state_size = move_states.size();

        for (string key : move_states)
        {
            if (count == state_size)
            {
                cout << key;
            }
            else
            {
                cout << key << " ";
            }
        }
        cout << endl;
    }
}