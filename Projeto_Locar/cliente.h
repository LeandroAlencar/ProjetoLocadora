#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>
#include <QMessageBox>
#include <QDate>
class Cliente
{

private:
    QString Nome;
    QString Cpf;
    QString Tel;
    QDate Data;
    QString Carro;
    QString Plano;
    int Lucros;
    bool Status;
    bool check;

public:
    Cliente();

    QString getNome() const;
    bool setNome(const QString &value);

    QString getTel() const;
    void setTel(const QString &value);

    QString getCpf() const;
    void setCpf(const QString &value);

    QString getCarro() const;
    void setCarro(const QString &value);

    QString getPlano() const;
    void setPlano(const QString &value);

    bool getStatus() const;
    void setStatus(bool value);

    bool getIsChecked() const;
    void setIsChecked(bool value);

    QDate getData() const;
    void setData(const QDate &value);

    int getLucros() const;
    void setLucros(int value);

    bool getCheck() const;
    void setCheck(bool value);
};

#endif // CLIENTE_H
