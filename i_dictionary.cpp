#include "i_dictionary.h"

I_Dictionary::I_Dictionary(const std::string & file_name): Dictionary(file_name)
{

}

/* K1 - wykorzystanie metody klasy Dictionary z podaniem interaktywnie argumentow za posrednictwem prywatnych metod klasy I_Dictionary */

void I_Dictionary::add_word()
{
    Dictionary::add_word(ask4_pol_word(), ask4_for_word()); // K1
}

void I_Dictionary::delete_by_word()
{
    Dictionary::delete_by_word(ask4_for_word()); // K1
}

void I_Dictionary::delete_by_number()
{
    Dictionary::delete_by_number(ask4_number()); // K1
}

void I_Dictionary::change_word()
{
    Dictionary::change_word(ask4_pol_word(), ask4_for_word(), ask4_number()); // K1
}

void I_Dictionary::change_foreign_word()
{
    Dictionary::change_foreign_word(ask4_for_word(), ask4_number()); // K1
}

void I_Dictionary::change_polish_word()
{
    Dictionary::change_polish_word(ask4_pol_word(), ask4_number()); // K1
}

void I_Dictionary::show_by_letters()const
{
    char let_1st, let_2nd;
    std::cout << "Podaj litere poczatkowa: ";
    std::cin >> let_1st;
    std::cout << "Podaj litere koncowa: ";
    std::cin >> let_2nd;
    Dictionary::show_by_letters(let_1st,let_2nd);
    std::cout << std::endl;
}

void I_Dictionary::show_dictionary_option()const
{
    std::cout << std::endl << "MENU SLOWNIKA" << std::endl << std::endl;
    std::cout << "1 - wyjscie" << std::endl; 
    std::cout << "2 - wyswietlenie mozliwych opcji slownika" << std::endl;
    std::cout << "3 - dodanie nowego slowka" << std::endl;
    std::cout << "4 - usuniecie slowka (nazwa)" << std::endl;
    std::cout << "5 - usuniecie slowka (numer) " << std::endl;
    std::cout << "6 - zmien slowko" << std::endl;
    std::cout << "7 - pokazanie zawartosci slownika" << std::endl;
    std::cout << "8 - pokazanie zawartosci slownika od litery 'x' do litery 'y'" << std::endl;
    std::cout << "9 - zapisanie postepu" << std::endl;
}

void I_Dictionary::use_all()
{
    int option_number;
    do
    {
        show_dictionary_option();
        option_number = ask4_choice();
        system("clear");
        switch(option_number) // wybor opcji slownika
        {
            case 1: 
            std::cout << "Wyjscie z slownika" << std::endl; break;
            case 2:
            show_dictionary_option(); break;
            case 3:
            add_word(); break;
            case 4:
            delete_by_word(); break;
            case 5:
            delete_by_number(); break;
            case 6:
            choose_changing_mode(); break;
            case 7:
            show_all(); break;
            case 8: 
            show_by_letters(); break;
            case 9:
            save_changes(); break; // bez podania opcji zapisu zmiany nie zostana wprowadzone do pliku
            default:
            std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(option_number!=1); // ciagle dzialanie petli dopoki nie nastapi podanie opcji wyjscia
}

void I_Dictionary::choose_changing_mode()
{
    int option_number;
    do
    {
        std::cout << "1 - zmien obcojezyczne i polskie tlumaczenie" << std::endl;
        std::cout << "2 - zmien obcojezyczne tlumaczenie" << std::endl;
        std::cout << "3 - zmien polskie tlumaczenie" << std::endl;
        option_number = ask4_choice();
        switch(++option_number) // wybor trybu zmiany slowa
        {
            case 2:
            change_word(); break;
            case 3:
            change_foreign_word(); break;
            case 4:
            change_polish_word(); break;
            default:
            std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(option_number<2||option_number>4);
}

std::string I_Dictionary::ask4_for_word()const
{
    std::string temp_var;
    std::cout << "Podaj obcojezyczna wersje slowka: ";
    std::getline(std::cin, temp_var); // przechwycenie tlumaczenia obcojezycznego
    return temp_var;
}

std::string I_Dictionary::ask4_pol_word()const
{
    std::string temp_var;
    std::cout << "Podaj polska wersje slowka: ";
    std::getline(std::cin, temp_var); // przechywcenie tlumaczenia polskiego
    return temp_var;
}

int I_Dictionary::ask4_number()const
{
    int temp_var;
    std::cout << "Podaj numer slowka: ";
    std::cin >> temp_var; // podanie numeru na liscie
    std::cin.get();
    return temp_var;
}

int ask4_choice()
{
    int option_number;
    std::cout << std::endl << "Podaj swoj wybor: ";
    std::cin >> option_number;
    if(std::cin.fail()) // jesli wystapil blad wpisywania
    {
        std::cin.clear(); // wyczysc strumien
        std::cin.ignore(1000, '\n'); // zignoruj wszystko
    }
    else
        std::cin.get(); // jesli poprawnie pobierz pozostaly znak '\n' w strumieniu
    return option_number;
}