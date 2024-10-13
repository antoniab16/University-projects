from board import Board

class Game:
    def __init__(self, computer_player):
        self.__board = Board()
        self.__computer_player = computer_player

    def get_board(self):
        return self.__board

    def human_move(self, row, column):
        return self.__board.make_move(row, column, 'X')

    def computer_move(self):
        row, column = self.__computer_player.choose_move(self.__board)
        return self.__board.make_move(row, column, 'O')

