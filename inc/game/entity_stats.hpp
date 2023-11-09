#pragma once

#include <string>
#include <unordered_map>

class EntityStats {
public:
  enum StatType {
    HP,
    SP,
    Defense,
    Attack,
    MovementSpeed,
  };

  EntityStats();
  EntityStats(const std::unordered_map<StatType, float>& initialValues);

  float getStat(StatType stat) const;
  void setStat(StatType stat, float value);
  void modifyStat(StatType stat, float amount);

private:
  std::unordered_map<StatType, float> m_stats;
  void setDefaultValues();
};