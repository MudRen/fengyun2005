
inherit ROOM;
void create()
{
	set("short", "海岸边");
	set("long", @LONG
日已西斜，但阳光还是灿烂，海浪拍打着礁石，激起一连串银白色的泡沫。五
七只海鸥在蔚蓝色的天空下，蔚蓝色的海洋上低回。刚从黑暗中走出来的人，骤然
见到阳光，都不禁闭起眼睛，让眼帘先接受阳光温暖的轻抚，然后才能接受这令人
心跳的光明！ 
LONG
	);
    set("exits", ([ 
        "east" : __DIR__"anbian2",
    ]));
	set("objects", ([
        __DIR__"npc/wang"   : 1,

    ]));
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",30);
	    set("outdoors", "bat");
	setup();
	replace_program(ROOM);
}



