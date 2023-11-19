#include "physics.hpp"

Physics::Physics()
  : m_b2_world(b2Vec2{ 0, 0 }) {

  b2BodyDef static_body_def;
  static_body_def.type = b2_staticBody;
  static_body_def.position.Set(0, 0);
  m_static_body = m_b2_world.CreateBody(&static_body_def);
}

Physics::~Physics() {}

void Physics::simulateOneTick() {
  constexpr float time_step = 1.0f / 60.0f;
  constexpr int velocity_iterations = 6;
  constexpr int position_iterations = 2;
  m_b2_world.Step(time_step, velocity_iterations, position_iterations);
}

void Physics::updateEntity(Entity& entity) {

  if (!entity.m_physics_body) {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.position.Set(entity.m_position.x, entity.m_position.y);
    entity.m_physics_body = m_b2_world.CreateBody(&body_def);

    b2PolygonShape shape;
    shape.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixture_def;
    fixture_def.shape = &shape;
    fixture_def.density = 1.0f;
    fixture_def.friction = 0.3f;

    entity.m_physics_body->CreateFixture(&fixture_def);

    b2FrictionJointDef friction_joint_def;
    friction_joint_def.bodyA = entity.m_physics_body;
    friction_joint_def.bodyB = m_static_body;
    friction_joint_def.maxForce = 20.0f;
    friction_joint_def.localAnchorA = entity.m_physics_body->GetLocalCenter();
    friction_joint_def.localAnchorA = m_static_body->GetLocalCenter();

    m_b2_world.CreateJoint(&friction_joint_def);
  }

  entity.m_physics_body->ApplyForceToCenter({ entity.m_acceleration.x * 10, entity.m_acceleration.y * 10 }, true);
  entity.m_acceleration = {};
  // TODO: rename m_acceleration to m_acceleration_to_apply or something

  entity.m_position = sf::Vector2f({ entity.m_physics_body->GetPosition().x, entity.m_physics_body->GetPosition().y });
}
