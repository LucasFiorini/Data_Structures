#include <iostream>
#include <string>
using namespace std;

const int UMPRIMO = 37;//bom que seja um numero primo
//porque sendo primo, a possibilidade do resto da divisao 
//ser o mesmo pra mais de um numero eh menor

int funcaoHash(string s, int M) {
	int h = 0;
	for (unsigned int i = 0; i < s.length(); ++i) {
		h = (UMPRIMO * h + s[i]) % M;
	}
	return h;
}

class noh {
	friend class tabelaHash;
private:
	string chave;
	string valor;
	noh* proximo = NULL;
public:
	noh() {
		chave = "";
		valor = "";
	}
};

class tabelaHash {
private:
	//vetor de ponteiro de nós
	noh** elementos;
	int capacidade;
public:
	tabelaHash(int cap = 100){
		elementos = new noh*[cap];
		capacidade = cap;

		for (int i = 0; i < cap; ++i) {
			elementos[i] = NULL;
		}
	}

	~tabelaHash(){
		for (int i = 0; i < capacidade; ++i) {
			noh* atual = elementos[i];

			//percorre a lista removendo todos os nós
			while(atual != NULL){
				noh* aux = atual;
				atual = atual->proximo;
				delete aux;
			}
		}
		delete[] elementos;
	}
	void insere(string c, string v);
	string recupera(string c);
	void altera(string c, string v);
	void remove(string c);
	void percorre();
};

//insere um valor v com chave c
void tabelaHash::insere(string c, string v) {
	int h;
	h = funcaoHash(c, capacidade);

	if (recupera(c) == "NAO ENCONTRADO!") {
		if (elementos[h] == NULL) {
			elementos[h] = new noh;
			elementos[h]->chave = c;
			elementos[h]->valor = v;
		} else {
			cout << "Colidiu: " << c <<endl;
			noh* atual = elementos[h];

			//achando local para insercao
			while(atual->proximo != NULL){
				atual = atual->proximo;
			}

			noh* novo = new noh;
			novo->chave = c;
			novo->valor = v;
			atual->proximo = novo;
		}
	} else {
		cout << "ITEM JA ESTA NA TABELA!" << endl;
	}
}

//recupera um valor associado a uma dada chave
string tabelaHash::recupera(string c){
	int h;
	h = funcaoHash(c, capacidade);

	if ((elementos[h] != NULL) and (elementos[h]->chave == c)) {
		return elementos[h]->valor;
	} else {
		noh* atual = elementos[h];

		while ((atual != NULL) and (atual->chave != c)){
			atual = atual->proximo;
		}

		if ((atual != NULL) and (atual->chave == c)){
			return atual->valor;
		} else {
			return "NAO ENCONTRADO!";
		}
	}
}


//altera o valor associado a uma chave
void tabelaHash::altera(string c, string v){
	//nao trata colisao, nem chave nao encontrada
	int h;
	h = funcaoHash(c, capacidade);

	if ((elementos[h] != NULL) and elementos[h]->chave == c){
		elementos[h]->valor = v;		
	} else {
		noh* atual = elementos[h];

		while ((atual != NULL) and (atual->chave != c)) {
			atual = atual->proximo;
		}

		if ((atual != NULL) and (atual->chave == c)) {
			atual->valor = v;
		} else {
			cerr << "ERRO NA ALTERACAO!" << endl;
		}
	}
}

//retira um valor associado a uma chave 
void tabelaHash::remove(string c){
	int h;
	h = funcaoHash(c, capacidade);

	if ((elementos[h] != NULL) and (elementos[h]->chave == c)) {
		//removendo da cabeca da lista
		noh* aux = elementos[h];
		elementos[h] = elementos[h]->proximo;
		delete aux;
	} else {
		noh* atual = elementos[h];
		noh* anterior;

		while((atual != NULL) and (atual->chave != c)) {
			anterior = atual;
			atual = atual->proximo;
		}

		if ((atual != NULL) and (atual->chave == c)) {
			anterior->proximo = atual->proximo;
			delete atual;
		} else {
			cerr << "ERRO NA REMOCAO!" << endl;
		}
	}
}

//percorrendo a tabela hash (para fins de debug)
void tabelaHash::percorre() {
	noh* atual;
	for (int i = 0; i < capacidade; ++i) {
		cout << i << ":";
		atual = elementos[i];
		while (atual != NULL) {
			cout << "[" << atual->chave << "/"
				 << atual->valor << "]->";
			atual = atual->proximo; 
		}
		cout << "NULL   ";
	}
}

int main() {
	tabelaHash th(10);

	th.insere("ola", "ola a todos");
	th.insere("olk","vai ter colisao");
	th.insere("joulim","joaquim uchoa");
	th.insere("tales","Tales Heimfarth");
	th.insere("joaquim","selvagem de bicicleta");
	th.insere("francisco","francisco de albiquerque");
	th.insere("tomate","too much");
	th.insere("28","vinte e oito dias para o fim do mes");
	th.insere("joulim","ja tem um antes!");
	th.insere("bruno","bruno schinneider");

	th.percorre();
	cout << endl;

	cout << th.recupera("joulim") << endl;
	cout << th.recupera("ola") << endl;
	cout << th.recupera("olk") << endl;
	cout << th.recupera("bruno") << endl;

	th.altera("aranha", "homem que arranha");
	cout << th.recupera("aranha") <<endl;

	th.altera("bruno", "Xinagod");
	cout << th.recupera("bruno");

	th.remove("joulim");
	th.remove("olk");
	cout << th.recupera("joulim") << endl;
	cout << th.recupera("olk") << endl;
	th.remove("olk");

	cout << endl;
	th.percorre();
	cout << endl;
		
	return 0;
}


