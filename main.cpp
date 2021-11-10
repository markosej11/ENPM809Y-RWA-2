/**
 * @file main.cpp
 * @author Markose Jacob
 * @version 1.0
 * @section DISCRIPTION
 * This program is used to find the path inside a maze which is predefined
 */
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>// for converting float to string
#include <string>

using namespace std;
/**
 * @brief Function checks if the coordinates are going out of the maze
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns ture if x or y goes outside the Maze
 */
bool IsOutsideMaze (int x,int y);
/**
 * @brief Function checks if the goal coordinate has reached or not
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @param goalx Coordinate of goal along x axis
 * @param goaly Coordinate of goal along x axis
 * @return Returns true if goal position has reached else false
 */
bool IsGoal (int x,int y, int goalx, int goaly);
/**
 * @brief Function checks if the coordinate has an obstacle
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns true if there is an obstacle in that location
 */
bool Isobstacle (int x, int y);
/**
 * @brief Recursive function to find a valid path from start to goal.
 * The function first checks if the current position is out side the maze.
 * It then checks if the current position is goal or not
 * It then checks if the current position is an obstacle
 * Then function tries to find a path in north direction, then in East Direction, then in South direction, and finally in West direction.
 * If any of these are possible then the move is saved in a vector and returns true
 * If no moves are possible then the function marks that location  with a 'X' and backtracks.
 * When the goal is reached, it returns a true.
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns true if a path is found
 */
bool FindPath (int x, int y);
/**
 * @brief Function makes a move in North direction
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns a vector with new coordinates
 */
vector<int> GoNorth (int x,int y);
/**
 * @brief Function makes a move in East direction
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns a vector with new coordinates
 */
vector<int> GoEast (int x,int y);
/**
 * @brief Function makes a move in South direction
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns a vector with new coordinates
 */
vector<int> GoSouth (int x,int y);
/**
 * @brief Function makes a move in West direction
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns a vector with new coordinates
 */
vector<int> GoWest (int x,int y);
/**
 * @brief Function checks if the coordinate entered by the user is an obstacle or not
 * @param x Current position along x axis
 * @param y Current position along y axis
 * @return Returns false if there is an obstacle in that location
 */
bool CheckEntryIsobstacle(int x, int y);
/**
 * Function Displays the maze
 */
void DisplayMaze();

vector<vector<int>> Path; // Vector to store the path
int SizeOfPath;  // Variable to store the size of path
vector<string> Movements; // Vector to store movements made
int goalx{}; // To store x coordinate of goal
int goaly{}; // To store y coordinate of goal
vector<vector <char> > maze{ {'.','#','#','#','#','#'},  // To store the maze
                              {'.','.','.','#','.','#'},
                              {'#','.','#','#','.','#'},
                              {'#','.','#','#','.','#'},
                              {'#','.','#','.','.','.'},
                              {'#','.','.','.','#','#'},
                              } ;


int main(){
    float a,b,c,d;
    int w,x,t,s,y,z; // int variables to store coordinates
    string g = "."; // to check if there is a decimal number
    bool con1,con2 = true; // bool variables to terminate while loops
    bool con3, con4, con6,con7 = false; // bool variables to terminate while loops
    char Answer; // Char Variable to terminate while loop
    cout << "Maze is : ";
    DisplayMaze(); //Displays the maze
    while((Answer != 'y') || (Answer != 'Y'))
    {
            do {
                do {
                    do {
                        cout << "\n\nEnter the coordinates for start position : " << endl;
                        cin >> a >> b; //Takes input from user
                        std::string a1 = boost::lexical_cast<std::string>(a);
                        std::string a2 = boost::lexical_cast<std::string>(b);
                        if ((a1.find(g) != string::npos) || (a2.find(g) != string::npos)) { //Checks if the entry has decimal value
                            cout << "Please enter a int value and not float!!";
                            con6 = true;
                        } else {
                            con6 = false;
                        }
                    }while(con6==true);
                    if (((a >= 6) || (a < 0)) || ((b >= 6) || (b < 0))) //checks if the the input is inside the maze
                    {
                        con3 = true;
                        cout << "The value is outside maze" << endl;
                        DisplayMaze();
                    } else {
                        con3 = false;
                    }
                } while (con3 == true);
                cout << endl;
                w = 5 - b; //Changing the coordinates to match that of vector
                x = a; //Changing the coordinates to match that of vector
                if (CheckEntryIsobstacle(w, x)) //Checks if the location has an obstacle
                {
                    con1 = true;
                }
                else
                    {
                    cout << "The entered coordinate is an obstacle. Please re-enter!! " << endl; //checks if there is an obstacle in the entered coordinate.
                    con1 = false;
                }
            }while(con1 == false);
            do {
                do {
                    do{

                        DisplayMaze();
                        cout << "\nEnter the coordinates for goal position : " << endl;
                        cin >> c >> d; //goal input from user
                        std::string a3 = boost::lexical_cast<std::string>(c);
                        std::string a4 = boost::lexical_cast<std::string>(d);
                        if ((a3.find(g) != string::npos) || (a4.find(g) != string::npos)) {
                            cout << "Please enter a int value and not float!!";
                            con7 = true;
                        }
                        else{
                        con7 = false;
                        }
                    }while(con7==true);
                    if (((c>=6)||(c<0))||((d>=6)||(d<0))) //checks if the the input is inside the maze
                    {
                        con4 = true;
                        cout << "The value is outside maze" << endl;

                    } else
                    {
                        con4 = false;
                    }
                }while (con4==true);
                cout << endl;
                t = 5 - d;//Changing the coordinates to match that of vector
                s = c;//Changing the coordinates to match that of vector
                if (CheckEntryIsobstacle(t, s)) //Checks if the location has an obstacle
                {
                    con2 = true;
                }
                else
                    {
                    cout << "The entered coordinate is an obstacle. Please re-enter!! " << endl;
                    con2 = false;
                }
            }while(con2 == false);
    cout << endl;
    maze.at(w).at(x) = 'S';
    maze.at(t).at(s) = 'G';
    DisplayMaze();
    cout << "\n\nIs this the start and goal location you want? (y/n) " << endl; //Asks if the user wants to change the goal and start location
    cin >> Answer;
    if((Answer=='y') || (Answer == 'Y'))
    {
        break;
    }
        maze.at(w).at(x) = '.';
        maze.at(t).at(s) = '.';
    }

    goalx = t;
    goaly = s;
    DisplayMaze();
    maze.at(w).at(x) = '.';
    FindPath(w,x); // Runs recursive function to solve maze
    if(maze[w][x]=='+') {

        maze[w][x]='S';
        cout << "\nThe maze solution path looks like this: " << endl;
        cout << "\nStarting Position: " << "[" << a << "," << b << "]\n"; //outputs the starting location
        for (int i=SizeOfPath-1 ; i > -1 ; --i)
        {
            cout << Movements[i] << ": "; // Outputs all the movements made to reach goal
            y = Path[i][1];//Changing the coordinates to match that of vector
            z = 5-Path[i][0];//Changing the coordinates to match that of vector
            cout << "[" << y << "," << z << "]" << endl;
        }
        cout << "\n\nReached Goal Node!!!\n" << endl;
        DisplayMaze();
    }
    else
        cout << " No path can be found!! \n" << endl;
    return 0;
}



bool CheckEntryIsobstacle(int x,int y)
{
    if(maze[x][y]=='#' || maze[x][y]=='+')
    {
        return false;
    }
    else
    {
        return true;
    }
}
void DisplayMaze()
{

    cout << endl;
    for(int i =0; i<6; i++)
    {
        cout << 5-i << " ";
        for(int j=0; j<6; j++)
        {
            cout << maze.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << "  ";
    for(int g = 0; g<6; g++)
    {
        cout << g << " ";
    }
}

bool IsOutsideMaze(int x,int y)
{
    if(x>=6 || x<0)
    {
        return true;
    }
    else if(y>=6 || y<0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool IsGoal(int x,int y, int goalx, int goaly)
{
    if(x == goalx && y == goaly)
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool Isobstacle(int x,int y)
{
    if(maze[x][y]=='#' || maze[x][y]=='+')
    {
        return true;
    }
    else
    {
        return false;
    }
}
vector<int> GoNorth(int x,int y)
{
    x = x-1;
    y = y;
    vector<int> North{x,y};
    return North;
}
vector<int> GoEast(int x,int y)
{
    x = x;
    y = y+1;
    vector<int> East{x,y};
    return East;
}
vector<int> GoSouth(int x,int y)
{
    x = x+1;
    y = y;
    vector<int> South{x,y};
    return South;
}
vector<int> GoWest(int x,int y)
{
    x = x;
    y = y-1;
    vector<int> West{x,y};
    return West;
}

bool FindPath (int x, int y) // Recursive function to find path
{
    if(IsOutsideMaze(x, y))
    {
        return false;
    }
    if(IsGoal(x, y,goalx,goaly))
    {
        return true;
    }
    if(Isobstacle(x, y))
    {
        return false;
    }
    vector<int> PosibleMoves;
    maze[x][y] = '+';
    if(FindPath(GoNorth(x,y)[0],GoNorth(x,y)[1]))
    {
        PosibleMoves = GoNorth(x,y); // Storing the coordinates of north move
        Path.push_back(PosibleMoves); // updating with new coordinates
        SizeOfPath = Path.size(); // Updating the size of path
        Movements.push_back("Moved North"); //Updating Movement with the Moved North
        return true;

    }
    if(FindPath(GoEast(x,y)[0],GoEast(x,y)[1]))
    {
        PosibleMoves = GoEast(x,y);
        Path.push_back(PosibleMoves);
        SizeOfPath = Path.size();
        Movements.push_back("Moved East ");
        return true;

    }
    if(FindPath(GoSouth(x,y)[0],GoSouth(x,y)[1]))
    {
        PosibleMoves = GoSouth(x,y);
        Path.push_back(PosibleMoves);
        SizeOfPath = Path.size();
        Movements.push_back("Moved South");
        return true;

    }
    if(FindPath(GoWest(x,y)[0],GoWest(x,y)[1]))
    {
        PosibleMoves = GoWest(x,y);
        Path.push_back(PosibleMoves);
        SizeOfPath = Path.size();
        Movements.push_back("Moved West ");
        return true;

    }
    maze[x][y] = 'X';
    return false;
}
