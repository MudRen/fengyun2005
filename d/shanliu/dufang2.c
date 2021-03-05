// Room: dufang2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "偏厅");

	set("long", @LONG
这里本也应该是江湖豪客们掷金如土的地方，但现在却空荡荡的没几个人，只
有三个看上去很特别的人清闲地或坐或立，一个和尚，一个道士，还有一个酸秀才。
这三个人并不是来赌的，根本就没有下注。和尚手里拿着一串佛珠，嘴里念念有词，
像是念经。道士闭着眼，双手合十，居然在那里打坐。穷秀才左手端着杯酒，右手
捧着本书，正看得摇头晃脑，津津有味。
LONG);
	set("type","indoors");
	set("exits",([
	"east":__DIR__"dufang1",
	]) );
	//}}
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
        set("indoors", "shanliu");
	set("objects", ([
	__DIR__"npc/xiucai"  :1,
	__DIR__"npc/taoist1"  :1,
	__DIR__"npc/monk1" :1,
        ]) );
	setup();
	replace_program(ROOM);
}
