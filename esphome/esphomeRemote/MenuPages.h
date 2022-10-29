#pragma once
#include "esphome.h"

/*
PRIVATE CODE(used by PUBLIC CODE later on in this file)

*/

std::vector<std::shared_ptr<MenuTitleBase>> tastyTreatsMenu() {
  return {
  std::make_shared<MenuTitleBase>("Icecream", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Chocolate", "", ArrowMenuTitleState)
  };
}

int tastytreatsMenuSize = tastyTreatsMenu().size();


/*
PUBLIC CODE (to be called from lambda in YAML file)
*/

void drawTastyMenu() {
  drawMenu(tastyTreatsMenu());
}
