#include "TicTacToe.h"
#include "App.cpp"
#include <iostream>

using namespace std;

    class TicTacToe
    {
        public:
            TicTacToe() : numOfBoardPos(9) {}

            //void setAttributes(sf::RectangleShape& shape, const sf::Vector2f pos, const sf::Vector2f size, const sf::Color color)
            void createBoard(const BoardPos[] arr)
            {
                // sets board with specific attributes 
                for(int i = 0; i < 9; ++i)
                {
                    // 0 1 2
                    if(i <= 2)
                    {
                        if(i == 2)
                        {
                            arr.pos = sf::Vector2f(x3,y1);
                        } 
                        else if(i == 1)
                        {
                            arr.pos = sf::Vector2f(x2,y1);
                        }
                        else
                        {
                            arr.pos = sf::Vector2f(x1,y1);
                        }
                    }// 3 4 5
                    else if(i <= 5)
                    {
                        if(i == 5)
                        {
                            arr.pos = sf::Vector2f(x3,y2);
                        } 
                        else if(i == 4)
                        {
                            arr.pos = sf::Vector2f(x2,y2);
                        }
                        else
                        {
                            arr.pos = sf::Vector2f(x1,y2);
                        }
                    } // 6 7 8
                    else
                    {
                        if(i == 8)
                        {
                            arr.pos = sf::Vector2f(x3,y3);
                        } 
                        else if(i == 7)
                        {
                            arr.pos = sf::Vector2f(x2,y3);
                        }
                        else
                        {
                            arr.pos = sf::Vector2f(x1,y3);
                        }
                    }
                    setAttributes(arr.shapeOfObj, arr.pos, arr.sizeOfBoard, arr.boardColor);
                }
            }

    };

    class BoardPos extends TicTacToe
    {
        // pos(1-9) posFloat(250,250)
        public:
            BoardPos() : boardPos(0), pos(0,0), boardColor(sf::Color{25,25,25}) {}

            sf::Vector2f getPos() const
            {
                return pos;
            }

            sf::Color getColor() const
            {
                return boardColor;
            }

            sf::Vector2f getSize() const
            {
                return sizeOfBoard;
            }

            int getBoardPos() const 
            {
                return boardPos;
            }

            void setBoardPos(const int posOnBoard)
            {
                boardPos = posOnBoard;
            }

    };



int main()
{

    TicTacToe ticTacGame = new TicTacToe();
    BoardPos[] array = new BoardPos();

    ticTacGame.createBoard(array);

    return 0;
}
