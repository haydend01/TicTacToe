#include <SFML/Graphics.hpp>
#ifndef TICTACTOE
#define TICTACTOE

    class TicTacToe
    {
        public:
            TicTacToe() : numOfBoardPos(9), positions() {}

            void createBoard(const BoardPos[] arr);

        private:
            int numOfBoardPos;
            BoardPos[] positions;

    };

    class BoardPos extends TicTacToe
    {
        // pos(1-9) posFloat(250,250)
        public:
            // CONSTRUCTORS
            BoardPos() : pos(0), posFloat(0,0) {}

            // GET AND SETS
            sf::Vector2f getPos();
            sf::Color getColor() const;
            sf::Vector2f getSize() const;
            int getBoardPos() const;
            
            void setBoardPos(const int);
            void setPos(const sf::Vector2f&);
            void setColor(const sf::Color&);
            void setSizeOfBoard(const sf::Vector2f);

        private:
            int boardPos; // 1 - 9
            sf::Vector2f pos; // pos(250px,250px)
            sf::Color boardColor; // color of board
            sf::Vector2f sizeOfBoard;// size(250px,250px)

            // X Y for BOARD POS
            // ROW 1
            int x1 = 388;
            int y1 = 185;

            // ROW 2
            int x2 = 574;
            int y2 = 363;

            // ROW 3
            int x3 = 760;
            int y3 = 541

    };


#endif