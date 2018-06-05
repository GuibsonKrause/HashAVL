# HashAVL
Segundo Trabalho de TPA – Árvores AVL
Objetivos:
•
•
•
Implementar uma biblioteca de árvores AVLs
Implementar hash fechada utilizando estruturas de árvores AVL para resolver colisões;
Avaliar a complexidade dos algoritmos de busca em árvore AVL e na hash fechada desenvolvida
neste trabaho comparando com as complexidades das buscas obtidas no trabalho anterior.
Especificações do programa
1. Arquivos de entrada
Seu programa receberá como entrada os mesmos arquivos utilizados como entrada do trabalho
anterior.
2. Leitura do arquivo entrada.txt e geração, em memória, da tabela hash
Seu programa deve ler o arquivo entrada.txt gerando, a cada linha lida, um registro de contato. Esse
registro deve ser então inserido na hash fechada utilizando o nome do contato como chave. A
diferença desta tabela hash para a implementada no trabalho anterior é que neste você utilizará
árvores AVL para tratar as colisões, em lugar das listas utilizadas anteriormente. Ou seja, cada índice
da hash conterá uma árvore AVL. Você deve construir uma biblioteca de AVL e utilizá-la para
desenvolver essa funcionalidade. Assim como no trabalho anterior, você pode utilizar a função hash
que desejar, considerando que sua tabela hash deve ter, ao menos, 1000 índices. Por fim, lembre-se
que, assim como no trabalho anterior, podemos ter contatos com nomes iguais.
3. Leitura do arquivo operacoes.txt e geração dos arquivos de saída.
Depois de ler o arquivo gerando as estruturas em memória vc deve ler o arquivo operacoes.txt. Para
cada linha deste arquivo você deve:
a. Se a linha se iniciar com “E”:
i. Leia o nome que acompanha a letra E, e elimine da tabela os registros de todos
os contatos com o nome informado.
ii. Pode haver mais de um contato com o mesmo nome!
iii. Dica: Lembre-se de desalocar o contato depois de eliminá-lo de todas as
estruturas.
b. Se a linha se iniciar com a letra “I”:
i. Obtenha os dados da contato a ser inserido, gere o registro do contato e insira
na hash fechada, seguindo o mesmo procedimento que fez na leitura do arquivo
inicial.
c. Se a linha se iniciar com a letra “B”:
i. Leia o nome que acompanham a letra “B”
ii. Busque na hash fechada pelo primeiro contato que tiver o nome solicitado,
contando quantos elementos foram verificados na busca
iii. Seu programa deve gerar um arquivo de saída, chamado “buscas.txt” que terá
uma linha para cada busca, contendo os seguintes dados separados por ponto-
e-virgula:1. Nome do contato pesquisado
2. Telefone do contato pesquisado
3. Flag indicando se encontrou ou não o registro na hash (0 se não
encontrar e 1 se encontrar)
4. Quantidade de contatos comparados até encontrar o elemento
iv. Por exemplo, suponha que o registro de nome “Zé” e telefone “27999988822”
não tenha sido encontrado e tenha comparado com 300 contatos para chegar à
conclusão de que o elemento não existe. Nesse caso, deve ser gerada a seguinte
linha no arquivo de saída:
Zé;27999988822;0;300
4. Geração de arquivos de saída
Agora seu programa deve gerar um arquivo de saída, mostrando o conteúdo da tabela hash, sendo
nomeado saidaHashAVL.txt.
i. Para gerar esse arquivo faça uma varredura na hash iniciando do índice zero até
o índice máximo. Para cada índice, liste os elementos do índice, fazendo um
caminhamento por nível na árvore do índice. Cada elemento deve gerar uma
linha neste arquivo.
ii. Cada linha dessas deve conter: o índice do contato na hash fechada, o nível do
elemento na árvore, o nome do contato e o telefone do contato. Os dados
devem sempre ser separados por ponto-e-virgula (;).
iii. A última linha do arquivo deve conter o índice, a quantidade de elementos que
estava em cada índice da hash e a altura da árvore do índice(separados por
ponto e vírgula).
Requisitos não-funcionais
•
•
•
Crie bibliotecas de árvore AVL e de tabelas hash;
Utilize a biblioteca de árvore AVL para implementar os métodos de hash fechada;
Siga a ideia do trabalho anterior de armazenar na estrutura ponteiros para Contato..
Relatório
Faça um relatório contendo:
1. Avaliação da ordem de complexidade das buscas em árvores AVL e da hash fechada com árvore
AVL, Ilustrando a análise com trechos do seu código e exemplificando com resultados da
execução dos arquivos de busca. Compare a ordem de complexidade da hash deste trabalho
com a ordem de complexidade do trabalho anterior quando utilizou listas para tratar as colisões.
Entrega
Deve ser entregue um arquivo compactado contendo:•
•
Os códigos fontes (programa principal + bibliotecas)
Relatório
O trabalho deve ser entregue até 29/05/2017. O prazo final não será adiado em hipótese alguma.
Valor: 15 pontos (15% da nota semestral).
Eventuais alterações nas especificações serão comunicadas durantes as aulas e formalizadas pela
substituição deste arquivo de especificações no Moodle. Assim, antes de submeter seu trabalho
certifique-se de que está atendendo às especificações mais recentes!
