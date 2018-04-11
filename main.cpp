#include <list>
#include <iostream>
#include <windows.h>
using namespace std;
struct krawedzie
{
    int waga;
    int numer;
    int w1;
    int w2;
    int wagatest[30];


};
/*
struct wierzcholki
{
    int numer;
    int numer2;


};
*/
bool compare(krawedzie* first, krawedzie* second){
    if (first->waga < second->waga) return true;
    return false;
}

int main()
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    int n,l_w,w,i,p=1;
   // krawedzie tab[100];
    cout << "Ile chcesz wierzcholkow? ";
    cin >> l_w;
//    list<wierzcholki*>lista_w;
    list<krawedzie*>lista_k;
    lista_k.clear();
    list<krawedzie*>::iterator it;
    //list<wierzcholki*>::iterator it2;

    cout << "Ile chcesz krawedzi? ";
    cin >> i;
    n=0,w=0;
    int ile,wazy,n_w;
    krawedzie* element;
    //wierzcholki* las;
    while(n<i)
    {
      element = new krawedzie;
       //las = new wierzcholki;
    cout << "Podaj z iloma wierzcholkami ma sie laczyc wierzcholek nr " << p << endl;
    cin >> ile;
    for (int z=1;z<ile+1;z++)
    {
          element = new krawedzie;
          //las = new wierzcholki;
        element->numer = ++w;
        element->w1=p;

//        tab[z+p*8].w2 = p+z;
        cout << "Wierzcholek nr " << p << " laczy sie z nr ";

        cin >> n_w;
        cout << " i ma wage: ";
         element->w2=n_w;
        cin >> wazy;
       // tab[z+p*8].waga = wazy;
        element->waga=wazy;
        n++;
       // las->numer = p;
       // las->numer2=p+z;
        lista_k.push_back(element);
       // lista_w.push_back(las);

    }

p++;




    }



    //sortowanie
    cout << "Posortowalem!" << endl;
    lista_k.sort(compare);
int suma=0;
    // wyswietlenie skladnikow listy
   for( it=lista_k.begin(); it!=lista_k.end(); ++it )
   {
       cout<< "Krawedz numer: " << (*it)->numer <<'\n';
     cout<< "Waga: " << (*it)->waga <<'\n';
     cout<< "W1: " << (*it)->w1 <<'\n';
     cout<< "W2: " << (*it)->w2 <<'\n';

   }
      // wyswietlenie skladnikow listy

    cout << "Drzewo rozpinajace to: " << endl;
       int a=0;
       int zbior[100];
       int ost=1;
       bool jeden = false;
       bool dwa = false;
   for( it=lista_k.begin(); it!=lista_k.end(); ++it)
   {
       zbior[a]=(*it)->w1;
       zbior[a+1]=(*it)->w2;
       for(int i=0;i < a+1;i++)
       {
        if (((*it)->w1==zbior[i] && dwa != true) || ((*it)->w2==zbior[i] && dwa != true ) )
       {
           jeden = true;
       }
       if (((*it)->w2==zbior[i] && jeden == true) )
           {
                dwa = true;
                jeden = false;
           }

       }
          if (dwa == false || (ost == l_w-1 && dwa == false))
           {
                cout << "W" << (*it)->w1 << "-->" << "W" << (*it)->w2;
        cout << " waga: " << (*it)->waga << endl;
        suma = suma + (*it)->waga;
        ost++;

           }
          if (dwa == true)
   {
       jeden = false;
    dwa = false;
    }
a=a+2;
   }

cout << endl << "Suma drzewa rozpinajacego " << suma << endl;




}
