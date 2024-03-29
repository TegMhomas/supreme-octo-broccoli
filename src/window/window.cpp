
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include "window.hpp"
#include <filesystem>
#include <spdlog/spdlog.h>
#include <string>
#include <filesystem>

Window::Window() {
  SPDLOG_INFO("constructing the window");

  m_window.create(sf::VideoMode(800, 600), "SUPREME-OCTO-RPG");
  m_window.setFramerateLimit(144);
  m_window.setVerticalSyncEnabled(true);

  std::string path_prefix = FindPathToResources();

  SPDLOG_INFO("found resources at " + path_prefix);

  /* if (!(m_font.loadFromFile(path_prefix +
                                 "fonts/SourceCodePro-Regular.ttf"))) {
    SPDLOG_CRITICAL("can't load font");
  }  */
  if (!(m_font.loadFromFile(path_prefix + "fonts/VTC-Tribal-Regular.ttf"))) {
    SPDLOG_CRITICAL("can't load font");
  }

  SPDLOG_INFO("loaded fonts");

  for (auto& path :
       std::filesystem::directory_iterator(path_prefix + "Tiles")) {

    auto name = path.path().filename().string();

    if (name.ends_with(".tsj")) {
      continue;
    }

    if (!m_textures[name].loadFromFile(path_prefix + "Tiles/" + name)) {
      SPDLOG_WARN("could not load: " + path_prefix + "Tiles/" + name);
    }
  }

  SPDLOG_INFO("loaded tile textures");

  for (auto& path :
       std::filesystem::directory_iterator(path_prefix + "Entities")) {

    auto name = path.path().filename().string();

    if (!m_textures[name].loadFromFile(path_prefix + "Entities/" + name)) {
      SPDLOG_WARN("could not load: " + path_prefix + "Entities/" + name);
    }
  }  
  std::string textureName = "hp_full.png";                          
  std::string texturePath = path_prefix + "Icons/" + textureName; 

  if (!m_textures[textureName].loadFromFile(texturePath)) {
    SPDLOG_ERROR("Could not load texture from path: {}", texturePath);
  } else {
    SPDLOG_INFO("Loaded texture: {}", textureName);
  }



  SPDLOG_INFO("loaded entity textures");

  SPDLOG_INFO("window constructed nicely, all resources loaded");
  SPDLOG_INFO("current path: " + std::filesystem::current_path().string());
}

Window::~Window() {}
