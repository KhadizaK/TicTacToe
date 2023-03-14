#include <string>
#include <iostream>
#include <ctime>

#define GRID_SIZE 3

using namespace std;

string playerONEName;
string playerTWOName;
char p1XorO, compXorO, p2XorO;

class Game{

    private:
        char grid[GRID_SIZE][GRID_SIZE];

    public:

        void check_for_wins() {
            const char* winning_moves[8] = {
                "123",
                "456",
                "789",
                "147",
                "258",
                "369",
                "753",
                "159"
            };

            // loop thorough all of the posible winning movesets...

            for (int i = 0; i < 8; i++) {
                bool winner = true;
                char previous_grid = '0';
                const char* winning_move = winning_moves[i];

                for (int index = 0; index < 3; index++) {
                    char character = winning_move[index];

                    int entered_number = character - '0';
                    int grid_space = entered_number - 1;

                    int row = grid_space / GRID_SIZE;
                    int col = grid_space % GRID_SIZE;

                    char grid_char = grid[row][col];

                    if (previous_grid == '0') {
                        previous_grid = grid_char;
                    }
                    else if (previous_grid == grid_char) {
                        continue;
                    } else {
                        winner = false;
                        break;
                    }
                }
                if (winner) {
                    printf("\n****** We have a winner!******\n");
                    if (previous_grid == p1XorO) {
                        cout << "Looks like " << playerONEName << ", " << previous_grid << ", won! Congradualtions!\n";
                        
                    } else if (previous_grid == p2XorO) {
                        cout << "Looks like " << playerTWOName << ", " << previous_grid << ", won! Congradualtions!\n";
                        
                    } else {
                        cout << "Looks like the computer, " << previous_grid << ", won! Congradualtions!\n";

                    }
                    //printf("Looks like %c won, congratulations!\n", previous_grid);

                    exit(0);
                    break;
                } 
            }
        }

        bool ask_single_or_double_player() {
            puts("Choose a. player vs computer or b. player vs player");
            char input;
            cin >> input;
            while (true) {
                if (input == 'a') {
                    return false;
                } else if (input == 'b') {
                    return true;
                } else {
                    puts("Choose a or b");
                }
            }
        }

        void ask_turn() {
            string input;

            while (true) {
                puts("Where would Player 1 like to play?");
                getline(cin, input);

                if (input != "") {
                    char entered = input.c_str()[0];

                    if (entered >= '1' && entered <= '9'){
                        int entered_number  = entered - '0';
                        int index = entered_number - 1;
                        
                        int row = index / 3;
                        int col = index % 3;

                        char grid_position = grid[row][col];

                        cout << "you wanted to to place in this position " << grid_position << endl;

                        if (grid_position == 'X' || grid_position == 'O') {
                            puts("That grid position is already taken!");
                        } else {
                            grid[row][col] = p1XorO;
                            break;
                        }


                    } else {
                        puts("you have to play in range 1 - 9");
                    }
                } else {
                    puts("You must enter something!");
                }
            }
        }

        void ask_turn_with_multiPlayer() {
            string input;

            while (true) {
                puts("Where would Player 2 like to play?");
                getline(cin, input);

                if (input != "") {
                    char entered = input.c_str()[0];

                    if (entered >= '1' && entered <= '9'){
                        int entered_number  = entered - '0';
                        int index = entered_number - 1;
                        
                        int row = index / 3;
                        int col = index % 3;

                        char grid_position = grid[row][col];

                        cout << "you wanted to to place in this position " << grid_position << endl;

                        if (grid_position == 'X' || grid_position == 'O') {
                            puts("That grid position is already taken!");
                        } else {
                            grid[row][col] = p2XorO;
                            break;
                        }


                    } else {
                        puts("you have to play in range 1 - 9");
                    }
                } else {
                    puts("You must enter something!");
                }
            }
        }

        void computer_player_turn() {
            
            while (true) {
                int computer_choice = ( rand() % 9) + 1;

                int row = (computer_choice - 1) / 3;
                int col = (computer_choice - 1) % 3;

                char grid_position = grid[row][col];

                if (grid_position == 'X' || grid_position == 'O') {
                    continue;
                    // this shows that positon is already taked so try another number
                } else {
                    printf("Computer will play at %d.\n", computer_choice);
                    grid[row][col] = compXorO;
                    break;
                }
            }
            
            
        }

        void generate_grid(){
            int number = 1;
            for (int x = 0; x < GRID_SIZE; x++) {
                for (int y = 0; y < GRID_SIZE; y++) {
                    grid[x][y] = to_string(number).c_str()[0];
                    number +=1;
                }
            }
        }

        void show_grid() {
            printf(" ------------------\n");
            for (int x = 0; x < GRID_SIZE; x++) {
                printf(" |");
                for (int y = 0; y < GRID_SIZE; y++) {
                    printf("  %c  |", grid[x][y]);
                }
                printf("\n ------------------\n");
            }
        }

        bool random_start(bool single_or_double) {
            srand((unsigned) time(NULL));
            int random = rand();
            if (single_or_double) {
                if (random % 2 == 0) {
                    puts("Player 1 will go first.");
                    return true;
                    // player 1 starts
                } else {
                    puts("Player 2 will go first.");
                    return false;
                    // player two starts
                }
            } else {
                if (random % 2 == 1) {
                    puts("Player 1 goes first.");
                    return true;
                    // player one starts
                } else {
                    puts("Computer goes first.");
                    return false;
                    // computer starts
                }
            }
        }
        void choose_x_or_o(bool t_or_f, bool comp_or_player2) {
            if (t_or_f) {
                // if t_or_f is true it means that player one is chosen to go first
                puts("What is your name player 1?");
                cin >> playerONEName;
                cout << "Welcome " << playerONEName << "!\n";
                puts("Choose X or O");
                cin >> p1XorO;
                if (!comp_or_player2) {
                    // this means that it's single player
                    // it doesn't matter who goes first player 1 will always choose first
                    if (p1XorO == 'X') {
                        compXorO = 'O';
                    } else if (p1XorO == 'O') {
                        compXorO = 'X';
                    }
                } else {
                    // this is when it's double player
                    puts("What is your name player 2?");
                    cin >> playerTWOName;
                    cout << "Welcome " << playerTWOName << "!\n";
                    if (p1XorO == 'X') {
                        p2XorO = 'O';
                        cout << playerTWOName << ", you are " << p2XorO << endl;
                    } else if (p1XorO == 'O') {
                        p2XorO = 'X';
                        cout << playerTWOName << ", you are " << p2XorO << endl;
                    }
                }
                
            } else {
                if(comp_or_player2) {
                    // when comp_or_player2 is true that means it's double player
                    // player two is chosen to go first
                    puts("What is your name player 2?");
                    cin >> playerTWOName;
                    cout << "Welcome " << playerTWOName << "!\n";
                    puts("Choose X or O");
                    cin >> p2XorO;
                    // gets name of player 1
                    puts("What is your name player 1?");
                    cin >> playerONEName;
                    cout << "Welcome " << playerONEName << "!\n";
                    
                    if (p2XorO == 'X') {
                        p1XorO = 'O';
                        cout << playerONEName << ", you are " << p1XorO << endl;
                    } else if (p2XorO == 'O') {
                        p1XorO = 'X';
                        cout << playerONEName << ", you are " << p1XorO << endl;
                    }

                }
            }
        }

        Game() {
            generate_grid();
            bool single_or_double = ask_single_or_double_player();

            if (single_or_double) {
                /// true means it's multi player
                if (random_start(single_or_double)) {
                    // if player one is picked to go first
                    bool t = true;
                    choose_x_or_o(t, t);
                    show_grid();
                        check_for_wins();
                        while (true) {
                            ask_turn();
                            check_for_wins();
                            show_grid();
                            
                            ask_turn_with_multiPlayer();
                            show_grid();
                            check_for_wins();
                        }

                } else {
                    // player two is picked to go first
                    bool f = false;
                    bool t = true;
                    choose_x_or_o(f, t);
                    show_grid();
                        check_for_wins();
                        while (true) {
                            ask_turn_with_multiPlayer(); //ask_turn();
                            check_for_wins();
                            show_grid();
                            
                            ask_turn(); //ask_turn_with_multiPlayer();
                            show_grid();
                            check_for_wins();
                        }
                }
                
            } else {
                // false when single player
                if (random_start(single_or_double)) {
                    // player 1 goes first
                    bool f = false;
                    bool t = true;
                    choose_x_or_o(t, f);
                    show_grid();
                    check_for_wins();
                    while (true) {
                        ask_turn();
                        check_for_wins();
                        show_grid();
                        
                        computer_player_turn();
                        show_grid();
                        check_for_wins();
                    }
                } else {
                    // Computer goes first
                    bool f = false;
                    bool t = true;
                    choose_x_or_o(t, f);
                    show_grid();
                    check_for_wins();
                    while (true) {
                        computer_player_turn(); //ask_turn();
                        check_for_wins();
                        show_grid();
                        
                        ask_turn(); //computer_player_turn();
                        show_grid();
                        check_for_wins();
                    }
                }
                
            }
            
        }


};

int main( int argc, char*argv[]) {
    
    Game game;

    return 0;

}