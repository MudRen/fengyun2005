
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的沙砾地，山势到了这里突然间变的无影无踪。地气极干燥，连
风都是暖的。地上的石砾发出一种暗红的颜色，就象是被鲜血染红的一样。一条布
满车痕的官道向西方和东方伸展。一块牌子指向路侧的小店，上面写着[33m『焦都驿』[32m
LONG
        );
        set("exits", ([ 
	  "east" : __DIR__"huangyie4",
	  "west" : __DIR__"sandroad",
	  "south" : AREA_DEATH"ghostinn",
	  "southeast" : __DIR__"huangyie3",
	  "northeast" : __DIR__"huangyie2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 3,
        ]) );

	set("coor/x",-1010);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	if(me->is_ghost()){
		room = load_object(AREA_DEATH"ghostinn");
		me->move(room);
		return notify_fail("你感到一阵晕眩，似乎看到很多人影从眼前晃过。\n");
	}
	return 1;

}
