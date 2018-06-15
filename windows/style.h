#ifndef STYLE_H
#define STYLE_H

#include <string>
#include "paths.h"

const std::string css_widget = "QWidget {color: black; font-weight: bold}";
const std::string css_pushbutton = "QPushButton {color: white; text-decoration: none; padding: .5em 2em; outline: none; border-width: 2px 0; border-style: solid none; border-color: #FDBE33 #000 #D77206; border-radius: 6px; background: linear-gradient(#F3AE0F, #E38916) #E38916;}";
const std::string css_messagebox = "QMessageBox {background-color: #CD853F; background-image: url(" + img_bground + ")}";
const std::string css_journal = "color: black";
const std::string css_table = "QListWidget {background-color: #E6E6FA}";

#endif // STYLE_H
