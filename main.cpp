#include <iostream>
#include <unordered_map>
#include <string>

const std::string GREETING_MESSAGE = "Seja bem vindo/a ao jogo de adivinhacao! Escolha sua dificuldade e veja se sera capaz de ler a mente do robo...";
const std::string DIFFICULTY_ASK_MESSAGE = "Selecione a dificuldade desejada. Cada nivel corresponde ao numero de chances que voce tem para adivinhar o numero.\nAs dificuldades sao:\n1. Facil - 10 chances\n2. Medio - 5 chances\n3. Dificil - 3 chances.\n4. Insano - 1 chance";

enum DifficultyEnum {
    FACIL,
    MEDIO,
    DIFICIL,
    INSANO
};

const std::unordered_map<DifficultyEnum, int> chancesByDifficulty = {{FACIL, 10}, {MEDIO, 5}, {DIFICIL, 3}, {INSANO, 1}};


void showGreetingsMessage() {
    std::cout << GREETING_MESSAGE << std::endl;
    return;
}

DifficultyEnum showDifficultyAskMessage() {
    int inputNumber;

    std::cout << DIFFICULTY_ASK_MESSAGE << std::endl;
    std::cin >> inputNumber;

    return (DifficultyEnum) inputNumber;
}

int readUserGuess() {
    // TODO implementar
}

void runGame(DifficultyEnum difficulty) {
    auto it = chancesByDifficulty.find(difficulty);

    int chances = it->second;


    while(chances > 0) {
        int guess = readUserGuess();
    }



}


int main(int argc, char* argv[]) {

    showGreetingsMessage();
    DifficultyEnum difficulty = showDifficultyAskMessage();
    runGame(difficulty);


    exit(0);
}