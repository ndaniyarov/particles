#include "particlesystem.h"
#include "AGLM.h"

using namespace glm;
using namespace std;
using namespace agl;

Renderer ParticleSystem::theRenderer;

Renderer& ParticleSystem::GetRenderer()
{
   return theRenderer;
}

ParticleSystem::ParticleSystem()
{
   mBlendMode = ADD;
   mTexture = -1;
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::init(int size)
{
   if (!theRenderer.initialized())
   {
      theRenderer.init("../shaders/billboard.vs", "../shaders/billboard.fs");
   }
   createParticles(size);
}

void ParticleSystem::draw() 
{
   //glActiveTexture(GL_TEXTURE0);
   //glBindTexture(GL_TEXTURE_2D, mTexture);

   //glActiveTexture(GL_TEXTURE1);
   //glBindTexture(GL_TEXTURE_2D, mTexture1);
   theRenderer.begin(mTexture, mBlendMode);
   for (int i = 0; i < mParticles.size(); i++)
   {
      Particle particle = mParticles[i];
      theRenderer.quad(particle.pos, particle.color, particle.size);
   }
}
