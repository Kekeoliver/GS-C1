Kethelyn Rocha 
RM:574016
Anna Luiza Carvalhaes
RM:573330    


EXPLICAÇAÕ DO TRABALHO:
O código gerencia o monitoramento de uma missão espacial utilizando uma estrutura (struct) para agrupar os dados de temperatura, energia e comunicação, salvando cada registro de forma sequencial em um vetor com capacidade para até 50 leituras. O fluxo principal é controlado por um menu interativo baseado no laço do-while e na estrutura switch, que direciona o usuário para as funções específicas de cadastro, listagem ou análise, garantindo que o programa rode continuamente até que a opção de encerramento (zero) seja digitada.

A inteligência do sistema reside nas validações lógicas executadas antes e durante o processamento dos dados. Na inserção, o programa impede o travamento da memória ao checar se o limite do vetor foi atingido, enquanto nas funções de exibição e diagnóstico, loops for fazem a varredura automática apenas nas posições preenchidas. Por fim, uma série de condicionais if/else analisa os parâmetros operacionais em tempo real, disparando alertas visuais críticos caso a temperatura ultrapasse 80°C, a energia caia abaixo de 20% ou ocorra uma perda de conectividade.
