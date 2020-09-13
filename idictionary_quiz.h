#ifndef IDIC_QUIZ_H
#define IDIC_QUIZ_H

class I_Quiz
{

};

#endif // IDIC_QUIZ_H

        void start_test()const;
            private:
        enum Test_size {small = 10, medium = 25, big = 50};
        Test_size t_size;
        const int * draw_words_numbers()const;




        void I_Dictionary::start_test()const
{
    int points = 0;
    std::string answer;
    const int * question_number = draw_words_numbers();
    std::cout << std::endl << "Rozpoczecie testu: ilosc pytan - " << int(t_size) << std::endl << std::endl;
    for(int i=0;i<int(t_size);++i)
    {
        std::cout << "Pytanie nr " << i+1 << ": " << get_foreign_word(question_number[i]) << std::endl;
        std::cout << "Twoja odpowiedz: ";
        std::getline(std::cin, answer);
        if(answer == get_polish_word(question_number[i]))
        {
            std::cout << "Poprawna odpowiedz!" << std::endl;
            ++points;
        }
        else
            std::cout << "Bledna odpowiedz! Tlumaczenie to: " << get_polish_word(question_number[i]) << std::endl;
        std::cout << "Twoj wynik to: " << double(points/int(t_size)) << "% (" << points << "/" << i+1 << ")" << std::endl;
    }
    std::cout << std::endl << "Koniec testu. Twoj ostateczny wynik to: " << points/int(t_size) << "% (" << points << "/" << int(t_size) << ")" << std::endl;
    delete [] question_number;
}



const int * I_Dictionary::draw_words_numbers()const
{
    int * draw_numbers = new int[int(t_size)];
    int help_number;
    for(int i=0;i<int(t_size);++i)
        draw_numbers[i] = -1;
    for(int i=0;i<int(t_size);++i)
    {
        help_number = (std::rand()%get_number_of_words() + 0);
        for(int j=0;j<int(t_size);++j)
        {
            if(draw_numbers[j] == help_number)
            {
                j = int(t_size);
                --i;
            }
            if(j==int(t_size)-1)
                draw_numbers[i] = help_number;
        }
    }
    return draw_numbers;
}

void I_Dictionary::do_all()
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
                show_all(); break;
            case 7: 
                show_by_letters(); break;
            case 8:
                save_changes(); break;
            default:
                std::cout << "Brak opcji o podanym numerze" << std::endl;
        }
    }while(option_number!=1);
}