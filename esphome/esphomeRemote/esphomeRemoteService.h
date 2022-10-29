#include "esphome.h"
#include "DisplayUpdateInterface.h"
#include "MenuTitle.h"

#pragma once

class BaseService: public CustomAPIDevice {
  public:
    std::string entityId;
    std::string friendlyName;
    std::string serviceType;
    std::string getEntityId() { return entityId; }
    std::string getFriendlyName() { return friendlyName; }
    void callService() {
      if (serviceType == "script") {
        call_homeassistant_service(entityId.c_str());
      } else {
        call_homeassistant_service("scene.turn_on", {
          {"entity_id", entityId.c_str()}
        });
      }
    }

    void superSetup(std::string newEntityId, std::string newFriendlyName) {
      entityId = newEntityId;
      friendlyName = newFriendlyName;
    }
};

class SceneService: public BaseService {
  public:
    SceneService(std::string newEntityId, std::string newFriendlyName) {
      serviceType = "scene";
      superSetup(newEntityId, newFriendlyName); 
   }
};

class ScriptService: public BaseService {
  public:
    ScriptService(std::string newEntityId, std::string newFriendlyName) {
      serviceType = "script";
      superSetup(newEntityId, newFriendlyName); 
   }
};

class SceneGroupComponent : public CustomAPIDevice, public Component {
 public:
  std::vector<BaseService> services;

  void setup(std::vector<BaseService> newServices) {
    services = newServices;
  }

  std::vector<std::shared_ptr<MenuTitleBase>> sceneTitleStrings() {
    std::vector<std::shared_ptr<MenuTitleBase>> out;
    for (auto &service: services) {
      out.push_back(std::make_shared<MenuTitleBase>(service.getFriendlyName(), "", NoMenuTitleState));
    }
    return out;
  }

  bool selectScene(int index) {
   if(index >= 0 && index < services.size()) {
      BaseService service = services[index];
      ESP_LOGI("Scene", "Service called %s", service.getFriendlyName().c_str());
      service.callService();
      return false;
    }
    return true;
  }
};
