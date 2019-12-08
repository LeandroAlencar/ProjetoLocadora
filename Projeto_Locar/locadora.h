#ifndef LOCADORA_H
#define LOCADORA_H
#include "cliente.h"
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QFileDialog>
#include <QStringList>
#include <QMessageBox>
#include <QDate>

class Locadora
{

private:
    QVector <Cliente> fulano;
public:
    Locadora();
    void inserirCliente(Cliente c);
    void ordenarporNome();
    bool ordenarporData();
    void salvarArquivo(QString arquivo);
    bool carregarArquivo(QString arquivo);
    int size();
    bool jacadastrado(Cliente c);
    void eraseNome(QString text);
    void eraseTel(QString text);
    void eraseCpf(QString text);
    void excluirCliente(int c);
    Cliente operator[](int i);
    int calcLucros();
};

#endif // LOCADORA_H
