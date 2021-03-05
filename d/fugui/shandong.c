inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "洞道");

	set("long", @LONG
山洞极窄，须膝行而爬，若一不小心，就不免被洞中的石壁撞的头破血流，洞
中潮湿阴暗，腥臭难闻，一阵阵的恶臭扑面而来，你不禁头晕目眩，难受异常。
LONG);
    set("indoors", "fugui");
	set("type","mountain");
	set("exits",([
		"out":__DIR__"dongkou",
		"north":__DIR__"shandong1",
	]) );

	set("coor/x",-10);
	set("coor/y",280);
	set("coor/z",80);
	setup();
	
}

int valid_leave(object me, string dir)
{
	
	message_vision( HIC "一阵阵的恶臭扑面而来，$N不禁头晕目眩,难受异常。\n\n"NOR,me);
	if(userp(me)&&!me->query_temp("fugui_liquan") && dir == "north")
	{
		me->unconcious();
		return 0;
	} else
	{
		return 1;
	}
}
