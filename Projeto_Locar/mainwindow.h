#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "locadora.h"
#include "cliente.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QCheckBox>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
//    void on_pushButton_clicked();



    void on_btn_ordenanome_clicked();

    void on_btn_cadastrar_clicked();

    void on_excluirCliente_clicked();

    void on_ocultarCliente_clicked();

    void on_mostrarOcultos_clicked();

    void on_tabela_cellClicked(int row, int column);

    void on_ordenar_data_clicked();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Locadora l;

    void inserirnaTabela();
};
#endif // MAINWINDOW_H
