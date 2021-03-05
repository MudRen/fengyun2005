inherit ROOM;

void create()
{
	set("short", "十八盘");
	set("long", @LONG
山路崎岖盘绕难行，处处可见嶙峋的怪石奇岩，荆棘丛生，蔓藤环绕，在茫茫
的山雾中看去，更觉得阴森可怖。你辨了辨四下的地势，遂从乱山盘石间，往里穿
行。浓雾中不时冒出一两双泛着绿芒的怪眼狠狠地盯着你打量。
LONG);

	set("type","road");
	set("exits",([
		"northdown":__DIR__"bigstage",
        "southup":__DIR__"18pan2",
	]) );
       set("outdoors", "wolfmount");
	set("coor/x",-20);
	set("coor/y",65);
	set("coor/z",-45);
        set("objects", ([
        __DIR__"obj/stone1":1,
		__DIR__"npc/fwolf2":1,
		__DIR__"npc/fwolf2a":1,
                        ]) );
	setup();
	replace_program(ROOM);
}
