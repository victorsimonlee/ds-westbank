/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
#pragma once
#include <PA9.h>

#include "constants.h"
#include "utils.h"
#include "Types.h"
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

extern Animations arrAnimations[10]; //to control loaded animations

class AnimationManager {

	private:

	public:
		
		static void ReleaseMemory(u8 _tag, bool _force);
		static void RegisterAnimation(u8 _id, u8 _lastFrame, u8 _tag);
};
