#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int tentativa(string teste,string chave,string* naotem){

    size_t posicao;
    int i;

    if(teste==chave){
        return 0;
    }
    else{                                     

        for(i=0;i<=4;i++){
            posicao=chave.find(teste[i]);
            if(posicao<=4 && posicao>=0){
                if(teste[i]==chave[i]){
                    cout << teste[posicao];
                }
                else{
                    char minusculo;
                    minusculo=tolower(teste[i]);
                    cout << minusculo;
                    
                }
            }

            else{
                cout << "*";

                if((*naotem).find(teste[i])!=string::npos){
            
                }
                else{
                    *naotem=*naotem+teste[i];
                }
                
            }

        }

        return 1;
    }
}


int main() {
    int n,i;
    int limitador=0;
    

    ifstream arquivo("palavras.txt");

    if(arquivo.is_open()){
    }
    else{
        cout << "Erro ao abrir arquivo" << endl;
        return 0;
    }

    string chave;
    
    cout << "Digite um número de 1 a 40" << endl;

    cin >> n;

    for(i=1;i<=n+1;i++){
        arquivo >> chave;
    }

    string teste;

    cin >> teste;

    while(tentativa(teste,chave,&naotem)==1){
        cout << " (" << naotem << ")" <<endl;

        limitador=limitador+1;

        if(limitador==5){

            cout << "PERDEU! " << chave;

            break;
        }

        else{
            cin >> teste;
        }
    }
    
    if(limitador!=5){
       cout << chave;
       cout << " (" << naotem << ")" <<endl;
       cout << "GANHOU!";
    }
    //apenas mais 72 horas
    cout << "brasil" << endl;
    return 0;
}
