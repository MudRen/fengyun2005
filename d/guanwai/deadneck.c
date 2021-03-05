inherit ROOM;

void create()
{
	set("short", "死颈");

	set("long", @LONG
这里便是通往拉萨的天险死颈，但见群山环插，壁立千仞，青天如一线，道路
如羊肠。那蓝天盘旋在危岩怪石的狼牙般锐角间，羊肠曲路也崎岖险恶如狼牙，路
正中站着个夜叉般的黑衣大汉。
LONG);

         set("exits", ([ 
		"west" : __DIR__"grassland4",
		"east" : __DIR__"grassland3",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
        	__DIR__"npc/weitianpeng" : 1,
        ]) ); 
	set("coor/x",55);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
