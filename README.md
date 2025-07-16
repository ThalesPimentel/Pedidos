# Pedidos
Esse é projeto da faculdade é um sistema de contrele de pedidos em um restaurante, em linguagem C, usando ponteiros, struct, alocação dinâmica.
serão duas structs:

Mesas : Lista Duplamente Encadeada onde cada nó deverá conter as seguintes informações: Número da mesa,
código do garçom, total do pedido e um elo para a lista de pedidos.

Pedidos : Lista Simplesmente Encadeada onde cada nó deverá conter o Código do Pedido, Quantidade do
pedido e um elo para o próximo pedido.

Foram criados dois arquivos binarios:
Um com: com um struct com os pratos, as bebidas, seus respectivos
códigos e preços;
e outro com: com um struct com o nome do garçom e seu código. Quando do fechamento da conta de
uma mesa, o sistema deverá gerar uma nota fiscal com a discriminação do consumo e o valor total da conta e
o nome do garçom que atendeu a mesa. 

A nota fiscal deverá ser apresentada em vídeo. Os nós referentes à mesa e aos pedidos que foram computados na nota fiscal deverão ser retirados de memória.

Além disso, as operações de inserção / deleção / alteração / consulta de registros / consulta de nós, servem tanto para as listas, quanto para os arquivos.
