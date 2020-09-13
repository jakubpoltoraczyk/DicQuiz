/* Klasa reprezentuje slownik wyrazow obcojezycznych, udostepniajac podstawowe mozliwosci obslugi 
   slownika takie jak m.in. dodawanie nowych slowek, usuwanie ich oraz pokazywanie zawartosci slownika
   w kolejnosci numerowanej i alfabetycznej */ 

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

class Dictionary
{
    public:
        /* Konstruktor przyjmujacy jako argument nazwe pliku, ktory ma sluzyc do obslugiwania slownika. Plik moze byc pusty, jak i zawierac 
           liste slowek w formacie: 'foreign_word - pol_word1, pol_word2'. Mozliwe wykorzystanie konstruktora bezparametrycznego, nastepuje
           wtedy utworzenie ukrytego pustego pliku do obslugi slownika */
        Dictionary(const std::string & f_name = ".idic_lofw_2506.txt");
        virtual ~Dictionary() {} // destruktor wirtualny, nie wykonywujacy zadnych zadan
        /* Metoda dodajaca slowko do slownika, parametry to kolejno wyraz obcojezyczny oraz ciag znakow reprezentujacych jego polskie tlumaczenie */
        virtual void add_word(const std::string & new_for_word, const std::string & new_pol_word);
        virtual void delete_by_word(const std::string & del_word); // metoda usuwajaca slowko o podanej nazwie
        virtual void delete_by_number(int word_number); // metoda usuwajaca slowka o podanym numerze w slowniku
        void show_all()const; // metoda udostepniajaca zawartosc slownika w kolejnosci numerowanej i alfabetycznej
        virtual void show_by_letters(char let_1st, char let_2nd)const; // metoda pokazujaca zawartosc slownika w zakresie liter od 'let_1st' do 'let_2nd'
        bool save_changes()const; // metoda zapisujaca wszelkie zmiany dokonane w slowniku
    private:
        std::vector<std::string> list_of_foreign_words; // lista slowek obcojezycznych
        std::vector<std::string> list_of_polish_words; // lista polskich tlumaczen slowek obcojezycznych (indeksy danego slowka obcjez. i polskiego tlumaczenia sa takie same)
        std::string file_name; // zmienna do przechowania nazwy pliku obslugujacego slownik
        void set_alfabet(); // ustawia zawartosc slownika w kolejnosci alfabetycznej
};

#endif // DICTIONARY_H