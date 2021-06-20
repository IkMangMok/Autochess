#include"Chess.h"
#include<string>
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;



Chess* Chess::createChess(string picture_name)
{

	auto chess = new  Chess();

	auto temp = Sprite::create(picture_name);
	chess->addChild(temp);
	chess->autorelease();
	return chess;
	
}

Chess::Chess()
{
	Blood->setBarChangeRate(Point(1, 0));
	Blood->setType(ProgressTimer::Type::BAR);
	Blood->setMidpoint(Point(0, 1));
	Blood->setScaleX(0.22);
	Blood->setScaleY(0.6);
	bloodFrame->setScaleX(0.22);
	bloodFrame->setScaleY(0.6);
	
	_Mana->setBarChangeRate(Point(1, 0));
	_Mana->setType(ProgressTimer::Type::BAR);
	_Mana->setMidpoint(Point(0, 1));
	_Mana->setScaleX(0.18);
	_Mana->setScaleY(0.6);
	ManaFrame->setScaleX(0.18);
	ManaFrame->setScaleY(0.6);

	this->addChild(Star, 1);
	this->scheduleUpdate();
	this->addChild(bloodFrame, 1);
	this->addChild(Blood, 2);
	this->addChild(_Mana, 2);
	this->addChild(ManaFrame, 1);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1 / 120.0f);
	
}
void Chess::set(float x1 = 0, float y1 = 0)  //传入数值，有两种重载形式
{
	x = x1;
	y = y1;
}

void Chess::Attack(float dt)
{
  //  if (test_timer->pTime <= 0)
    
	
	if (AttackTarget != (Chess*)nullptr && !Die())
	{
		float  distance = sqrt((AttackTarget->getPosition().x - getPosition().x)  //获得距离
			* (AttackTarget->getPosition().x - getPosition().x) +
			(AttackTarget->getPosition().y - getPosition().y)
			* (AttackTarget->getPosition().y - getPosition().y));
		if (distance < AttackDistance)                           //小于攻击距离则开始攻击
		{
			isMove = 0;
			
			shootbullet("pea.png", AttackTarget->getPosition() - this->getPosition(), this);
		
		
			if (!SkillFlag)
				Mana += 10;

			if (AttackTarget->Die())
			{
	
				AttackTarget = (Chess*)nullptr;
			}
		}
	}
    
}

void Chess::Hurted(float Damage)
{
	if (Damage > 0)
	{
		Health = Health - Damage * (1.0f - Armor / (Armor + 100)) * HurtRate;    //受伤
		if(!SkillFlag)
			Mana = min(Mana + Damage / 10, ManaLimit);
	}
	else
	{
		Health = min(HealthLimit, Health - Damage);      //回血
	}
}
void Chess::MagicHurt(float Damage)
{
	if (Damage > 0)
	{
		Health = Health - Damage * (1.0f - MagicResistance / (MagicResistance + 100)) * HurtRate;    //受伤
		Mana = min(Mana + Damage / 10, ManaLimit);
	}
	else
	{
		Health = min(HealthLimit, Health - Damage);      //回血
	}
}
void Chess::setPlayer(int player)
{
	OfPlayer = player;
	if (player == 0)
	{
		
		Blood->setSprite(Sprite::create("OurBlood.png"));
	}
}
bool Chess::Die()
{
	if (Health <= 0)
	{

		ChessExist[MapIntReturn(getPosition()).x][MapIntReturn(getPosition()).y] = 0;
		setPosition(Point(10000, 10000));
		set(10000, 10000);
		
		return 1;
	}
	else
		return 0;
}
int Chess::GetAttackDistance()
{
	return AttackDistance;
}
void Chess::update(float dt)
{
	if (Mana >= ManaLimit && AttackTarget != (Chess*)nullptr)           //释放技能
	{
		Skill();
		
	}
	
}
void Chess::recover() 
 {
	Mana = ManaOrigin; 
	Health = HealthLimit;
	AttackTarget = (Chess*)nullptr;
	Blood->setPercentage(100.f);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / this->AttackSpeed);
	this->scheduleUpdate();
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Bloodupdate), 1/60.0f);
	chessAnimation(picturename, picturenum, this, getPosition(), 0.8f, -1);
}

void Chess::Bloodupdate(float dt)
{
	_Mana->setPosition(Vec2(30, 80));
	ManaFrame->setPosition(Vec2(30, 80));
	Blood->setPosition(Vec2(35, 90));
	bloodFrame->setPosition(Vec2(35, 90));
	Blood->setPercentage(float(Health) / float(HealthLimit) * 100);
	Blood->setTag(Health);
	_Mana->setPercentage(float(Mana) / float(ManaLimit) * 100);
	_Mana->setTag(Mana);
	Star->setPosition(Vec2(85, 50));
	Star->setString(to_string(star));
 }

void Chess::chessAnimation(string picturename, const int picturenum, Sprite* sprite, Point location, const float speed, const int loop)
{
	/*Sprite* sp = Sprite::create(picturename);
	sp->setPosition(location);
	mychess->addChild(sp);*/
	// sp->setFlippedX(true);//相对位置关系，先保留

	Animation* animation = Animation::create();

	const char* picname = picturename.c_str();

	for (int i = 0; i <= picturenum; i++) {
		char key[32];
		sprintf(key, picname, i);
		animation->addSpriteFrameWithFile(key);
	}

	animation->setDelayPerUnit(speed); //设定速度
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(loop); //loop=-1,循环
	auto action = Animate::create(animation);
	action->setTag(-2);
	//sp->runAction(animate);
	sprite->runAction(action);
	
}

void Chess::EquimentChange()
{
	for (int i = 0; i < equipment->num; i++)
	{
		auto equ = (Equipment*)equipment->arr[i];
		this->EquipToChess(equ);
	}
}

void Chess::EquipToChess(Equipment* equ)
{
	this->HealthLimit += equ->getaddHealthLimit();
	Health = HealthLimit;
	this->Armor += equ->getaddArmor();
	this->AttackSpeed += equ->getaddAttackSpeed();
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / this->AttackSpeed);
	this->Damage += equ->getaddDamage();
	this->AttackDistance += equ->getaddAttackDistance();
}

void Chess::shootbullet(string picturename, Point deltaPos, Chess* mychess)
{
	Sprite* bullet = Sprite::create(picturename);
	this->addChild(bullet);
	bullet->setPosition(40, 30);

	auto move = MoveBy::create(1.f, deltaPos);
	auto back = MoveTo::create(0.f, Vec2(40, 30));
	auto appear = FadeIn::create(0.f);
	auto disappear = FadeOut::create(0.f);

	auto actionTo = Sequence::createWithTwoActions(appear, move);
	auto actionBack = Sequence::createWithTwoActions(disappear, back);
	auto all = Sequence::createWithTwoActions(actionTo, actionBack);
	bullet->runAction(Repeat::create(all, 1));
	AttackTarget->Hurted(Damage);
}