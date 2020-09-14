#include "dicquiz.h"

DicQuiz::DicQuiz(): dic()
{
    srand(time(NULL));
}

DicQuiz::DicQuiz(const I_Dictionary & new_dic): dic(new_dic)
{
    srand(time(NULL));
}

DicQuiz::DicQuiz(const std::string & file_name): dic(file_name)
{
    srand(time(NULL));
}

void DicQuiz::start()
{
    int option_number;
    std::cout << "Witamy w DicQuiz!" << std::endl;
    do
    {
        show_dicquiz_option();
        std::cout << std::endl << "Podaj swoj wybor: ";
        std::cin >> option_number;
        std::cin.get();
        std::cout << std::endl;
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
        numbers[i] = -1;
    for(int i=0;i<quiz_size;++i)
    {
        help_number = (std::rand()%dic.get_number_of_words() + 1);
        for(int j=0;j<quiz_size;++j)
        {
            if(numbers[j] == help_number)
            {
                j = quiz_size;
                --i;
            }
            if(j==quiz_size-1)
                numbers[i] = help_number;
        }
    }
    return numbers;
}

void DicQuiz::make_quiz()
{
    int option_number, total = 0, points = 0;
    const int * question_number; 
    char answer;
    do
    {
        show_quiz_option();
        std::cout << std::endl << "Podaj swoj wybor: ";
        std::cin >> option_number;
        std::cin.get();
        std::cout << std::endl;
        system("clear");
        if(change_quiz_size(option_number))
        {
            question_number = draw_numbers();
            std::cout << std::endl << "Start quizu!" << std::endl;
            for(int i=0;i<quiz_size;++i)
            {
                std::cout << std::endl << "Pytanie nr " << i+1 << ": " << dic.get_foreign_word(question_number[i]) << std::endl;
                do
                {
                    std::cout << "Gotowy na odpowiedz - nacisnij enter: ";
                    std::cin.get(answer);
                }while(answer!='\n');
                std::cout << "Tlumaczenie to: " << dic.get_polish_word(question_number[i]) << std::endl;
                do
                {
                    std::cout << "Czy Twoja odpowiedz byla poprawna ('t' lub 'n')? ";
                    std::cin.get(answer);
                    std::cin.get();
                    if(answer == 't')
                    {
                        std::cout << "Brawo! ";
                        ++points;
                    }
                    if(answer == 'n')
                        std::cout << "Niestety! ";
                }while(answer!='t'&&answer!='n');
                ++total;
                std::cout << "Twoj wynik to: " << 100*double(points)/total << "% (" << points << "/" << total << ")" << std::endl;
            }
            std::cout << std::endl << "Twoj ostateczny rezultat to: " << 100*double(points)/total << "% (" << points << "/" << total << ")" << std::endl;
            std::cout << "Gratulacje!" << std::endl;
        }
    }while(option_number!=1);
    delete [] question_number;
}

void DicQuiz::show_dicquiz_option()const
{
    std::cout << std::endl << "MENU GLOWNE" << std::endl << std::endl;
    std::cout << "1 - wyjscie" << std::endl;
    std::cout << "2 - slownik" << std::endl;
    std::cout << "3 - quiz" << std::endl;
}

void DicQuiz::show_quiz_option()const
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