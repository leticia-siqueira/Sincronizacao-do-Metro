# Sincronização do Metrô

## Objetivo

Implementar uma simulação de embarque de passageiros em um metrô
utilizando threads e mecanismos de sincronização na linguagem C.

## Arquivos

- sync_car.h: declaração da struct station e protótipos das funções.
- sync_car.c: implementação das funções de sincronização.
- sync_car-runner.c: Arquivo de Teste.
- Makefile: compilação do programa e limpeza dos arquivos gerados.

## Sistema operacional

Ubuntu/WSL

## Compilação

make

## Execução

./sync_car

## Limpeza

make clean

## Testes

Os testes são realizados utilizando o arquivo `sync_car-runner.c`, fornecido pelo professor, que verifica o funcionamento das funções de sincronização e do embarque de passageiros.

Para compilar e executar:

```bash
make clean
make
./sync_car
```

Se o programa funcionar corretamente nos testes do runner, será exibida a mensagem:

```text
Looks good!
```

Para executar o runner 20 vezes e verificar possíveis falhas de sincronização:

```bash
for i in $(seq 1 20); do
    echo "Teste $i"
    ./sync_car || break
done
```

