// Room: nilu6.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "泥土山路");

	set("long", @LONG
这是条通往梵音寺的泥土路，似乎刚下过雨，山路也格外泥泞难行，你低一脚
高一脚往前努力走着，不一会便气喘吁吁，汗流夹背了。前面不远便是"梵音寺"了，
愈往前走，山雾就愈来愈大，到后来几乎无法辩得清眼前的东西了。
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"southdown":__DIR__"nilu5",
	"enter":__DIR__"fanyinshi",
	]) );
	//}}
	set("coor/x",-2);
	set("coor/y",40);
	set("coor/z",60);
	setup();
	replace_program(ROOM);
}
