
inherit ROOM;

void create()
{
	set("short", "杂货店");
	set("long", @LONG
普普通通的一间杂货店。靠墙的架子上摆著各种生活必需用品，中间一张柜台，
店主人正坐在柜台后面算帐。他不时地抬头望一眼门外，像是在等待什么人。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xzroad3",
	]));
        set("objects", ([
                __DIR__"npc/seller2" : 1,
                __DIR__"npc/taoist2" : 1,
        ]) );
	set("coor/x",10);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}
