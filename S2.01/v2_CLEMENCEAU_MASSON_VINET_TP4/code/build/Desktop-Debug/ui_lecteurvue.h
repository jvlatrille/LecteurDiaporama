/********************************************************************************
** Form generated from reading UI file 'lecteurvue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTEURVUE_H
#define UI_LECTEURVUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lecteurDiaporama
{
public:
    QAction *actionQuitter;
    QAction *actionVitesseDefilement;
    QAction *actionChargerDiapo;
    QAction *actionEnleverDiapo;
    QAction *actionAPropos;
    QAction *actionAutomatique;
    QAction *actionManuel;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *titreDiapo;
    QLabel *titreImage;
    QLabel *categorieImage;
    QLabel *rangImage;
    QLabel *imageDiapo;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *bPrecedent;
    QToolButton *bPause;
    QPushButton *bSuivant;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuParam_tres;
    QMenu *menuAide;
    QMenu *menuMode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *lecteurDiaporama)
    {
        if (lecteurDiaporama->objectName().isEmpty())
            lecteurDiaporama->setObjectName(QString::fromUtf8("lecteurDiaporama"));
        lecteurDiaporama->resize(800, 600);
        actionQuitter = new QAction(lecteurDiaporama);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionVitesseDefilement = new QAction(lecteurDiaporama);
        actionVitesseDefilement->setObjectName(QString::fromUtf8("actionVitesseDefilement"));
        actionChargerDiapo = new QAction(lecteurDiaporama);
        actionChargerDiapo->setObjectName(QString::fromUtf8("actionChargerDiapo"));
        actionEnleverDiapo = new QAction(lecteurDiaporama);
        actionEnleverDiapo->setObjectName(QString::fromUtf8("actionEnleverDiapo"));
        actionAPropos = new QAction(lecteurDiaporama);
        actionAPropos->setObjectName(QString::fromUtf8("actionAPropos"));
        actionAutomatique = new QAction(lecteurDiaporama);
        actionAutomatique->setObjectName(QString::fromUtf8("actionAutomatique"));
        actionManuel = new QAction(lecteurDiaporama);
        actionManuel->setObjectName(QString::fromUtf8("actionManuel"));
        centralwidget = new QWidget(lecteurDiaporama);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        titreDiapo = new QLabel(centralwidget);
        titreDiapo->setObjectName(QString::fromUtf8("titreDiapo"));

        horizontalLayout_3->addWidget(titreDiapo);

        titreImage = new QLabel(centralwidget);
        titreImage->setObjectName(QString::fromUtf8("titreImage"));

        horizontalLayout_3->addWidget(titreImage);

        categorieImage = new QLabel(centralwidget);
        categorieImage->setObjectName(QString::fromUtf8("categorieImage"));

        horizontalLayout_3->addWidget(categorieImage);

        rangImage = new QLabel(centralwidget);
        rangImage->setObjectName(QString::fromUtf8("rangImage"));

        horizontalLayout_3->addWidget(rangImage);


        verticalLayout->addLayout(horizontalLayout_3);

        imageDiapo = new QLabel(centralwidget);
        imageDiapo->setObjectName(QString::fromUtf8("imageDiapo"));

        verticalLayout->addWidget(imageDiapo);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        bPrecedent = new QPushButton(centralwidget);
        bPrecedent->setObjectName(QString::fromUtf8("bPrecedent"));

        horizontalLayout_4->addWidget(bPrecedent);

        bPause = new QToolButton(centralwidget);
        bPause->setObjectName(QString::fromUtf8("bPause"));

        horizontalLayout_4->addWidget(bPause);

        bSuivant = new QPushButton(centralwidget);
        bSuivant->setObjectName(QString::fromUtf8("bSuivant"));

        horizontalLayout_4->addWidget(bSuivant);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout);

        lecteurDiaporama->setCentralWidget(centralwidget);
        menubar = new QMenuBar(lecteurDiaporama);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuParam_tres = new QMenu(menubar);
        menuParam_tres->setObjectName(QString::fromUtf8("menuParam_tres"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuMode = new QMenu(menubar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        lecteurDiaporama->setMenuBar(menubar);
        statusbar = new QStatusBar(lecteurDiaporama);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        lecteurDiaporama->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuParam_tres->menuAction());
        menubar->addAction(menuMode->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionChargerDiapo);
        menuFichier->addAction(actionQuitter);
        menuParam_tres->addAction(actionVitesseDefilement);
        menuParam_tres->addAction(actionEnleverDiapo);
        menuAide->addAction(actionAPropos);
        menuMode->addAction(actionAutomatique);
        menuMode->addAction(actionManuel);

        retranslateUi(lecteurDiaporama);

        QMetaObject::connectSlotsByName(lecteurDiaporama);
    } // setupUi

    void retranslateUi(QMainWindow *lecteurDiaporama)
    {
        lecteurDiaporama->setWindowTitle(QCoreApplication::translate("lecteurDiaporama", "lecteurDiaporama", nullptr));
        actionQuitter->setText(QCoreApplication::translate("lecteurDiaporama", "Quitter", nullptr));
        actionVitesseDefilement->setText(QCoreApplication::translate("lecteurDiaporama", "Vitesse de d\303\251filement", nullptr));
        actionChargerDiapo->setText(QCoreApplication::translate("lecteurDiaporama", "Charger diaporama", nullptr));
        actionEnleverDiapo->setText(QCoreApplication::translate("lecteurDiaporama", "Enlever diaporama", nullptr));
        actionAPropos->setText(QCoreApplication::translate("lecteurDiaporama", "A propos", nullptr));
        actionAutomatique->setText(QCoreApplication::translate("lecteurDiaporama", "Automatique", nullptr));
        actionManuel->setText(QCoreApplication::translate("lecteurDiaporama", "Manuel", nullptr));
        titreDiapo->setText(QCoreApplication::translate("lecteurDiaporama", "TitreDiapo", nullptr));
        titreImage->setText(QCoreApplication::translate("lecteurDiaporama", "TitreImage", nullptr));
        categorieImage->setText(QCoreApplication::translate("lecteurDiaporama", "Categorie", nullptr));
        rangImage->setText(QCoreApplication::translate("lecteurDiaporama", "Rang", nullptr));
        imageDiapo->setText(QCoreApplication::translate("lecteurDiaporama", "Image diapo", nullptr));
        bPrecedent->setText(QCoreApplication::translate("lecteurDiaporama", "Pr\303\251c\303\251dent", nullptr));
        bPause->setText(QCoreApplication::translate("lecteurDiaporama", "Pause", nullptr));
        bSuivant->setText(QCoreApplication::translate("lecteurDiaporama", "Suivant", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("lecteurDiaporama", "Fichier", nullptr));
        menuParam_tres->setTitle(QCoreApplication::translate("lecteurDiaporama", "Param\303\250tres", nullptr));
        menuAide->setTitle(QCoreApplication::translate("lecteurDiaporama", "Aide", nullptr));
        menuMode->setTitle(QCoreApplication::translate("lecteurDiaporama", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lecteurDiaporama: public Ui_lecteurDiaporama {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTEURVUE_H
