// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
        set("short", "秘密寨口");
        set("long", @LONG
这里只见一个木头搭成的大门，门框上挂著四、五个的不知道是什麽动物的头
骨，头骨已经有年头了，外面再铺上一层乾枯的松枝，在这样一个光线暗淡的森林
里还真不容易发现。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"west" : __DIR__"pine2",
  		"east" : __DIR__"keep15",
	]));
        set("objects", ([ /* sizeof() == 1 */
  		__DIR__"npc/bandit_guard" : 4,
	]));
        
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
