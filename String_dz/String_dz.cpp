#include <iostream>
#include <fstream>
#include <string>

void task_1() {
    std::string firstName, lastName, patronymic;
    int option;

    std::cout << "Виберіть варіант перетворення (1 або 2): ";
    std::cin >> option;

    std::ifstream inputFile("f.txt");
    std::ofstream outputFile("g.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Помилка відкриття файлу.\n";
  
    }

    while (inputFile >> lastName >> firstName >> patronymic) {
        if (option == 1) {
            outputFile << firstName << " " << patronymic << " " << lastName << "\n";
        }
        else if (option == 2) {
            outputFile << lastName << " " << firstName[0] << "." << patronymic[0] << ".\n";
        }
    }

    inputFile.close();
    outputFile.close();
}

void task_2() {
    std::string line, wordToReplace, replacementWord;
    std::ifstream file1("f1.txt"), file2("f2.txt");
    std::ofstream outputFile("g2.txt");

    if (!file1 || !file2 || !outputFile) {
        std::cerr << "Помилка відкриття файлу.\n";
    }

    file2 >> wordToReplace >> replacementWord;

    while (getline(file1, line)) {
        size_t pos = 0;
        while ((pos = line.find(wordToReplace, pos)) != std::string::npos) {
            line.replace(pos, wordToReplace.length(), replacementWord);
            pos += replacementWord.length();
        }
        outputFile << line << '\n';
    }

    file1.close();
    file2.close();
    outputFile.close();
}

int main() {
    
    task_1();
    task_2();
    return 0;
}
