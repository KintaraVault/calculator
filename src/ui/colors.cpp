// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#include "colors.h"

#include "ui/theme.h"

using namespace cutefish::ui;

void addCalculatorColors(ColorMixer& mixer, const Theme& theme)
{
    const bool dark = theme.darkMode;
    mixer[CalculatorColor::WindowBackground] =
            wallpaperTinted(theme.secondBackground.withAlpha(0.96));

    const Color key = dark ? Color::rgb(0x3F3F41) : Color::rgb(0xFFFFFF);
    mixer[CalculatorColor::Key] = key;
    mixer[CalculatorColor::KeyRim] = dark ? Color::rgb(0xFFFFFF).withAlpha(.14) : Color::rgb(0x000000).withAlpha(.08);
    mixer[CalculatorColor::KeyHovered] = dark ? key.lighter(1.12) : key.darker(1.03);
    mixer[CalculatorColor::KeyPressed] = dark ? key.lighter(1.3) : key.darker(1.08);

    const Color operatorKey = theme.alternateBackground;
    mixer[CalculatorColor::OperatorKey] = operatorKey;
    mixer[CalculatorColor::OperatorKeyRim] = CalculatorColor::KeyRim;
    mixer[CalculatorColor::OperatorKeyHovered] = dark ? operatorKey.lighter(1.16) : operatorKey.darker(1.03);
    mixer[CalculatorColor::OperatorKeyPressed] = dark ? operatorKey.lighter(1.32) : operatorKey.darker(1.08);

    mixer[CalculatorColor::AccentKey] = ColorId::MenuHighlight;
    mixer[CalculatorColor::AccentKeyRim] = Color::rgb(0xFFFFFF).withAlpha(.19);
    mixer[CalculatorColor::AccentKeyHovered] = lighter(ColorId::MenuHighlight, 1.05);
    mixer[CalculatorColor::AccentKeyPressed] = darker(ColorId::MenuHighlight, 1.14);

    mixer[CalculatorColor::InactiveAccentKey] = Color::rgb(dark ? 0x59595C : 0x626267);
    mixer[CalculatorColor::InactiveAccentKeyRim] = CalculatorColor::AccentKeyRim;

    mixer[CalculatorColor::KeyShadow] = dark ? Color::rgb(0x000000).withAlpha(0) : Color::rgb(0x000000).withAlpha(0.07);
    mixer[CalculatorColor::AccentKeyShadow] = withAlpha(ColorId::MenuHighlight, dark ? .18 : .22);
}
