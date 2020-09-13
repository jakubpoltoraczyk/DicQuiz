/* Klasa reprezentuje interaktywny slownik wyrazow obcojezycznych. Udostepnia mozliwosci po dziedziczonej
   publicznie klasie Dictionary, rozwijajac znaczna czesc z nich o sposobnosc interakcji z uzytkownikiem.
   Z tego tez wzgledu metody wystepujace w owej klasie sa pozbawione jakichkolwiek parametrow - potrzebne
   informacje maja byc podawane wprost przez uzytkownika w konsoli. Metoda use_all() daje ponadto mozliwosc 
   ciaglego korzystania z wszystkich mozliwosci i funkcji slownika, bazujac na teorii prostego menu 
   z wielokrotnym i powtarzalnym wyborem dostepnych opcji. */

#ifndef IDIC_H
#define IDIC_H

#include "dictionary.h" // podlaczenie klasy Dictionary

class I_Dictionary: public Dictionary
{
    public: 
        explicit I_Dictionary(const std::string & file_name = ".idic_lofw_2506.txt"); // konstruktor identyczny jak w klasie Dictionary
        void add_word(); // metoda dodajaca nowy wyraz
        void delete_by_word(); // metoda usuwajaca wyraz na podstawie jego obcojezycznego tlumaczenia
        void delete_by_number(); // metoda usuwajaca wyraz na podstawie numeru na liscie
        void show_by_letters()const; // metoda pokazujaca zawartosc slownika w zakresie liter od 'let_1st' do 'let_2nd'
        void show_dictionary_option()const; // metoda udostepniajaca spis opcji umozliwiajacych korzystanie ze slownika w trybie use_all()
        void use_all(); // metoda opisana we wstepie do klasy
};

#endif // IDIC_H