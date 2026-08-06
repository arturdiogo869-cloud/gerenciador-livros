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

---

##Próximos Passos de Evolução

[ ] Refatorar a `struct` para uma `class` com encapsulamento (`private`/`public`).
[ ] Implementar Getters e Setters com validações internas.
[ ] Aplicar **Herança** para criar categorias diferentes de itens (ex: `LivroDigital`, `Revista`).