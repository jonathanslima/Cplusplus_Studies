#include <iostream>
#include <cctype>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "************************************" << endl;
	cout << "* JOGO DA ADVINHACAO *" << endl;
	cout << "" << endl;

	cout << "Escolha o nivel de dificuldade:" << endl;
	cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

	char nivelDificuldade;
	cin >> nivelDificuldade;
	int numero_de_tentativas;

	nivelDificuldade = toupper(nivelDificuldade);

	if (nivelDificuldade == 'F')
	{
		numero_de_tentativas = 15;
	}
	else if (nivelDificuldade == 'M')
	{
		numero_de_tentativas = 10;
	}
	else
	{
		numero_de_tentativas = 5;
	}

	cout << "Voce tem " << numero_de_tentativas << " tentativas!" << endl;
	srand(time(0));
	const int NUMBER = rand() % 100;

	int naoAcertou = true;
	int tentativas = 0;
	double pontos = 1000.0;

	for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
	{
		int chuteUser;
		cout << "Chute um numero: " << endl;
		cin >> chuteUser;
		cout << "" << endl;
		cout << "/ ******************************************** /" << endl;
		cout << "Voce chutou o numero: " << chuteUser << endl;
		cout << "Tentivas: " << tentativas << "/10" << endl;

		bool acertou = chuteUser == NUMBER;
		bool errou = chuteUser > NUMBER;
		double pontos_perdidos = abs(chuteUser - NUMBER) / 2.0;
		pontos = pontos - pontos_perdidos;

		if (!chuteUser)
		{
			cout << "Voce precisa digitar um numero!" << endl;
		}
		else if (acertou)
		{
			cout << "Voce acertou! Parabens!" << endl;
			naoAcertou = false;
			break;
		}
		else if (errou)
		{
			cout << "O valor do seu chute e MAIOR que o numero secreto" << endl;
			cout << "/ ******************************************** /" << endl;
			cout << "" << endl;
		}
		else
		{
			cout << "O valor do seu chute e MENOR que o numero secreto" << endl;
			cout << "/ ******************************************** /" << endl;
			cout << "" << endl;
		}
	}

	cout << "" << endl;
	cout << "************************************" << endl;
	cout << "* FIM DO JOGO *" << endl;
	cout << "************************************" << endl;
	cout << "" << endl;

	if (naoAcertou)
	{
		cout << "Voce perdeu! Esgotou o numero de tentativas! O numero era " << NUMBER << endl;
	}
	else
	{
		cout << "Tentativas: " << tentativas << endl;
		cout.precision(2);
		cout << fixed;
		cout << "Pontuacao: " << pontos << endl;
	}
}
