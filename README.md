# Projeto Locar 

Projeto realizado no QT Creator, para a disciplina de Técnicas de Programação 2019.2, Curso de Engenharia Elétrica-IFPB. O programa consiste em uma aplicação offline capaz de cadastrar diversos clientes da locadora. A aplicação tem o intuito de fornecer ao usuário uma fácil manipulação dos dados do cliente bem como um controle da empresa. 


## Interface

![enter image description here](https://github.com/LeandroAlencar/ProjetoLocadora/blob/master/Projeto_Locar/FotosProjeto/Foto%20interface%28Cadastro%29.JPG)
A interface do programa é de fácil manipulação e o usuário pode cadastrar o cliente de maneira muito simples, após preencher todos os dados o usuário deve clicar no botão cadastrar para assim colocar as informações do cliente na tabela.Vale ressaltar que o programa não irá cadastrar clientes que possuem o mesmo número de CPF, afinal podem existir dois clientes com o mesmo nome porém, eles nunca terão o mesmo número de CPF.

## Tabela de dados
Após Cadastrar o cliente suas informações pessoais são dispostas em uma tabela
que vai permitir que o usuário execute algumas funções importantes de maneira muito simples.

## Ocultando um Cliente
![enter image description here](https://github.com/LeandroAlencar/ProjetoLocadora/blob/master/Projeto_Locar/FotosProjeto/OcultandoClientes.JPG)
A ideia principal dessa função é permitir que o usuário deixe a tabela mais reduzida, um exemplo pratico dessa função seria ocultar os clientes que já estão em dia com a locadora. Para usar a função ocultar cliente basta selecionar a checkbox e clicar no botão "Ocultar Cliente", evidentemente que para voltar a apresentar os dados do cliente na tabela basta clicar no botão "Mostrar Clientes Ocultos". Vale ressaltar que a função excluir cliente funciona da mesma forma que as duas funções mostradas anteriormente, porém se o cliente for excluído ele não poderá mais aparecer na tabela.

## Editando Dados
![enter image description here](https://github.com/LeandroAlencar/ProjetoLocadora/blob/master/Projeto_Locar/FotosProjeto/EditandoNome.JPG)
Editar dados é um artificio do programa que faz com que o usuário não precise realizar um novo cadastro caso tenha errado algum dado pessoal do cliente. Para editar basta clicar na célula que corresponde a informação a ser modificada, no caso apresentado acima o usuário está prestes a editar o nome do cliente. Depois de selecionar "yes" o programa solicita que o usuário digite o nome do cliente que deseja para então modifica-lo. Vale ressaltar que o programa não irá cadastrar usuários com menos de 3 letras no nome.

## Ordenar Tabela
O Locar permite que seu usuário possa realizar uma ordenação na tabela por ordem alfabética clicando no botão "Ordenar Por Nome". OBS: O método ordenar por data ainda não está funcionando perfeitamente nesta versão do Locar.
## Salvar dados em um arquivo
Para facilitar a manipulação dos dados mostrados na tabela é possível salva-los em um arquivo .csv. A intenção dessa função é permitir que o usuário possa manipular os dados salvos em uma planilha onde será possível imprimir e executar outras funcionalidades.


## Carregando Dados
O Locar permite que seu usuário entre com os dados do cliente através de um arquivo .csv ja criado. Para isso o usuário deve clicar na opção Menu no canto superior esquerdo do programa e selecionar a opção carregar. Feito isto basta selecionar o arquivo desejado e pronto, os dados do cliente serão colocados na tabela de forma automatica.



