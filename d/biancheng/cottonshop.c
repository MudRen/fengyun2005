inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "棉花行");
        set("long", @LONG
俗话说，小镇生意八大行，指的就是盐行、茶行、药材行、什货行、油行、粮
行、皮行和这个棉花行。还没走进店堂，就能听到里面铮铮弹棉花的声音。门外挂
着的大招牌上写着：“精弹棉花，外卖雕漆器皿”。棉花行的宋老板常年奔波于内
地，这儿经常就交给伙计看管。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"sstreet2",
	]));
        set("objects", ([
        	__DIR__"npc/bosssong":	1,
	]) );
        set("coor/x",-20);
        set("coor/y",-20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

void reset(){
	if (present("hua hua",this_object()))	return;
	::reset();
}	