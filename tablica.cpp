#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <stddef.h>
#include <stdlib.h>

using namespace std;

/*!
 * \file
 * \brief Definicja szablonu Tablica i jej metod.
 */
template <typename T>
class Tablica {

  std::size_t rozmiar;
  T * tab_danych;

public:

  /*! 
   * \brief konstruktor obiektu Tablica.
   */
  Tablica(int konstruktor=0){this->rozmiar=konstruktor; tab_danych = new T[this->rozmiar];
    for(unsigned int i=0; i<this->rozmiar; i++){tab_danych[i]=0;}}

  /*! 
   * \brief konstruktor kopiujacy obiektu Tablica.
   */
  Tablica(Tablica & Tab){ this->rozmiar=Tab.rozmiar; this->tab = new T[rozmiar];
    for(unsigned int i=0; i<this->Rozmiar(); i++){ this->tab_danych[i]=Tab[i];}}

  /*! 
   * \brief destruktor obiektu Tablica.
   */
  ~Tablica(){ if(tab_danych) delete [] tab_danych; } //destruktor sprawdzajacy przed wywolaniem czy tablica nie jest pusta

  /*! 
   * \brief Metoda zwracajaca rozmiar tablicy zapisany w czesci private obiektu Tablica.
   */
  const std::size_t Rozmiar() const {return rozmiar;}

  /*! 
   * \brief Operator indeksujacy nie-const.
   */
  T & operator [] (std::size_t i){return tab_danych[i];}

  /*! 
   * \brief Operator indeksujacy const.
   */
  const T & operator [] (std::size_t i) const {return tab_danych[i];}

  /*! 
   * \brief Funkcja zwracajaca wskaznik na pierwszy element tablicy.
   */
  T * begin(){return tab_danych;}
  
  /*! 
   * \brief Funkcja zwracajaca wskaznik na ostatni element tablicy.
   */
  T * end(){return (tab_danych+rozmiar);}

  /*! 
   * \brief Operator przypisania L - wartosci.
   */
  Tablica & operator = ( const Tablica & Tab){

    rozmiar=Tab.Rozmiar();
    for(unsigned int i=0;i<Tab.Rozmiar();i++){
      tab_danych[i]=Tab[i];
    }
    return *this;
  }

  /*! 
   * \brief Metoda zamieniajaca zawartosc dwoch tablic.
   */
  void ZamienZawartosc (Tablica & Tab){

    T * tab_save= new T[this->Rozmiar()];

    tab_save=this->tab_danych;
    this->tab_danych=Tab;
    Tab=tab_save;

    delete [] tab_save;
  }

  /*! 
   * \brief Metoda dodajaca nowy element na koncu tablicy.
   */
  void push_back(T const & wartosc){

    T * tab_save=new T[++(this->rozmiar)];
    int j=0;
    for( unsigned int i=0; i<(this->rozmiar-1);i++){
      tab_save[i]=this->tab_danych[i];
      j=i;
    }

    tab_save[j+1]=wartosc;
    delete [] tab_danych;
    tab_danych= new T[this->rozmiar];

    for(unsigned int i=0; i<(this->rozmiar);i++){
      this->tab_danych[i]=tab_save[i];
    }
    delete [] tab_save;
  }


  /*! 
   * \brief Metoda usuwajaca ostatni element tablicy.
   */
  void pop_back(){

    T * tab_save=new T[--(this->rozmiar)];

    for(unsigned int i=0;i<this->rozmiar;i++){
      tab_save[i]=this->tab_danych[i];
    }

    delete [] this->tab_danych;
    this->tab_danych = new T[this->rozmiar];

    for(unsigned int i=0;i<this->rozmiar;i++){
      this->tab_danych[i]=tab_save[i];
    }

    delete [] tab_save;
  }

  /*! 
   * \brief Przeciazenie operatora wyswietlajacego tablice <<.
   */
  friend ostream & operator << <> ( ostream &, Tablica<T> & Tab );

  /*! 
   * \brief Przeciazenie operatora wczytujacego tablice >>.
   */
  friend istream & operator >> <> ( istream &, Tablica<T> & Tab );


};


template <typename T>
ostream & operator << (ostream & StrmWy, Tablica<T> & Tab){

  for(unsigned int i=0;i<Tab.Rozmiar();i++)
    StrmWy<<Tab->tab_danych[i]<<endl;

  return StrmWy;
}


template <typename T>
istream & operator >> (istream & StrmWe, Tablica<T> & Tab){

  for(unsigned int i=0;i<Tab.Rozmiar();i++)
    StrmWe>>Tab->tab_danych[i];

  return StrmWe;
}




/*!
 *\brief
 * funkcja main(), w której moze byc przetestowany obiekt tablica 
 */
int main(){ 
cout << endl; 

  return 0;
}
