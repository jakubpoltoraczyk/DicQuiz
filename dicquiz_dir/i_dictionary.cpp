/* DicQuiz wersja 1.25 */

#include "i_dictionary.h"

I_Dictionary::I_Dictionary(const std::string & file_name): Dictionary(file_name)
{

}

/* K1 - wykorzystanie metody klasy Dictionary z podaniem interaktywnie argumentow za posrednictwem prywatnych metod klasy I_Dictionary */

void I_Dictionary::add_word()
{
    Dictionary::add_word(ask4_pol_word(), ask4_for_word()); // K1
}

void I_Dictionary::delete_word_by_foreign_translation()
{
    Dictionary::delete_word_by_foreign_translation(ask4_for_word()); // K1
}

void I_Dictionary::delete_word_by_number()
{
    Dictionary::delete_word_by_number(ask4_number()); // K1
}

void I_Dictionary::change_whole_translation()
{
    Dictionary::change_whole_translation(ask4_pol_word(), ask4_for_word(), ask4_number()); // K1
}

void I_Dictionary::change_foreign_translation()
{
    Dictionary::change_foreign_translation(ask4_for_word(), ask4_number()); // K1
}

void I_Dictionary::change_polish_translation()
{
    Dictionary::change_polish_translation(ask4_pol_word(), ask4_number()); // K1
}

void I_Dictionary::show_words_by_letters()const
{
    char letter_1st, letter_2nd;
    std::cout << "Podaj litere poczatkowa: ";
    std::cin >> letter_1st;
    std::cout << "Podaj litere koncowa: ";
    std::cin >> letter_2nd;
    Dictionary::show_words_by_letters(letter_1st,letter_2nd);
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
    int tmp;
    do
    {
        show_dictionary_option();
        tmp = ask4_choice();
        system("clear");
        switch(tmp) // wybor opcji slownika
        {
            case 1: 
            std::cout << "Wyjscie z slownika" << std::endl; break;
            case 2:
            show_dictionary_option(); break;
            case 3:
            add_word(); break;
            case 4:
            delete_word_by_foreign_translation(); break;
            case 5:
            delete_word_by_number(); break;
            case 6:
            choose_changing_mode(); break;
            case 7:
            show_all_words(); break;
            case 8: 
            show_words_by_letters(); break;
            case 9:
            save_changes(); break; // bez podania opcji zapisu zmiany nie zostana wprowadzone do pliku
            default:
            std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(tmp != 1); // ciagle dzialanie petli dopoki nie nastapi podanie opcji wyjscia
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
            change_whole_translation(); break;
            case 3:
            change_foreign_translation(); break;
            case 4:
            change_polish_translation(); break;
            default:
            std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(option_number < 2 || option_number > 4);
}

std::string I_Dictionary::ask4_for_word()const
{
    std::string tmp;
    std::cout << "Podaj obcojezyczna wersje slowka: ";
    std::getline(std::cin, tmp); // przechwycenie tlumaczenia obcojezycznego
    return tmp;
}

std::string I_Dictionary::ask4_pol_word()const
{
    std::string tmp;
    std::cout << "Podaj polska wersje slowka: ";
    std::getline(std::cin, tmp); // przechywcenie tlumaczenia polskiego
    return tmp;
}

int I_Dictionary::ask4_number()const
{
    int tmp;
    std::cout << "Podaj numer slowka: ";
    std::cin >> tmp; // podanie numeru na liscie
    std::cin.get();
    return tmp;
}

int ask4_choice()
{
    int tmp;
    std::cout << std::endl << "Podaj swoj wybor: ";
    std::cin >> tmp;
    if(std::cin.fail()) // jesli wystapil blad wpisywania
    {
        std::cin.clear(); // wyczysc strumien
        std::cin.ignore(1000, '\n'); // zignoruj wszystko do 1000 znakow az do napotkania znaku 'enter'
    }
    else
        std::cin.get(); // jesli poprawnie pobierz pozostaly znak '\n' w strumieniu
    return tmp;
}