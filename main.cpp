#include <iostream>

void displayBoard(char board[3][3]) {
  for(int i = 0; i < 3; i++ ) {
    for(int j = 0; j < 3; j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
  };

  int player = 1;
  int choice;
  char mark;

  for (int i = 0; i < 9; i++) {
    displayBoard(board);
    player = (player % 2) ? 1 : 2;
    mark = (player == 1) ? 'X' : 'O';
    std::cout << "Player " << player << ", enter a number: ";
    std::cin >> choice;

    if (choice == 1 && board[0][0] == '1')
      board[0][0] = mark;
    else if (choice == 2 && board[0][1] == '2')
      board[0][1] = mark;
    else if (choice == 3 && board[0][2] == '3')
      board[0][2] = mark;
    else if (choice == 4 && board[1][0] == '4')
      board[1][0] = mark;
    else if (choice == 5 && board[1][1] == '5')
      board[1][1] = mark;
    else if (choice == 6 && board[1][2] == '6')
      board[1][2] = mark;
    else if (choice == 7 && board[2][0] == '7')
      board[2][0] = mark;
    else if (choice == 8 && board[2][1] == '8')
      board[2][1] = mark;
    else if (choice == 9 && board[2][2] == '9')
      board[2][2] = mark;
    else {
      std::cout << "Invalid move ";
      player--;
      std::cin.ignore();
      std::cin.get();
    }

    if(( board[0][0] ==mark && board[0][1] == mark && board[0][2] == mark) ||
        ( board[1][0] ==mark && board[1][1] == mark && board[1][2] == mark) ||
        ( board[2][0] ==mark && board[2][1] == mark && board[2][2] == mark) ||
        ( board[0][0] ==mark && board[1][0] == mark && board[2][0] == mark) ||
        ( board[0][1] ==mark && board[1][1] == mark && board[2][1] == mark) ||
        ( board[0][2] ==mark && board[1][2] == mark && board[2][2] == mark) ||
        ( board[0][0] ==mark && board[1][1] == mark && board[2][2] == mark) ||
        ( board[0][2] ==mark && board[1][1] == mark && board[2][0] == mark)) {
      displayBoard(board);
      std::cout << "Player " << player << " wins!" << std::endl;
      break;
    }
    else if (i == 8) {
      displayBoard(board);
      std::cout << "Draw!" << std::endl;
    }

    player++;

  }

  return 0;
}

