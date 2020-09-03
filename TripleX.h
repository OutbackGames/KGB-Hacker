#include <iostream>
#include <ctime>
namespace OutbackGames{
    namespace CPP{
        namespace TripleX{
            //Triple X Class
            class TripleX{

                private:
                    const signed int MAX_DIFFICULTY = 10;
                    const signed int MIN_DIFFICULTY = 1;
                    bool wantsToExit = false;
                    int codeA = 4;
                    int codeB = 10;
                    int codeC = 3;
                    int codeSum;
                    int codeProduct;
                    int guessA, guessB, guessC;
                    int guessSum;
                    int guessProduct;
                    int levelDifficulty = 1;
                    void ProductCalc(){
                        codeProduct = codeA * codeB * codeC;
                        std::cout << "+ The numbers multiply to get: " << codeProduct << "\n";
                    }
                    void SumCalc(){
                        codeSum = codeA + codeB + codeC;
                        std::cout << "+ The numbers add up to: " << codeSum << "\n";
                    }
                    void GuessProduct(){
                        guessProduct = guessA * guessB * guessC;
                    }
                    void GuessSum(){
                        guessSum = guessA + guessB + guessC;
                    }

                public:
                    void PrintIntro(){
                        std::cout << "Morior Invictus: Veni, the Level " << levelDifficulty << " KGB server room console is now available to you.\n";
                        std::cout << "Morior Invictus: There seems to be a 3 number code required...\n";
                        if(levelDifficulty == 1){
                            std::cout << "Morior Invictus: The control of the console is now yours, I can only guide you from here on out.\n";
                        }
                        std::cout << "*** Clues:\n";
                        ProductCalc();
                        SumCalc();
                        std::cout << "\nEnter The Correct Code To Continue ...\n";
                    }
                //Constructor
                TripleX(){
                    
                }

                //Destructor
                ~TripleX(){
                    
                }

                void PlayGameAtDifficulty(int difficulty){
                    //clamp the difficulty to ensure that it is not out of scope.
                    int modifier = difficulty + (1+2)^3;
                    CodeGenerator(modifier);
                }

                void CodeGenerator(int modifier){
                    //Do Random Difficulty Modification
                    codeA = rand() % levelDifficulty + modifier;
                    codeB = rand() % levelDifficulty + modifier;
                    codeC = rand() % levelDifficulty + modifier;
                }

                bool IsCorrect(){
                    if(guessSum == codeSum && guessProduct == codeProduct){
                        std::cout << "*** Veni! That code is correct great job! ***\n\n";
                        return true;
                    }else{
                        std::cout << "*** Oh NO Veni! That code was wrong! Try Again! ***\n\n";
                        return false;
                    }
                }

                void LogicLoop(){
                    std::cin >> guessA;
                    std::cin >> guessB;
                    std::cin >> guessC;
                    GuessProduct();
                    GuessSum();
                    if(IsCorrect() == true){
                        //increase Difficulty
                        levelDifficulty++;
                        PlayGameAtDifficulty(levelDifficulty);
                        if(levelDifficulty < MAX_DIFFICULTY){
                            PrintIntro();
                        }
                    }
                }

                void WaitForEnd(){
                    std::cout << "\nPress Enter Key To Exit\n";
                    while(!wantsToExit){
                        while (std::cin){
                            if(std::cin.get() == '\n'){
                                wantsToExit = true;
                                return;
                            }
                        }
                        break;
                    }
                }

                void GameLoop(){
                    while(levelDifficulty <= MAX_DIFFICULTY && !wantsToExit){
                        LogicLoop();
                        std::cin.clear();
                        std::cin.ignore();
                    }
                    if(levelDifficulty >= MAX_DIFFICULTY){
                        std::cout << "\n*** Morior Invictus: Great job Veni! The Boss wants that info, you'd better get out of there real quick! ***\n";
                        WaitForEnd();
                    }else{
                       std::cout << "\n *** Morior Invictus: Whaa! Veni Where are you going!? There's work to be done! ***\n";
                       WaitForEnd();
                    }
                }

            };

        }
    }
}
//veni vidi vici
