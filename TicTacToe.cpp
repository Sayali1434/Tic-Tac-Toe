#include <iostream>
using namespace std;

char box[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char sym = 'X';
string player1;
string player2;
bool tie = false;

void print(){
    cout << "  " << box[0][0] << " |  " << box[0][1] << " |  " << box[0][2] << " \n";
    cout << "____|____|____\n";
    cout << "  " << box[1][0] << " |  " << box[1][1] << " |  " << box[1][2] << " \n";
    cout << "____|____|____\n";
    cout << "  " << box[2][0] << " |  " << box[2][1] << " |  " << box[2][2] << " \n";
    cout << "    |    |    \n";

}

void beginning(){
    cout << "Enter name of PLAYER1: ";
    cin >> player1;
    cout << "Enter name of PLAYER2: ";
    cin >> player2;
    
    cout << endl;
    cout << player1 << " will play first and then ";
    cout << player2 << " will play second!\n\n";
    
    print();
}

void startGame(){
    int place;

    if(sym == 'X'){
        cout << player1 << ", please enter the position : ";
        cin >> place;
    }
    if(sym == 'O'){
        cout << player2 << ", please enter the position : ";
        cin >> place; 
    }

    switch (place)
    {
        case 1:{
            row = 0;
            column = 0;
            break;
        }
        case 2:{
            row = 0;
            column = 1;
            break;
        }
        case 3:{
            row = 0;
            column = 2;
            break;
        }
        case 4:{
            row = 1;
            column = 0;
            break;
        }
        case 5:{
            row = 1;
            column = 1;
            break;
        }
        case 6:{
            row = 1;
            column = 2;
            break;
        }
        case 7:{
            row = 2;
            column = 0;
            break;
        }
        case 8:{
            row = 2;
            column = 1;
            break;
        }
        case 9:{
            row = 2;
            column = 2;
            break;
        }
        default :{
            cout << "Invalid position :(\n";

        }
    }

    if(sym == 'X' && (box[row][column] != 'O' || box[row][column] != 'X')){
        box[row][column] = 'X';
        sym = 'O';
    }
    else if(sym == 'O' && (box[row][column] != 'O' || box[row][column] != 'X')){
        box[row][column] = 'O';
        sym = 'X';
    }
    else cout << "There is no empty space!\n";
}

bool isGameFinished(){
    for(int i=0; i<3; i++){
        if((box[i][0] == box[i][1] && box[i][1] == box[i][2]) || (box[0][i] == box[1][i] && box[1][i] == box[2][i]))
            return true;
    }
    if((box[0][0] == box[1][1] && box[1][1] == box[2][2]) || (box[0][2] == box[1][1] && box[1][1] == box[2][0]))
        return true;
            
        
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
                if(box[i][j] != 'X' && box[i][j] != 'O') return false;
            }
        }
    
    tie = true;
    return false;
}

int main(){
    beginning();
    cout << endl;

    while(!isGameFinished()){
        startGame();
        cout << endl;
        print();
        cout << endl;
    }

    if(sym == 'O' && tie == false){
        cout << player2 << " wins!!!" << endl;
    }
    else if(sym == 'O' && tie == false){
        cout << player1 << " wins!!!" << endl;
    }
    else cout << "It's a draw!" << endl;
    
}