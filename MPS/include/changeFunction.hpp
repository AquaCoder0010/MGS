#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
 

class changeFunction
:public Plot
{
    public:
        changeFunction()
        :func_var(0)
        {}
        void inputChange(sf::Keyboard::Key key)
        {
            if(key == sf::Keyboard::Left && func_var != 0){
                func_var -= 1;
            }
            if(key == sf::Keyboard::Right && func_var != 5){
                func_var += 1;
            }
        }
        short returnVar(){
            return func_var;
        }
    private:
        short func_var;
};