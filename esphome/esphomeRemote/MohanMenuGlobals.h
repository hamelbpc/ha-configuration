#pragma once
#include "esphome.h"

/*
PRIVATE CODE(used by PUBLIC CODE later on in this file)

*/

std::vector<std::shared_ptr<MenuTitleBase>> customRootMenuTitles() {
  return {
  std::make_shared<MenuTitleBase>("One", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Two", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Three", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Four", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Five", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Six", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Seven", "", ArrowMenuTitleState),
  std::make_shared<MenuTitleBase>("Eight", "", ArrowMenuTitleState),
  };
}

int rootMenuSize = customRootMenuTitles().size();

void call_homeassistant_service(const std::string &service_name) {
    HomeassistantServiceResponse resp;
    resp.service = service_name;
    id(homeassistantapi).send_homeassistant_service_call(resp);
}

void call_homeassistant_service(const std::string &service_name, const std::map<std::string, std::string> &data) {
    HomeassistantServiceResponse resp;
    resp.service = service_name;
    for (auto &it : data) {
      HomeassistantServiceMap kv;
      kv.key = it.first;
      kv.value = it.second;
      resp.data.push_back(kv);
    }
    id(homeassistantapi).send_homeassistant_service_call(resp);
}


/*
PUBLIC CODE (to be called from lambda in YAML file)
*/

void drawCustomRootMenu() {
  drawMenu(customRootMenuTitles());
}


void pressButton1() {
 resetMarquee();
 if (buttonPressWakeUpDisplay()) {
    return;
  }

 menuIndex++;
 if (menuIndex >= rootMenuSize) {
  menuIndex=0;
 }

 menuDrawing = false;
 displayUpdate.updateDisplay(true);
 menuDrawing = false;
}



void pressButton2() {
  //ESP_LOGD("script.test", "calling script");
  //call_homeassistant_service("script.test");
  /*
  call_homeassistant_service("script.testcallingfromttgo", {
    {"param1", "Hello"},
    {"param2", "World!"}
  });
  */
  /*
  call_homeassistant_service("script.testcallingfromttgo", {
    {"param1", to_string(42)},
    {"param2", to_string(5.34)}
  });
  */
}
