#Gerenciador de Livros em C++

Um sistema em terminal para cadastro, listagem e remoção de livros, desenvolvido em C++.

**Desenvolvido por:** Artur Aveiro Diogo

**O projeto tem objetivo de demonstração de minha evolução pessoal na linguagem e comprometimento com o trabalho**

##Funcionalidades

**Adicionar Livros:** Permite cadastrar múltiplos livros informando nome, autor e ano de lançamento.
**Listar Acervo:** Exibe todos os livros armazenados com seus respectivos índices.
**Remover Livro:** Apaga um livro específico da lista com validação de índice para evitar complicações.
**Gestão Eficiente de Memória:** Uso de passagem de parâmetros por referência (`&`) e referência constante (`const &`).

##"Ferramentas"

**Linguagem:** C++
**Bibliotecas** iostream, string e vector
**Estruturas de Dados:** `std::vector` e `struct`
**Controle de Buffer:** `std::cin.ignore()` e `std::getline`
**Fluxo do Programa:** Funções com retorno, menu dinâmico com `switch/case` e laço `while`


PRIMEIRA ATUALIZAÇÃO, PONTOS IMPORTANTES!:
##Biblioteca <fstream> adicionada!
**Adicionado** salvamento de suas listagens pelo arquivo .txt "Lista", apagar ele irá resultar na perca de seus dados!