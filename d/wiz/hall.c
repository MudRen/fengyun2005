// Tie@fy3
inherit ROOM;
void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是管理人员休息和聊天讨论的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"jobroom"
	]));
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",20);
	set("no_magic",1);
	setup();
	call_other("/obj/board/wizard_b", "???");
}


void init()
{
	object room;
	if(!wizardp(this_player()) && userp(this_object()))
	{
		if(!room = find_object(AREA_FY"church"))
		room = load_object(AREA_FY"church");
		this_player()->move(room);
	}
}