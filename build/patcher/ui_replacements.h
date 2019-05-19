/********************************************************************************
** Form generated from reading UI file 'replacements.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEMENTS_H
#define UI_REPLACEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Replacements
{
public:
    QDialogButtonBox *okCancel_buttons;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *libToReplaceLabel;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *thunkLabel;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *gridLayoutWidget_2;
    QGridLayout *editLayout;
    QLineEdit *libraryEdit;
    QLabel *label_12;
    QLineEdit *functionEdit;
    QLabel *label_13;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *choseLayout;
    QComboBox *libraryCombo;
    QPushButton *addLibraryButton;
    QComboBox *functionCombo;
    QLabel *label_15;
    QLabel *label_14;

    void setupUi(QDialog *Replacements)
    {
        if (Replacements->objectName().isEmpty())
            Replacements->setObjectName(QStringLiteral("Replacements"));
        Replacements->setWindowModality(Qt::WindowModal);
        Replacements->resize(410, 337);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Replacements->sizePolicy().hasHeightForWidth());
        Replacements->setSizePolicy(sizePolicy);
        Replacements->setMinimumSize(QSize(410, 320));
        Replacements->setMaximumSize(QSize(410, 500));
        Replacements->setContextMenuPolicy(Qt::CustomContextMenu);
        Replacements->setAcceptDrops(true);
        Replacements->setAutoFillBackground(true);
        Replacements->setSizeGripEnabled(false);
        Replacements->setModal(false);
        okCancel_buttons = new QDialogButtonBox(Replacements);
        okCancel_buttons->setObjectName(QStringLiteral("okCancel_buttons"));
        okCancel_buttons->setGeometry(QRect(10, 300, 381, 32));
        okCancel_buttons->setOrientation(Qt::Horizontal);
        okCancel_buttons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Replacements);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 391, 101));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(9, 5, 9, 5);
        libToReplaceLabel = new QLineEdit(groupBox);
        libToReplaceLabel->setObjectName(QStringLiteral("libToReplaceLabel"));
        libToReplaceLabel->setReadOnly(true);

        gridLayout->addWidget(libToReplaceLabel, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        thunkLabel = new QLineEdit(groupBox);
        thunkLabel->setObjectName(QStringLiteral("thunkLabel"));
        thunkLabel->setEnabled(true);
        thunkLabel->setReadOnly(true);

        gridLayout->addWidget(thunkLabel, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(Replacements);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 110, 391, 191));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(10);
        gridLayout_4->setVerticalSpacing(5);
        gridLayout_4->setContentsMargins(5, 20, 5, 5);
        tabWidget = new QTabWidget(groupBox_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        gridLayoutWidget_2 = new QWidget(tab_1);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 361, 91));
        editLayout = new QGridLayout(gridLayoutWidget_2);
        editLayout->setObjectName(QStringLiteral("editLayout"));
        editLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        editLayout->setContentsMargins(10, 10, 10, 0);
        libraryEdit = new QLineEdit(gridLayoutWidget_2);
        libraryEdit->setObjectName(QStringLiteral("libraryEdit"));

        editLayout->addWidget(libraryEdit, 0, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        editLayout->addWidget(label_12, 1, 0, 1, 1);

        functionEdit = new QLineEdit(gridLayoutWidget_2);
        functionEdit->setObjectName(QStringLiteral("functionEdit"));

        editLayout->addWidget(functionEdit, 1, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        editLayout->addWidget(label_13, 0, 0, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 361, 91));
        choseLayout = new QGridLayout(gridLayoutWidget);
        choseLayout->setObjectName(QStringLiteral("choseLayout"));
        choseLayout->setContentsMargins(10, 10, 10, 0);
        libraryCombo = new QComboBox(gridLayoutWidget);
        libraryCombo->setObjectName(QStringLiteral("libraryCombo"));

        choseLayout->addWidget(libraryCombo, 0, 1, 1, 1);

        addLibraryButton = new QPushButton(gridLayoutWidget);
        addLibraryButton->setObjectName(QStringLiteral("addLibraryButton"));
        addLibraryButton->setMaximumSize(QSize(30, 16777215));
        addLibraryButton->setAutoFillBackground(true);

        choseLayout->addWidget(addLibraryButton, 0, 2, 1, 1);

        functionCombo = new QComboBox(gridLayoutWidget);
        functionCombo->setObjectName(QStringLiteral("functionCombo"));

        choseLayout->addWidget(functionCombo, 1, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setSizeIncrement(QSize(50, 0));

        choseLayout->addWidget(label_15, 1, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(50, 16777215));

        choseLayout->addWidget(label_14, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(okCancel_buttons, thunkLabel);
        QWidget::setTabOrder(thunkLabel, libToReplaceLabel);

        retranslateUi(Replacements);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Replacements);
    } // setupUi

    void retranslateUi(QDialog *Replacements)
    {
        Replacements->setWindowTitle(QApplication::translate("Replacements", "Define replacement", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Replacements", "Replace:", Q_NULLPTR));
        libToReplaceLabel->setPlaceholderText(QString());
        label_10->setText(QApplication::translate("Replacements", "Thunk:", Q_NULLPTR));
        label_11->setText(QApplication::translate("Replacements", "Function:", Q_NULLPTR));
        thunkLabel->setPlaceholderText(QString());
        groupBox_3->setTitle(QApplication::translate("Replacements", "With:", Q_NULLPTR));
        libraryEdit->setPlaceholderText(QApplication::translate("Replacements", "example.dll", Q_NULLPTR));
        label_12->setText(QApplication::translate("Replacements", "Function:", Q_NULLPTR));
        functionEdit->setPlaceholderText(QApplication::translate("Replacements", "functionName", Q_NULLPTR));
        label_13->setText(QApplication::translate("Replacements", "Library:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Replacements", "Edit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addLibraryButton->setToolTip(QApplication::translate("Replacements", "<html><head/><body><p>Load replacement library</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addLibraryButton->setText(QApplication::translate("Replacements", "+", Q_NULLPTR));
        label_15->setText(QApplication::translate("Replacements", "Function:", Q_NULLPTR));
        label_14->setText(QApplication::translate("Replacements", "Library:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Replacements", "Choose", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Replacements: public Ui_Replacements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEMENTS_H
