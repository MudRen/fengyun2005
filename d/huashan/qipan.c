
inherit ROOM;

void create()
{
        set("short", "棋盘台");
        set("long", @LONG
孤峰顶上原本平坦，更有后人凿削峰顶建成台，台上建有铁亭一座，亭内置古
围棋一盘。台面不大，三面临壑，探头向下望，只见云缭雾绕迷迷茫茫，与东峰仅
一刀形山背相连。
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"yaozi",
	]));
	set("objects", ([
                __DIR__"npc/gongye.c" : 1,
	            __DIR__"npc/crow.c" : 1,
       ]) );

   
    set("outdoors", "huashan");

	set("coor/x",-1);
	set("coor/y",-60);
	set("coor/z",33);
	setup();
    replace_program(ROOM);
}

