// Copyright 2022 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <map>
#include <QListWidgetItem>
#include "tas_input_dialog.h"
#include "tas_input_ui.h"
#include "tas_checkbox.h"

TASInputDialog::TASInputDialog(QWidget* parent, HotkeyRegistry& registry, bool enable_web_config)
    : QDialog(parent), ui(std::make_unique<Ui::TASInputDialog>()), registry(registry) {
    ui->setupUi(this);
    Ui_TASInputDialog *TASDialog{};
    //GetButton<u16>(TASDialog->a_button, , static_cast<u16>(TASDialog->padState->a.mask));
 /*
        padState->a.Assign(a_button->isChecked());
        padState->b.Assign(b_button->isChecked());
        padState->select.Assign(select_button->isChecked());
        padState->start.Assign(start_button->isChecked());
        padState->right.Assign(right_button->isChecked());
        padState->left.Assign(left_button->isChecked());
        padState->up.Assign(up_button->isChecked());
        padState->down.Assign(down_button->isChecked());
        padState->r.Assign(r_button->isChecked());
        padState->l.Assign(l_button->isChecked());
        padState->x.Assign(x_button->isChecked());
        padState->y.Assign(y_button->isChecked());
        Service::HID::DirectionState circledirection = Service::HID::GetStickDirectionState(circlePadX_value->value(), circlePadY_value->value());
        padState->circle_right.Assign(circledirection.right);
        padState->circle_left.Assign(circledirection.left);
        padState->circle_up.Assign(circledirection.up);
        padState->circle_down.Assign(circledirection.down);
        
        extraHid->buttons.zl_not_held.Assign(!zl_button->isChecked());
        extraHid->buttons.zr_not_held.Assign(!zr_button->isChecked());
        
        extraHid->c_stick.c_stick_x.Assign(cstickPadX_value->value());
        extraHid->c_stick.c_stick_y.Assign(cstickPadY_value->value());

        if(touchEnable->GetValue()) {
        //touchState->x.Assign(touchX_value->value());

        }
        */
}



//Q_DECLARE_METATYPE(QList<QWidget*>);

TASCheckBox* TASInputDialog::CreateButton(const QString& name)
{
  return new TASCheckBox(name, this);
}

TASInputDialog::~TASInputDialog() = default;

/*
QGroupBox* TASInputDialog::CreateStickInputs(QString name, QSpinBox*& x_value, QSpinBox*& y_value,
                                             u16 max_x, u16 max_y, Qt::Key x_shortcut_key,
                                             Qt::Key y_shortcut_key)
{
  const QKeySequence x_shortcut_key_sequence = QKeySequence(Qt::ALT + x_shortcut_key);
  const QKeySequence y_shortcut_key_sequence = QKeySequence(Qt::ALT + y_shortcut_key);

  auto* box =
      new QGroupBox(QStringLiteral("%1 (%2/%3)")
                        .arg(name, x_shortcut_key_sequence.toString(QKeySequence::NativeText),
                             y_shortcut_key_sequence.toString(QKeySequence::NativeText)));

  const int x_default = static_cast<int>(std::round(max_x / 2.));
  const int y_default = static_cast<int>(std::round(max_y / 2.));

  auto* x_layout = new QHBoxLayout;
  x_value = CreateSliderValuePair(x_layout, x_default, max_x, x_shortcut_key_sequence,
                                  Qt::Horizontal, box);

  auto* y_layout = new QVBoxLayout;
  y_value =
      CreateSliderValuePair(y_layout, y_default, max_y, y_shortcut_key_sequence, Qt::Vertical, box);
  y_value->setMaximumWidth(60);

  auto* visual = new StickWidget(this, max_x, max_y);
  visual->SetX(x_default);
  visual->SetY(y_default);

  connect(x_value, qOverload<int>(&QSpinBox::valueChanged), visual, &StickWidget::SetX);
  connect(y_value, qOverload<int>(&QSpinBox::valueChanged), visual, &StickWidget::SetY);
  connect(visual, &StickWidget::ChangedX, x_value, &QSpinBox::setValue);
  connect(visual, &StickWidget::ChangedY, y_value, &QSpinBox::setValue);

  auto* visual_ar = new AspectRatioWidget(visual, max_x, max_y);

  auto* visual_layout = new QHBoxLayout;
  visual_layout->addWidget(visual_ar);
  visual_layout->addLayout(y_layout);

  auto* layout = new QVBoxLayout;
  layout->addLayout(x_layout);
  layout->addLayout(visual_layout);
  box->setLayout(layout);

  return box;
}
/*
QBoxLayout* TASInputDialog::CreateSliderValuePairLayout(QString name, QSpinBox*& value,
                                                        int default_, u16 max, Qt::Key shortcut_key,
                                                        QWidget* shortcut_widget, bool invert)
{
  const QKeySequence shortcut_key_sequence = QKeySequence(Qt::ALT + shortcut_key);

  auto* label = new QLabel(QStringLiteral("%1 (%2)").arg(
      name, shortcut_key_sequence.toString(QKeySequence::NativeText)));

  QBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(label);

  value = CreateSliderValuePair(layout, default_, max, shortcut_key_sequence, Qt::Horizontal,
                                shortcut_widget, invert);

  return layout;
}

QSpinBox* TASInputDialog::CreateSliderValuePair(QBoxLayout* layout, int default_, u16 max,
                                                QKeySequence shortcut_key_sequence,
                                                Qt::Orientation orientation,
                                                QWidget* shortcut_widget, bool invert)
{
  auto* value = new QSpinBox();
  value->setRange(0, 99999);
  value->setValue(default_);
  connect(value, qOverload<int>(&QSpinBox::valueChanged), [value, max](int i) {
    if (i > max)
      value->setValue(max);
  });
  auto* slider = new TASSlider(default_, orientation);
  slider->setRange(0, max);
  slider->setValue(default_);
  slider->setFocusPolicy(Qt::ClickFocus);
  slider->setInvertedAppearance(invert);

  connect(slider, &QSlider::valueChanged, value, &QSpinBox::setValue);
  connect(value, qOverload<int>(&QSpinBox::valueChanged), slider, &QSlider::setValue);

  auto* shortcut = new QShortcut(shortcut_key_sequence, shortcut_widget);
  connect(shortcut, &QShortcut::activated, [value] {
    value->setFocus();
    value->selectAll();
  });

  layout->addWidget(slider);
  layout->addWidget(value);
  if (orientation == Qt::Vertical)
    layout->setAlignment(slider, Qt::AlignRight);

  return value;
}
*/
template <typename UX>
void TASInputDialog::GetButton(TASCheckBox* checkbox, UX& buttons, UX mask)
{
    /*
  const bool pressed = (buttons & mask) != 0;
  if (m_use_controller->isChecked())
  {
    if (pressed)
    {
      m_checkbox_set_by_controller[checkbox] = true;
      QueueOnObjectBlocking(checkbox, [checkbox] { checkbox->setChecked(true); });
    }
    else if (m_checkbox_set_by_controller.count(checkbox) && m_checkbox_set_by_controller[checkbox])
    {
      m_checkbox_set_by_controller[checkbox] = false;
      QueueOnObjectBlocking(checkbox, [checkbox] { checkbox->setChecked(false); });
    }
  }
  */
  if (checkbox->GetValue())
    buttons |= mask;
  else
    buttons &= ~mask;
}
template void TASInputDialog::GetButton<u8>(TASCheckBox* button, u8& pad, u8 mask);
template void TASInputDialog::GetButton<u16>(TASCheckBox* button, u16& pad, u16 mask);

/*
void TASInputDialog::GetSpinBoxU8(QSpinBox* spin, u8& controller_value)
{
  if (m_use_controller->isChecked())
  {
    if (!m_spinbox_most_recent_values_u8.count(spin) ||
        m_spinbox_most_recent_values_u8[spin] != controller_value)
    {
      QueueOnObjectBlocking(spin, [spin, controller_value] { spin->setValue(controller_value); });
    }

    m_spinbox_most_recent_values_u8[spin] = controller_value;
  }
  else
  {
    m_spinbox_most_recent_values_u8.clear();
  }

  controller_value = spin->value();
}

void TASInputDialog::GetSpinBoxU16(QSpinBox* spin, u16& controller_value)
{
  if (m_use_controller->isChecked())
  {
    if (!m_spinbox_most_recent_values_u16.count(spin) ||
        m_spinbox_most_recent_values_u16[spin] != controller_value)
    {
      QueueOnObjectBlocking(spin, [spin, controller_value] { spin->setValue(controller_value); });
    }

    m_spinbox_most_recent_values_u16[spin] = controller_value;
  }
  else
  {
    m_spinbox_most_recent_values_u16.clear();
  }

  controller_value = spin->value();
}

void TASInputDialog::RetranslateUI() {
    ui->retranslateUi(this);
      // restore selection after repopulating
   /* ui->selectorList->setCurrentRow(old_row);
    ui->tabWidget->setCurrentIndex(old_index);

    ui->generalTab->RetranslateUI();
    ui->systemTab->RetranslateUI();
    ui->inputTab->RetranslateUI();
    ui->hotkeysTab->RetranslateUI();
    ui->graphicsTab->RetranslateUI();
    ui->enhancementsTab->RetranslateUI();
    ui->audioTab->RetranslateUI();
    ui->cameraTab->RetranslateUI();
    ui->debugTab->RetranslateUI();
    ui->webTab->RetranslateUI();
    ui->uiTab->RetranslateUI();
    ui->storageTab->RetranslateUI();
    
}*/
