#include <string>
#include <iostream>

#define GRID_SIZE 3

using namespace std;

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
                    puts("****** We have a winner!******");
                    printf("Looks like %c won, congratulations!\n", previous_grid);

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
                            grid[row][col] = 'X';
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
                            grid[row][col] = 'O';
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
                    grid[row][col] = 'O';
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

        Game() {
            generate_grid();

            if (ask_single_or_double_player()) {
                ///
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
                show_grid();
                check_for_wins();
                while (true) {
                    ask_turn();
                    check_for_wins();
                    
                    computer_player_turn();
                    show_grid();
                    check_for_wins();
                }
            }
            
        }


};

int main( int argc, char*argv[]) {
    
    Game game;

    return 0;

}