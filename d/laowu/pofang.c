
inherit ROOM;

void create()
{
        set("short", "破房间");
        set("long", @LONG
一间东倒西歪的小屋，四五张破破烂烂的破板凳，门上的喜字写得无论正着看，
到着看都不顺眼，墙上贴着的财神爷画得到像是一个暴发户。
LONG
        );
	set("exits", ([ 
		"west" : __DIR__"inn",
	]));
	set("objects", ([
		"/obj/npc/xiaotong" : 2,
		 __DIR__"npc/kiddo" : 1,

	]) );
	set("coor/x",25);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

