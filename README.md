Introdução

Este relatório detalha os resultados obtidos ao implementar o cálculo do fatorial utilizando múltiplas threads em C, com o objetivo de acelerar o processo. A biblioteca Pthreads foi utilizada para gerenciar a concorrência, e a ferramenta hyperfine foi empregada para medir o desempenho.
Implementação e Testes

Código:
O código foi desenvolvido em C, utilizando a biblioteca Pthreads para a criação e gerenciamento das threads. O cálculo do fatorial foi dividido entre as threads, explorando o paralelismo para acelerar o processo.

Compilação:
Bash

gcc fatorial_10_threads.c -o fatorial_4 -pthread

Use o código com cuidado.

Testes de Desempenho:
A ferramenta hyperfine foi utilizada para medir o tempo de execução de forma precisa e consistente. Os seguintes parâmetros foram configurados:

    --warmup 3: Executa o comando 3 vezes antes da medição para estabilizar o sistema.
    -m 10: Realiza 10 medições para obter resultados mais robustos.

Bash

hyperfine --warmup 3 -m 10 ./fatorial_4

Use o código com cuidado.
Resultados e Métricas

Os resultados dos testes demonstraram uma melhoria substancial no desempenho ao utilizar múltiplas threads (2 ou 10) em comparação com a execução sequencial. As métricas coletadas incluem:

    Mediana: Representa o tempo central de execução, fornecendo uma medida robusta do desempenho.
    Desvio padrão (σ): Indica a variabilidade dos tempos de execução, permitindo avaliar a consistência dos resultados.
    (user): Tempo de CPU gasto em modo de usuário, relacionado ao código da aplicação.
    (system): Tempo de CPU gasto em modo de sistema, relacionado a chamadas do sistema operacional.
    Max: Maior tempo de execução registrado, indicando o pior caso.

Discussão

Os resultados obtidos confirmam a eficácia do processamento paralelo para o cálculo do fatorial. Ao dividir o trabalho entre múltiplas threads, é possível aproveitar a capacidade de processamento de sistemas multicore, reduzindo significativamente o tempo de execução.

Observações:

    A melhoria no desempenho é mais evidente para valores maiores de n (número a ser calculado o fatorial), pois o overhead de criação e sincronização das threads se torna menos significativo em relação ao trabalho realizado por cada thread.
    A escalabilidade do desempenho depende de diversos fatores, como a arquitetura do sistema, o número de núcleos disponíveis e a eficiência da implementação da sincronização entre as threads.

Conclusão

A implementação paralela do cálculo do fatorial utilizando Pthreads demonstrou ser uma abordagem eficaz para acelerar o processo. Os resultados obtidos indicam que o uso de múltiplas threads pode levar a ganhos significativos de desempenho, especialmente para problemas que podem ser facilmente paralelizados.

Recomendações:

    Explorar diferentes estratégias de divisão do trabalho: A forma como o cálculo do fatorial é dividido entre as threads pode influenciar o desempenho.
    Analisar o overhead de sincronização: A comunicação e sincronização entre as threads podem introduzir overhead, que deve ser minimizado.
    Considerar a granularidade do trabalho: Dividir o trabalho em tarefas muito pequenas pode aumentar o overhead de criação e gerenciamento das threads.

Próximos Passos:

    Analisar o impacto do número de threads: Investigar como o aumento do número de threads afeta o desempenho, considerando o número de núcleos disponíveis no sistema.
    Comparar com outras bibliotecas: Avaliar o desempenho ao utilizar outras bibliotecas para programação paralela, como OpenMP.
    Implementar outras estratégias de paralelização: Explorar outras técnicas de paralelização, como o uso de GPUs.

Este relatório fornece uma base sólida para futuras investigações e otimizações da implementação paralela do cálculo do fatorial.
