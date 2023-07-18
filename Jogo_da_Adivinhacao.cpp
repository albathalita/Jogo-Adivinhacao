#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

/*
    Esse programa permite simular o jogo da adivinhação gerando números
    de 0 a 99 para que o usuário descubra antes das tentativas acabarem.
*/

int main(){
  /*Mensagem de abertura do jogo*/
  
  cout << "**************************************" << endl;
  cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
  cout << "**************************************" << endl << endl << endl;

  cout << "Escolha seu nível de dificuldade." << endl;
  cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

  char dificuldade = NULL;
  cin >> dificuldade;

  
  int numero_de_tentativas = 0;

  if(dificuldade == 'f' || dificuldade == 'F'){
    numero_de_tentativas = 15;
  }
  else if(dificuldade == 'm' || dificuldade == 'M'){
    numero_de_tentativas = 10;
  }
  else{
    numero_de_tentativas = 5;
  }

  // Gerando o número aleatório
  srand(time(NULL));
  const int NUMERO_SECRETO = rand() % 100;

  bool nao_acertou = true;
  int tentativas = 0;

  double pontos = 1000.0;

  
  for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
    int chute = 0;
    cout << "Tentativa " << tentativas << endl;
    cout << "Qual é o seu chute? ";
    cin >> chute;

    double pontos_perdidos = abs(chute-NUMERO_SECRETO)/2.0;
    pontos = pontos - pontos_perdidos;
    

    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    if(acertou){
      cout << "Parabéns! Você acertou o número secreto!" << endl << endl;
      nao_acertou = false;
      break;
    }
    else if(maior){
      cout << "Seu chute foi MAIOR que o número secreto." << endl << endl;
    }
    else{
      cout << "Seu chute foi MENOR que o número secreto." << endl << endl;
    }
  }

  cout << "Fim de jogo!" << endl;
  
  if(nao_acertou){
    cout << "Você perdeu! Tente novamente!" << endl;
  }
  else{
    cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
    cout.precision(2); // Para colocar quantas casas decimais querermos
    cout << fixed;     // Modificador para aparecer o número com a virgula em vez da notação científica
    cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
  }
  
}