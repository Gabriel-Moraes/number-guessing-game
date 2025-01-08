#include <iostream>
#include <unordered_map>
#include <string>
#include <time.h>

const std::string GREETING_MESSAGE = "Seja bem vindo/a ao jogo de adivinhacao! Escolha sua dificuldade e veja se sera capaz de ler a mente da maquina...";
const std::string DIFFICULTY_ASK_MESSAGE = "\nPrimeiro, selecione a dificuldade desejada. Cada nivel corresponde ao numero de chances que voce tem para adivinhar o numero.\nAs dificuldades sao:\n1. Facil - 10 chances\n2. Medio - 5 chances\n3. Dificil - 3 chances.\n4. Insano - 1 chance";
const std::string WINNING_MESSAGE = "Voce venceu o jogo! Parabens!";
const std::string LOSING_MESSAGE = "\nInfelizmente suas chances acabaram :(\nO numero sorteado pelo maquina era: ";


enum DifficultyEnum {
    FACIL = 1,
    MEDIO,
    DIFICIL,
    INSANO
};

std::string toString(DifficultyEnum difficulty) {
    switch (difficulty) {
        case FACIL:
            return(std::string("Facil"));
        case MEDIO:
            return(std::string("Medio"));
        case DIFICIL:
            return(std::string("Dificil"));
        case INSANO:
            return(std::string("Insano"));            
    }
}

const std::unordered_map<DifficultyEnum, int> chancesByDifficulty = {{FACIL, 10}, {MEDIO, 5}, {DIFICIL, 3}, {INSANO, 1}};


void showGreetingsMessage() {
    std::cout << GREETING_MESSAGE << std::endl;
    return;
}

DifficultyEnum showDifficultyAskMessage() {
    std::cout << DIFFICULTY_ASK_MESSAGE << std::endl;
    
    int inputDifficulty;
    do {
        std::cin >> inputDifficulty;

        if (std::cin.fail()) {
            std::cout << "Falha na leitura do valor. Verifique se o texto digitado corresponde a um numero inteiro." << std::endl;
            continue;
        }

        if (inputDifficulty < 0 || inputDifficulty > 5) {
            std::cout << "Valor invalido! Digite um numero correspondente a dificuldade desejada." << std::endl;
            continue;
        }
    } while (inputDifficulty < 0 || inputDifficulty > 5);

    return (DifficultyEnum) inputDifficulty;
}

int readUserGuess() {
    int inputGuess;
    std::cin >> inputGuess;

    return inputGuess;
}

int generateRandomNumber() {
    srand(time(NULL));
    return 1 + (std::rand() % 100);
}

void runGame(DifficultyEnum difficulty) {
    const int generatedNumber = generateRandomNumber();

    auto it = chancesByDifficulty.find(difficulty);
    std::cout << "A dificuldade do jogo eh: " << toString(difficulty) << std::endl;
    int chances = it->second;

    while(chances > 0) {
        std::cout << "Palpite: ";
        int guess = readUserGuess();

        if (guess == generatedNumber) {
            std::cout << WINNING_MESSAGE << std::endl;
            return;
        }

        std::string keyword = guess < generatedNumber ? "maior" : "menor";
        std::cout << "O numero sorteado eh " << keyword << " que " << guess << std::endl;
        chances--;        
    }


    std::cout << LOSING_MESSAGE << generatedNumber << std::endl;
}


int main(int argc, char* argv[]) {
    showGreetingsMessage();
    DifficultyEnum difficulty = showDifficultyAskMessage();
    runGame(difficulty);


    exit(0);
}