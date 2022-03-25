```
Disciplina      : ECO0016 - Estruturas de Dados
Professor       : Jarbas Joaci de Mesquita Sá Júnior
Descrição       : Trabalho 02
Autor(a)        : Izaias Machado Pessoa Neto
Data de Entrega : 17/08/2021
```

## Detalhes de Execução
Para executar a primeira questão, basta navegar para a pasta q1 e abrir o arquivo q1.dev,
se o Dev C++ já estiver instalado na sua máquina, vai ser aberto automaticamente o projeto
na IDE. Se não, leia mais detalhes a seguir sobre a versão e IDE que foi utilizada para
realização desse trabalho.

## Árvore de Arquivos
```
.
├── q1
│   ├── arvb.c
│   ├── arvb.h
│   ├── arvb.o
│   ├── fila.c
│   ├── fila.h
│   ├── fila.o
│   ├── main.c
│   ├── main.o
│   ├── Makefile.win
│   ├── q1.dev
│   └── q1.layout
└── README.md
```

## Disclaimer
### Sobre a Questão 1
Foram feitas duas alterações ao copiar o arquivo main, mas não mudam a execução conforme
designado. As quais são:
 - 1. Arv foi trocado por ArvB na declaração das árvores, nas linhas 12, 26, 32 e 38.
 - 2. Na comparação de árvores iguais, minha IDE não executou para casos de redeclaração,
      por isso tive que retirar o `int comp` e deixar apenas `comp=`, nas linhas 51 e 54. 

### Ambiente de Desenvolvimento
Como dito nas orientações prévias a realização do trabalho, foi utilizado o Dev C++ e para
fins de debug, abaixo estão as configurações do meu ambiente de desenvolvimento e execução.

```
S.O.: Windows 10 - 64-bit
IDE: Dev C++ 5.11
Compilador: TDM-GCC 4.9.2 64-bit Release
```