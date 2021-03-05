// street2.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
string rider();
void create()
{
  set("short","山坡");
  set("long",@LONG
这里仿佛是济南南郊的一个无名山丘，远处的济南城被笼罩在硝烟之中。震天
的呐喊声从山下东北角方向传来。眼前的平原上有千军万马在厮杀中！烟尘很大，
你看不清楚远处的战况，只能看到一队队整齐的骑兵从你所在的山丘下向北面开拔。 
LONG
  );
	set("exits",([
		"southup" : __DIR__"shanding",
    ]));
	set("item_desc", ([
		"骑兵" : (: rider :),
		"qibing" : (: rider :),
		"rider" : (: rider :),
	]));
    set("valid_startroom",1);
    set("outdoors", "dreamland");
	set("no_fight", 1);
	set("no_magic", 1);
	setup();

}

string rider(){
	object me;
	me = this_player();
	tell_object(me, "盔甲鲜明的大队宋朝骑军。 一面青缎赤纛镶金的大旗迎风招展，中间斗\n"); 
	tell_object(me, "大的"HIR"岳"NOR"字凝重如山。\n"); 
	return "";
}
