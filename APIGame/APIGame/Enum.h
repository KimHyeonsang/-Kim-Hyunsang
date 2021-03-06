#pragma once

enum class SCENEID
{
	LOGO,
	MENU,
	HELPSCENE,
	PLAYERSELECTSCENE,
	STAGE,
	EXIT,
};

enum class MENUID
{
	ZERO,
	START,
	HELP,
	EXIT,
};

enum class BULLETID
{
	ZERO,
	PLAYER,
	ENEMY,
};

enum class ENEMYID
{
	ZERO,
	NOMAL,
	BOOMB,
	BOSS,
};

enum class DIRECTION
{
	BOTTOM1,
	BOTTOM2,
	BOTTOM3,
	LEFTBOTTOM3,
	RIGHTBOTTOM3,
	LEFTBOTTOM1,
	LEFTBOTTOM2,
	RIGHTBOTTOM1,
	RIGHTBOTTOM2,
};
	
enum ITEMNAME
{
	ITEM_BOOMB,
	ITEM_NOMALBULLET,
	ITEM_REFLECTION_BULLET,
};