/* DicQuiz wersja 1.25 */

#include "dictionary.h"


Dictionary::Dictionary(const std::string & f_name): file_name(f_name)
{
    std::ifstream words_file;
    words_file.open(file_name);
    if(!words_file.is_open()) // sprawdzanie poprawnosci otwarcia pliku
        system("touch dicquiz_dir/.idic_lofw_2506.txt"); // nazwa ukyrtego pliku do zapisu zawartosci slownika
    else
    {
        std::string tmp;
        while(!words_file.eof())
        {
            std::getline(words_file, tmp, '-'); // pobranie obcojezycznej wersji, pominiecie znaku '-'
            foreign_translations.push_back(tmp);
            std::getline(words_file, tmp); // pobranie polskiej wersji
            polish_translations.push_back(tmp);
        }
        words_file.close();
        set_alphabetically(); // ulozenie alfabetyczne raz w konstruktorze (pozniej aby w metodzie Dictionary::add_word())
    }
}

void Dictionary::add_word(const std::string & pol_trans, const std::string & for_trans)
{
    foreign_translations.push_back(for_trans);
    polish_translations.push_back(pol_trans);
    set_alphabetically(); // ukladanie alfabetycznie po kazdym nowo dodanym slowku
}

void Dictionary::delete_word_by_foreign_translation(const std::string & for_trans)
{
    for(int i = 0; i < foreign_translations.size(); ++i)
        if(foreign_translations[i] == for_trans)
        {
            delete_word_by_number(i+1); // plus jeden ze wzgledu przystosowanie metody Dictionary::delete_by_number() na liczenie slow od 1 a nie 0 (ulatwienie dla uzytkownika)
            i = foreign_translations.size();
        }
}

void Dictionary::delete_word_by_number(int word_number)
{
    foreign_translations.erase(foreign_translations.begin() + word_number - 1); // liczy od 1 a nie od 0 (ulatwienie dla uzytkownika)
    polish_translations.erase(polish_translations.begin() + word_number - 1);
}

void Dictionary::change_whole_translation(const std::string & pol_trans, const std::string & for_trans, int word_number)
{
    foreign_translations[word_number-1] = for_trans; // minus jeden ze wzgledu na numerowanie dla uzytkownika od 1 a nie 0 (analogicznie w ponizszych metod od zmian tlumaczen)
    polish_translations[word_number-1] = pol_trans;
    set_alphabetically();
}

void Dictionary::change_foreign_translation(const std::string & for_trans, int word_number)
{
    foreign_translations[word_number-1] = for_trans;
    set_alphabetically();
}

void Dictionary::change_polish_translation(const std::string & pol_trans, int word_number)
{
    polish_translations[word_number-1] = pol_trans;
}

void Dictionary::show_all_words()const
{
    for(int i = 0; i < foreign_translations.size(); ++i)
        std::cout << i+1 << ". " << foreign_translations[i] << " - " << polish_translations[i] << std::endl;
}

void Dictionary::show_words_by_letters(char letter_1st, char letter_2nd)const
{
    for(int i = 0; i < foreign_translations.size() && foreign_translations[i][0] <= letter_2nd; ++i) // zawarty warunek 'pokaz do drugiej litery wlacznie'
        if(foreign_translations[i][0] >= letter_1st) // warunek 'pokaz od pierwszej litery wlacznie'
            std::cout << i+1 << ". " << foreign_translations[i] << " - " << polish_translations[i] << std::endl;
}

bool Dictionary::save_changes()const
{
    std::ofstream words_file;
    words_file.open(file_name); // tworzy plik lub go nadpisuje (nazwa zapamietana w konstruktorze)
    for(int i = 0; i < foreign_translations.size(); ++i)
    {
        words_file << foreign_translations[i] << "-" << polish_translations[i];
        if(i!=foreign_translations.size()-1)
            words_file << std::endl;
    }
    words_file.close();
    return true;
}

const std::string & Dictionary::get_foreign_translation(int word_number)const
{
    return  foreign_translations[word_number-1];
}

const std::string & Dictionary::get_polish_translation(int word_number)const
{
    return polish_translations[word_number-1];
}

int Dictionary::get_number_of_words()const
{
    return foreign_translations.size();
}

void Dictionary::set_alphabetically() // metoda wykorzystujaca sortowanie babelkowe
{
    for(int i = 0;i < foreign_translations.size(); ++i)
        for(int j = 1; j < foreign_translations.size(); ++j)
            if(foreign_translations[j] < foreign_translations[j-1])
                swap_by_number(j, j-1);
}

void Dictionary::swap_by_number(int word_number_1st, int word_number_2nd)
{
    std::swap(foreign_translations[word_number_1st], foreign_translations[word_number_2nd]); // metoda std::swap() zamienia miejscami dwa elementy tablicy
    std::swap(polish_translations[word_number_1st], polish_translations[word_number_2nd]);
}