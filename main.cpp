#include "TripleX.h"

using namespace OutbackGames::CPP::TripleX;
TripleX game = TripleX();
TripleX* gamePtr = &game;

int main(){
    srand(time(NULL));
    gamePtr -> PrintIntro();
    gamePtr -> GameLoop();
    
    return 0;
}

//veni vidi vici
