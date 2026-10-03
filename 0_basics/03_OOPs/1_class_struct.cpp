#include <iostream>
using namespace std;

// # define struct class        //treat struct like classes

class Player{

    int payout;     // this will be hidden hence can't access in main function

    public:
        string name;
        int x,y;
        int speed;

        void Move(int xa, int ya){
            x += xa * speed;
            y += ya * speed;

        }
};

// the only difference between struct and class is that class is private initially and struct is public
// so in struct you need to add private: to make something private 

// why struct then?
// c doesn't have classes but have structure so c++ will lose all the compatability 


struct Game{
    string name;
    int number_of_players;
};


int main(){
    Player player1;
    player1.name = "abc";
    player1.x = 3;
    player1.y = 4;
    player1.speed = 10;

    player1.Move(1, -1); 



    Game game1;
    game1.name = "mario";
    game1.number_of_players = 1;
}
