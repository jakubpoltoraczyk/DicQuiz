#include "i_Dic.h"

i_Dic::i_Dic(const std::string & file_name): Dictionary(file_name)
{

}

void i_Dic::add_word()
{
    std::string temp_var_1st, temp_var_2nd;
    std::cout << "Podaj angielska wersje slowka: ";
    std::getline(std::cin, temp_var_1st);
    std::cout << "Podaj polska wersje slowka: ";
    std::getline(std::cin, temp_var_2nd);
    Dictionary::add_word(temp_var_1st,temp_var_2nd);
}

void i_Dic::delete_by_word()
{
    int temp_var;
    std::cout << "Podaj numer slowka do usuniecia: ";
    std::cin >> temp_var;
    Dictionary::delete_word(temp_var);
}

void i_Dic::show_by_letters()const
{
    char let_1st, let_2nd;
    std::cout << "Podaj litere poczatkowa: ";
    std::cin >> let_1st;
    std::cout << "Podaj litere koncowa: ";
    std::cin >> let_2nd;
    Dictionary::show_letters(let_1st,let_2nd);
}

void i_Dic::show_dictionary_option()const
{
    std::cout << std::endl << "LISTA MOZLIWYCH OPCJI SLOWNIKA" << std::endl << std::endl;
    std::cout << "1 - wyjscie" << std::endl; 
    std::cout << "2 - wyswietlenie mozliwych opcji slownika" << std::endl;
    std::cout << "3 - dodanie nowego slowka" << std::endl;
    std::cout << "4 - usuniecie slowka" << std::endl;
    std::cout << "5 - pokazanie zawartosci slownika" << std::endl;
    std::cout << "6 - pokazanie zawartosci slownika od litery 'x' do litery 'y'" << std::endl;
    std::cout << "7 - zapisanie postepu" << std::endl << std::endl;
}

void i_Dic::do_all()
{
    int option_number;
    do
    {
        show_dictionary_option();
        std::cout << std::endl << "Podaj swoj wybor: ";
        std::cin >> option_number;
        std::cin.get();
        std::cout << std::endl;
        switch(option_number)
        {
            case 1: 
                std::cout << "Wyjscie z programu" << std::endl; break;
            case 2:
                show_dictionary_option(); break;
            case 3:
                add_word(); break;
            case 4:
                delete_word(); break;
            case 5:
                show_all(); break;
            case 6: 
                show_letters(); break;
            case 7:
                save_changes(); break;
            default:
                std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(option_number!=1);
}