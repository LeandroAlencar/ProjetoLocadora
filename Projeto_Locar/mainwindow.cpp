#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_cadastrar_clicked()
{

    Cliente temp;

    ui->tabela->setColumnWidth(0,10);

    if((ui->insert_nome->text())!="" and (ui->insert_cpf->text())!= "" and (ui->insert_tel->text())!="" ){

        if(temp.setNome(ui->insert_nome->text()) == 0){
            QMessageBox::critical(this, "ERRO", "Certifique-se que o nome tem mais de 3 letras");
        }else{

            temp.setCpf(ui->insert_cpf->text());
            temp.setTel(ui->insert_tel->text());
            temp.setCarro(ui->selCarro->currentText());            
            temp.setPlano(ui->selplano->currentText());
            temp.setData(ui->Data->date());

            int quantidade_linhas = ui->tabela->rowCount();

            if(l.jacadastrado(temp)==1){
                QMessageBox::critical(this,"REPETIDO", "Este cliente ja foi cadastrado");

            }else{
                l.inserirCliente(temp);
                ui->tabela->insertRow(quantidade_linhas);
                inserirnaTabela();
                QMessageBox::information(this,"Cadastro:","Cadastrado com sucesso!");
            }
        }

    }else{
        QMessageBox::critical(this,"Erro","Certifique-se de ter preenchido todos os parâmetros.");
    }
    ui->insert_nome->clear();
    ui->insert_cpf->clear();
    ui->insert_tel->clear();
}


void MainWindow::inserirnaTabela()
{

    int linha = 0;
     ui->tabela->setRowCount(0);

    for(int i = 0; i<l.size(); i++){

     QTableWidgetItem *uncheck = new QTableWidgetItem();
     QTableWidgetItem *check = new QTableWidgetItem();
     uncheck->setCheckState(Qt::Unchecked);
     check->setCheckState(Qt::Checked);

     ui->tabela->insertRow(linha);

     if(l[i].getCheck()) ui->tabela->setItem(linha, 0, check);
     else ui->tabela->setItem(linha, 0, uncheck);

    ui->tabela->setItem(linha,1, new QTableWidgetItem(l[i].getNome()));
    ui->tabela->setItem(linha,2, new QTableWidgetItem(l[i].getCpf()));
    ui->tabela->setItem(linha,3, new QTableWidgetItem(l[i].getTel()));
    ui->tabela->setItem(linha,4, new QTableWidgetItem(l[i].getCarro()));
    ui->tabela->setItem(linha,5, new QTableWidgetItem(l[i].getPlano()));
    ui->tabela->setItem(linha,6, new QTableWidgetItem(l[i].getData().toString()));
    ui->tabela->setRowHeight(linha++, 6);
}
}

void MainWindow::on_btn_ordenanome_clicked()
{
    l.ordenarporNome();
    ui->tabela->clearContents();
    for(int i =0; i<l.size();i++){
        inserirnaTabela();
    }
}


void MainWindow::on_excluirCliente_clicked()
{
    for (int i = ui->tabela->rowCount()-1; i >= 0; i--) {
             QTableWidgetItem *check = ui->tabela->item(i,0);
            if (check->checkState()){
            l.excluirCliente(i);
            }
            inserirnaTabela();

}
}
void MainWindow::on_ocultarCliente_clicked()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++) {
          QTableWidgetItem *check = ui->tabela->item(i,0);
          if (check->checkState()) ui->tabela->hideRow(i);
      }
}

void MainWindow::on_mostrarOcultos_clicked()
{
    for (int i = 0; i < ui->tabela->rowCount(); i++) {
          QTableWidgetItem *check = ui->tabela->item(i,0);
          if (check->checkState()) ui->tabela->showRow(i);
      }
}

void MainWindow::on_tabela_cellClicked(int row, int column)
{
    Cliente temp;
    if(column == 1){
        QMessageBox::StandardButton resp = QMessageBox::question(this, "EDITAR", "Deseja editar este item?");
        if(resp == QMessageBox::Yes){
        bool ok;
        QString txt = QInputDialog::getText(this, "ALTERAR NOME", "Digite o nome do cliente", QLineEdit::Normal,"",&ok);
            if(ok and !txt.isEmpty() and txt.size()>=3){


            temp.setNome(txt);
            temp.setTel(l[row].getTel());
            temp.setCpf(l[row].getCpf());
            temp.setCarro(l[row].getCarro());
            temp.setPlano(l[row].getPlano());
            temp.setData(l[row].getData());
            l.eraseNome(l[row].getNome());
            l.inserirCliente(temp);
            ui->tabela->setItem(row, column, new QTableWidgetItem(temp.getNome()));
            QMessageBox::information(this,"ALTERADO:","Nome alterado com sucesso!");
            }else{
            QMessageBox::critical(this,"NOME INVALIDO", "Certifique-se que o nome tem mais de 3 letras");
            }
          }
    }
    if(column == 2){
    QMessageBox::StandardButton resp = QMessageBox::question(this, "EDITAR", "Deseja editar este item?");
    if(resp == QMessageBox::Yes){
    bool ok;
    QString txt = QInputDialog::getText(this, "ALTERAR CPF", "Digite o CPF do cliente", QLineEdit::Normal,"",&ok);
        if(ok and !txt.isEmpty()){

        temp.setCpf(txt);
        temp.setTel(l[row].getTel());
        temp.setNome(l[row].getNome());
        temp.setCarro(l[row].getCarro());
        temp.setPlano(l[row].getPlano());
        temp.setData(l[row].getData());
        l.inserirCliente(temp);
        l.eraseCpf(l[row].getCpf());
            if(l.jacadastrado(temp) == 1){
                QMessageBox::critical(this,"REPETIDO", "Este cliente ja foi cadastrado");
            }else{
                 ui->tabela->setItem(row, column, new QTableWidgetItem(temp.getCpf()));
            }
         }else{
            QMessageBox::critical(this,"CPF INVALIDO", "Certifique-se de nao ter deixado o parametro vazio");
    }
    }
    }

    if(column == 3){
    QMessageBox::StandardButton resp = QMessageBox::question(this, "EDITAR", "Deseja editar este item?");
    if(resp == QMessageBox::Yes){
    bool ok;
    QString txt = QInputDialog::getText(this, "ALTERAR TELEFONE", "Digite o telefone do cliente", QLineEdit::Normal,"",&ok);
        if(ok and !txt.isEmpty()){


        temp.setTel(txt);
        temp.setNome(l[row].getNome());
        temp.setCpf(l[row].getCpf());
        temp.setCarro(l[row].getCarro());
        temp.setPlano(l[row].getPlano());
        temp.setData(l[row].getData());
        temp.setLucros((l[row].getLucros()));
        l.eraseTel(l[row].getTel());
        l.inserirCliente(temp);
        ui->tabela->setItem(row, column, new QTableWidgetItem(temp.getTel()));
        QMessageBox::information(this,"ALTERADO:","Telefone alterado com sucesso!");
         }else{
            QMessageBox::critical(this,"TELEFONE INVALIDO", "Certifique-se de nao ter deixado o parametro vazio");
        }
        }
    }

}

void MainWindow::on_ordenar_data_clicked()
{
    l.ordenarporData();
    ui->tabela->clearContents();
    for(int i =0; i<l.size();i++){
        inserirnaTabela();
    }
}

void MainWindow::on_actionSalvar_triggered()
{
       QString filename;
       filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");
       l.salvarArquivo(filename);
}

void MainWindow::on_actionCarregar_triggered()
{
    QString filename;
        filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");
        l.carregarArquivo(filename);
        for(int i=0;i<l.size();i++){
            ui->tabela->insertRow(i);
            inserirnaTabela();
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_lucro->setText("R$ "+QString::number(l.calcLucros()));

}
