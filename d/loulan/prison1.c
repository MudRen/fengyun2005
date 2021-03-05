inherit ROOM;

void create()
{
        set("short", "石牢");
        set("long", @LONG
这是间石砌的屋子，石壁上也雕刻着奇异而古拙的图案，有的人身兽首，有的
兽身人首，形状虽然丑恶，雕刻却极精细。但室内的陈设，却都是崭新、华丽的，
犁花木的茶几，宽大而舒服的椅子，雕花的大床上，支着流苏锦帐。这当然是快
活王带来的。新旧两代的艺术，便在这石室中形成了一种奇妙的融合。
LONG
        );

        set("exits", ([ 
		"east" : __DIR__"northstrt",
	]));
        set("objects", ([
                __DIR__"npc/shenlang" : 1,
                __DIR__"npc/bai" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
