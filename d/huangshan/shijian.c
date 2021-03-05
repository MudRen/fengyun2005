#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "试剑石");
	set("long", @LONG
一块巨大的石头，孤处路中，中间一痕，深几近半，相传这是一古代剑师试剑
之处，铸剑千余，最后终于造出一把可以劈开此石的剑，名为“苍穹神剑”，可惜剑
师因心力憔悴而死。相传黄山剑庐主人世代相传的便是此剑。
LONG
	);
	set("exits", ([ 
	"north"  : __DIR__"zuishi",
	]));
	set("item_desc", ([
"stone": "一块巨大的石头，中间一痕，裂缝深处似乎有一
东西闪闪发光。你似乎也可以在这里试一试（ｔｅｓｔ）你的武器。\n",
		"石头": "一块巨大的石头，中间一痕，裂缝深处似乎有一
东西闪闪发光。你似乎也可以在这里试一试（ｔｅｓｔ）你的武器。\n",
		"rock": "一块巨大的石头，中间一痕，裂缝深处似乎有一
东西闪闪发光。你似乎也可以在这里试一试（ｔｅｓｔ）你的武器。\n",

	]) );
    
	set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",-20);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("do_test","test");
}

int do_test(string arg)
{
	object me,weapon;
	if(!arg ) return notify_fail("你要试一试你身上的哪样武器？\n");
	me=this_player();
	
	if(!(weapon = present(arg,me))) return notify_fail("你身上似乎没有这样东西！\n");
	if(!weapon->query("weapon_prop")) return notify_fail(weapon->name()+"似乎并不是一种武器！\n");
	if(!weapon->query("equipped")) return notify_fail("你并没有将"+weapon->name()+"握在手中。\n");

	message_vision(WHT"$N用尽全力，将手中的"+weapon->name()+"猛力向巨石挥去。。。。\n"NOR,me);
	
	if (me->query("max_force")< 1000)
		return notify_fail("你的力气太小，被巨石反震得摇摇晃晃（需要1000点最大内力）\n");
	
	weapon->unequip();
	if(weapon->query("owner")){
		weapon->set("orig_name", weapon->query("name"));
		weapon->set("weapon_prop/damage",1);
        weapon->set("item_damaged", 1);
	} else {
		weapon->set("weapon_prop",0);
	}
	
	message_vision(HIG"只听见”铛“的一声，$N手中的"+weapon->name()+"应声而断！
$N被震得气血翻涌，腾腾腾倒退数十步，一跤跌倒在地，半晌儿没法动弹。\n"NOR,me);
		
	weapon->set("name","断掉的" + weapon->query("name"));
	weapon->set("item_damaged", 1);
	weapon->set("value",0);
	weapon->save();
	me->reset_action();
	
		message_vision(BLU"一块黑黝黝的东西从石缝中掉了出来落入$N怀中！\n"NOR, me);
		weapon = new(__DIR__"obj/banzhi");
		weapon->move(me);
		weapon->set("no_drop",1);
	
	me->perform_busy(10);
	return 1;
}
