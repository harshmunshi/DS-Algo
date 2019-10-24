/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., 
maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. 
A rat starts from source and has to reach the destination. The rat can move only in two directions: 
forward and down.

In the maze matrix, 0 means the block is a dead end and 1 means the block 
can be used in the path from source to destination. Note that this is a 
simple version of the typical Maze problem. For example, a more complex version
can be that the rat can move in 4 directions and a more complex version can be 
with a limited number of moves.

*/

#include <iostream>
#include <vector>

#define N 4

using namespace std;

bool mazeutil(int maze[N][N], int x, int y, int path[N][N]);
void printArray(int path[N][N]);

void printArray(int path[N][N]){
    for (int i =0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}
bool mazesolver(int maze[N][N]){
    /* simple steps that I will follow:
    1. start with a node, check if it's the goal position.
    2. if not enter the recursive callback to mazeutil
    */

   int start_x = 0;
   int start_y = 0;
   int path[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 

   if (mazeutil(maze, start_x, start_y, path) == false){
       cout << "No solution";
       return false;
   }

   printArray(path);
   return true;
}

bool mazeutil(int maze[N][N], int x, int y, int path[N][N]){
    // check the boundary condition first
    if (x == N-1 && y == N-1){
        path[x][y] = 1;
        return true;
    }

    // now since it is not the final value, let us expand
    // from the root node we can move into right or down direction
    
    // initially let us pick one direction for expansion (let's say right)
    if (x >= 0 && x < N && y >=0 && y < N && maze[x][y] ==1){
        path[x][y] = 1;

        // keep on moving right until hit a dead end
        if(mazeutil(maze, x+1 , y, path)==true){
            return true;
        }

        // move down
        if(mazeutil(maze, x, y+1, path) == true){
            return true;
        }

        // IMP if none of them work, backtrack
        path[x][y] = 0;
        return false;

    }
    // if nothing works return false
    return false;
}

int main(){
    int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    mazesolver(maze); 
    return 0; 
}