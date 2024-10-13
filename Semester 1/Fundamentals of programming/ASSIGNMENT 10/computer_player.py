from board import Board
import random
class ComputerPlayer():
    def __init__(self, symbol):
        self.__symbol = symbol

    def get_valid_moves(self, board: Board):
        """
        Gets all the valid moves
        :param board: game board
        :return: list of valid moves
        """
        valid_moves = []
        for row in range(6):
            for column in range(7):
                if board.get_board(row, column) == 0:
                    valid_moves.append((row, column))
        return valid_moves

    def check_for_winning_move(self, board, symbol):
        """
        Checks if the move can win the game or not
        :param board: game board
        :param symbol: the symbol of the player/computer
        :return: row, column if the move wins the game, None otherwise
        """
        for row in range(6):
            for column in range(7):
                if board.get_board(row, column) == 0:
                    board.make_move(row, column, symbol)
                    if board.check_for_win():
                        board.undo_move(row, column)
                        return row, column
                    board.undo_move(row, column)
        return None

    def choose_move(self, board):
        """
        Chooses the move the computer makes
        :param board: game board
        :return: the move the computer chooses, None if there aren't any moves left
        """
        if self.__symbol == 'X':
            human_symbol = 'O'
        else:
            human_symbol = 'X'
        winning_move = self.check_for_winning_move(board, self.__symbol)
        if winning_move:
            return winning_move
        blocking_move = self.check_for_winning_move(board, human_symbol)
        if blocking_move:
            return blocking_move
        valid_moves = self.get_valid_moves(board)
        if valid_moves:
            return random.choice(valid_moves)
        else:
            None