#include <iostream>
#include <list>
#include <locale.h>
#include <queue>
#include <regex>
using namespace std;

class Doacao {
public:
    int roupas = 0;
    int calcados = 0;
    int cobertas = 0;
    int comida = 0;
   

    void adicionarItem(string item, int quantidade) {
        if (item == "roupas") {
            roupas += quantidade;
        } else if (item == "calcados") {
            calcados += quantidade;
        } else if (item == "cobertas") {
            cobertas += quantidade;
        } else if (item == "comida") {
            comida += quantidade;
        }
    }

    void removerItem(string item, int quantidade) {
        if (item == "roupas" && roupas >= quantidade) {
            roupas -= quantidade;
        } else if (item == "calcados" && calcados >= quantidade) {
            calcados -= quantidade;
        } else if (item == "cobertas" && cobertas >= quantidade) {
            cobertas -= quantidade;
        } else if (item == "comida" && comida >= quantidade) {
            comida -= quantidade;
        } else {
            cout << "Quantidade insuficiente de " << item << " para dar baixa.\n";
        }
    }

    void mostrarEstoque() {
        cout << "Estoque Atual:\n";
        cout << "Roupas: " << roupas << endl;
        cout << "Calçados: " << calcados << endl;
        cout << "Cobertas: " << cobertas << endl;
        cout << "Comida: " << comida << endl;
    }
};

class Usuario {
public:
  int id[5] = {999,999,999,999,999};
  string nome[5];
  string idade[5];
  string cidade[5];
  string bairro[5];
  string medic[5];
  string cpf[5];
  string abrigo[5];
  int cont = 0;
};

class Voluntario {
public:
  int id[5] = {999,999,999,999,999};
  string nome[5];
  string senha[5];
  string idade[5];
  string funcao[5];
  string login[5];
  string cpf [5];
  int cont = 0;
void doarItem(Doacao &doacao, string item, int quantidade) {
    doacao.removerItem(item, quantidade);
}
};

class Gestor {
public:
  int id[5] = {999,999,999,999,999};
  string nome[5];
  string senha[5];
  string idade[5];
  string funcao[5];
  string login[5];
  string cpf[5];
  int cont = 0;

void adicionarItem(Doacao &doacao, string item, int quantidade) {
  doacao.adicionarItem(item, quantidade);
}

void removerItem(Doacao &doacao, string item, int quantidade) {
  doacao.removerItem(item, quantidade);
}
};
class gestorSenior{
public:
  string login= {"senior"};
  string senha = {"senior"};
  string idade = {"45"};
  string funcao = {"Gerente Senior"};
  string cpf = {"12345678911"};
  string nome = {"Carlos"};
  int cont = 0;
void adicionarItem(Doacao &doacao, string item, int quantidade) {
  doacao.adicionarItem(item, quantidade);
}

void removerItem(Doacao &doacao, string item, int quantidade) {
  doacao.removerItem(item, quantidade);
}
};
//cout <<"Fale um pouco do problema que está ocorrendo\n:";
    //  cin >> user.texto[id];
    //  cout << user.texto[id]; 