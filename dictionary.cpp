#include "dictionary.h"


Dictionary::Dictionary(const std::string & f_name): file_name(f_name)
{
    if(file_name==".idic_lofw_2506.txt")
        system("touch .idic_lofw_2506.txt");
    else
    {
        std::ifstream words_file;
        words_file.open(file_name);
        std::string temp_var;
        while(!words_file.eof())
        {
        std::getline(words_file, temp_var, '-');
        list_of_foreign_words.push_back(temp_var);
        std::getline(words_file, temp_var);
        list_of_polish_words.push_back(temp_var);
        }
        words_file.close();
        set_alfabet();
    }
}

void Dictionary::add_word(const std::string & new_for_word, const std::string & new_pol_word)
{
    list_of_foreign_words.push_back(new_for_word);
    list_of_polish_words.push_back(new_pol_word);
    set_alfabet();
}

void Dictionary::delete_by_word(int word_number)
{
    list_of_foreign_words.erase(list_of_foreign_words.begin() + word_number - 1);
    list_of_polish_words.erase(list_of_polish_words.begin() + word_number - 1);
}

void Dictionary::delete_by_number(int )

void Dictionary::show_all()const
{
    for(int i=0;i<list_of_foreign_words.size();++i)
        std::cout << i+1 << ". " << list_of_foreign_words[i] << " - " << list_of_polish_words[i] << std::endl;
}

void Dictionary::show_by_letters(char let_1st, char let_2nd)const
{
    for(int i=0;i<list_of_foreign_words.size();++i)
    {
        if(list_of_foreign_words[i][0]>=let_1st&&list_of_foreign_words[i][0]<=let_2nd)
            std::cout << i+1 << ". " << list_of_foreign_words[i] << " - " << list_of_polish_words[i] << std::endl;
        if(list_of_foreign_words[i][0]>let_2nd)
            i = list_of_foreign_words.size();
    }
}

bool Dictionary::save_changes()const
{
    std::ofstream words_file;
    words_file.open(file_name);
    for(int i=0;i<list_of_foreign_words.size();++i)
    {
        words_file << list_of_foreign_words[i] << " - " << list_of_polish_words[i];
        if(i!=list_of_foreign_words.size()-1)
            words_file << std::endl;
    }
    words_file.close();
    return true;
}

void Dictionary::set_alfabet()
{
    std::string temp_var;
    for(int i=0;i<list_of_foreign_words.size();++i)
        for(int j=1;j<list_of_foreign_words.size()-1;++j)
            if(list_of_foreign_words[j]<list_of_foreign_words[j-1])
            {
                std::swap(list_of_foreign_words[j],list_of_foreign_words[j-1]);
                std::swap(list_of_polish_words[j],list_of_polish_words[j-1]);
            }
}