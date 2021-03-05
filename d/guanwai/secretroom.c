inherit ROOM;

void create()
{
	set("short", "密窟");

	set("long", @LONG
一间窄小阴暗的密窟，一丝阳光透过天窗洒了进来，屋中空荡荡没什么摆设，
一桌一椅一人。椅中人正捧着个海碗往嘴里灌着烈酒。阳光下，这是一个很矮小的
人，脸也很瘦削，穿着件宽大的白色袍子，戴着顶很大的竹笠。
LONG);

	set("type","street");
        set("exits", ([ 
		"east" : __DIR__"wallhole",
        ]));
        set("objects", ([
                __DIR__"npc/ying" : 1,
	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
        setup();
	replace_program(ROOM);
}