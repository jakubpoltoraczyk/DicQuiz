#ifndef IDIC_H
#define IDIC_H

#include "dictionary.h"

class i_Dic: public Dictionary
{
    public: 
        i_Dic(const std::string & file_name = ".idic_lofw_2506.txt");
        void add_word();
        void delete_by_word();
        void delete_by_number();
        void show_by_letters()const;
        void show_dictionary_option()const;
        void do_all();
};

#endif // IDIC_H
