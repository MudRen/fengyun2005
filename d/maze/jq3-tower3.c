// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"黄金塔三层"NOR);
	set("long", @LONG
这是一座黄金打造的六层高塔，刺眼的辉煌让人眩目而不知所措，每一层都 
让人目不暇接。美女，佳酿，珠宝，名剑。。。而更多的就是满目的黄金，地板 
是金子打造的，塔梯是黄金打造的。。。这里，就是一个黄金的世界。 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"down" :  __DIR__"jq3-tower2",
		"up":	  __DIR__"jq3-tower4",
	]));
        set("item_desc", ([

	]) );
        set("objects", ([
                __DIR__"npc/jq3-lufengxian" : 1,

 	]) );
	setup();
	
}

int	valid_leave(object who, string dir) {
	object guard;
	if (dir == "up") {
		if ( !REWARD_D->riddle_check(who,"决战黄金塔"))
			return notify_fail("黄金塔上杀气凛然，鬼哭神泣，你手脚酥软，举步维艰。\n");
		if (guard = present("lu fengxian",this_object()))
			return notify_fail("吕凤先冷笑一声：想上楼？先过了我这一关！\n");
	}
	return ::valid_leave(who,dir);
}