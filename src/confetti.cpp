// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

bool comparator (Particle& prev, Particle& current) { return (prev.pos.z < current.pos.z); }
  
void Confetti::createParticles(int size)
{
  mTexture = theRenderer.loadTexture("../textures/particle.png");
  for (int i = 0; i < size; i++)
  {
    Particle random = {random_unit_cube(), random_unit_vector(), vec4(random_unit_vector(), random_float()), 0.25f, 1.0f};
    mParticles.push_back(random);
  }
}

void Confetti::update(float dt)
{
  for (int i = 0; i < mParticles.size(); i++)
  {
    Particle particle = mParticles[i];
    vec3 position = particle.pos + dt * particle.vel;

    if (position.x < -1.0f)
    {
      particle.vel.x = -particle.vel.x;
      position.x = -1.0f;
    }
    if (position.y < -1.0f)
    {
      particle.vel.y = -particle.vel.y;
      position.y = -1.0f;
    }
    if (position.z < -1.0f)
    {
      particle.vel.z = -particle.vel.z;
      position.z = -1.0f;
    }
    if (position.x > 1.0f)
    {
      particle.vel.x = -particle.vel.x;
      position.x = 1.0f;
    }
    if (position.y > 1.0f)
    {
      particle.vel.y = -particle.vel.y;
      position.y = 1.0f;
    }
    if (position.z > 1.0f)
    {
      particle.vel.z = -particle.vel.z;
      position.z = 1.0f;
    }
    particle.pos = position;
    mParticles[i] = particle;
    sort(mParticles.begin(), mParticles.end(), comparator);
  }
}
