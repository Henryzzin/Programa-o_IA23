#include <iostream>
#define pi 3.14

    class Retangulo{
        public:
            Retangulo(){};
            ~Retangulo(){};
            float calcularArea(){
                float area;
                area=altura*largura;
                return area;
            }
            float calcularPerimetro(){
                float perimetro;
                perimetro=(altura*2)+(largura*2);
                return perimetro;
            }
            void setAltura(float altura2){
                altura=altura2;
            }
            void setLargura(float largura2){
                largura=largura2;
            }
        private:
        float altura;
        float largura;
    };

int main (){
    Retangulo conta;
    float area;
    float perimetro;
    float altura;
    float largura;
    std::cout<< "Digite o valor da altura em metros: ";
    std::cin>>altura;
    std::cout<< "Digite o valor da largura em metros: ";
    std::cin>>largura;
    conta.setAltura(altura);
    conta.setLargura(largura);
    area=conta.calcularArea();
    perimetro=conta.calcularPerimetro();
    std::cout<< "A área é de " << area << " metros.\n";
    std::cout<< "O perímetro é de " << perimetro << " metros.\n";
}