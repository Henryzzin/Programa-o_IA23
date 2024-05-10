#include <iostream>

class ContaBancaria{
    public:
    ContaBancaria(){}
    ~ContaBancaria(){}
    void setSaldo (float _saldo){
        saldo=_saldo;
    }

    float sacar (){
        float saque;
        std::cout << "Digite quanto você deseja sacar: ";
        std::cin >> saque;
        saldo= saldo - saque;
        return saldo;
    }

    float depositar (){
        float deposito;
        std::cout << "Digite quanto você deseja depositar: ";
        std::cin >> deposito;
        saldo= saldo + deposito;
        return saldo;
    }

    private:
    float saldo;
};

int main(){
    ContaBancaria conta;
    int numConta;
    std::string nome;
    float saldo;
    int op=1;
    std::cout << "Digite o número da conta desejada: ";
    std::cin >> numConta;
    std::cout << "Digite o nome do titular da conta: ";
    std::cin >> nome;
    std::cout << "Digite o saldo da conta: ";
    std::cin >> saldo;
    conta.setSaldo(saldo);
    while (op!=0)
    {
        std::cout << "Caso deseje encerrar o precesso, digite 0.\nCaso deseje sacar, digite 1.\nCaso deseje depositar, digite 2.";
        std::cin >> op;
        switch (op){
        case 1:
            saldo=conta.sacar();
            std::cout << "\nSALDO ATUAL: R$"<<saldo<<".\n";
            break;
        case 2:
            saldo=conta.depositar();
            std::cout << "\nSALDO ATUAL: R$"<<saldo<<".\n";
            break;
        default:
            std::cout << "Operação INVÁLIDA.";
            break;
        }
    }
    return 0;
}