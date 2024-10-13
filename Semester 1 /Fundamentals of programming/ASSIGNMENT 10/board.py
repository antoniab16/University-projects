from texttable import Texttable
from unittest import TestCase

class Board:
    def __init__(self):
        self.__data = [0] * 42
        self.__move_count = 0


    def get_data(self):
        return self.__data

    def get_board(self, rows, columns):
        return self.__data[7 * rows + columns]

    def make_move(self, row, column, symbol):
        """
        Makes a move on the board
        :param row: row of the board
        :param column: column of the board
        :param symbol: 'X' or 'O' for the 2 players
        :return: None
        """
        if symbol.upper() not in ['X', 'O']:
            raise ValueError("Invalid symbol")
        if row not in (0, 1, 2, 3, 4, 5) or column not in (0, 1, 2, 3, 4, 5, 6):
            raise ValueError("symbol is outside the board")
        if self.get_board(row, column) != 0:
            raise ValueError("The chosen place is already occupied")
        if symbol.upper() == 'X':
            value = 1
        elif symbol.upper() == 'O':
            value = -1
        self.__data[7 * row + column] = value
        self.__move_count += 1

    def undo_move(self, row, column):
        if 0 <= row < 6 and 0 <= column < 7:
            self.__data[7 * row + column] = 0
        else:
            raise ValueError("Invalid row or column")

    def check_for_win(self):
        """
        Checks if the game was won
        :return: True if won, False otherwise
        """
        for row in range(6):
            for column in range(4):
                if abs((self.get_board(row, column)) + self.get_board(row, column + 1) + self.get_board(row, column + 2) + self.get_board(row, column + 3)) == 4:
                    return True

        for column in range(7):
            for row in range(3):
                if abs(self.get_board(row, column) + self.get_board(row + 1, column) + self.get_board(row + 2, column) + self.get_board(row + 3, column)) == 4:
                    return True

        for row in range(3):
            for column in range(4):
                if abs(self.get_board(row, column) + self.get_board(row + 1, column + 1) + self.get_board(row + 2, column + 2) + self.get_board(row + 3, column + 3)) == 4:
                    return True

        for row in range(3, 6):
            for column in range(4):
                if abs(self.get_board(row, column) + self.get_board(row - 1, column + 1) + self.get_board(row - 2, column + 2) + self.get_board(row - 3, column + 3)) == 4:
                    return True

    def is_full(self):
        """
        Checks if the board is full by checking the move count
        :return: True if the board is full, False otherwise
        """
        return self.__move_count == 42

    def __display_board(self):
        """
        Displays the board
        :return: board
        """
        board_result = []
        for element in self.__data:
            if element == 0:
                board_result.append(' ')
            elif element == 1:
                board_result.append('X')
            elif element == -1:
                board_result.append('O')
        return board_result

    def __str__(self):
        data = self.__display_board()
        table = Texttable()
        for index in (0, 7, 14, 21, 28, 35):
            table.add_row(data[index:index + 7])
        return table.draw()

class TestBoard(TestCase):
    def setUp(self):
        self.board = Board()

    def test_initialization(self):
        self.assertEqual(self.board.get_data(), [0] * 42)

    def test_make_move(self):
        self.board.make_move(0, 0, 'O')
        self.board.make_move(1, 1, 'X')
        self.assertEqual(self.board.get_board(0, 0), -1)
        self.assertEqual(self.board.get_board(1, 1), 1)
        with self.assertRaises(ValueError):
            self.board.make_move(0, 0, 'X')
        with self.assertRaises(ValueError):
            self.board.make_move(1, 2, 'Z')
        with self.assertRaises(ValueError):
            self.board.make_move(7, 0, 'X')
        with self.assertRaises(ValueError):
            self.board.make_move(10, 11, 'O')

    def test_undo_move(self):
        self.board.make_move(0, 0, 'X')
        self.board.undo_move(0 ,0)
        self.assertEqual(self.board.get_board(0, 0), 0)
        with self.assertRaises(ValueError):
            self.board.undo_move(11, 0)

    def test_check_for_win(self):
        self.board.make_move(0, 0, 'X')
        self.board.make_move(0, 1, 'X')
        self.board.make_move(0, 2, 'X')
        self.board.make_move(0, 3, 'X')
        self.assertTrue(self.board.check_for_win())

    def test_is_full(self):
        for row in range(6):
            for column in range(7):
                if (row + column) % 2 == 0:
                    self.board.make_move(row, column, 'O')
                else:
                    self.board.make_move(row, column, 'X')
        self.assertTrue(self.board.is_full())



