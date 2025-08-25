# 🏙️ Super Trunfo de Cidades em C

Este projeto é uma versão simplificada do jogo **Super Trunfo**, focado em comparar atributos de cidades. Ele foi desenvolvido em linguagem C, com entrada de dados via terminal, e pode ser executado com qualquer compilador compatível com GCC.

## 📁 Estrutura do Código

- **Arquivo principal**: `logicaSuperTrunfo.c`
- **Linguagem**: C
- **Compilador recomendado**: GCC (via MinGW para Windows)

## ⚙️ Funcionalidades

- Cadastro de até **duas cidades** com os seguintes atributos:
  - Nome da cidade
  - Estado
  - Código
  - População
  - Área (km²)
  - PIB (em bilhões)
  - Pontos turísticos

- Dois modos de comparação:
  - **Simples**: compara um único atributo
  - **Mestre**: compara dois atributos com critérios de desempate

## 🧱 Dependências

- GCC (MinGW) instalado e configurado no `PATH`
- Visual Studio Code com as seguintes extensões:
  - [C/C++ da Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) (opcional)

## 🚀 Como compilar e executar no VS Code (sem debug)

### 1. Abrir o terminal no VS Code

Use o atalho:

Ctrl + `

Ou vá em: `Terminal → New Terminal`

### 2. Compilar o código

No terminal, digite:

gcc logicaSuperTrunfo.c -o logicaSuperTrunfo.exe


Esse comando irá gerar um executável chamado `logicaSuperTrunfo.exe`.

### 3. Executar o programa

./logicaSuperTrunfo.exe


Você será guiado para cadastrar duas cidades e, em seguida, poderá escolher os atributos para compará-las.

## 💡 Observações

- O programa usa `scanf()` e `fgets()` para entrada de dados — portanto, **deve ser executado via terminal**, e não por depuradores automáticos.
- A opção de comparação ativa no código é o **modo mestre**, que compara dois atributos. Para mudar para o modo simples, edite a função `main()` e comente/descomente as linhas:

```c
//compararSimples(cartas[0], cartas[1]);
compararDoisAtributos(cartas[0], cartas[1]);

📸 Exemplo de uso

Cadastro da primeira carta:
Digite o código da carta: 1
Digite o nome da cidade: São Paulo
Digite o estado: SP
Digite a população: 12000000
Digite a área (km²): 1521
Digite o PIB (em bilhões): 700
Digite o número de pontos turísticos: 15

Cadastro da segunda carta:
...

Escolha o primeiro atributo:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Populacional
> 1

Escolha o segundo atributo:
> 3

Vencedora: São Paulo

🧠 Autor

Projeto criado por João gabriel, com apoio de orientação para compilação, execução e estruturação no VS Code.

