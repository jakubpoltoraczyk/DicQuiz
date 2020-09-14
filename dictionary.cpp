#include "dictionary.h"


Dictionary::Dictionary(const std::string & f_name): file_name(f_name)
{
    if(file_name==".idic_lofw_2506.txt") // nazwa ukyrtego pliku do zapisu zawartosci slownika
        system("touch .idic_lofw_2506.txt");
    else
    {
        std::ifstream words_file;
        words_file.open(file_name);
        std::string temp_var;
        while(!words_file.eof())
        {
        std::getline(words_file, temp_var, '-'); // pobranie obcojezycznej wersji, pominiecie znaku '-'
        list_of_foreign_words.push_back(temp_var);
        std::getline(words_file, temp_var); // pobranie polskiej wersji
        list_of_polish_words.push_back(temp_var);
        }
        words_file.close();
        set_alfabet(); // ulozenie alfabetyczne raz w konstruktorze (pozniej aby w metodzie Dictionary::add_word())
    }
}

void Dictionary::add_word(const std::string & new_pol_word, const std::string & new_for_word)
{
    list_of_foreign_words.push_back(new_for_word);
    list_of_polish_words.push_back(new_pol_word);
    set_alfabet(); // ukladanie alfabetycznie po kazdym nowo dodanym slowku
}

void Dictionary::delete_by_word(const std::string & del_word)
{
    for(int i=0;i<list_of_foreign_words.size();++i)
        if(list_of_foreign_words[i]==del_word)
        {
            delete_by_number(i+1); // plus jeden ze wzgledu przystosowanie metody Dictionary::delete_by_number() na liczenie slow od 1 a nie 0 (ulatwienie dla uzytkownika)
            i = list_of_foreign_words.size();
        }
}

void Dictionary::delete_by_number(int word_number)
{
    list_of_foreign_words.erase(list_of_foreign_words.begin() + word_number - 1); // liczy od 1 a nie od 0 (ulatwienie dla uzytkownika)
    list_of_polish_words.erase(list_of_polish_words.begin() + word_number - 1);
}

void Dictionary::change_word(const std::string & pol_word, const std::string & for_word, int number)
{
    list_of_foreign_words[number-1] = for_word; // minus jeden ze wzgledu na numerowanie dla uzytkownika od 1 a nie 0 (analogicznie w ponizszych metod od zmian tlumaczen)
    list_of_polish_words[number-1] = pol_word;
    set_alfabet();
}

void Dictionary::change_foreign_word(const std::string & for_word, int number)
{
    list_of_foreign_words[number-1] = for_word;
    set_alfabet();
}

void Dictionary::change_polish_word(const std::string & pol_word, int number)
{
    list_of_polish_words[number-1] = pol_word;
}

void Dictionary::show_all()const
{
    for(int i=0;i<list_of_foreign_words.size();++i)
        std::cout << i+1 << ". " << list_of_foreign_words[i] << " - " << list_of_polish_words[i] << std::endl;
}

void Dictionary::show_by_letters(char let_1st, char let_2nd)const
{
    for(int i=0;i<list_of_foreign_words.size();++i)
    {
        if(list_of_foreign_words[i][0]>=let_1st&&list_of_foreign_words[i][0]<=let_2nd) // od litery 'x' do 'y' wlacznie 
            std::cout << i+1 << ". " << list_of_foreign_words[i] << " - " << list_of_polish_words[i] << std::endl;
        if(list_of_foreign_words[i][0]>let_2nd)
            i = list_of_foreign_words.size();
    }
}

bool Dictionary::save_changes()const
{
    std::ofstream words_file;
    words_file.open(file_name); // tworzy plik lub go nadpisuje (nazwa zapamietana w konstruktorze)
    for(int i=0;i<list_of_foreign_words.size();++i)
    {
        words_file << list_of_foreign_words[i] << "-" << list_of_polish_words[i];
        if(i!=list_of_foreign_words.size()-1)
            words_file << std::endl;
    }
    words_file.close();
    return true;
}

const std::string & Dictionary::get_foreign_word(int number)const
{
    return  list_of_foreign_words[number-1];
}

const std::string & Dictionary::get_polish_word(int number)const
{
    return list_of_polish_words[number-1];
}

int Dictionary::get_number_of_words()const
{
    return list_of_foreign_words.size();
}

void Dictionary::set_alfabet() // metoda wykorzystujaca sortowanie babelkowe
{
    std::string temp_var;
    for(int i=0;i<list_of_foreign_words.size();++i)
        for(int j=1;j<list_of_foreign_words.size();++j)
            if(list_of_foreign_words[j]<list_of_foreign_words[j-1])
            {
                std::swap(list_of_foreign_words[j],list_of_foreign_words[j-1]); // metoda swap() zamienia miejscami dwa elementy tablicy
                std::swap(list_of_polish_words[j],list_of_polish_words[j-1]);
            }
}