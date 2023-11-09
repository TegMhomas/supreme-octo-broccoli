#include "game/entity_stats.hpp"
#include <algorithm>

EntityStats::EntityStats() {
  setDefaultValues();
}

EntityStats::EntityStats(const std::unordered_map<StatType, float>& initialValues)
  : m_stats(initialValues) {
}

void EntityStats::setDefaultValues() {
  m_stats[HP] = 100.0f;    
  m_stats[SP] = 100.0f;     
  m_stats[Defense] = 0.0f; 
  m_stats[Attack] = 10.0f; 
  m_stats[MovementSpeed] = 1.0f; 
                        
}

float EntityStats::getStat(StatType stat) const {
  auto it = m_stats.find(stat);
  if (it != m_stats.end()) {
    return it->second;
  }
  return 0.0f; 
}

void EntityStats::setStat(StatType stat, float value) {
  m_stats[stat] = value;
}

void EntityStats::modifyStat(StatType stat, float amount) {
  m_stats[stat] = std::max(m_stats[stat] + amount, 0.0f);
}