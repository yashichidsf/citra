// Copyright 2022 Citra Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "tas/tas_checkbox.h"

#include <QMouseEvent>

#include "core/movie.h"
#include "tas/tas_input_dialog.h"


TASCheckBox::TASCheckBox(const QString& text, TASInputDialog* parent)
    : QCheckBox(text, parent), m_parent(parent)
{
  setTristate(true);
}

bool TASCheckBox::GetValue() const
{
  /*
  if (checkState() == Qt::PartiallyChecked)
  {
    const u64 frames_elapsed = Movie::GetCurrentFrame() - m_frame_turbo_started;
    return static_cast<int>(frames_elapsed % m_turbo_total_frames) < m_turbo_press_frames;
  }*/
  
  return isChecked();
}

void TASCheckBox::mousePressEvent(QMouseEvent* event)
{
  if (event->button() != Qt::RightButton)
  {
    setChecked(!isChecked());
    return;
  }

  if (checkState() == Qt::PartiallyChecked)
  {
    setCheckState(Qt::Unchecked);
    return;
  }

  //m_frame_turbo_started = Movie::GetCurrentFrame();
  //m_turbo_press_frames = m_parent->GetTurboPressFrames();
  //m_turbo_total_frames = m_turbo_press_frames + m_parent->GetTurboReleaseFrames();
  setCheckState(Qt::PartiallyChecked);
}