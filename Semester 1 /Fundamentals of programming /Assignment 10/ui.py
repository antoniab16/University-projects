"""
Implementation of a game on a board. This is a combination of tik tak toe with connect four.
"""

from game import Game
from computer_player import ComputerPlayer
from board import Board


class UserInterface:
    def run(self):
        computer_player = ComputerPlayer('O')
        game = Game(computer_player)
        human_move = True
        print("Welcome to the game!")
        print(end = '\n')
        print("Rules: ")
        print("     Your symbol : X")
        print("     Computer's symbol : O")
        print("     To win form a horizontal, vertical, or diagonal line of four ")
        print("     Enter the row and column for your move. Rows are between 0 - 5. Columns between 0 - 6.")
        print(end='\n')
        while True:
            print("The board: ")
            game_board = game.get_board()
            print(str(game_board))
            print(end = '\n')
            if human_move:
                try:
                    row = int(input("Enter row for your move: "))
                    column = int(input("Enter column for your move: "))
                    game.human_move(row, column)
                except ValueError as ve:
                    print(ve)
                    continue
            else:
                game.computer_move()
            if game_board.check_for_win():
                if human_move:
                    print("You won!")
                else:
                    print("You lost :(")
                print(game_board)
                break
            elif game_board.is_full():
                print("Game is a draw")
                break
            human_move = not human_move

ui = UserInterface()
ui.run()

