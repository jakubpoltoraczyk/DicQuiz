#include "dicquiz.h"

DicQuiz::DicQuiz(): dic()
{

}

DicQuiz::DicQuiz(const I_Dictionary & new_dic): dic(new_dic)
{

}

DicQuiz::DicQuiz(const std::string & file_name): dic(file_name)
{

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
            std::cout << "Wkrotce dostepne!" << std::endl; break;
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
        help_number = (std::rand()%dic.get_number_of_words() + 0);
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

void DicQuiz::make_quiz()const
{
    int points = 0;
    std::string answer;
    const int * question_number = draw_numbers();
    std::cout << std::endl << "Rozpoczecie testu: ilosc pytan - " << quiz_size<< std::endl << std::endl;
    for(int i=0;i<quiz_size;++i)
    {
        std::cout << "Pytanie nr " << i+1 << ": " << dic.get_foreign_word(question_number[i]) << std::endl;
        std::cout << "Twoja odpowiedz: ";
        std::getline(std::cin, answer);
        if(answer == dic.get_polish_word(question_number[i]))
        {
            std::cout << "Poprawna odpowiedz!" << std::endl;
            ++points;
        }
        else
            std::cout << "Bledna odpowiedz! Tlumaczenie to: " << dic.get_polish_word(question_number[i]) << std::endl;
        std::cout << "Twoj wynik to: " << points/quiz_size << "% (" << points << "/" << i+1 << ")" << std::endl;
    }
    std::cout << std::endl << "Koniec testu. Twoj ostateczny wynik to: " << points/quiz_size << "% (" << points << "/" << quiz_size << ")" << std::endl;
    delete [] question_number;
}

void DicQuiz::show_dicquiz_option()const
{
    std::cout << std::endl << "MENU GLOWNE" << std::endl << std::endl;
    std::cout << "1 - wyjscie" << std::endl;
    std::cout << "2 - slownik" << std::endl;
    std::cout << "3 - quiz" << std::endl;
}