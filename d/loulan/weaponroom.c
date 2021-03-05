inherit ROOM;

void create()
{
        set("short", "百兵库");
        set("long", @LONG
快活王志在天下，暗中征召天下豪杰，铸造百兵以供沙场之用，这间百兵库本
是古楼兰的长史府，十分庞大宏伟，现被快活王改造为兵器库，但见室中壁上、桌
上、架上、柜中。几间，尽皆列满兵刃，式样繁多，十之八九都是名剑名刀，或长
逾丈寻，或短仅数寸，有的铁锈斑驳，有的寒光逼人，不禁让人眼花缭乱。 
LONG
        );

        set("exits", ([ 
		"east" : __DIR__"southstrt",
	]));
        set("objects", ([
		"obj/weapon/axe_l" : 2,
       	]) );
	set("indoors", "loulan");

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}
