#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIR"凤求凰客栈"NOR);
    set("long", @LONG
前厅挂着一幅龙凤双飞的巨画。当门挂着对鸳鸯球，球上系着几个小小的黄铜
风铃。微风掠过，风铃发出清脆悦耳的叮咚声。一个满面春风的小二正忙碌地[37m招待[32m
顾客，案桌上贴着张[37m白纸[32m，上面龙飞凤舞地写着几个草字。走出大门，迎面便是斗
大的大红[37m灯笼[32m，灯笼下一口[37m大缸[32m，想是为往来行人提供清水。
LONG);
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"huanyun4",
      ]));
    set("valid_startroom", 1);
    set("resource/water", 1);
    set("liquid/container", "水缸");    
    set("item_desc", ([
	"大缸":	"一口大缸，水清见底，如果你有水袋或者葫芦，可以在这儿打水（fill 容器）
如果你刚来，可以试着用 fill hulu
而后就可以喝了，drink hulu\n",
	"白纸":	"小店生意繁忙，欲问路请自己看地图（使用map指令）\n",
	"灯笼": HIR" 			有 凤 求 凰 
\n\n"NOR,
	"招待": "本店供应上好酒菜，请使用list指令。
如果需要购买，使用buy 某物 from 某人
而后就可以吃了，eat 食物名\n",
      ]));

    set("objects", ([
	__DIR__"npc/waiter" : 1,
	__DIR__"npc/gifter" : 1,	
      ]) );

    set("coor/x",80);
    set("coor/y",-200);
    set("coor/z",0);
    set("no_dazuo",1);
    set("map","fysouth");
    setup();
    //        replace_program(NEWBIE_HELP_ROOM);
}



