// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;


bool comparatorCloud (Particle& prev, Particle& current) { return (prev.pos.z < current.pos.z); }
void MyParticleSystem::createParticles(int size) 
{
   //mTexture1 = theRenderer.loadTexture("../textures/moon.png");
   //Particle moon = {vec3(0.45,0.45,0), vec3(0,0,0), vec4(vec3(1,1,1), 0.5), 2.0f,0.1};
   //mParticles.push_back(moon);
   mTexture = theRenderer.loadTexture("../textures/ParticleCloudWhite.png");
  for (int i = 0; i < size; i++)
  {
    Particle clouds = {random_unit_cube(), vec3(1,0,0), vec4(vec3(0.7,0.7,0.7), 0.2), random_float(), 1.0f};
    mParticles.push_back(clouds);
  }
}

void MyParticleSystem::update(float dt)
{
  for (int i = 0; i < mParticles.size()-1; i++)
  {
    Particle particle = mParticles[i];
    vec3 position = particle.pos + 0.001f * particle.vel;

    if (position.x > 1.0f)
    {
      position.x = -1.0f;
    }
    particle.pos = position;
    mParticles[i] = particle;
    sort(mParticles.begin(), mParticles.end(), comparatorCloud);
  }
}


