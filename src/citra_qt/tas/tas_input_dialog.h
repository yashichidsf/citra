// Copyright 2022 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <QDialog>
#include <common/common_types.h>

class HotkeyRegistry;
class QBoxLayout;
class QCheckBox;
class QDialog;
class QGroupBox;
class QSpinBox;
class QString;
class TASCheckBox;

namespace Ui {
class TASInputDialog;
}

class TASInputDialog : public QDialog {
    Q_OBJECT

public:
    explicit TASInputDialog(QWidget* parent, HotkeyRegistry& registry,
                             bool enable_web_config = true);
    ~TASInputDialog() override;

protected:
  TASCheckBox* CreateButton(const QString& name);
  QGroupBox* CreateStickInputs(QString name, QSpinBox*& x_value, QSpinBox*& y_value, u16 max_x,
                               u16 max_y, Qt::Key x_shortcut_key, Qt::Key y_shortcut_key);
  QBoxLayout* CreateSliderValuePairLayout(QString name, QSpinBox*& value, int default_, u16 max,
                                          Qt::Key shortcut_key, QWidget* shortcut_widget,
                                          bool invert = false);
  QSpinBox* CreateSliderValuePair(QBoxLayout* layout, int default_, u16 max,
                                  QKeySequence shortcut_key_sequence, Qt::Orientation orientation,
                                  QWidget* shortcut_widget, bool invert = false);
  template <typename UX>
  void GetButton(TASCheckBox* button, UX& pad, UX mask);
  void GetSpinBoxU8(QSpinBox* spin, u8& controller_value);
  void GetSpinBoxU16(QSpinBox* spin, u16& controller_value);

private slots:
    //void OnLanguageChanged(const QString& locale);

signals:
    //void LanguageChanged(const QString& locale);

private:
    void RetranslateUI();

    std::unique_ptr<Ui::TASInputDialog> ui;
    std::map<TASCheckBox*, bool> m_checkbox_set_by_controller;
    std::map<QSpinBox*, u8> m_spinbox_most_recent_values_u8;
    std::map<QSpinBox*, u8> m_spinbox_most_recent_values_u16;
    HotkeyRegistry& registry;

};