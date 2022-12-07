#include <SFML/Graphics.hpp>
#ifndef TICTACTOE
#define TICTACTOE

    class TicTacToe
    {
        public:
            TicTacToe() : numOfBoardPos(9) {}






        private:
            int numOfBoardPos;

    }

    class BoardPos extends TicTacToe
    {
        public:
            BoardPos() : pos(0), posFloat(0,0) {}

        private:
            int pos; // 1 - 9
            sf::Vector2f posFloat; // pos(250px,250px)



    };


#endif