// Copyright 2022 Citra Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <QCheckBox>

class QMouseEvent;
class TASInputDialog;

class TASCheckBox : public QCheckBox
{
  Q_OBJECT
public:
  explicit TASCheckBox(const QString& text, TASInputDialog* parent);

  bool GetValue() const;

protected:
  void mousePressEvent(QMouseEvent* event) override;

private:
  const TASInputDialog* m_parent;
  int m_frame_turbo_started = 0;
  int m_turbo_press_frames = 0;
  int m_turbo_total_frames = 0;
};