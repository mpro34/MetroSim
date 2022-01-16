#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{

public:
	unsigned int startFrame, endFrame;
	
	float duration;

	Animation(unsigned int sf, unsigned int ef, float d) :
		startFrame{sf},
		endFrame{ef},
		duration{ d } {}

	unsigned int getLength()
	{
		return endFrame - startFrame - 1;
	}
};

class AnimationHandler
{
	/* Array of animations */
	std::vector<Animation> animations;

	/* Current time since the animation loop started */
	float t;

	int currentAnim;

public:
	/* Add a new animation */
	void addAnim(Animation& anim);

	/* Update the current frame of animation. dt is the time since
		the update was last called (i.e. the time for one frame to
		be executed)
	*/
	void update(const float dt);

	/* Change the animation, resetting t in the process */
	void changeAnim(unsigned int animNum);

	/* Current section of the texture that should be displayed */
	sf::IntRect bounds;

	/* Pixel dimensions of each individual frame */
	sf::IntRect frameSize;

	/* Constructor */
	AnimationHandler() : 
		t{ 0.0f },
		currentAnim{ -1 } {}

	AnimationHandler(const sf::IntRect& fs) :
		frameSize{ fs },
		t{ 0.0f },
		currentAnim{ -1 } {}
};
