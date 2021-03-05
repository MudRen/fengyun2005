#include <ansi.h>
inherit ITEM;
string statuedesc();

void create()
{
    set_name("铁像", ({"statue","铁像"}) );
    set_weight(200000);
    set("long", "一座二人高的铁像，塑一大手大脚的虬髯汉子，两条发墨般的浓眉，棱棱的颧
骨，一只瘦骨嶙峋的大手抓着柄已锈得快烂的铁剑。\n");
    set("no_get",1);
    set("no_shown",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("long",(: statuedesc :));
                set("unit", "座");
                set("value", 3000);
              }
    ::init_item();
}

void init()
{
	add_action("do_turn","turn");
	add_action("do_look","look");
}


int do_look(string arg){
	
	if (arg=="铁剑" || arg == "把手") {
		tell_object(this_player(),"锈的快烂掉的铁剑，上面的把手也残缺了。\n");
		return 1;
	}
	return 0;
}


int do_turn( string arg){
	object me, room;
	
	me=this_player();
	if (!REWARD_D->check_m_success(me,"魔窟寻踪")) {	
		// 恶人窟　is not finished right now. no riddle gives this mark
		tell_object(me,"你使劲转了转把手，却找不到窍门也没什么反应。\n");
		return 1;
	}
	
	if (!arg || (arg!="把手" && arg!="handle")) {
		tell_object(me,"你要转什么？\n");
		return 1;
		}
	message_vision	(YEL"$N用力一扳剑柄，只听一阵嘎嘎的响声，$N脚下出现了一个大洞。\n"NOR,me);
	room = find_object(AREA_EREN"tocave");
    if(!objectp(room)) 
      	room = load_object(AREA_EREN"tocave"); 
	message_vision(HIR"一声惊叫，$N向洞里直坠下去。\n"NOR,me);
	message("vision",HIG"上方又掉下一个人来，手忙脚乱地抓住了你身边的藤条。\n"NOR,room);
	me->move(room);
	return 1;
}