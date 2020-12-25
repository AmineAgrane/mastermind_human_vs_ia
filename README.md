# What is Mastermind ?
<img src="https://github.com/AmineAgrane/mastermind_human_vs_ia/blob/main/logo.png" height="200" align="center"/>

MasterMind is a board game invented by Marco Meirovitz in the 1960s. It is a game of reflection and deduction for two players. Like chess, Master Mind uses logic and memory. The principle of the game is relatively simple. Player 1 creates a combination of N pieces with C colors. Player 2 must find the secret combination. For this he has T attempts. At each test, player 1 indicates the number of well-placed and badly-placed checkers. If player 2 finds the secret combination in less than T attempts he wins the round. Then both players switch roles. 

The goal is to find the secret combination. Each pawn of the combination is of a random color among all the possible colors. There can be several pieces of the same color. There is no time limit for reflection.

# Goal of this project
The goal of this project is to design an automatic resolution of the Mastermind game. An "artificial intelligence" will be created which will have to find the solution according to certain parameters defined by the rules of the game and the various tests. These different parameters will reduce the number of possible combinations for the final solution. 

# How does it works
The principle of this algorithm is based on the fact of defining the certain position of a pawn before trying to place the others. Indeed, with a number of squares equal to **N** and a number of color equal to **k** we have **k^N** solutions. If we determine with certainty the place of a pawn, by keeping the same constraints there are only **k^(N-1)** solutions left. This technique thus makes it possible to improve the heuristics in a considerable way in a very short time. We will see later in the test part that this method allows to solve a combination of 100 pawns with 100 different colors and repetitions allowed in less than 3 sec.
