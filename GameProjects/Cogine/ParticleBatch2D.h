#pragma once

#include <functional>
#include <glm/glm.hpp>
#include "Vertex.h"
#include "SpriteBatch.h"
#include "GLTexture.h"

namespace Cogine {


	class Particle2D {
	public:
		glm::vec2 position = glm::vec2(0.0f);
		glm::vec2 velocity = glm::vec2(0.0f);
		ColorRGBA8 color;
		float life = 0.0f;
		float width = 0.0f;

	};

	inline void defaultParticalUpdate(Particle2D& partical, float deltaTime) {
		partical.position += partical.velocity*deltaTime;
	}


	class ParticleBatch2D {
	public:
		friend class Particle;

		ParticleBatch2D();
		~ParticleBatch2D();

		void init(int maxParticles,
			float decayRate,
			GLTexture texture,
			std::function<void(Particle2D&, float)> updateFunc= defaultParticalUpdate);

		void update(float deltaTime);

		void draw(SpriteBatch* spriteBatch);

		void addParticle(const glm::vec2& position,
			const glm::vec2& velocity,
			const ColorRGBA8& color,
			float width);

	private:
		int findFreeParticle();

		std::function<void(Particle2D&, float)> m_updateFunc;

		float m_decayRate = 0.1f;
		Particle2D* m_particles = nullptr;
		int m_maxParticles = 0;
		int m_lastFreeParticle = 0;
		GLTexture m_texture;


	};

}