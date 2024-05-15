#include <iostream>

class Aluno {
    public:
    Aluno () {}
    ~Aluno (){}
    float setNotas(float _n1, float _n2, float _n3){
        n1=_n1;
        n2=_n2;
        n3=_n3;
    }
    float CalculoMedia (float n1, float n2, float n3){
        media=(n1+n2+n3)/3;
    }
    private:
    float n1, n2, n3, media;
};

int main (){
    Aluno discente;
    std::string nome;
    int matricula;
    float n1, n2, n3, media;
    std::cout << "Qual o nome do aluno?";
    std::cin >> nome;
    std::cout << "Qual o número da matrícula do aluno? ";
    std::cin >> matricula;
    std::cout << "Qual a primeira nota do aluno? ";
    std::cin >> n1;
    std::cout << "Qual a segunda nota do aluno? ";
    std::cin >> n2;
    std::cout << "Qual a terceira nota do aluno? ";
    std::cin >> n3;
    discente.setNotas(n1,n2,n3);
    media=discente.CalculoMedia(n1,n2,n3);
    std::cout << "Nome: "<< nome <<"\nMatrícula: " << matricula <<"\nMédia final: "<< media;
    if (media<6){
        std::cout << "\nAluno reprovado.";
    } else {
        std::cout << "\nAluno aprovado.";
    }
}