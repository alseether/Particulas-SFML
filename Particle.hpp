#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML\Graphics.hpp>
#include <time.h>

#define MIN_LIFETIME 5
#define MAX_LIFETIME 30
#define MAX_SIZE 100.f

class Particle{
public:

	Particle(){
		std::srand(std::time(NULL));
	}

	/**
	Initialize the particle, it will put the particle in the middle of the world and give it a 
	random direction vector with random speed and lifetime.

	@param worldSize Receive the world size which the particle is in.

	@return true if everything went well, false in other case.
	*/
	const bool reset(sf::Vector2f worldSize){
		this->_pos = sf::Vector2f(worldSize.x / 2, worldSize.y / 2);
		this->_isAlive = true;
		_lifetime = sf::seconds(MIN_LIFETIME + (rand() % (MAX_LIFETIME - MIN_LIFETIME)));
		this->_size = 2;

		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = (std::rand() % 50) + 50.f;
		this->_vel = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	}

	/**
	Increases the particle size

	@param amount How much particle must be fattened

	@return how much the particle was really fattened
	*/
	const float fattenParticle(float amount){
		this->_size += amount;
		if (this->_size > MAX_SIZE){
			float ret = amount - (this->_size - MAX_SIZE);
			this->_size = MAX_SIZE;
			return ret;
		}
		else{
			return amount;
		}
	}

	/**
	Update the particle position

	@param elapsed Time has passed from one loop to another
	*/
	const void update(sf::Time elapsed){
		if (!this->_isAlive){
			return;
		}
		_lifetime -= elapsed;

		if (_lifetime <= sf::Time::Zero)
			this->_isAlive = false;

		this->_pos += this->_vel * elapsed.asSeconds();
	}
private:
	sf::Time _lifetime;
	float _size;
	bool _isAlive;
	sf::Vector2f _pos;
	sf::Vector2f _vel;

};

#endif