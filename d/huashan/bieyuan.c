#include <ansi.h>
inherit ROOM;
string tree();
void create()
{
        set("short", "华山别院");
        set("long", @LONG
华山别院为一座北方园林，占地十余亩，观门前曲水修竹，观内古树婆娑，且
伴有奇花异草交相辉映，院内更有一棵菩提树，据说是从印度引进的树种，每逢花
季白花绿萼，清雅宜人。
LONG
        );
    set("exits", ([ 
  		"west" : __DIR__"shaluo",
		"east" : __DIR__"zhengtang",
	]));
	set("item_desc", ([
		"tree" : (: tree :),
		"菩提树" : (: tree :),
	]) );   
	set("objects", ([
		__DIR__"npc/linger" : 1,
	]));
    set("flower_amount", 4);
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

string tree(){
	object me;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	message_vision("$N抬头向菩提树望去。\n", me);
	if(i != 2) {
		tell_object(me, "菩提树枝叶茂密，巨大的树冠遮蔽了半边天日。\n");
	} else {
		tell_object(me, HIW"\n菩提树上枝叶茂密，浓密的枝叶里点缀着白色的花朵，阵阵清香随风飘来。\n"NOR);
		if(query("flower_amount") >= 0) {
			tell_object(me, HIW"几朵碗口大的白花在你触手可及的枝条上。\n"NOR);
			add_action("do_pick", "pick");
		}
	}
	return "";
}

int do_pick(string arg){
	object me, flower;
	me = this_player();
	if(!arg || (arg != "flower" && arg != "白花")){
		return 0;
	}
	message_vision("$N伸手摘下了一朵白色的花朵。\n", me);
	flower = new(__DIR__"obj/flower2");
	if(objectp(flower)){
		flower->move(me);
	}
	add("flower_amount", -1);
	return 1;
}

void reset(){
	::reset();
	set("flower_amount", 4);
}
