// Room: nilu1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "泥土山路");

	set("long", @LONG
这是条泥土路，似乎刚下过雨，山路也格外泥泞难行，你低一脚高一脚往前努
力走着，不一会便气喘吁吁，汗流夹背了。前面不远似乎人烟嘈杂，有家店铺，愈
往前走，山雾就愈来愈大，到后来几乎无法辩得清眼前的东西了。
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"westup":__DIR__"nilu2",
	"southeast":__DIR__"qiongjie4",
	]) );
	//}}
        set("outdoors", "shanliu");
	set("coor/x",12);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	
	if (random(4))
	{
		me->move(this_object());
		tell_object(me,"山路也格外泥泞难行，你低一脚高一脚往前努力走着\n");
		return notify_fail("");
	}		
	return 1;
}
