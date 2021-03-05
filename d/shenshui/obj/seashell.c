#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("海蚌", ({ "sea shell" , "shell"}) );
    	set_weight(5000);
    	set_max_encumbrance(8000);
    	set("no_get", 1);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("prep", "in");
        	set("unit", "个");
        	set("long",  "一个巨大的海蚌。它的蚌壳紧闭。你似乎可以试着拉动它。（ｐｕｌｌ） \n");
    	}
    	::init_item();
}

void init()
{
   	add_action("do_pull", "pull");
}

int do_pull(string arg){
   	object me, shark, dia, shark1;
    	int num, i;
    	
    	me = this_player();
    	if(me->is_busy()){
        	return notify_fail("你正在忙。\n");
    	}
    	if(me->is_fighting()){
        	return notify_fail("还是先打完再说吧。\n");
    	}
    	if(!arg || arg != "shell" && arg != "sea shell"){
        	return notify_fail("你要拉什么？\n");
    	}    
    	if(!query("shark_came")) {
        	tell_object(me, HIY"你正准备拉动海蚌，猛然感到周围水流不寻常地紊动起来，心中忽生警兆。。。\n"NOR);
        	message_vision(HIW"\n    几条大白鲨缓缓的游了过来。\n"NOR, me);
        	num = me->query("宿命B/黄山_云海") +2;
        	for (i=0;i<num;i++) {
        	       	shark1 = new(AREA_SHENSHUI"npc/shark");
        		shark1 -> move(environment(this_object()));
        	}	
        	set("shark_came", 1);
    	} else if(present("big white shark", environment(me))){
        	tell_object(me, "你还是先担心大白鲨吧！\n");
    	}else {
        	message_vision("$N用力拉动海蚌。 \n", me);
        	message_vision("海蚌受到惊动，蚌壳忽然急剧地一张一合。。。 \n", me);
        	message_vision("一股强力的水流从蚌壳喷出，大海蚌一下滑向深海，一个闪光的东西掉落出来。。。\n", me);

//        	if(me->query("宿命B/黄山_云海") && !me->query("stone_mark/bstone")) {
			      	
        	message_vision(HIC"一块碧蓝的石头落在$N脚下的沙地上。\n"NOR, me);       
	        dia = new("/obj/specials/stone/bstone");
        	dia->move(environment(this_object()));
        	REWARD_D->riddle_done(me,"碧海蓝心",200,1);
//	You can get as many as you want.        	
/*        	} else {
        		message_vision(HIC"一道蓝光滑入海的深处。\n"NOR, me);
        	}*/
        	destruct(this_object()); 
    	}
    return 1;
}