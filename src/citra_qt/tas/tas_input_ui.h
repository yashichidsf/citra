#ifndef UI_TAS_INPUT_H
#define UI_TAS_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <tas/stick_widget.h>
#include <tas/tas_checkbox.h>
#include <tas/touch_widget.h>
#include <tas/tas_input_dialog.h>
#include <QtWidgets/QGridLayout>
#include "core/movie.h"
#include "core/hle/service/hid/hid.h"
#include "core/hle/service/ir/extra_hid.h"

QT_BEGIN_NAMESPACE

class Ui_TASInputDialog
{
public:

    using pad_state = Service::HID::PadState;
    using touch_state = Service::HID::TouchDataEntry;
    using extra_hid = Service::IR::ExtraHIDResponse;
    extra_hid *extraHid{};

    touch_state *touchState{};

    pad_state *padState{};
    
    QLabel *labelTitle;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *sticksLayout;
    QGridLayout *sticksGrid;

    QGroupBox *circlePadBox;
    QGroupBox *cstickPadBox;
    QGroupBox *touchBox;
    QGroupBox *buttonsBox;
    QGroupBox *accelBox;
    QGroupBox *gyroBox;

    QLabel *circlePadLabel;
    QLabel *cstickPadLabel;
    QGridLayout *circlePadGrid;
    QGridLayout *cstickPadGrid;
    QVBoxLayout *circlePadBoxLayout;
    QVBoxLayout *cstickPadBoxLayout;
    QVBoxLayout *circlePadYSlideSpin;
    QHBoxLayout *circlePadXSlideSpin;
    QHBoxLayout *circlePadStickYSlideSpin;
    QVBoxLayout *cstickYSlideSpin;
    QHBoxLayout *cstickXSlideSpin;
    QHBoxLayout *cstickStickYSlideSpin;
    QSlider *circlePadX;
    QSlider *circlePadY;
    QSlider *cstickPadX;
    QSlider *cstickPadY;
    QSpinBox *circlePadX_value;
    QSpinBox *circlePadY_value;
    QSpinBox *cstickPadX_value;
    QSpinBox *cstickPadY_value;
    StickWidget *circlePadStick;
    StickWidget *cstickPadStick;

    QLabel *touchLabel;
    QGridLayout *touchGrid;
    TASCheckBox *touchEnable;
    TouchWidget *touchScreen;
    AspectRatioWidget *touchRatio;
    QVBoxLayout *touchBoxLayout;
    QVBoxLayout *touchYSlideSpin;
    QHBoxLayout *touchXSlideSpin;
    QHBoxLayout *touchStickYSlideSpin;
    QSlider *touchX;
    QSlider *touchY;
    QSpinBox *touchX_value;
    QSpinBox *touchY_value;

    QLabel *buttonLabel;
    QGridLayout *buttonGrid;
    QVBoxLayout *buttonBoxLayout;
    QHBoxLayout *shoulderButtons;
    QHBoxLayout *otherButtons;
    QGridLayout *dpadButtons;
    QGridLayout *abxyButtons;
    TASCheckBox *a_button;
    TASCheckBox *b_button;
    TASCheckBox *select_button;
    TASCheckBox *start_button;
    TASCheckBox *right_button;
    TASCheckBox *left_button;
    TASCheckBox *up_button;
    TASCheckBox *down_button;
    TASCheckBox *r_button;
    TASCheckBox *l_button;
    TASCheckBox *x_button;
    TASCheckBox *y_button;
    TASCheckBox *zl_button;
    TASCheckBox *zr_button;

    QLabel *accelLabel;
    QGridLayout *accelGrid;
    QVBoxLayout *accelBoxLayout;
    QHBoxLayout *accelXBox;
    QHBoxLayout *accelYBox;
    QHBoxLayout *accelZBox;
    QLabel *accelX_label;
    QLabel *accelY_label;
    QLabel *accelZ_label;
    QSlider *accelX;
    QSlider *accelY;
    QSlider *accelZ;
    QSpinBox *accelX_value;
    QSpinBox *accelY_value;
    QSpinBox *accelZ_value;

    QLabel *gyroLabel;
    QGridLayout *gyroGrid;
    QVBoxLayout *gyroBoxLayout;
    QHBoxLayout *gyroXBox;
    QHBoxLayout *gyroYBox;
    QHBoxLayout *gyroZBox;
    QLabel *gyroX_label;
    QLabel *gyroY_label;
    QLabel *gyroZ_label;
    QSlider *gyroX;
    QSlider *gyroY;
    QSlider *gyroZ;
    QSpinBox *gyroX_value;
    QSpinBox *gyroY_value;
    QSpinBox *gyroZ_value;

    void setupUi(QDialog *TASInputDialog)
    {
        if (TASInputDialog->objectName().isEmpty())
            TASInputDialog->setObjectName(QStringLiteral("TASInputDialog"));
        TASInputDialog->setWindowModality(Qt::ApplicationModal);
        TASInputDialog->resize(400, 938);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TASInputDialog->sizePolicy().hasHeightForWidth());
        TASInputDialog->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(TASInputDialog);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        labelTitle = new QLabel(TASInputDialog);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QFont font;
        font.setPointSize(10);
        labelTitle->setFont(font);

        //Setup circle pad and c-stick arrangement
        sticksLayout = new QHBoxLayout();
        sticksLayout->setObjectName(QStringLiteral("sticksLayout"));
        sticksGrid = new QGridLayout();
        sticksGrid->setObjectName(QStringLiteral("sticksGrid"));
        
        //CIRCLE PAD
        circlePadBox = new QGroupBox(QStringLiteral("Circle Pad"));
        circlePadBox->setObjectName(QStringLiteral("circlePadBox"));
        circlePadBox->setMaximumHeight(300);

        circlePadGrid = new QGridLayout(circlePadBox);
        circlePadGrid->setObjectName(QStringLiteral("circlePadGrid"));
        circlePadBoxLayout = new QVBoxLayout();
        circlePadBoxLayout->setObjectName(QStringLiteral("circlePadBoxLayout"));
        circlePadXSlideSpin = new QHBoxLayout();
        circlePadXSlideSpin->setObjectName(QStringLiteral("circlePadXSlideSpin"));
        circlePadX = new QSlider(Qt::Horizontal);
        circlePadX->setObjectName(QStringLiteral("circlePadX"));
        circlePadX->setRange(0,255);
        circlePadX->setValue(0);
        circlePadX->setFocusPolicy(Qt::ClickFocus);
        circlePadGrid->addWidget(circlePadX, 0,0);
        circlePadX_value = new QSpinBox();
        circlePadX_value->setObjectName(QStringLiteral("circlePadX_value"));
        circlePadX_value->setRange(0,255);
        circlePadX_value->setValue(0);
        circlePadGrid->addWidget(circlePadX_value, 0,1);
              
        circlePadStickYSlideSpin = new QHBoxLayout();
        circlePadStickYSlideSpin->setObjectName(QStringLiteral("circlePadStickYSlidespin"));
        circlePadStick = new StickWidget(circlePadBox, 255, 255);
        circlePadStick->setObjectName(QStringLiteral("circlePadStick"));
        circlePadGrid->addWidget(circlePadStick, 1, 0);
        circlePadYSlideSpin = new QVBoxLayout();
        circlePadYSlideSpin->setObjectName(QStringLiteral("circlePadYSlideSpin"));
        circlePadY = new QSlider(Qt::Vertical);
        circlePadY->setObjectName(QStringLiteral("circlePadY"));
        circlePadY->setMaximumWidth(60);
        circlePadY->setRange(0,255);
        circlePadY->setValue(0);
        circlePadY->setFocusPolicy(Qt::ClickFocus);
        circlePadY_value = new QSpinBox();
        circlePadY_value->setObjectName(QStringLiteral("circlePadY_value"));
        circlePadY_value->setRange(0,255);
        circlePadY_value->setValue(0);
        circlePadYSlideSpin->addWidget(circlePadY);
        circlePadYSlideSpin->addWidget(circlePadY_value);
        circlePadGrid->addLayout(circlePadYSlideSpin, 1,1);

        circlePadBox->setLayout(circlePadBoxLayout);
        sticksGrid->addWidget(circlePadBox, 0,0);
        QObject::connect(circlePadX, &QSlider::valueChanged, circlePadX_value, &QSpinBox::setValue);
        QObject::connect(circlePadY, &QSlider::valueChanged, circlePadY_value, &QSpinBox::setValue);
        QObject::connect(circlePadX_value, qOverload<int>(&QSpinBox::valueChanged), circlePadX, &QSlider::setValue);
        QObject::connect(circlePadY_value, qOverload<int>(&QSpinBox::valueChanged), circlePadY, &QSlider::setValue);
 //       QObject::connect(circlePadX_value, qOverload<int>(&QSpinBox::valueChanged), circlePadStick, &StickWidget::SetX);
 //       QObject::connect(circlePadY_value, qOverload<int>(&QSpinBox::valueChanged), circlePadStick, &StickWidget::SetY);
        QObject::connect(circlePadStick, &StickWidget::ChangedX, circlePadX_value, &QSpinBox::setValue);
        QObject::connect(circlePadStick, &StickWidget::ChangedY, circlePadY_value, &QSpinBox::setValue);

        //CSTICK PAD
        cstickPadBox = new QGroupBox(QStringLiteral("CStick"));
        cstickPadBox->setObjectName(QStringLiteral("cstickPadBox"));
        cstickPadBox->setMaximumHeight(300);
        cstickPadGrid = new QGridLayout(cstickPadBox);
        cstickPadGrid->setObjectName(QStringLiteral("cstickPadGrid"));
        cstickPadBoxLayout = new QVBoxLayout();
        cstickPadBoxLayout->setObjectName(QStringLiteral("cstickPadBoxLayout"));
        cstickXSlideSpin = new QHBoxLayout();
        cstickXSlideSpin->setObjectName(QStringLiteral("cstickPadXSlideSpin"));
        cstickPadX = new QSlider(Qt::Horizontal);
        cstickPadX->setObjectName(QStringLiteral("cstickPadX"));
        cstickPadX->setRange(0,255);
        cstickPadGrid->addWidget(cstickPadX, 0,0);
        cstickPadX_value = new QSpinBox();
        cstickPadX_value->setObjectName(QStringLiteral("cstickPadX_value"));
        cstickPadX_value->setRange(0,255);
        cstickPadGrid->addWidget(cstickPadX_value, 0,1);

        cstickStickYSlideSpin = new QHBoxLayout();
        cstickStickYSlideSpin->setObjectName(QStringLiteral("cstickPadStickYSlidespin"));
        cstickPadStick = new StickWidget(cstickPadBox, 255, 255);
        cstickPadStick->setObjectName(QStringLiteral("cstickPadStick"));
        cstickPadGrid->addWidget(cstickPadStick, 1, 0);
        cstickYSlideSpin = new QVBoxLayout();
        cstickYSlideSpin->setObjectName(QStringLiteral("cstickPadYSlideSpin"));
        cstickPadY = new QSlider(Qt::Vertical);
        cstickPadY->setObjectName(QStringLiteral("cstickPadY"));
        cstickPadY->setMaximumWidth(60);
        cstickPadY->setRange(0,255);
        cstickPadY_value = new QSpinBox();
        cstickPadY_value->setObjectName(QStringLiteral("cstickPadY_value"));
        cstickPadY_value->setRange(0,255);
        cstickYSlideSpin->addWidget(cstickPadY);
        cstickYSlideSpin->addWidget(cstickPadY_value);
        cstickPadGrid->addLayout(cstickYSlideSpin, 1,1);

        cstickPadBox->setLayout(cstickPadBoxLayout);
        sticksGrid->addWidget(cstickPadBox, 0,1);

        vboxLayout->addLayout(sticksGrid);

        QObject::connect(cstickPadX, &QSlider::valueChanged, cstickPadX_value, &QSpinBox::setValue);
        QObject::connect(cstickPadY, &QSlider::valueChanged, cstickPadY_value, &QSpinBox::setValue);
        QObject::connect(cstickPadX_value, qOverload<int>(&QSpinBox::valueChanged), cstickPadX, &QSlider::setValue);
        QObject::connect(cstickPadY_value, qOverload<int>(&QSpinBox::valueChanged), cstickPadY, &QSlider::setValue);
    //    QObject::connect(cstickPadX_value, qOverload<int>(&QSpinBox::valueChanged), cstickPadStick, &StickWidget::SetX);
    //    QObject::connect(cstickPadY_value, qOverload<int>(&QSpinBox::valueChanged), cstickPadStick, &StickWidget::SetY);
        QObject::connect(cstickPadStick, &StickWidget::ChangedX, cstickPadX_value, &QSpinBox::setValue);
        QObject::connect(cstickPadStick, &StickWidget::ChangedY, cstickPadY_value, &QSpinBox::setValue);

        //TOUCH SCREEN
        touchBox = new QGroupBox(QStringLiteral("Touch Screen"));
        touchBox->setObjectName(QStringLiteral("touchBox"));
        touchLabel = new QLabel(touchBox);
        touchLabel->setObjectName(QStringLiteral("touchLabel"));
        touchGrid = new QGridLayout(touchBox);
        touchGrid->setObjectName(QStringLiteral("touchGrid"));
        touchXSlideSpin = new QHBoxLayout();
        touchXSlideSpin->setObjectName(QStringLiteral("touchXSlideSpin"));
        touchEnable = new TASCheckBox(QStringLiteral("&Touch"), nullptr); //uhhh
        touchEnable->setObjectName(QStringLiteral("touchEnable"));
        touchX = new QSlider(Qt::Horizontal);
        touchX->setObjectName(QStringLiteral("touchX"));
        touchX->setRange(0,319);
//       touchX->setInvertedAppearance(true);
        touchX_value = new QSpinBox();
        touchX_value->setObjectName(QStringLiteral("touchX_value"));
        touchX_value->setRange(0,319);

        touchXSlideSpin->addWidget(touchEnable);
        touchXSlideSpin->addWidget(touchX);

        touchGrid->addLayout(touchXSlideSpin, 0,0);
        touchGrid->addWidget(touchX_value, 0,1);

        touchScreen = new TouchWidget(touchBox);
        touchScreen->setObjectName(QStringLiteral("touchScreen"));
        touchScreen->setFixedSize(320,240);

        
        touchYSlideSpin = new QVBoxLayout();
        touchYSlideSpin->setObjectName(QStringLiteral("touchYSlideSpin"));
        touchY = new QSlider(Qt::Vertical);
        touchY->setObjectName(QStringLiteral("touchY"));
        touchY->setRange(0,239);
//        touchY->setInvertedAppearance(true);
        touchYSlideSpin->addWidget(touchY);
        touchY_value = new QSpinBox();
        touchY_value->setObjectName(QStringLiteral("touchY_value"));
        touchY_value->setRange(0,239);

        touchYSlideSpin->addWidget(touchY_value);

        touchGrid->addWidget(touchScreen, 1,0);
        touchGrid->addLayout(touchYSlideSpin, 1,1);
        touchBox->setLayout(touchGrid);
        vboxLayout->addWidget(touchBox);

        QObject::connect(touchX, &QSlider::valueChanged, touchX_value, &QSpinBox::setValue);
        QObject::connect(touchY, &QSlider::valueChanged, touchY_value, &QSpinBox::setValue);
        QObject::connect(touchX_value, qOverload<int>(&QSpinBox::valueChanged), touchX, &QSlider::setValue);
        QObject::connect(touchY_value, qOverload<int>(&QSpinBox::valueChanged), touchY, &QSlider::setValue);
        //QObject::connect(touchX_value, qOverload<int>(&QSpinBox::valueChanged), touchScreen, &TouchWidget::SetX);
        //QObject::connect(touchY_value, qOverload<int>(&QSpinBox::valueChanged), touchScreen, &TouchWidget::SetY);
        QObject::connect(touchScreen, &TouchWidget::ChangedX, touchX_value, &QSpinBox::setValue);
        QObject::connect(touchScreen, &TouchWidget::ChangedY, touchY_value, &QSpinBox::setValue);

        //BUTTONS
        buttonsBox = new QGroupBox(QStringLiteral("Buttons"));
        buttonsBox->setObjectName(QStringLiteral("buttonsBox"));
        buttonGrid = new QGridLayout(buttonsBox);
        buttonGrid->setObjectName(QStringLiteral("buttonGrid"));
        a_button = new TASCheckBox(QStringLiteral("&A"), nullptr);
        a_button->setObjectName(QStringLiteral("a_button"));
        b_button = new TASCheckBox(QStringLiteral("&B"), nullptr);
        b_button->setObjectName(QStringLiteral("b_button"));
        select_button = new TASCheckBox(QStringLiteral("Select"), nullptr);
        select_button->setObjectName(QStringLiteral("select_button"));
        start_button = new TASCheckBox(QStringLiteral("Start"), nullptr);
        start_button->setObjectName(QStringLiteral("start_button"));
        right_button = new TASCheckBox(QStringLiteral("Right"), nullptr);
        right_button->setObjectName(QStringLiteral("right_button"));
        left_button = new TASCheckBox(QStringLiteral("Left"), nullptr);
        left_button->setObjectName(QStringLiteral("left_button"));
        up_button = new TASCheckBox(QStringLiteral("Up"), nullptr);
        up_button->setObjectName(QStringLiteral("up_button"));
        down_button = new TASCheckBox(QStringLiteral("Down"), nullptr);
        down_button->setObjectName(QStringLiteral("down_button"));
        r_button = new TASCheckBox(QStringLiteral("&R"), nullptr);
        r_button->setObjectName(QStringLiteral("r_button"));
        l_button = new TASCheckBox(QStringLiteral("&L"), nullptr);
        l_button->setObjectName(QStringLiteral("l_button"));
        x_button = new TASCheckBox(QStringLiteral("&X"), nullptr);
        x_button->setObjectName(QStringLiteral("x_button"));
        y_button = new TASCheckBox(QStringLiteral("&Y"), nullptr);
        y_button->setObjectName(QStringLiteral("y_button"));
        zl_button = new TASCheckBox(QStringLiteral("ZL"), nullptr);
        zl_button->setObjectName(QStringLiteral("zl_button"));
        zr_button = new TASCheckBox(QStringLiteral("ZR"), nullptr);
        zr_button->setObjectName(QStringLiteral("zr_button"));

        buttonGrid->addWidget(zl_button, 0,0);
        buttonGrid->addWidget(l_button, 0,2);
        buttonGrid->addWidget(r_button, 0,5);
        buttonGrid->addWidget(zr_button, 0,7);
        buttonGrid->addWidget(up_button, 1,1);
        buttonGrid->addWidget(x_button, 1,6);
        buttonGrid->addWidget(left_button, 2,0);
        buttonGrid->addWidget(right_button, 2,2);
        buttonGrid->addWidget(y_button, 2,5);
        buttonGrid->addWidget(a_button, 2,7);
        buttonGrid->addWidget(down_button, 3,1);
        buttonGrid->addWidget(b_button, 3,6);
        buttonGrid->addWidget(select_button, 4,3);
        buttonGrid->addWidget(start_button, 4,4);

        buttonsBox->setLayout(buttonGrid);

        vboxLayout->addWidget(buttonsBox);

        //ACCELEROMETER
        accelBox = new QGroupBox(QStringLiteral("Accelerometer"));
        accelBox->setObjectName(QStringLiteral("accelBox"));
        accelGrid = new QGridLayout(accelBox);
        accelGrid->setObjectName(QStringLiteral("accelGrid"));
        accelX_label = new QLabel(QStringLiteral("X"));
        accelX_label->setObjectName(QStringLiteral("accelX_label"));
        accelY_label = new QLabel(QStringLiteral("Y"));
        accelY_label->setObjectName(QStringLiteral("accelY_label"));
        accelZ_label = new QLabel(QStringLiteral("Z"));
        accelZ_label->setObjectName(QStringLiteral("accelZ_label"));
        accelX = new QSlider(Qt::Horizontal);
        accelX->setObjectName(QStringLiteral("accelX"));
        accelX->setRange(0,65535);
        accelY = new QSlider(Qt::Horizontal);
        accelY->setObjectName(QStringLiteral("accelY"));
        accelY->setRange(0,65535);
        accelZ = new QSlider(Qt::Horizontal);
        accelZ->setObjectName(QStringLiteral("accelZ"));
        accelZ->setRange(0,65535);
        accelX_value = new QSpinBox();
        accelX_value->setObjectName(QStringLiteral("accelX_value"));
        accelX_value->setRange(0,65535);
        accelY_value = new QSpinBox();
        accelY_value->setObjectName(QStringLiteral("accelY_value"));
        accelY_value->setRange(0,65535);
        accelZ_value = new QSpinBox();
        accelZ_value->setObjectName(QStringLiteral("accelZ_value"));
        accelZ_value->setRange(0,65535);

        accelGrid->addWidget(accelX_label, 0,0);
        accelGrid->addWidget(accelX, 0,1);
        accelGrid->addWidget(accelX_value, 0,2);
        accelGrid->addWidget(accelY_label, 1,0);
        accelGrid->addWidget(accelY, 1,1);
        accelGrid->addWidget(accelY_value, 1,2);
        accelGrid->addWidget(accelZ_label, 2,0);
        accelGrid->addWidget(accelZ, 2,1);
        accelGrid->addWidget(accelZ_value, 2,2);

        accelBox->setLayout(accelGrid);

        vboxLayout->addWidget(accelBox);
        QObject::connect(accelX, &QSlider::valueChanged, accelX_value, &QSpinBox::setValue);
        QObject::connect(accelY, &QSlider::valueChanged, accelY_value, &QSpinBox::setValue);
        QObject::connect(accelZ, &QSlider::valueChanged, accelZ_value, &QSpinBox::setValue);
        QObject::connect(accelX_value, qOverload<int>(&QSpinBox::valueChanged), accelX, &QSlider::setValue);
        QObject::connect(accelY_value, qOverload<int>(&QSpinBox::valueChanged), accelY, &QSlider::setValue);
        QObject::connect(accelZ_value, qOverload<int>(&QSpinBox::valueChanged), accelZ, &QSlider::setValue);

        //GYRO
        gyroBox = new QGroupBox(QStringLiteral("Gyro"));
        gyroBox->setObjectName(QStringLiteral("gyroBox"));
        gyroGrid = new QGridLayout(gyroBox);
        gyroGrid->setObjectName(QStringLiteral("gyroGrid"));
        gyroX_label = new QLabel(QStringLiteral("X"));
        gyroX_label->setObjectName(QStringLiteral("gyroX_label"));
        gyroY_label = new QLabel(QStringLiteral("Y"));
        gyroY_label->setObjectName(QStringLiteral("gyroY_label"));
        gyroZ_label = new QLabel(QStringLiteral("Z"));
        gyroZ_label->setObjectName(QStringLiteral("gyroZ_label"));
        gyroX = new QSlider(Qt::Horizontal);
        gyroX->setObjectName(QStringLiteral("gyroX"));
        gyroX->setRange(0,65535);
        gyroY = new QSlider(Qt::Horizontal);
        gyroY->setObjectName(QStringLiteral("gyroY"));
        gyroY->setRange(0,65535);
        gyroZ = new QSlider(Qt::Horizontal);
        gyroZ->setObjectName(QStringLiteral("gyroZ"));
        gyroZ->setRange(0,65535);
        gyroX_value = new QSpinBox();
        gyroX_value->setObjectName(QStringLiteral("gyroX_value"));
        gyroX_value->setRange(0,65535);
        gyroY_value = new QSpinBox();
        gyroY_value->setObjectName(QStringLiteral("gyroY_value"));
        gyroY_value->setRange(0,65535);
        gyroZ_value = new QSpinBox();
        gyroZ_value->setObjectName(QStringLiteral("gyroZ_value"));
        gyroZ_value->setRange(0,65535);

        gyroGrid->addWidget(gyroX_label, 0,0);
        gyroGrid->addWidget(gyroX, 0,1);
        gyroGrid->addWidget(gyroX_value, 0,2);
        gyroGrid->addWidget(gyroY_label, 1,0);
        gyroGrid->addWidget(gyroY, 1,1);
        gyroGrid->addWidget(gyroY_value, 1,2);
        gyroGrid->addWidget(gyroZ_label, 2,0);
        gyroGrid->addWidget(gyroZ, 2,1);
        gyroGrid->addWidget(gyroZ_value, 2,2);

        gyroBox->setLayout(gyroGrid);

        vboxLayout->addWidget(gyroBox);

        QObject::connect(gyroX, &QSlider::valueChanged, gyroX_value, &QSpinBox::setValue);
        QObject::connect(gyroY, &QSlider::valueChanged, gyroY_value, &QSpinBox::setValue);
        QObject::connect(gyroZ, &QSlider::valueChanged, gyroZ_value, &QSpinBox::setValue);
        QObject::connect(gyroX_value, qOverload<int>(&QSpinBox::valueChanged), gyroX, &QSlider::setValue);
        QObject::connect(gyroY_value, qOverload<int>(&QSpinBox::valueChanged), gyroY, &QSlider::setValue);
        QObject::connect(gyroZ_value, qOverload<int>(&QSpinBox::valueChanged), gyroZ, &QSlider::setValue);
 
        retranslateUi(TASInputDialog);

        QMetaObject::connectSlotsByName(TASInputDialog);
    } // setupUi

    void retranslateUi(QDialog *TASInputDialog)
    {
        TASInputDialog->setWindowTitle(QApplication::translate("TASInputDialog", "TAS Input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TASInputDialog: public Ui_TASInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAS_INPUT_H
