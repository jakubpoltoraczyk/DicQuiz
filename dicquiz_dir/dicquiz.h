/* DicQuiz wersja 1.25 */

/* Klasa reprezentujaca interaktywny program DicQuiz, ktorego celem jest umozliwienie nauki slowek obcojezycznych, 
   za posrednictwem prostego quizu opartego na tlumaczeniu slowek. Zawarty w klasie obiekt klasy::I_Dictionary stanowi
   baze danych dla slowek potrzebnych do nauki. Jedyna metoda dostepna dla uzytkownika jest metoda start(), ktora uruchamia
   program DicQuiz. Stanowi ona zbior wszelkich funkcji programu i opierajac sie na menu wielokrotnego wyboru umozliwia
   nie tylko nauke poprzez powtarzanie quizu, ale takze aktualizowanie bazy slowek za pomoca obiektu klasy I_Dictionary i jego
   metod interaktywnych. */

#ifndef IDIC_QUIZ_H
#define IDIC_QUIZ_H

#include "i_dictionary.h"

class DicQuiz
{
    public:
        DicQuiz(); // konstruktor inicjalizujacy nowa, pusta baze slowek
        explicit DicQuiz(const I_Dictionary & new_dic); // konstruktor wymagajacy podania obiektu I_Dictionary z dostepna w nim baza slowek
        explicit DicQuiz(const std::string & file_name); // konstruktor wymagajacy podania nazwy pliku z dostepnymi slowkami
        void start(); // metoda wspomniania w opisie klasy
    private:
        enum Quiz_size {small = 10, medium = 25, big = 50}; // typ wyliczeniowy dla ustalenia rozmiaru quizu (liczby pytan)
        I_Dictionary dic; // obiekt klasy I_Dictionary stanowiacy baze slowek
        Quiz_size quiz_size; // obecny rozmiar quizu
        const int * draw_numbers()const; // metoda losujaca niepowtarzajace sie numery slowek z bazy zgodnie z rozmiarem quizu
        void make_quiz(); // metoda uruchamiajaca quiz
        void show_dicquiz_option()const; // metoda ukazujaca opcje dostepne w programie DicQuiz
        void show_quiz_size_option()const; // metoda ukazujaca opcje rozmiaru quizu
        void show_quiz_lang_option()const; // metoda ukazujaca opcje jezykowe quizu (z obcjez. na polski lub na odwrot)
        bool change_quiz_size(int n); // metoda zmieniajaca rozmiar quizu
};

#endif // IDIC_QUIZ_H