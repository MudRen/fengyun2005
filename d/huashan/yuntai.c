
inherit ROOM;

void create()
{
        set("short", "云台峰");
        set("long", @LONG
站在山峰顶端，回首遥望，来路若隐若现，不时飘过的云雾挡住你的视线。此
处四面下临深壑，悬崖陡峭如刀削而成，峰上盘山路千曲百回，路两旁青松成林，
风景秀丽，别具一格。
LONG
        );
    set("exits", ([ 
        "southdown" : __DIR__"canglong",
	]));
	set("objects", ([
		__DIR__"obj/tree" : 1,
		__DIR__"npc/baiyun" : 1,
	]));  
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-48);
	set("coor/z",40);
	setup();
    replace_program(ROOM);
}

