#include "App.h"
#include <limits>
#include <regex>

void clear() // função que limpa a tela1
{
  cout << "\033[2J\033[1;1H";
};

bool isNumero(const std::string& str) {
    std::regex numeroRegex("^[0-9]+$");
    return std::regex_match(str, numeroRegex);
}

void telaGestorDoacao(gestorSenior &senior, Doacao &doacao) {
  int opcao;
  string item;
  int quantidade;
  string quantidadeStr;

  

  do {
      cout << "1 - Adicionar Item\n";
      cout << "2 - Remover Item\n";
      cout << "3 - Mostrar Estoque\n";
      cout << "4 - Voltar\n";
      cin >> opcao;

      switch (opcao) {
      case 1:
          cout << "Qual o tipo de sua doação (Roupas, Calçados, Cobertas ou Comida): ";
          cin >> item;
          cout << "Quantidade: ";
          cin >> quantidadeStr;
        if (!isNumero(quantidadeStr)) {
            std::cout << "\033[0;31mPor favor, insira um número válido.\033[0m" << std::endl;
            return;
        }
          quantidade = std::stoi(quantidadeStr);
          senior.adicionarItem(doacao, item, quantidade);
          break;
      case 2:
          cout << "Qual item deseja remover (Roupas, Calçados, Cobertas ou Comida): ";
          cin >> item;
          cout << "Quantidade: ";
          cin >> quantidade;
          senior.removerItem(doacao, item, quantidade);
          break;
      case 3:
          doacao.mostrarEstoque();
          break;
      case 4:
          return;
      default:
          cout << "Opção inválida!\n";
      }
  } while (true);
}

void telaVoluntarioDoacao(Voluntario &voluntario, Doacao &doacao) {
  int opcao;
  string item;
  int quantidade;

  do {
      cout << "1 - Doar Item\n";
      cout << "2 - Mostrar Estoque\n";
      cout << "3 - Voltar\n";
      cin >> opcao;

      switch (opcao) {
      case 1:
          cout << "Item (roupas, calcados, cobertas, comida): ";
          cin >> item;
          cout << "Quantidade: ";
          cin >> quantidade;
          voluntario.doarItem(doacao, item, quantidade);
          
          break;
      case 2:
          doacao.mostrarEstoque();
          break;
      case 3:
          return;
      default:
          cout << "Opção inválida!\n";
      }
  } while (true);
}

void listarDesabrigados(Usuario &user) {
  for (int i = 0; i < 5; i++) {
    cout << i + 1 << "- Nome: " << user.nome[i] << endl;
    cout << i + 1 << "- Idade: " << user.idade[i] << endl;
    cout << i + 1 << "- CPF: " << user.cpf[i] << endl;
    cout << i + 1 << "- Medicamento: " << user.medic[i] << endl;
    cout << i + 1 << "- Cidade: " << user.cidade[i] << endl;
    cout << i + 1 << "- Bairro: " << user.bairro[i] << endl;
    cout << "-----------------------" << endl;
  }
}

void listargestor(Gestor &gestor) {
  for (int i = 0; i < 5; i++) {
    cout << i + 1 << "- Nome: " << gestor.nome[i] << endl;
    cout << i + 1 << "- Idade: " << gestor.idade[i] << endl;
    cout << i + 1 << "- CPF: " << gestor.cpf[i] << endl;
    cout << i + 1 << "- nome de usuario: " << gestor.login[i] << endl;
    }
}

void listarVolunt(Voluntario &volunt) {
  for (int i = 0; i < 5; i++) {
    cout << i + 1 << "- Nome: " << volunt.nome[i] << endl;
    cout << i + 1 << "- Idade: " << volunt.idade[i] << endl;
    cout << i + 1 << "- CPF: " << volunt.cpf[i] << endl;
    cout << i + 1 << "- Login: " << volunt.login[i] << endl;
    cout << "-----------------------" << endl;
  }
};

void cadastroUser(Usuario &user, Voluntario &volunt, Gestor &gestor, int id) {
  
  string cinNome;
  string cinCPF;
  string cinidade;
  int opc2;
  int opc[5];
  string cinCidade;
  string cinBairro;
  string cinMedic;
  string opcMedic;
  bool loop;
  regex cpfRegex("^[0-9]{11}$"); // comando para limitar letra/número
  regex nomeRegex("^[A-Za-z]+(\\s[A-Za-z]+)*$");
  regex idadeRegex("^(0|[1-9][0-9]?|1[01][0-9]|120)$");

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  clear();
  
  cout << "\033[0;32m***** CADASTRO DESABRIGADO *****\033[0m" << endl << endl;
  
  do { // função validar nome
  loop = false;
  cout << "Qual seu nome? ";
  getline (cin >> ws, cinNome);
   if (!regex_match(cinNome, nomeRegex)) {
    cout << "\033[0;31mNome Inválido!\033[0m\n";
    loop = true;
    continue; 
    }
  } while (loop);
  do { // função validar idade
  loop = false;
  cout << "Qual sua idade: " ;
  cin >> cinidade;
   if (!regex_match(cinidade, idadeRegex)) {
    cout << "\033[0;31mIdade Inválida!\033[0m\n";
    loop = true;
    continue;
   }
  } while (loop);
  bool cpfRepetido;
  do { // função validar cpf
   cpfRepetido = false;
    cout << "CPF: ";
    cin >> cinCPF;
    if (!regex_match(cinCPF, cpfRegex)) {
     cout << "\033[0;31mCPF inválido, insira seu CPF novamente!\033[0m\n";
     cpfRepetido = true;
     continue; 
    }
      // Verificar se o CPF já foi cadastrado
      for (int i = 0; i < 5; i++) {
        if (cinCPF == gestor.cpf[i] || cinCPF == volunt.cpf[i]) {
         cout << "Pessoa já cadastrada\n";
         cpfRepetido = true;
        break; // Sair do loop se encontrar um CPF repetido
        }
      }
  } while (cpfRepetido);
  do { // função validar cidade
  loop = false;
  cout << "Qual cidade você mora? ";
  getline (cin >> ws, cinCidade);
   if (!regex_match(cinCidade, nomeRegex)) {
    cout << "\033[0;31mCidade não encontrada, digite novamente!\033[0m\n";
    loop = true;
    continue; 
    }
  } while (loop);
  do { // função validar bairro
  loop = false;
  cout << "Qual seu bairro? ";
  getline (cin >> ws, cinBairro);
   if (!regex_match(cinBairro, nomeRegex)) {
    cout << "\033[0;31mBairro não encontrado, digite novamente!\033[0m\n";
    loop = true;
    continue; 
    }
  } while (loop);
  
  cout << "Medicamento controlado:  " << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Não" << endl;
  cin >> opc2;
  switch (opc2) {
  case 1:
    cout << "Qual o medicamentos? " << endl;
    getline(cin,cinMedic);
    break;
  case 2:
    cinMedic = "Não";
    break;
  }
    
  user.nome[user.cont] = cinNome;
  user.idade[user.cont] = cinidade;
  user.cpf[user.cont] = cinCPF;
  user.medic[user.cont] = cinMedic;
  user.cidade[user.cont] = cinCidade;
  user.bairro[user.cont] = cinBairro;
  user.cont++;
  clear();
}; 

void cadastroVolunt(Voluntario &volunt, Gestor &gestor) {
  string cinNome;
  string cinidade;
  string cinCPF;
  string cinLogin;
  string cinSenha;
  bool loop;
  regex cpfRegex("^[0-9]{11}$"); // comando para limitar letra/número
  regex nomeRegex("^[A-Za-z]+(\\s[A-Za-z]+)*$");
  regex idadeRegex("^(0|[1-9][0-9]?|1[01][0-9]|120)$");
  
  cout << "\033[0;32m***** CADASTRO VOLUNTARIO *****\033[0m" << endl << endl;
  do { // função validar nome
  loop = false;
  cout<<"Qual seu nome? ";
  getline (cin >> ws, cinNome);
   if (!regex_match(cinNome, nomeRegex)) {
    cout << "\033[0;31mNome Inválido!\033[0m\n";
    loop = true;
    continue; 
   }
  } while (loop);
  do { // função validar idade
  loop = false;
  cout << "Qual sua idade: " ;
  cin >> cinidade;
    if (!regex_match(cinidade, idadeRegex)) {
      cout << "\033[0;31mIdade Inválida!\033[0m\n";
      loop = true;
      continue; // Repetir a solicitação da Idade
    }
  } while (loop);
  bool cpfRepetido;
  do { // função validar cpf
    cpfRepetido = false;
    cout << "CPF: ";
    cin >> cinCPF;
    if (!regex_match(cinCPF, cpfRegex)) {
     cout << "\033[0;31mCPF inválido, insira seu CPF novamente!\033[0m\n";
     cpfRepetido = true;
     continue; // Repetir a solicitação do CPF
    }
      // Verificar se o CPF já foi cadastrado
      for (int i = 0; i < 5; i++) {
       if (cinCPF == gestor.cpf[i] || cinCPF == volunt.cpf[i]) {
        cout << "Pessoa já cadastrada\n";
        cpfRepetido = true;
        break; // Sair do loop se encontrar um CPF repetido
       }
      }
  } while (cpfRepetido);
  bool loginRepetido; // verificar se tem um 
    do {
      loginRepetido = false;
      cout << "Digite seu usuário para login: ";    
      cin >> cinLogin;
      for(int i=0; i<5; i++){
         if (cinLogin== volunt.login[i]|| cinLogin == gestor.login[i]){
          cout << "Login já cadastrado" << endl;
          loginRepetido = true;
          break;
        }
      }
    } while(loginRepetido);    // Atribuir os valores aos arrays da classe Voluntario
  cout << "Digite uma senha: ";
  cin >> cinSenha;

    volunt.senha[volunt.cont] = cinSenha;
    volunt.nome[volunt.cont] = cinNome;
    volunt.idade[volunt.cont] = cinidade;
    volunt.cpf[volunt.cont] = cinCPF;
    volunt.login[volunt.cont] = cinLogin;
    volunt.cont++;
};

void cadastroGestor(Gestor &gestor, Voluntario volunt) {
 
  string cinCPF;
  string cinNome;
  string cinidade;
  int opc;
  string cinLogin;
  regex cpfRegex("^[0-9]{11}$"); // comando para limitar letra/número
  regex nomeRegex("^[A-Za-z]+(\\s[A-Za-z]+)*$");
  regex idadeRegex("^(0|[1-9][0-9]?|1[01][0-9]|120)$");
  
  clear();
  cout << "\033[0;32m***** CADASTRO GESTOR *****\033[0m" << endl <<endl;
  bool loop;
  do { // função validar nome
  loop = false;
  cout << "Nome para cadastro: ";
  getline (cin >> ws, cinNome);
  if (!regex_match(cinNome, nomeRegex)) {
      cout << "\033[0;31mNome Inválido!\033[0m\n";
      loop = true;
      continue; 
  }
  } while (loop);
  bool cpfRepetido;
  do { // função validar cpf
      cpfRepetido = false;
      cout << "CPF: ";
      cin >> cinCPF;
    if (!regex_match(cinCPF, cpfRegex)) {
        cout << "\033[0;31mCPF inválido, insira seu CPF novamente!\033[0m\n";
        cpfRepetido = true;
        continue; // Repetir a solicitação do CPF
    }
      // Verificar se o CPF já foi cadastrado
      for (int i = 0; i < 5; i++) {
          if (cinCPF == volunt.cpf[i]|| cinCPF == gestor.cpf[i]) {
              cout << "Pessoa já cadastrada\n";
              cpfRepetido = true;
              break; // Sair do loop se encontrar um CPF repetido
          }
      }
  } while (cpfRepetido);
  do { // função validar idade
  loop = false;
  cout << "Qual sua idade: " ;
  cin >> cinidade;
    if (!regex_match(cinidade, idadeRegex)) {
        cout << "\033[0;31mIdade Inválida!\033[0m\n";
        loop = true;
        continue; 
    }
  } while (loop);
  cout << "Escreva um nome de usuario: ";
  cin >> cinLogin;
  for (int i = 0; i < 5; i++) {
    if (cinLogin == gestor.login[i] || cinLogin == volunt.login[i]) {
      while (cinLogin == gestor.login[i] || cinLogin == volunt.login[i]) {
        cout << "\033[0;31mo Nome de Usuario já existe\n";
        cout << "Nome para cadastro:";
        cin >> cinLogin;
      }
    } else {
      gestor.login[gestor.cont] = cinLogin;
      break;
    }
  }
  cout << "Senha: ";
  cin >> gestor.senha[gestor.cont];
  
  gestor.cpf[gestor.cont] = cinCPF;
  gestor.nome[gestor.cont] = cinNome;
  gestor.idade[gestor.cont] = cinidade;
  gestor.id[gestor.cont] = gestor.cont;
  gestor.cont++;
  clear();
};

void telaGestor(Usuario &user, Voluntario &volunt, Gestor &gestor, int id) {
  int opc = 0;
  bool loop = true;

  do {
    cout << "\033[0;32m***** MENU GESTOR *****\033[0m" << endl<<endl;
    cout << "1 - Cadastrar Voluntários" << endl;
    cout << "2 - Cadastrar Doações\n";
    cout << "3 - Listar Voluntários" << endl;
    cout << "4 - Listar Desabrigados\n";
    cout << "5 - Informações do estoque\n";
    cout << "6 - Sair\n";
    cin >> opc;

    switch (opc) {
    case 1:
      cadastroVolunt(volunt, gestor);
      break;
    //case 2:
      //cadastroDoacao(volunt, gestor);
      break;
    case 3:
      listarVolunt(volunt);
      break;
    case 4:
      listarDesabrigados(user);
      break;
    case 6:
      loop = false;
      break;
    default:
      cout << "\033[0;31mComando invalido!";
    }
  } while (opc != 6);
};

void telaVolunt(Voluntario volunt, Gestor gestor, Usuario user,Doacao doacao){
  int opc = 0;
  bool loop = true;
 

  do {
    cout << "\033[0;32m***** MENU VOLUNTÁRIO *****\033[0m" << endl<<endl;
    cout << "1 - Cadastrar Desabrigados" << endl;
    cout << "2 - Cadastrar Doações\n"; // pendente parte do estoque
    cout << "3 - Listar Desabrigados\n";
    cout << "4 - Listar Doações necessárias\n"; // pendente parte do estoque
    cout << "5 - Sair\n";
    cin >> opc;

    switch (opc) {
     case 1:
     cadastroUser( user, volunt,gestor,0);
     break;
     case 2:
     telaVoluntarioDoacao(volunt,doacao);
     break;
     case 3:
     listarDesabrigados(user);
     break;
  /* case 4:
     função puxar estoque */
     case 5:
     loop = false;
     break;
     default:
      cout << "\033[0;31mComando invalido!";
     }
  } while (opc != 5);
};

void telaSenior(gestorSenior &senior, Gestor &gestor,Voluntario &volunt,Usuario &user,Doacao doacao){
  int op;
  do{
    cout << "\033[0;32m***** MENU SENIOR *****\033[0m\n\n";
    cout << "1 - Cadastrar Gestor"<<endl;
    cout << "2 - Cadastrar Doações"<<endl;
    cout << "3 - Cadastrar Voluntario"<<endl;
    cout << "4 - Cadastrar Desabrigado"<<endl;
    cout << "5 - Listar Voluntario"<<endl;
    cout << "6 - Listar Gestor" <<endl ; 
    cout << "7 - Listar Desabrigado"<<endl;
    cout << "8 - Sair"<<endl;
  
    cin >> op;
    switch(op){
      case 1:
        cadastroGestor(gestor,volunt);
        break;
      case 2:
        telaGestorDoacao(senior,doacao);
        break;
      case 3:
        cadastroVolunt(volunt,gestor);
        break;
      case 4:
        cadastroUser(user, volunt, gestor, 0);
        break;
      case 5:
        listarVolunt(volunt);
      break;
      case 6:
      listargestor(gestor);
      break;
      case 7:
      listarDesabrigados(user);
      break;
      case 8:
      break;
      default:
        cout <<"Comando invalido!\n";
    }
  }while (op!=8);
};

void login(Voluntario &volunt, Gestor &gestor, Usuario &user,gestorSenior &senior,Doacao doacao) {

  string login;
  string senha;
  bool logado = false;
  clear();
  cout << "Login: ";
  cin >> login;
  cout << "Senha: ";
  cin >> senha;
  for (int i = 0; i < 5; i++) {
    if (login == volunt.login[i] && senha == volunt.senha[i]) {

      logado = true;
      telaVolunt(volunt, gestor,user,doacao);
      break;
    } else if (login == gestor.login[i] && senha == gestor.senha[i]) {

      logado = true;
      telaGestor(user, volunt, gestor, i);
      break;
    } else if (login == senior.login && senha == senior.senha) {

    logado = true;
    telaSenior(senior,gestor,volunt,user,doacao);
    break;
  };
  }
  if (!logado) {
    cout << "\033[0;31mUsuário não encontrado, tente novamente!\n";
  }
};

void cadastro(Usuario &user, Voluntario &volunt, Gestor &gestor){
  int opc;
  bool loop = true;
  
  cout << "\033[0;32m******** Selecione seu usuário para login: ********\033[0m\n\n"
     << "1 - Desabrigado:\n"
     << "2 - Voluntario:\n"
     << "3 - Gestor:\n"
     << "4 - Sair:\n";
  cin >> opc;
  do{ 
  switch(opc){
    case 1:
      cadastroUser(user, volunt, gestor, 0);
      loop = false;
      break;
    case 2:
      cadastroVolunt(volunt, gestor);
      loop = false;
      break;
    case 3:
      cadastroGestor(gestor, volunt);
      loop = false;
      break;
    case 4:
      loop = false;
     break;
    default:
    cout <<  "Comando incorreto\n";
    break;
  }
  }while (loop == true);
};

void App::start() { // em c++ precisar construir o metod fora da classe
  
  Usuario user;
  Voluntario volunt;
  Gestor gestor;
  gestorSenior senior;
  Doacao doacao;
  int opcao ;
 
  do {
    cout << "\033[0;32m******** MÃOS SOLIDÁRIAS! ********\033[0m\n\n"
         << "1 - Login:\n"
         << "2 - Listar Desabrigados:\n"
         << "3 - Sair:\n";
         cin >> opcao;
        switch(opcao){
          case 1:
            login(volunt, gestor, user,senior,doacao);
            break;
          case 2: // opção para sair do sistema.
            listarDesabrigados(user);
            break;
          case 3 :
            break;
          default:
            cout << "Comando invalido!" << endl;
          }
        } while (opcao != 3);
      }

void App::Finish() { cout << "FIM DO SISTEMA"; };