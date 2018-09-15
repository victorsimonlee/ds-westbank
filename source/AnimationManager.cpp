#include "AnimationManager.h"
//TODO: CHANGE FROM STATIC METHODS TO INSTANCE METHODS
//TODO: MAKE USE OF CLASS PROPERTY INSTEAD OF GLOBAL VARIABLE '::arrAnimations'


//register an animation, to be managed
void AnimationManager::RegisterAnimation(u8 _id, u8 _lastFrame, u8 _tag) {
	//check for a free spot to register this animation
	for (u8 x=0; x<10; x++) {
		//free spot
		if ( ::arrAnimations[x].id < 0 ) {
			//debug("added: ", _id);

			::arrAnimations[x].id = _id;
			::arrAnimations[x].lastFrame = _lastFrame;
			::arrAnimations[x].tag = _tag;
			return;
		}
	}
}

//manage memory for loaded animations: will free memory for each ended animation
//will consider the 'category' indicated by _tag
//'force': will release memory, no matter which frame the animation currently is
void AnimationManager::ReleaseMemory(u8 _tag, bool _force) {
	for (u8 x=0; x<10; x++) {
		if ( _tag == TAG_ALL || ::arrAnimations[x].tag == _tag ) {
			if ( ::arrAnimations[x].id > 0 && (PA_GetSpriteAnimFrame(0, ::arrAnimations[x].id) == ::arrAnimations[x].lastFrame || _force)) {
				//debug("delete: ", ::arrAnimations[x].id);

				PA_DeleteSprite(0, ::arrAnimations[x].id);
				::arrAnimations[x].id = -1;
				::arrAnimations[x].lastFrame = 0;
			}
		}
	}
}