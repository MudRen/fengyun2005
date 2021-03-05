#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
石英岩铺成的山路越走越陡，越走越窄，山势也越来越高，前面白茫茫的一片，
不知道是山间的雾气，还是高处的浮云。两旁是茂密的松林，松涛阵阵，隐约有些
奇怪的声响，你禁不住想停步倾听。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"northup" : __DIR__"road5",
  		"southdown" : __DIR__"road3",
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",-30);
	setup();

}

void init(){
        add_action("do_listen","listen");
}



int do_listen(){
        tell_object(this_player(),"
你感到脖子发凉，黑暗处好像有双眼睛盯着你！
你仔细地看了一下四周，却什么也没有！\n");
        this_player()->set_temp("sq_listen",1);
        return 1;
}
