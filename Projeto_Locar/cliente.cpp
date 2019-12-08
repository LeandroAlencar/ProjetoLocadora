#include "cliente.h"

QString Cliente::getNome() const
{
    return Nome;
}

bool Cliente::setNome(const QString &value)
{
    if(value.size() >= 3){
        Nome = value;
        return 1;
    }else{
        return 0;
    }
}

QString Cliente::getTel() const
{
    return Tel;
}

void Cliente::setTel(const QString &value)
{
    Tel = value;
}


QString Cliente::getCpf() const
{
    return Cpf;
}

void Cliente::setCpf(const QString &value)
{  
        Cpf = value;
}


QString Cliente::getCarro() const
{
    return Carro;
}

void Cliente::setCarro(const QString &value)
{
    Carro = value;
}

QString Cliente::getPlano() const
{
    return Plano;
}

void Cliente::setPlano(const QString &value)
{
    Plano = value;
}

bool Cliente::getStatus() const
{
    return Status;
}

void Cliente::setStatus(bool value)
{
    Status = value;
}



QDate Cliente::getData() const
{
    return Data;
}

void Cliente::setData(const QDate &value)
{
    Data = value;
}

int Cliente::getLucros() const
{
    return Lucros;
}

void Cliente::setLucros(int value)
{
    Lucros = value;
}

bool Cliente::getCheck() const
{
    return check;
}

void Cliente::setCheck(bool value)
{
    check = value;
}

Cliente::Cliente()
{
    check = false;
}
