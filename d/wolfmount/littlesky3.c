inherit ROOM;

void create()
{
    set("short", "一线天");

	set("long", @LONG
行路至此，山路愈发变得陡峭无比，两边悬崖峭壁高高笔立，中间只留出一条
窄窄的山路，已是两人不能并肩而行，抬头望去，只有一线的天空，间或有几只山
鹰盘旋飞过。。。
LONG);

	set("exits",([
        "westdown":__DIR__"littlesky1",
        "eastup":__DIR__"littlesky2",
	]) );
        set("objects",([
                __DIR__"npc/heiyan":1,
                __DIR__"npc/heixin":1,
                __DIR__"npc/heimian":1,
        ]) );
       set("outdoors", "wolfmount");
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
