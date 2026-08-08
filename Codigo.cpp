#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Dados{
public:
	std::string name;
	std::string autor;
	std::string ano;	
};

int Menu(){
	int escolha;
	
	std::cout << "---ORGANIZADOR DE BIBLIOTECA---\n";
	std::cout << "1. Listar livro\n";
	std::cout << "2. Mostrar livros\n";
	std::cout << "3. Remover livro\n";
	std::cout << "4. SAIR\n";
	
	std::cin >> escolha;
	return escolha;
}

void SalvarTodosLivros(const std::vector<Dados> &lista) {
    std::ofstream saveLista("Lista.txt"); 
    
    if (saveLista.is_open()) {
        for (int i = 0; i < lista.size(); i++) {
            saveLista << lista[i].name << "\n";
            saveLista << lista[i].autor << "\n";
            saveLista << lista[i].ano << "\n";
        }
        saveLista.close();
    }
}

void ListarLivro(std::vector<Dados> &lista){
	int qtd;
	std::ofstream saveLista("Lista.txt", std::ios::app);
	
	std::cout << "Quantos livros deseja listar?\n";
	std::cin >> qtd;
	std::cin.ignore();
	
	if(saveLista.is_open()){
		for(int i = 0; i < qtd; i++){
			Dados analise;
			
			std::cout << "Diga o nome do livro:\n";
			std::getline(std::cin, analise.name);
			
			std::cout << "Diga o nome do autor:\n";
			std::getline(std::cin, analise.autor);
			
			std::cout << "Diga o ano em que foi publicado:\n";
			std::cin >> analise.ano;
			
			lista.push_back(analise); 
			saveLista << analise.name << "\n";
            saveLista << analise.autor << "\n";
            saveLista << analise.ano << "\n";
		}
	}else{
		std::cout << "Erro no arquivo de salvamento!\n";
	}
	
	saveLista.close();
}

void CarregarLivros(std::vector<Dados> &lista){
	std::ifstream arquivo("Lista.txt");
	
	if (arquivo.is_open()) {
        lista.clear(); 
        Dados temp;

        while(std::getline(arquivo, temp.name)){
            std::getline(arquivo, temp.autor);
            
            arquivo >> temp.ano;
            arquivo.ignore(); 

            lista.push_back(temp);
        }
        
        arquivo.close();
    }
}

void MostrarLista(const std::vector<Dados> &lista){
	if(lista.size() > 0){
		for(int i = 0; i < lista.size(); i++){
			std::cout << "Livro " << i+1 << ": " << lista[i].name << ", do autor: " << lista[i].autor << ", do ano de: " << lista[i].ano << ";" << std::endl;
		}	
	}else{
		std::cout << "Nenhum livro adicionado!\n";
	}
}

void RemoverLivro(std::vector<Dados> &lista){
	int indice;
	
	std::cout << "Qual livro deseja remover?\n";
	MostrarLista(lista);
	
	std::cin >> indice;
	std::cin.ignore();
	
	if(indice >= 1 && indice <= lista.size()){
        lista.erase(lista.begin() + (indice - 1));
        
        SalvarTodosLivros(lista);
        
        std::cout << "Livro removido!\n";
    }else{
        std::cout << "Indice invalido!\n";
    }
}

int main(){
	int escolhido = 0;
	std::vector<Dados> lista;
	CarregarLivros(lista);
	
	while(escolhido!=4){
		escolhido = Menu();
		
		switch(escolhido){
			case 1:
				ListarLivro(lista);
				break;
			case 2:
				MostrarLista(lista);
				break;
			case 3:
				RemoverLivro(lista);
				break;
			case 4:
				std::cout << "Saindo...";
				break;
			default:
				std::cout << "Opcao invalida!\n";
				break;
		}
	}
}