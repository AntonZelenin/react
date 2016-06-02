#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include "pzmr.h"
#include "rw_1_3.h"
#include "rw_2_3.h"
#include "ufp_np.h"
#include "snp.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void optimalRegime();
    void feedbackRegime();
    void imposedRegime();

    QButtonGroup *groupOptStimul;
    QButtonGroup *groupOptAmount;
    QButtonGroup *groupOptPZMRexpo;
    QButtonGroup *groupOptRW13expo;
    QButtonGroup *groupOptRW23expo;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

    PZMR *pzmr;
    RW_1_3 *rw13;
    RW_2_3 *rw23;
    UFP_NP *ufp_np;
    SNP *snp;

private slots:
    void on_pbStart_clicked();

};

#endif // MAINWINDOW_H
