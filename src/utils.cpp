#include "utils.hpp"

std::string FindPathToResources() {
  std::string path_prefix = "";

  if (std::filesystem::exists("resources")) {
    path_prefix = "resources/";
    SPDLOG_INFO("found resources: " + path_prefix);

  } else if (std::filesystem::exists("../resources")) {
    path_prefix = "../resources/";
    SPDLOG_INFO("found resources at: " + path_prefix);

  } else if (std::filesystem::exists("../../resources")) {
    path_prefix = "../../resources/";
    SPDLOG_INFO("found resources at: " + path_prefix);

  } else if (std::filesystem::exists("../../../resources")) {
    path_prefix = "../../../resources/";
    SPDLOG_INFO("found resources at: " + path_prefix);

  } else {
    SPDLOG_CRITICAL("can't find directory: resources");
  }

  return path_prefix;
}