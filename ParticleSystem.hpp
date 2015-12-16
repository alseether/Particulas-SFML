#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <SFML\Window.hpp>
#include <vector>

class ParticleSystem {
public:

	ParticleSystem (int particles, sf::Vector2f worldSize) : 
	_particles(particles),
	_worldSize(worldSize)
	{

	}

	const int initSystem() const;

	const int addParticles(int amount);

	const int removeParticles(int amount);

	const int update(sf::Time elapsed);

private:
	const int _MAXPARTICLES = 10000;
	int _particles;
	sf::Vector2f _worldSize;
	std::vector<int> particlesVector;
}

#endif
