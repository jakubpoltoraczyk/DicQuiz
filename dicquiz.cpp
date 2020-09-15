/* DicQuiz wersja 1.0 */

#include "dicquiz.h"

DicQuiz::DicQuiz(): dic()
{
    srand(time(NULL)); // konieczne dla losowania roznych pseudolosowych liczb na przestrzeni kilku uruchomien programu
}

DicQuiz::DicQuiz(const I_Dictionary & new_dic): dic(new_dic)
{
    srand(time(NULL)); // jak wyzej
}

DicQuiz::DicQuiz(const std::string & file_name): dic(file_name)
{
    srand(time(NULL)); // jak wyzej
}

void DicQuiz::start()
{
    int option_number;
    std::cout << "Witamy w DicQuiz!" << std::endl;
    do
    {
        show_dicquiz_option();
        option_number = ask4_choice();
        system("clear");
        switch(option_number)
        {
            case 1:
            std::cout << "Wyjscie z programu" << std::endl; break;
            case 2:
            dic.use_all(); break;
            case 3:
            make_quiz(); break;
            default:
            std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(option_number!=1);
}

const int * DicQuiz::draw_numbers()const
{
    int * numbers = new int[quiz_size];
    int help_number;
    for(int i=0;i<quiz_size;++i)
        numbers[i] = -99;
    for(int i=0;i<quiz_size;++i)
    {
        help_number = (std::rand()%dic.get_number_of_words() + 1); // losowanie numerka sposrod dostepnych
        for(int j=0;j<quiz_size;++j)
        {
            if(numbers[j] == help_number) // jesli byl on juz wylosowany powtorz losowanie
            {
                j = quiz_size;
                --i;
            }
            if(j==quiz_size-1) // jesli nie byl wylosowany zapisz go do tablicy
                numbers[i] = help_number;
        }
    }
    return numbers; // zwraca wskaznik na zaalokowana dynamicznie tablice wylosowanych numerkow (nalezy pamietac o jej zwolnieniu po wykorzystaniu w innej funkcji)
}

void DicQuiz::make_quiz()
{
    int option_number, lang_choice, total = 0, points = 0;
    const int * question_number;
    char answer;
    do
    {
        show_quiz_size_option();
        option_number = ask4_choice();
        system("clear");
        if(change_quiz_size(option_number)) // jesli podano dostepny rozmiar quizu
        {
            question_number = draw_numbers(); // przypisanie tabeli numerkow slowek do wskaznika
            show_quiz_lang_option();
            lang_choice = ask4_choice();
            if(++lang_choice==2||lang_choice==3) // jesli wybrano poprawna opcje wersji jezykowej
            {
                std::cout << std::endl << "Start quizu!" << std::endl;
                for(int i=0;i<quiz_size;++i)
                {
                    std::cout << std::endl << "Pytanie nr " << i+1 << ": "; 
                    if(lang_choice==2) // rozroznienie wersji jezykowej
                        std::cout << dic.get_foreign_word(question_number[i]) << std::endl;
                    else
                        std::cout << dic.get_polish_word(question_number[i]) << std::endl;
                    do
                    {
                        std::cout << "Gotowy na odpowiedz - nacisnij enter: ";
                        std::cin.get(answer);
                        if(answer!='\n') // jesli podany inny znak niz enter zignorowanie calego strumienia
                            std::cin.ignore(1000,'\n');
                    }while(answer!='\n'); // proszenie do skutku o 'enter'
                    std::cout << "Tlumaczenie to: ";
                    if(lang_choice==2) // rozroznienie wersji jezykowej
                        std::cout << dic.get_polish_word(question_number[i]) << std::endl;
                    else
                        std::cout << dic.get_foreign_word(question_number[i]) << std::endl;
                    do
                    {
                        std::cout << "Czy Twoja odpowiedz byla poprawna ('t' lub 'n')? ";
                        std::cin.get(answer);
                        if(answer!='\n')
                            std::cin.ignore(1000,'\n');
                        if(answer == 't')
                        {
                            std::cout << "Brawo! ";
                            ++points;
                        }
                        if(answer == 'n')
                            std::cout << "Niestety! ";
                    }while(answer!='t'&&answer!='n'); // dopoki nie podana zostanie odpowiedz tak lub nie
                    ++total;
                    std::cout << "Twoj wynik to: " << 100*double(points)/total << "% (" << points << "/" << total << ")" << std::endl;
                }
                std::cout << std::endl << "Twoj ostateczny rezultat to: " << 100*double(points)/total << "% (" << points << "/" << total << ")" << std::endl;
                std::cout << "Gratulacje!" << std::endl;
            }
            else // jesli podano zly rozmiar quizu
            {
                system("clear");
                std::cout << "Brak opcji o podanym numerze" << std::endl << std::endl;
            }
        delete [] question_number; // zwolnienie pamieci zajmowanej przez tablice z numerkami pytan
        }
        else if(option_number!=1)
                std::cout << "Brak opcji o podanym numerze" << std::endl;
    }while(option_number!=1);
}

void DicQuiz::show_dicquiz_option()const
{
    std::cout << std::endl << "MENU GLOWNE" << std::endl << std::endl;
    std::cout << "1 - wyjscie" << std::endl;
    std::cout << "2 - slownik" << std::endl;
    std::cout << "3 - quiz" << std::endl;
}

void DicQuiz::show_quiz_size_option()const
{
    std::cout << std::endl << "MENU QUIZU" << std::endl << std::endl;
    std::cout << "1 - wyjscie" << std::endl;
    if(dic.get_number_of_words()>=10)
        std::cout << "2 - maly quiz (10 pyt.)" << std::endl;
    if(dic.get_number_of_words()>=25)
        std::cout << "3 - sredni quiz (25 pyt.)" << std::endl;
    if(dic.get_number_of_words()>=50)
        std::cout << "4 - duzy quiz (50 pyt.)" << std::endl;
}

void DicQuiz::show_quiz_lang_option()const
{
    std::cout << std::endl << "MENU QUIZU" << std::endl << std::endl;
    std::cout << "1 - obcyjezyk -> polski" << std::endl;
    std::cout <<  "2 - polski -> obcyjezyk" << std::endl;
}

bool DicQuiz::change_quiz_size(int n)
{
    switch(n)
    {
        case 2:
        if(dic.get_number_of_words()>=10)
        {
            quiz_size = small;
            return true;
        }
        break; 
        case 3:
        if(dic.get_number_of_words()>=25)
        {
            quiz_size = medium;
            return true;
        }
        break;
        case 4:
        if(dic.get_number_of_words()>=50)
        {
            quiz_size = big;
            return true;
        }
        break;
    }
    return false;
}