#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "聚义厅");

	set("long", @LONG
饿虎岗的聚义厅是用巨大的树木盖成的，虽然粗糙简陋，却带著种原始的粗犷
纯朴，看来别有一种令人慑服的雄壮气势。这里的人也一样，野蛮、骠悍、勇猛，
就象是洪荒时的野兽。西面低处的木墙似乎可以移动。
LONG);

	set("type","street");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",10);
	set("exits",([
		"westdown":__DIR__"andao2",
		"northdown":__DIR__"shanlu4",
	]) );
	set("objects",([
		__DIR__"npc/gui":1,
		__DIR__"npc/ding_xi":1,
		__DIR__"npc/wang_ruo_lan":1,
		]) );

	setup();
	create_door("westdown", "wall","木墙", "eastup", DOOR_CLOSED);
}
