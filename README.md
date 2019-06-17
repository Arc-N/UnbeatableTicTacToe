# TicTacToe-Min-Max-AI

Welcome to the unbeatable tic tac toe.

This program uses an algorithm called minimax. --> https://en.wikipedia.org/wiki/Minimax

You can find more on how minimax is applied to tic tac toe --> here https://neverstopbuilding-dropblog.herokuapp.com/minimax

The computer essentially calls itself recursively and "plays" every possible move given the board arrangment.
Each move is assigned a score based on the outcome and stored in a vector. 
After the recursion terminates the vector of moves is run through a loop to determine the best score and the index of that move is returned as the "goldenMove".
This is done for every possible empty spot on the board to ensure the best overall move.
