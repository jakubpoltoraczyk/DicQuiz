/* DicQuiz wersja 1.25 */

/* Klasa reprezentuje slownik wyrazow obcojezycznych, udostepniajac podstawowe mozliwosci obslugi 
   slownika takie jak m.in. dodawanie nowych slowek, usuwanie ich oraz pokazywanie zawartosci slownika
   w kolejnosci numerowanej i alfabetycznej. */

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
        Dictionary(const std::string & f_name = "dicquiz_dir/.idic_lofw_2506.txt");
        virtual ~Dictionary() {} // destruktor wirtualny, nie wykonywujacy zadnych zadan
        /* Metoda dodajaca slowko do slownika, parametry to kolejno wyraz obcojezyczny oraz ciag znakow reprezentujacych jego polskie tlumaczenie */
        virtual void add_word(const std::string & new_pol_trans, const std::string & new_for_trans);
        virtual void delete_word_by_foreign_translation(const std::string & for_trans); // metoda usuwajaca slowko o podanej nazwie
        virtual void delete_word_by_number(int word_number); // metoda usuwajaca slowka o podanym numerze w slowniku
        virtual void change_whole_translation(const std::string & pol_trans, const std::string & for_trans, int word_number); // metoda umozliwiajaca zmienienie zarowno obcojezycznego tlumaczenia jak i polskiego
        virtual void change_foreign_translation(const std::string & for_trans, int word_number); // metoda umozliwiajaca jedynie zmiane obcojezycznego tlumaczenia slowa
        virtual void change_polish_translation(const std::string & pol_trans, int word_number); // metoda umozliwiajaca jedynie zmiane polskiego tlumaczenia slowa
        void show_all_words()const; // metoda udostepniajaca zawartosc slownika w kolejnosci numerowanej i alfabetycznej
        virtual void show_words_by_letters(char letter_1st, char letter_2nd)const; // metoda pokazujaca zawartosc slownika w zakresie liter od 'let_1st' do 'let_2nd'
        bool save_changes()const; // metoda zapisujaca wszelkie zmiany dokonane w slowniku
        const std::string & get_foreign_translation(int word_number)const; // metoda zwracajaca slowko obcojezyczne o podanym numerze
        const std::string & get_polish_translation(int word_number)const; // metoda zwracajaca slowko polskie o podanym numerze
        int get_number_of_words()const; // metoda pobierajaca ilosc slow w slowniku
    private:
        std::vector<std::string> foreign_translations; // lista slowek obcojezycznych
        std::vector<std::string> polish_translations; // lista polskich tlumaczen slowek obcojezycznych (indeksy danego slowka obcjez. i polskiego tlumaczenia sa takie same)
        std::string file_name; // zmienna do przechowania nazwy pliku obslugujacego slownik
        void set_alphabetically(); // ustawia zawartosc slownika w kolejnosci alfabetycznej
        void swap_by_number(int word_number_1st, int word_number_2nd); // metoda zamieniajaca ze soba dwie pozycje na liscie slowek
};

#endif // DICTIONARY_H