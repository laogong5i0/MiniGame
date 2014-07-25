//
//  GameMarcos.h
//  bug
//
//  Created by pat on 13-11-25.
//
//

#ifndef bug_GameMarcos_h
#define bug_GameMarcos_h

#include "cocos2d.h"

#define DESIGN_RESOLUTION_480X320 0
#define DESIGN_RESOLUTION_1024X768 1
#define DESIGN_RESOLUTION_2048X1536 2
#define DESIGN_RESOLUTION_1280X720 3

#define TARGET_DESIGN_RESOLUTION_SIZE DESIGN_RESOLUTION_1280X720

typedef struct targetResource{
	cocos2d::CCSize size;
	char directory[100];
}Resource;

static Resource SmallResource = {cocos2d::CCSizeMake(480,320), "ihpone" };
static Resource mediumResource = {cocos2d::CCSizeMake(1024, 768), "ipad"};
static Resource largeResource = {cocos2d::CCSizeMake(2048, 1536), "ipadhd"};
static Resource hongMiResource = {cocos2d::CCSizeMake(1280, 720), "hongmi"};

#if(TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_480X320)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480, 320);
#elif(TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1024X768)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1023, 768);
#elif(TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_2048X1536)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(2048, 1536);
#elif(TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1280X720)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1280, 720);
#else
#ERROR unknow target design resolution;

#endif

#define CONFIG_HAS_XML_FILE "isHaveSaveFileXML"
#define CONFIG_KEY_HAS_MUSIC "HasMusic"
#define CONFIG_KEY_HEIGHT_SCORE "HeightScore"

enum layer_tag{
	TAG_CONFIG_MENU_LAYER=0,
	TAG_STOP_LAYER,
	TAG_RUNNING_LAYER
};

#endif
