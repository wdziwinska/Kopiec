//---------------------
//Wioletta Dziwińska
//WCY19IY5S1
//Kopiec maksimum
//---------------------


#include <iostream>

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
//    Kopiec *nowaWartosc;
//    nowaWartosc = new Kopiec;
//    nowaWartosc->liczba = liczba;

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

//void dodajWezel(Kopiec *&root, int liczba) {
//    Kopiec *nowaWartosc, *walker;
//    nowaWartosc = new Kopiec;
//    nowaWartosc->liczba = liczba;
//
//    if (root == NULL) {
//        root = nowaWartosc;
//        walker = root;
////        walker->left->liczba = NULL;
////        walker->right->liczba=NULL;
//        position++;
//    }
//    else {
//        if (position%2==0) {
//            walker->left->liczba = nowaWartosc->liczba;
//            position++;
////            nowaWartosc = nowaWartosc->next;
//        }
//        else{
//            walker->right->liczba = liczba;
//            position++;
//        }
//    }
//}
    /*
      if(tmp==NULL){
          root=nowaWartosc;
      }
      else {
          while (true) {
              if (liczba <= tmp->liczba) {
                  //jesli lewego potomka nie ma
                  if (!tmp->left) {
                      tmp->left = nowaWartosc;
                      cout<<tmp->liczba<<" ";
                      break;
                  } else {
                      tmp = tmp->left;
                      cout<<tmp->liczba<<" ";
                  }
              } else {
                  //jesli prawego potomka nie ma
                  if (!tmp->right) {
                      tmp->right = nowaWartosc;
                      cout<<tmp->liczba<<" ";
                      break;
                  } else {
                      tmp = tmp->right;
                      cout<<tmp->liczba<<" ";
                  }
              }
          }
      }
      wsk->up=tmp; //rodzicem wezla wsk jest zawsze wezel wskazywany przez tmp
 */
//  }




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

int main() {

    int liczba;
    Kopiec *root=NULL;

    cout << "Wprowadz liczbe"<<endl;
    for(int i=1; i<=6; i++) {
        cin >> liczba;
        insert(root, liczba, i);
    }
//    show(root);
    inOrder(root);

    return 0;
}
