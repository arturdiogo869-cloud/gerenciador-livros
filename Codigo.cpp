#include <iostream>
#include <vector>
#include <string>

// CODIGO C++ FEITO POR ARTUR AVEIRO DIOGO!!!

// Estrutura para otimizar classificacao de livros
struct infoLivros {
	std::string name;
	int ano;
	std::string autor;
};

// Funcao com retorno de valor (inteiro) sobre opcoes de escolha
int Menu(){
	int escolha;
	std::cout << "===ARMAZENAMENTO DE LIVROS===\n";
	std::cout << "1. Adicionar livro\n";
	std::cout << "2. Listar livro\n";
	std::cout << "3. Remover livro\n";
	std::cout << "4. SAIR\n";
	
	std::cin >> escolha;
	return escolha;
}

// Funcao modificadora, adicionando um livro ao vector (listaAdd), a modificando e usando o Struct (infoLivros) para agilidade e limpeza de codigo
void AdicionarLivro(std::vector<infoLivros> &listaAdd){
	int qtd;
	std::cout << "Quantos livros deseja adicionar? ";
	std::cin >> qtd;
	
	for(int i = 0; i < qtd; i++){
		int ano;
		std::string nome;
		std::string autor;
		
		std::cout << "Diga as infomacoes do livro: " << i+1 << std::endl;
		
		std::cout << "Ano: ";
		std::cin >> ano;
		
		std::cin.ignore();
		
		std::cout << "Nome: ";
		std::getline(std::cin, nome); 
		
		std::cout << "Autor: ";
		std::getline(std::cin, autor); 
		
		infoLivros config;
		config.name = nome;
		config.autor = autor;
		config.ano = ano;
		
		listaAdd.push_back(config);
	}
}

// Funcao apenas para mostrar livros armazenados no vector (nescessario para remocao de livros)
void mostrarLista(const std::vector<infoLivros> &listaAdd){
	if(listaAdd.size() > 0){
		for(int i = 0; i < listaAdd.size(); i++){
			std::cout << "livro " << i << ": nome: " << listaAdd[i].name << ", data de lancamento: " << listaAdd[i].ano << ", autor: " << listaAdd[i].autor << std::endl; 
		}		
	}else{
		std::cout << "Nenhum livro adicionado ainda!\n";
	}
}

// Funcao responsavel para apagar algum livro especifico do indice
void removerLivro(std::vector<infoLivros> &listaAdd){
	if(!listaAdd.empty()){ 
        int deletar;
        std::cout << "Qual o indice do livro que deseja remover? ";
        std::cin >> deletar;
        
        if(deletar < 0 || deletar >= listaAdd.size()){
            std::cout << "Invalido!\n";
        }else{
            listaAdd.erase(listaAdd.begin() + deletar);
            std::cout << "Livro removido com sucesso!\n";
        }
    } else {
        std::cout << "Nenhum livro listado ainda!\n";
    }
}

// Estrutura principal (main) para loop de funcionamento, sendo interrompido na escolha 4 do menu
int main(){
	std::vector<infoLivros> listaAdd;
	int escolha = 0;
	
	while(escolha!=4){	
		escolha = Menu();
		
		switch(escolha){
			case 1:
				AdicionarLivro(listaAdd);
				break;
			case 2:
				mostrarLista(listaAdd);
				break;
			case 3:
				removerLivro(listaAdd);
				break;
			case 4:
				std::cout << "Saindo...";
				break;
			default:
				std::cout << "Nenhuma escolha valida!\n";
				break;
		}
	}	
}