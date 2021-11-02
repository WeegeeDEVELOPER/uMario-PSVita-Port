#include "CFG.h"

/* ******************************************** */

CCFG::CCFG(void) { }

CCFG::~CCFG(void) {
	delete oText;
	delete oMM;
	delete tSMBLOGO;
}

/* ******************************************** */

int CCFG::GAME_WIDTH  = 960;
int CCFG::GAME_HEIGHT = 544;

Text* CCFG::oText = new Text();
CIMG* CCFG::tSMBLOGO = new CIMG();

MenuManager* CCFG::oMM = new MenuManager();
Music* CCFG::oMusic = new Music();

bool CCFG::keySpace = false;

int CCFG::keyIDA = 0;
int CCFG::keyIDD = 0;
int CCFG::keyIDS = 0;
int CCFG::keyIDSpace = 0;
int CCFG::keyIDShift = 0;

bool CCFG::canMoveBackward = true;

/* ******************************************** */

Text* CCFG::getText() {
	return oText;
}

MenuManager* CCFG::getMM() {
	return oMM;
}

Music* CCFG::getMusic() {
	return oMusic;
}

CIMG* CCFG::getSMBLOGO() {
	return tSMBLOGO;
}

std::string CCFG::getKeyString(int keyID) {
	if(keyID >= 97 && keyID <= 122) {
		return std::string(1, '0' + (keyID - 32) - 48);
	}

	if(keyID >= 48 && keyID <= 57) {
		return std::string(1, '0' + (keyID - 32) - 48);
	}

	//sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);
	//SceCtrlData ctrl;

	//key translations
	/*
	if (ctrl.buttons == SCE_CTRL_START){
		keyID = SDLK_ESCAPE;
	}else if (ctrl.buttons == SCE_CTRL_CROSS){
		keyID = SDLK_SPACE;
	}else if (ctrl.buttons == SCE_CTRL_CIRCLE){
		keyID = SDLK_LSHIFT;
	}else if (ctrl.buttons == SCE_CTRL_UP){
		keyID = SDLK_UP;
	}else if (ctrl.buttons == SCE_CTRL_DOWN){
		keyID = SDLK_DOWN;
	}else if (ctrl.buttons == SCE_CTRL_LEFT){
		keyID = SDLK_LEFT;
	}else if (ctrl.buttons == SCE_CTRL_RIGHT){
		keyID = SDLK_RIGHT;
	}
	*/

	//SDL_Keycode keycode;


	switch(keyID) {
		case SDLK_ESCAPE:
			return "ESCAPE";
		case SDLK_SPACE:
			return "SPACE";
		case SDLK_LSHIFT:
			return "LSHIFT";
		case SDLK_RSHIFT:
			return "RSHIFT";
		case SDLK_UP:
			return "UP";
		case SDLK_DOWN:
			return "DOWN";
		case SDLK_RIGHT:
			return "RIGHT";
		case SDLK_LEFT:
			return "LEFT";
		case SDLK_LCTRL:
			return "LCTRL";
		case SDLK_RCTRL:
			return "RCTRL";
	}

	return "NONE";
}