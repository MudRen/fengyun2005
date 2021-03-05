// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "石屋");
        set("long", @LONG
石屋不大，石头是就地取材在附近山上采的，青色的石料异常的厚实，即使是
夏日的烈日也晒它不透，小石屋的门口有几颗白杨树，屋后是一道小溪流。屋里有
一张石桌和两石凳，桌子上摆着一把小锤子、凿子和一个还没有完工的玉雕笛子，
旁边一套紫砂茶具，小杯里是清香碧绿的茶水，靠墙摆着一张木塌，墙角堆着一些
奇形怪状的石块。
LONG
        );

    set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"stoneroad",
	]));

	set("objects", ([
		__DIR__"npc/yujiang" : 1,	
	]));
    set("indoors", "guanwai");

	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

