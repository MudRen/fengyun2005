// Room: nilu4.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "泥土山路");

	set("long", @LONG
这是条通往梵音寺的泥土路，似乎刚下过雨，山路也格外泥泞难行，你低一脚
高一脚往前努力走着，不一会便气喘吁吁，汗流夹背了。前面不远便是"梵音寺"了，
愈往前走，山雾就愈来愈大，到后来几乎无法辩得清眼前的东西了。
LONG);
/*	set("long_night", @LONG
这是一块空地，到了晚上就更不要指望看见什么。
LONG);
*/
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"south":__DIR__"qigeban",
	"northwest":__DIR__"nilu5",
	]) );
	//}}
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
