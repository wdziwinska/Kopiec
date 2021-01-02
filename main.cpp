//---------------------
//Wioletta Dziwińska
//WCY19IY5S1
//Kopiec maksimum
//---------------------


#include <iostream>
#include <fstream>

using namespace std;

int position=1;

struct Kopiec{
    int liczba;
    Kopiec *next;
    Kopiec *left;
    Kopiec *right;
};

Kopiec *walker = NULL;

void swap(Kopiec *a, Kopiec *b){
    int tmp=a->liczba;
    a->liczba=b->liczba;
    b->liczba=tmp;
}

int size(Kopiec *root, Kopiec *strona){
    int size=0;
    Kopiec *tmp;
    if(root!=NULL){
        while(strona->left!=NULL){
            tmp=tmp->left->next;
            size++;
        }
    }
    else{
        size=0;
    }
}

void insert(Kopiec *&root, int liczba, int i) {

    if (root == NULL) {
        root=new Kopiec;
        root->left=NULL;
        root->right=NULL;
        root->liczba=liczba;
    }
    else {
        if(i%2==0 && root->left == NULL) {
            insert(root->left, liczba, i);
            if (root->left->liczba > root->liczba) {
                swap(root->liczba, root->left->liczba);
            }
        }
        else if((i/2)%2==0) {
            if (i%2 == 0) {
                insert(root->left->left, liczba, i);
                if (root->left->left->liczba > root->left->liczba) {
                    swap(root->left->left->liczba, root->left->liczba);
                }
            }
            else {
                insert(root->left->right, liczba, i);
                if (root->left->right->liczba > root->left->liczba) {
                    swap(root->left->right->liczba, root->left->liczba);
                }
            }
            if (root->left->liczba > root->liczba) {
                swap(root->left->liczba, root->liczba);
            }
        }
        else if(i%2!=0 && root->right == NULL) {
            insert(root->right, liczba, i);
            if (root->right->liczba > root->liczba) {
                swap(root->liczba, root->right->liczba);
            }
        }
        else if((i/2)%2!=0){
            if(i%2==0){
                insert(root->right->left, liczba, i);
                if (root->right->left->liczba > root->right->liczba) {
                    swap(root->left->left->liczba, root->right->liczba);
                }
            }
            else{
                insert(root->right->right, liczba, i);
                if (root->right->right->liczba > root->right->liczba) {
                    swap(root->left->right->liczba, root->right->liczba);
                }
            }
            if (root->right->liczba > root->liczba) {
                swap(root->right->liczba, root->liczba);
            }
        }
    }
}

//void show(Kopiec *root){
//    Kopiec *tmp = root;
//
//    cout<<"wyswietlanie"<<endl;
//    while(tmp->liczba!=NULL){
////        if(tmp->left!=NULL){
//            cout<<tmp->liczba<<endl;
//            tmp=tmp->left;
////        }
//    }
//}
//funkcja znajduje najwieksza wartosc
Kopiec* znajdzNajwiekszy(Kopiec* lewy, Kopiec* prawy){
    if(lewy->liczba<=prawy->liczba){
        return prawy;
    }
    else{
        return lewy;
    }
}

// Funkcja szuka w drzewie BST węzła o zadanym kluczu. Jeśli go znajdzie, zwraca jego wskazanie. Jeżeli nie, to zwraca wskazanie puste.
Kopiec * szukajWezelL (Kopiec *&root, int wartosc ){

    if(root){
        if(wartosc == root->liczba){
            cout<<"Znaleziono w L"<<endl;
            return root;
        }
        else if(root->left!=NULL && root->left && wartosc != root->liczba){
            szukajWezelL(root->left, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajWezelP (Kopiec *&root, int wartosc ){
    if(root){
        if(wartosc == root->liczba){
            cout<<"Znaleziono w P"<<endl;
            return root;
        }
        else if(root->right!=NULL && wartosc != root->liczba){
            szukajWezelP(root->right, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajWezelLL (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Znaleziono w LL"<<endl;
            return root;
        }
        else if(root->left!=NULL && root->left->left!=NULL && wartosc != root->left->liczba){
            szukajWezelLL(root->left->left, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajWezelLP (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Znaleziono w LP"<<endl;
            return root;
        }
        else if(root->left!=NULL && root->left->right!=NULL && wartosc != root->left->liczba){
            szukajWezelLP(root->left->right, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajWezelPL (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Znaleziono w PL"<<endl;
            return root;
        }
        else if( root->right!=NULL && root->right->left!=NULL && wartosc != root->right->liczba){
            szukajWezelPL(root->right->left, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajWezelPP (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Znaleziono w PP"<<endl;
            return root;
        }
        else if(root->right!=NULL && root->right->right!=NULL && wartosc != root->right->liczba){
            szukajWezelPP(root->right->right, wartosc);
        }
    }
    else{
        return NULL;
    }
}

// Funkcja szuka w drzewie BST węzła o zadanym kluczu. Jeśli go znajdzie, zwraca jego wskazanie. Jeżeli nie, to zwraca wskazanie puste.
Kopiec * szukajOstataniL (Kopiec *&root, int wartosc ){

    if(root){
        if(wartosc == root->liczba){
            cout<<"Usuwam L "<<endl;
            delete root;
            root=NULL;
        }
        else if(root->left!=NULL && wartosc != root->liczba){
            szukajOstataniL(root->left, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajOstatniP (Kopiec *&root, int wartosc ){
    if(root){
        if(wartosc == root->liczba){
            cout<<"Usuwam P "<<endl;
            delete root;
            root=NULL;        }
        else if(root->right!=NULL && wartosc != root->liczba){
            szukajOstatniP(root->right, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajOstatniLL (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Usuwam LL "<<endl;
            delete root;
            root=NULL;
        }
        else if(root->left!=NULL && root->left->left!=NULL && wartosc != root->left->liczba){
            szukajOstatniLL(root->left->left, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajOstatniLP (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Usuwam LP "<<endl;
            delete root;
            root=NULL;
        }
        else if(root->left!=NULL && root->left->right!=NULL && wartosc != root->left->liczba){
            szukajOstatniLP(root->left->right, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajOstatniPL (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Usuwam PL "<<endl;
            delete root;
            root=NULL;
        }
        else if(root->right!=NULL && root->right->left!=NULL && wartosc != root->right->liczba){
            szukajOstatniPL(root->right->left, wartosc);
        }
    }
    else{
        return NULL;
    }
}

Kopiec * szukajOstatniPP (Kopiec *&root, int wartosc ){
    if(root){
        if(root!=NULL && wartosc == root->liczba){
            cout<<"Usuwam PP "<<endl;
            delete root;
            root=NULL;
        }
        else if(root->right!=NULL && root->right->right!=NULL && wartosc != root->right->liczba){
            szukajOstatniPP(root->right->right, wartosc);
        }
    }
    else{
        return NULL;
    }
}

// funkcja usuwa wybrany wezel
void usuwanieWezlaPoWartosc(Kopiec *&root, int wartosc, int ostatniElement){
    if(wartosc!=ostatniElement) {
        Kopiec *tmp;
        tmp = szukajWezelL(root, wartosc);
        if (tmp == NULL) {
            tmp = szukajWezelP(root, wartosc);
        }
        if (tmp == NULL) {
            tmp = szukajWezelLL(root, wartosc);
        }
        if (tmp == NULL) {
            tmp = szukajWezelLP(root, wartosc);
        }
        if (tmp == NULL) {
            tmp = szukajWezelPL(root, wartosc);
        }
        if (tmp == NULL) {
            tmp = szukajWezelPP(root, wartosc);
        }
        szukajOstataniL(root, ostatniElement);
        szukajOstatniP(root, ostatniElement);
        szukajOstatniLL(root, ostatniElement);
        szukajOstatniLP(root, ostatniElement);
        szukajOstatniPL(root, ostatniElement);
        szukajOstatniPP(root, ostatniElement);


        if (root != NULL) {
            tmp->liczba = ostatniElement;

            while (tmp->left != NULL) {
                if (tmp->left->liczba > tmp->liczba) {
                    swap(tmp->liczba, tmp->left->liczba);
                }
                tmp = tmp->left;
            }
        }
    }
    else{
        szukajOstataniL(root, ostatniElement);
        szukajOstatniP(root, ostatniElement);
        szukajOstatniLL(root, ostatniElement);
        szukajOstatniLP(root, ostatniElement);
        szukajOstatniPL(root, ostatniElement);
        szukajOstatniPP(root, ostatniElement);
    }
}

void inOrder (Kopiec *&root){
    if(root){
        inOrder(root->left);
        cout<<root->liczba<<",";
        inOrder(root->right);
    }
}

void postOrder (Kopiec *&liczba){
    if(liczba){
        postOrder(liczba->left);
        postOrder(liczba->right);
        cout<<liczba->liczba<<",";
    }
}

void preOrder (Kopiec *&liczba){
    if(liczba){
        cout<<liczba->liczba<<",";
        preOrder(liczba->left);
        preOrder(liczba->right);
    }
}

//funkcja oblicza wysokosc drzewa
int height(Kopiec* wezel){

    if ( !wezel ) {
        return 0;
    }
    return 1 + max( height( wezel->left ), height( wezel->right ) );
}

//funkcja dodaje do tablic wyjsciowych kolejne wezel, odleglosci i ukosniki
void rysujWezel( string wyjscie[], string polaczenieWyzej[], Kopiec* wezel, int level, int rozmiar, char polaczenieZnak){

    //sprawdzenie czy drzewo nie jest puste, jesli jest to funkcja sie konczy
    if (!wezel) {
        return;
    }

    rozmiar = max( rozmiar, 0 );

    // zapelnia wszystko po lewej stronie
    if ( wezel->left ){
        //wywolanie rekurencyjne funkcji rysujWezel
        rysujWezel( wyjscie, polaczenieWyzej, wezel->left, level + 1, rozmiar - to_string( wezel->left->liczba ).size() - 2, '/');
        //ustalenie, ktora z podanych liczb jest wieksza i zapisanie jej do zmiennej rozmiar
        rozmiar = max( rozmiar, (int)wyjscie[level+1].size() );
    }

    int space = rozmiar - wyjscie[level].size();

    if ( space > 0 ){
        //dodanie spacji, czyli odleglosci pomiedzy wezlami
        wyjscie[level] += string( space, ' ' );
    }
    //zapisanie do tablicy wyjscie dwoch znakow odstepu oraz aktualnego wezla w postaci stringa
    wyjscie[level] += ' ' + to_string( wezel->liczba) + ' ';

    //warunek sprawdzajacy czy ukosnik zostal juz dodany
    if ( polaczenieZnak == '/' ) {
        rozmiar = wyjscie[level].size() - 1;
    }
    //ustalenie wolnej przestrzeni
    space = rozmiar - polaczenieWyzej[level].size();

    if ( space > 0 ){
        //dodanie do tablicy polaczenieWyzej odstepow
        polaczenieWyzej[level] += string( space, ' ' );
    }
    //dodanie ukosnika
    polaczenieWyzej[level] += polaczenieZnak;

    // uzuepelnia po prawej stronie
    rozmiar = wyjscie[level].size();
    rysujWezel( wyjscie, polaczenieWyzej, wezel->right, level + 1, rozmiar, '\\');
}

//funkcja wyswietla w konsoli drzewo
void draw(Kopiec *&root){

    int h = height( root );
    string wyjscie[h];
    string polaczeniePowyzej[h];

    rysujWezel( wyjscie, polaczeniePowyzej, root, 0, 0, ' ');

    for (int i = 0; i < h; i++){
        if (i){
            cout << polaczeniePowyzej[i] << '\n';
        }
        cout << wyjscie[i] << '\n';
    }
}

int main() {

    int liczba;
    Kopiec *root=NULL;
    int usuwany;
    char wybor;
    int ileLiczb;
    int i=1;
    int ostatniElement, poprzedniElement;

    cout<<"Wybierz sposob wczytania danych"<<endl<<"\"k\"-klawiatura, \"p\"-plik"<<endl;
    cin>>wybor;

    switch(wybor){
        case 'k':
            cout<<"Ile ma byc liczb w drzewie?"; cin>>ileLiczb;
            cout<<"Podaj liczby jakie chcesz wstawic do drzewa"<<endl;
            for(i=i; i<=ileLiczb; i++) {
                cin>>liczba;
                insert(root, liczba, i);
                ostatniElement=liczba;
            }
            cout<<endl<<endl;
            break;
        case 'p':
            fstream plik;
            plik.open("we.txt", ios::in);
            if(!plik.good()){
                cout<<"blad podczas wczytywania danych z pliku"<<endl;
            }
            else{
                while (!plik.eof()) {
                    plik >> liczba;
                    ostatniElement=liczba;
                    insert(root, liczba, i);
                    i++;
                    ileLiczb++;
                }
                plik.close();
            }
            break;
    }
    cout<<"ostatni element " <<ostatniElement<<endl;

    inOrder(root);
    cout<<endl<<"Wprowadz numer wezla, ktory chcesz usunac"<<endl;
    cin>>usuwany;
    usuwanieWezlaPoWartosc(root, usuwany, ostatniElement);
    inOrder(root);
    cout<<endl<<endl;
    draw(root);

    return 0;
}
