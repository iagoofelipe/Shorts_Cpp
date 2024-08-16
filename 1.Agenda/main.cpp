/* 

 Agenda de Eventos

 Componentes:
    - <class> Menu

*/

// menu
// 

#include <iostream>
#include <limits>
// #include <ctime>
#include <time.h>

#define PRINT_SEP() { std::cout << "\n--------------------------\n"; }
#define GET_LINE(X) { while(std::getline(std::cin, X)) if(X != "") break; }

// dados de um evento
struct Event
{
    std::string title;
    time_t date;
    std::string description;
};

// Classe principal para o menu, utilizado para receber e tratar as informações enviadas pelo usuário
class Menu
{

private:
    void displayOptions()
    {
        int op;
        int num_opts = 2;
        int ops[num_opts] = {1, 2};
        bool keepRunning = true;

        while(keepRunning)
        {
            PRINT_SEP();
            std::cout
                << "Bem-Vindo a sua Agenda!\n" << std::endl
                << "1. Novo evento" << std::endl
                << "2. Eventos disponiveis" << std::endl
                << "0. Sair\n" << std::endl
            ;

            getUserInput<int>(op, "Opcao escolhida", "Apenas numeros sao aceitos!");
            PRINT_SEP();
            
            switch (op)
            {
            case 1:
                newEvent();
                break;
            
            case 2:
                break;
            
            case 0:
                keepRunning = false;
                break;

            default:
                std::cout << "Escolha uma opcao dentre as disponiveis!\n";
                break;
            }
        }
    }

    template <typename T> void getUserInput(T &in, std::string msg_inp, std::string msg_error)
    {
        while(true)
        {
            std::cout << msg_inp + ": ";
            std::cin >> in;

            if (std::cin)
                break;

            // caso TypeError
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cout << msg_error + "\n\n";
        }
    }

public:
    void run()
    {
        displayOptions();
    }

    void newEvent()
    {
        std::string title;

        std::cout << "Titulo: ";
        GET_LINE(title);

        std::cout << title << std::endl;
    }
};

int main()
{
    // Menu m;
    // m.run();

    std::string date;
    std::cout << "Data do evento (HH:MM dd/mm/YYYY): ";
    GET_LINE(date);

    char buffer[100];
    struct tm result;

    strptime(buffer, "%H:%M %d/%m/%Y", &result);

    std::cout << "Hour: " << result.tm_hour;
    // strftime(buf,sizeof(buf), "%a %m/%d/%Y %r", timeptr);
}