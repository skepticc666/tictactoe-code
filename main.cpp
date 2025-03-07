

#include <iostream>

void drawtable(char *space);
void playerMove(char *space , char player);
void computerMove(char *space,  char computer);
bool checkWinner(char *space , char player ,char computer);
bool checkTie(char *space);

int main()
{
    char space[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawtable(space);

    while(running){
        playerMove(space,player);
        drawtable(space);
        if(checkWinner(space, player,computer)){
            running = false;
            for(int i=0 ; i<9 ; i++ ){
                space[i] == ' ';
            }
            break;
        } else {
            if(checkTie(space)){
                running = false;
                for(int i=0 ; i<9 ; i++ ){
                    space[i] == ' ';
                }
                break;
            }
        }
        computerMove(space, computer);
        drawtable(space);
        if(checkWinner(space,player,computer)){
            running = false;
            break;
        } else {
            if(checkTie(space)){
                running = false;
                return 0;
            }
        }

    }

} 


void drawtable(char *space)
{
    std::cout << '\n';
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << space[0] << " | "  << space[1] << " | " <<   space[2] << " " << std::endl;
    std::cout << "___|___|___    " ;

    
    std::cout << '\n';
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << space[3] << " | "  << space[4] << " | " <<   space[5] << " " << std::endl;
    std::cout << "___|___|___    "  ;

    
    std::cout << '\n';
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << space[6] << " | "  << space[7] << " | " <<   space[8] << " " << std::endl;
    
}

void playerMove(char *space , char player){
    int number;
    do{
        std::cout<< "choose a number between 0 and 9" << std::endl;
        std::cin >> number ;
        if(space[number] ==  ' '){
            space[number] = player;
            break;
        }
    } while (number >= 0 && number <= 8 );
     
}

bool checkWinner (char *space , char player , char winner){
    if(space[0] != ' ' && space[0]==space[1] && space[1]==space[2]){
        space[0] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[3] != ' ' && space[3]==space[4] && space[4]==space[5]){
        space[3] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[6] != ' ' && space[6]==space[7] && space[7]==space[8]){
        space[6] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[0] != ' ' && space[0]==space[3] && space[3]==space[6]){
        space[0] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[1] != ' ' && space[1]==space[4] && space[4]==space[7]){
        space[1] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[2] != ' ' && space[2]==space[5] && space[5]==space[8]){
        space[2] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[0] != ' ' && space[0]==space[4] && space[4]==space[8]){
        space[0] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else if(space[2] != ' ' && space[2]==space[4] && space[4]==space[6]){
        space[2] == player ? std::cout << "You win" << std::endl : std::cout << "You Lose" << std::endl;
    }
    else { return 0; }
    
    return true;
}

void computerMove(char *space,  char computer){
    int number;
    while(true){
        number = rand() % 9;
        if(space[number] != 0){
            space[number] = computer;
            
            break;
        }
    }
}

bool checkTie(char *space){
    for(int i =0 ; i<9 ; i++){
        if(space[i] == ' '){
            return false;
            break;
        }
    }
    std::cout << "The game Is a Tie" << std::endl;
    
    return true;
}
