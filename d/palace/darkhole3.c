
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "洞穴");
        set("long", @LONG
才进入石洞，你就迷失了方向，被无边的黑暗所吞食。在这里，你竭尽目力也
看不见自己所处的环境；你似乎听到身边有悉悉嗦嗦的声音，感觉有小动物跑来跑
去。这时的你，是多麽的希望身上有照明的东西。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"darkhole1",
		"west" : __DIR__"darkhole2",
		"north" : __DIR__"darkhole",
		"south" : __DIR__"darkhole4",
	]));
        set("objects", ([
//        __DIR__"obj/buddbook" : 3,
                        ]) );
	set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",40);
//	set("refresh_all_items", 1);
	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	int	kar;
	object	nroom;

	if(!arg) {
		kar = this_player()->query("kar");
		if(random(kar+ 70) < kar) {
			message_vision(HIY "\n在黑暗中$N四处摸索，突然$N触到了石壁上的一块突出。\n"NOR, this_player());
			message_vision(HIR "\n$N的脚下裂开了一个大洞！\n"NOR, this_player());
			message_vision(HIR "\n$N大叫了一声，掉了下去！\n"NOR, this_player());
			nroom = find_object(__DIR__"yadi");
			if(!objectp(nroom)) nroom = load_object(__DIR__"yadi");
			this_player()->move(nroom);
			message_vision(HIY "\n$N受到了太大的惊吓，晕了过去！\n"NOR, this_player());
			this_player()->unconcious();
			return 1;
		}
	}
        return notify_fail("\n你在黑暗中四处摸索，却甚麽都没发现。\n");
}

void reset() {
	string item= "buddbook";
	int num = 3;
	object obj, *inv;
	
	:: reset();
	
	inv = all_inventory();
	foreach (object ob in inv) 
	{
		if (userp(ob)) continue;
		if (ob->query("id") == "buddbook") destruct(ob);
	}
	while (num--) 
	{
		obj = new(BOOKS"iron-cloth_50");
		obj->move(this_object());
	}
}