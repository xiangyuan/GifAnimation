#include "HelloWorldScene.h"
#include "GifAnimation.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
  
	// 动画定义
	GifAnimationDef def;
	def.loops = -1;						// 循环次数
	def.filePath = "1.gif";				// 文件路径
	def.delayPerUnit = 0.1f;			// 每帧间隔
	def.restoreOriginalFrame = false;	// 还原初始状态

	// 创建动画
	auto pAnimation = GifAnimation::getInstance()->createAnimation(def);

	// 创建精灵播放动画
	auto sp = Sprite::create();
	sp->setPosition(Vec2(480, 320));
	addChild(sp);
	sp->runAction(Animate::create(pAnimation));
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
