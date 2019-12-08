#include "locadora.h"
#define Plano1 200
#define Plano2 400

#include<QDebug>

Locadora::Locadora()
{

}

void Locadora::inserirCliente(Cliente c)
{    
    fulano.push_back(c);
}

void Locadora::ordenarporNome()
{
    std::sort(fulano.begin(), fulano.end(), [](Cliente a, Cliente b){
        return a.getNome()<b.getNome();
    });

}

bool Locadora::ordenarporData()


{

    std::sort(fulano.begin(), fulano.end(), [](Cliente a, Cliente b){
        if(a.getData().year()==b.getData().year()){
            if(a.getData().month()==b.getData().month()){
                return a.getData().day()<b.getData().day();
            }else{
                return a.getData().month()<b.getData().month();
            }
        }else{
            return a.getData().year()<b.getData().year();
        }

    });
}

void Locadora::salvarArquivo(QString arquivo)
{
     QFile file(arquivo + ".csv");

     file.open(QIODevice::WriteOnly);

     for(auto a:fulano){
         QString linha = a.getNome() + ","
                         + a.getCpf() + ","
                         + a.getTel() + ","
                         + a.getCarro()+ ","
                         + a.getPlano()+ ","
                         + a.getData().toString() + "\n";
         file.write(linha.toLocal8Bit());
     }
     file.close();
}

bool Locadora::carregarArquivo(QString arquivo)
{

    QFile file(arquivo);
        if(file.isOpen() == 1)return 1;
        else{
            file.open(QIODevice::ReadOnly);
            QString linha;
            QStringList dados;
            while(!file.atEnd()){
                Cliente temp;
                QDate temp1;
                linha = file.readLine();

                dados = linha.split(",");

                temp.setNome(dados[0]);

                temp.setCpf(dados[1]);
                temp.setTel(dados[2]);
                temp.setCarro(dados[3]);
                temp.setPlano(dados[4]);
                temp.setData(temp1.fromString(dados[5]));
                if(jacadastrado(temp) == 0)
                    inserirCliente(temp);
            }
            file.close();
            return 0;
        }
}

int Locadora::size()
{
    return fulano.size();
}

bool Locadora::jacadastrado(Cliente c)
{
    if(fulano.size() >= 1){
          for(int i = 0; i < fulano.size(); i++){
              if((c.getCpf() == fulano[i].getCpf())){
                  return 1;
              }
          }
      }
    return 0;
}

void Locadora::eraseNome(QString text)
{
    for(int i = 0; i<fulano.size(); i++){
           if(fulano[i].getNome() == text){
               fulano.erase(fulano.begin()+i);
           }
       }
}

void Locadora::eraseTel(QString text)
{
    for(int i = 0; i<fulano.size(); i++){
           if(fulano[i].getTel() == text){
               fulano.erase(fulano.begin()+i);
           }
       }
}

void Locadora::eraseCpf(QString text)
{
    for(int i = 0; i<fulano.size(); i++){
           if(fulano[i].getCpf() == text){
               fulano.erase(fulano.begin()+i);
           }
    }
}
void Locadora::excluirCliente(int c)
{

    fulano.erase(fulano.begin()+c);
}

Cliente Locadora::operator[](int i)
{
    return fulano[i];
}

int Locadora::calcLucros()
{
    int valor = 0;
    for(int i = 0; i<fulano.size(); i++ ){
        if(fulano[i].getPlano()=="Plano1"){
            valor+=200;
        }else{
            valor+=400;
        }
    }

    return valor;
}
