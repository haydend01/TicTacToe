
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <set>
#include <iostream>
#include <string>

using namespace std;


void plot_o(const sf::Vector2f pos, sf::CircleShape& circle)
{
    circle.setPosition(pos);
}

void setAttributes(sf::RectangleShape& shape, const sf::Vector2f pos, const sf::Vector2f size, const sf::Color color)
{
    shape.setPosition(pos);
    shape.setFillColor(color);
    shape.setSize(size);
}

sf::Color setNextTurn(sf::Color turn)
{
    return (turn == sf::Color::Red) ? sf::Color::Blue : sf::Color::Red;
}

int main()
{
    bool gameOver = false;
    
    sf::Color currentColor = sf::Color::Red;

    sf::Color redUser = sf::Color::Red;
    sf::Color blueUser = sf::Color::Blue;

    // BUILD WINDOW
    sf::RenderWindow window(sf::VideoMode(1280,720), "Box Screen");
    window.setFramerateLimit(60);

    // IMPORTING FONT
    sf::Font open_sans;
    open_sans.loadFromFile("E:\\CODE\\c++\\SFML\\App\\fonts\\open-sans-condensed.light.ttf");

    // IMPORTING FONT
    sf::Font comic;
    comic.loadFromFile("E:\\CODE\\c++\\SFML\\App\\fonts\\Action Comics.ttf");

    // IMPORTING FONT
    sf::Font ka_blam;
    ka_blam.loadFromFile("E:\\CODE\\c++\\SFML\\App\\fonts\\Ka Blam.ttf");

    // importing crown sprite
    sf::Texture crown_helm_texture;
    crown_helm_texture.loadFromFile("E:\\CODE\\c++\\SFML\\App\\img\\helm.png");
    crown_helm_texture.setSmooth(true);

    // SOUNDS 
    // SETTING UP BOARD CLICK
    // IMPORTATION OF SOUND FILEs
    sf::SoundBuffer buffer;
    buffer.loadFromFile("E:\\CODE\\c++\\SFML\\App\\audio\\board\\current\\mixkit-plastic-bubble-click-1124.wav");

    sf::Sound board_click;
    board_click.setBuffer(buffer);
    board_click.setVolume(25);

    // QUIT AND RESET MENU SOUNDs
    sf::SoundBuffer menuBuffer;
    menuBuffer.loadFromFile("E:\\CODE\\c++\\SFML\\App\\audio\\menu\\mixkit-modern-click-box-check-1120.wav");

    sf::Sound menuButtons;
    menuButtons.setBuffer(menuBuffer);
    menuButtons.setVolume(20);

    // WIN CHEER
    sf::SoundBuffer winBuffer;
    winBuffer.loadFromFile("E:\\CODE\\c++\\SFML\\App\\audio\\win\\current\\mixkit-quick-win-video-game-notification-269.wav");

    sf::Sound winCheer;
    winCheer.setBuffer(winBuffer);
    winCheer.setVolume(25);

    // CUBE HITTING WALL
    sf::SoundBuffer wallHitBuffer;
    wallHitBuffer.loadFromFile("E:\\CODE\\c++\\SFML\\App\\audio\\cube\\wall hit\\mixkit-on-or-off-light-switch-tap-2585.wav");

    sf::Sound wallHit;
    wallHit.setBuffer(wallHitBuffer);
    wallHit.setVolume(1);


    // WIN SOUND
    /*
    sf::Sound win_cheer;
    win_cheer.setBuffer(buffer);
    win_cheer.setVolume(10);
    */
    /*
    // BUILD O
    sf::CircleShape circle;
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setFillColor(sf::Color::Black);
    circle.setRadius(25);

    // CENTER LINE
    // SETTING BAR BELOW TITLE
    sf::RectangleShape line1;
    sf::Vector2f linePos1(640, 0);
    line1.setPosition(linePos1);
    line1.setFillColor(sf::Color::Green);
    line1.setSize(sf::Vector2f(15, 720)); // 300 FOR TITLE

    // MISSED MSG
    sf::Text missed;
    missed.setString("you missed!");
    missed.setPosition(sf::Vector2f(-100, 0));
    missed.setFont(open_sans);
    missed.setCharacterSize(25);
    missed.setFillColor(sf::Color::White);
    */

    // SET TITLE
    sf::Text myTxt;
    myTxt.setString("TIC TAC TOE");
    myTxt.setPosition(sf::Vector2f(365, -10));
    myTxt.setFont(ka_blam);
    myTxt.setCharacterSize(115); // 125
    myTxt.setFillColor(sf::Color::Black);
    myTxt.setOutlineThickness(8);
    myTxt.setOutlineColor(sf::Color::White);

    // SETTING BAR BELOW TITLE
    sf::RectangleShape line;
    line.setPosition(sf::Vector2f(0, 135));
    line.setFillColor(sf::Color::White);
    line.setSize(sf::Vector2f(1280, 15)); // 300 FOR TITLE

    sf::RectangleShape outline;
    setAttributes(outline, sf::Vector2f(378, 175), sf::Vector2f(538, 512), sf::Color::Black);
    outline.setOutlineColor(sf::Color::White);
    outline.setOutlineThickness(8);

    // CREATION OF BOARD
    // VERTICAL LINES
    // void setAttributes(sf::RectangleShape& shape, const sf::Vector2f pos, const sf::Vector2f size, const sf::Color color)

    // left vertical line
    sf::RectangleShape leftV;
    setAttributes(leftV, sf::Vector2f(545, 175), sf::Vector2f(15, 512), sf::Color::White);

    // right vertical line
    sf::RectangleShape rightV;
    setAttributes(rightV, sf::Vector2f(732, 175), sf::Vector2f(15, 512), sf::Color::White);

    // Hoizontal Lines
    // TOP LINE
    sf::RectangleShape top;
    setAttributes(top, sf::Vector2f(378, 332), sf::Vector2f(538, 15), sf::Color::White);

    // BOTTOM LINE
    sf::RectangleShape bottom;
    setAttributes(bottom, sf::Vector2f(378, 512), sf::Vector2f(538, 15), sf::Color::White);

    // LIGHT INNER BOX(s)
    // TOP ROW
    sf::RectangleShape pos1;
    setAttributes(pos1, sf::Vector2f(388, 185), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    sf::RectangleShape pos2;
    setAttributes(pos2, sf::Vector2f(574, 185), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    sf::RectangleShape pos3;
    setAttributes(pos3, sf::Vector2f(760, 185), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    // MIDDLE ROW
    sf::RectangleShape pos4;
    setAttributes(pos4, sf::Vector2f(388, 363), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    sf::RectangleShape pos5;
    setAttributes(pos5, sf::Vector2f(574, 363), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    sf::RectangleShape pos6;
    setAttributes(pos6, sf::Vector2f(760, 363), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    // BOTTOM ROW
    sf::RectangleShape pos7;
    setAttributes(pos7, sf::Vector2f(388, 541), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    sf::RectangleShape pos8;
    setAttributes(pos8, sf::Vector2f(574, 541), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    sf::RectangleShape pos9;
    setAttributes(pos9, sf::Vector2f(760, 541), sf::Vector2f(143, 133), sf::Color{ 25,25,25 });

    // RESET BUTTON
    sf::Text resetText;
    resetText.setString("RESET");
    resetText.setPosition(sf::Vector2f(1000, 600));
    resetText.setFont(ka_blam);
    resetText.setCharacterSize(75);
    resetText.setFillColor(sf::Color::Black);
    resetText.setOutlineThickness(6);
    resetText.setOutlineColor(sf::Color::White);

    // QUIT BUTTON
    sf::Text quit;
    quit.setString("QUIT");
    quit.setPosition(sf::Vector2f(100, 590));
    quit.setFont(ka_blam);
    quit.setCharacterSize(85);
    quit.setFillColor(sf::Color::Black);
    quit.setOutlineThickness(6);
    quit.setOutlineColor(sf::Color::White);

    // BUILD CUBE
    sf::Vector2f rectPos(600, 350);
    sf::RectangleShape rect;
    setAttributes(rect, rectPos, sf::Vector2f(100, 100), currentColor);

    // CROWN
    sf::Sprite crown;
    crown.setTexture(crown_helm_texture);
    crown.setScale(sf::Vector2f(0, 0)); // .3f .3f
    crown.setOrigin(135,375);
    //crown.move(sf::Vector2f(10.f,10.f));

    // SPEED OF CUBE
    float xVelocity = 8;
    float yVelocity = 8;

    sf::RectangleShape objs[9] = { pos1 ,pos2 ,pos3 ,pos4 ,pos5 ,pos6 ,pos7 ,pos8 ,pos9 };

    // CLOSE WINDOW PROCESS0
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            // CLOSE THE WINDOW
            // RED X TO QUIT
            if (e.type == sf::Event::Closed) window.close();
            // ESCAPE KEY TO QUIT 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            // CHECKS MOUSE CLICKS CUBE
            // pos of mouse relative in window
            auto mousePos = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(mousePos);

            // Checks if left mouse button has been pressed and if the click is within the bounds of the cube
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                if (resetText.getGlobalBounds().contains(translated_pos))
                {
                    pos1.setFillColor(sf::Color{ 25,25,25 });
                    pos2.setFillColor(sf::Color{ 25,25,25 });
                    pos3.setFillColor(sf::Color{ 25,25,25 });

                    pos4.setFillColor(sf::Color{ 25,25,25 });
                    pos5.setFillColor(sf::Color{ 25,25,25 });
                    pos6.setFillColor(sf::Color{ 25,25,25 });

                    pos7.setFillColor(sf::Color{ 25,25,25 });
                    pos8.setFillColor(sf::Color{ 25,25,25 });
                    pos9.setFillColor(sf::Color{ 25,25,25 });
                    crown.setScale(sf::Vector2f(0, 0));
                    currentColor = setNextTurn(currentColor);
                    gameOver = false;
                    menuButtons.play();
                }
                // CLOSES WINDOW IF QUIT IS PRESSED
                if (quit.getGlobalBounds().contains(translated_pos))
                {
                    window.close();
                }

                // CHECKS IF GAME HAS ALREADY BEEN WON
                // LOCKS THE BOARD FROM BEING USED
                if (gameOver == false)
                {
                    // CHECK EACH POS ON THE BOARD IF THE MOUSE HAS BEEN PRESSED WITHIN THE
                    // LOCATION OF THE POS BOX
                    if (pos1.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos1.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos1.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos1.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }

                    }
                    else if (pos2.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos2.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos2.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos2.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos3.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos3.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos3.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos3.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos4.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos4.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos4.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos4.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos5.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos5.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos5.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos5.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos6.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos6.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos6.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos6.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos7.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos7.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos7.setFillColor(currentColor);
                            // update current colors
                            currentColor = setNextTurn(pos7.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos8.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos8.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos8.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos8.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                    else if (pos9.getGlobalBounds().contains(translated_pos))
                    {
                        if (pos9.getFillColor() == sf::Color{ 25,25,25 })
                        {
                            pos9.setFillColor(currentColor);
                            // update current color
                            currentColor = setNextTurn(pos9.getFillColor());
                            rect.setFillColor(currentColor);
                            board_click.play();
                        }
                    }
                }
            }
            // CHECKS EVERY POSSIBLE WIN STATE
            // UPDATES GAME OVER VARIABLE
            // WINNING ROW IS SET TO YELLOW
            if (pos1.getFillColor() == pos2.getFillColor() && pos3.getFillColor() == pos2.getFillColor() && pos1.getFillColor() != sf::Color{25,25,25})
            {
                pos1.setFillColor(sf::Color::Green);
                pos2.setFillColor(sf::Color::Green);
                pos3.setFillColor(sf::Color::Green);
                gameOver = true;
   
            }
            else if (pos4.getFillColor() == pos5.getFillColor() && pos6.getFillColor() == pos5.getFillColor() && pos4.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos4.setFillColor(sf::Color::Green);
                pos5.setFillColor(sf::Color::Green);
                pos6.setFillColor(sf::Color::Green);
                gameOver = true;
         
            }
            else if (pos7.getFillColor() == pos8.getFillColor() && pos9.getFillColor() == pos8.getFillColor() && pos7.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos7.setFillColor(sf::Color::Green);
                pos8.setFillColor(sf::Color::Green);
                pos9.setFillColor(sf::Color::Green);
                gameOver = true;
           
            }
            else if (pos1.getFillColor() == pos5.getFillColor() && pos5.getFillColor() == pos9.getFillColor() && pos1.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos1.setFillColor(sf::Color::Green);
                pos5.setFillColor(sf::Color::Green);
                pos9.setFillColor(sf::Color::Green);
                gameOver = true;
         
            }
            else if (pos7.getFillColor() == pos5.getFillColor() && pos5.getFillColor() == pos3.getFillColor() && pos3.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos7.setFillColor(sf::Color::Green);
                pos5.setFillColor(sf::Color::Green);
                pos3.setFillColor(sf::Color::Green);
                gameOver = true;
            
            }
            else if (pos7.getFillColor() == pos4.getFillColor() && pos4.getFillColor() == pos1.getFillColor() && pos1.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos7.setFillColor(sf::Color::Green);
                pos4.setFillColor(sf::Color::Green);
                pos1.setFillColor(sf::Color::Green);
                gameOver = true;
         
            }
            else if (pos2.getFillColor() == pos5.getFillColor() && pos8.getFillColor() == pos2.getFillColor() && pos2.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos2.setFillColor(sf::Color::Green);
                pos5.setFillColor(sf::Color::Green);
                pos8.setFillColor(sf::Color::Green);
                gameOver = true;
           
            }
            else if (pos3.getFillColor() == pos6.getFillColor() && pos6.getFillColor() == pos9.getFillColor() && pos9.getFillColor() != sf::Color{ 25,25,25 })
            {
                pos3.setFillColor(sf::Color::Green);
                pos6.setFillColor(sf::Color::Green);
                pos9.setFillColor(sf::Color::Green);
                gameOver = true;
                
            }
        }
        if (gameOver)
        {
            crown.setScale(sf::Vector2f(.3f, .3f));
            rect.setFillColor(setNextTurn(currentColor));
 
        }
        // BOUNDS CHECK
        // -100 added for padding due to clipping for rect obj.
        // .y + 15 added for line width
        // 135 for y pos is line pos
        if (rectPos.x < 0 || rectPos.x > 1280 - 100)
        {
            xVelocity *= -1;
            wallHit.play();
        }
        if (rectPos.y < 135 + 15 || rectPos.y > 720 - 100)
        {
            yVelocity *= -1;
            wallHit.play();
        }

        // RENDER
        window.clear();

        rectPos.x += xVelocity;
        rectPos.y += yVelocity;
        rect.setPosition(rectPos);
        crown.setPosition(rectPos);

        // BUILD TITLE 
        window.draw(myTxt);
        window.draw(line);

        // BUILD CUBE
        window.draw(rect);
        window.draw(crown);

        window.draw(outline);

        // BUILD BOARD
        window.draw(leftV);
        window.draw(rightV);
        window.draw(top);
        window.draw(bottom);

        // BOARD BOX(s)
        window.draw(pos1);
        window.draw(pos2);
        window.draw(pos3);

        window.draw(pos4);
        window.draw(pos5);
        window.draw(pos6);

        window.draw(pos7);
        window.draw(pos8);
        window.draw(pos9);

        window.draw(resetText);
        window.draw(quit);

        // SETS OBJ(s) VISIBLE
        window.display();
    }

    return 0;
}
