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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lecteurVue
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
    QPushButton *bPause;
    QPushButton *bSuivant;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuParam_tres;
    QMenu *menuAide;
    QMenu *menuMode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *lecteurVue)
    {
        if (lecteurVue->objectName().isEmpty())
            lecteurVue->setObjectName(QString::fromUtf8("lecteurVue"));
        lecteurVue->resize(800, 600);
        actionQuitter = new QAction(lecteurVue);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionVitesseDefilement = new QAction(lecteurVue);
        actionVitesseDefilement->setObjectName(QString::fromUtf8("actionVitesseDefilement"));
        actionChargerDiapo = new QAction(lecteurVue);
        actionChargerDiapo->setObjectName(QString::fromUtf8("actionChargerDiapo"));
        actionEnleverDiapo = new QAction(lecteurVue);
        actionEnleverDiapo->setObjectName(QString::fromUtf8("actionEnleverDiapo"));
        actionAPropos = new QAction(lecteurVue);
        actionAPropos->setObjectName(QString::fromUtf8("actionAPropos"));
        actionAutomatique = new QAction(lecteurVue);
        actionAutomatique->setObjectName(QString::fromUtf8("actionAutomatique"));
        actionAutomatique->setCheckable(false);
        actionAutomatique->setChecked(false);
        actionAutomatique->setEnabled(true);
        actionManuel = new QAction(lecteurVue);
        actionManuel->setObjectName(QString::fromUtf8("actionManuel"));
        centralwidget = new QWidget(lecteurVue);
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

        bPause = new QPushButton(centralwidget);
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

        lecteurVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(lecteurVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuParam_tres = new QMenu(menubar);
        menuParam_tres->setObjectName(QString::fromUtf8("menuParam_tres"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuMode = new QMenu(menubar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        lecteurVue->setMenuBar(menubar);
        statusbar = new QStatusBar(lecteurVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        lecteurVue->setStatusBar(statusbar);

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

        retranslateUi(lecteurVue);

        QMetaObject::connectSlotsByName(lecteurVue);
    } // setupUi

    void retranslateUi(QMainWindow *lecteurVue)
    {
        lecteurVue->setWindowTitle(QCoreApplication::translate("lecteurVue", "lecteurVue", nullptr));
        actionQuitter->setText(QCoreApplication::translate("lecteurVue", "Quitter", nullptr));
        actionVitesseDefilement->setText(QCoreApplication::translate("lecteurVue", "Vitesse de d\303\251filement", nullptr));
        actionChargerDiapo->setText(QCoreApplication::translate("lecteurVue", "Charger diaporama", nullptr));
        actionEnleverDiapo->setText(QCoreApplication::translate("lecteurVue", "Enlever diaporama", nullptr));
        actionAPropos->setText(QCoreApplication::translate("lecteurVue", "A propos", nullptr));
        actionAutomatique->setText(QCoreApplication::translate("lecteurVue", "Automatique", nullptr));
        actionManuel->setText(QCoreApplication::translate("lecteurVue", "Manuel", nullptr));
        titreDiapo->setText(QCoreApplication::translate("lecteurVue", "TitreDiapo", nullptr));
        titreImage->setText(QCoreApplication::translate("lecteurVue", "TitreImage", nullptr));
        categorieImage->setText(QCoreApplication::translate("lecteurVue", "Categorie", nullptr));
        rangImage->setText(QCoreApplication::translate("lecteurVue", "Rang", nullptr));
        imageDiapo->setText(QCoreApplication::translate("lecteurVue", "Image diapo", nullptr));
        bPrecedent->setText(QCoreApplication::translate("lecteurVue", "Pr\303\251c\303\251dent", nullptr));
        bPause->setText(QCoreApplication::translate("lecteurVue", "Pause", nullptr));
        bSuivant->setText(QCoreApplication::translate("lecteurVue", "Suivant", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("lecteurVue", "Fichier", nullptr));
        menuParam_tres->setTitle(QCoreApplication::translate("lecteurVue", "Param\303\250tres", nullptr));
        menuAide->setTitle(QCoreApplication::translate("lecteurVue", "Aide", nullptr));
        menuMode->setTitle(QCoreApplication::translate("lecteurVue", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lecteurVue: public Ui_lecteurVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTEURVUE_H
