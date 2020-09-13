#ifndef IDIC_QUIZ_H
#define IDIC_QUIZ_H

#include "i_dictionary.h"

class DicQuiz
{
    public:
        DicQuiz();
        explicit DicQuiz(const I_Dictionary & new_dic);
        explicit DicQuiz(const std::string & file_name);
        void start();
    private:
        enum Quiz_size {small = 10, medium = 25, big = 50};
        I_Dictionary dic;
        Quiz_size quiz_size;
        const int * draw_numbers()const;
        void make_quiz()const;
        void show_dicquiz_option()const;
};

#endif // IDIC_QUIZ_H