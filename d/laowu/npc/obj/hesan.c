#include <ansi.h>  
inherit ITEM;

void create()
{
		set_name(HIB"离魂散"NOR, ({ "lihunsan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long","这是昔年蝙蝠公子的独门密药，可以用在自己身上。\n");
                set("desc_ext", "use lihunsan");
        }
        ::init_item();
}
void init()
{
	add_action("do_yong","use");
}

int do_yong(string arg)
{
	object ob,room;
	object me,corpse;
	me=this_player();
	
	
	if (arg != "lihunsan") 
		return 0;
		
	if(me->is_busy()|| me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");
	
    if(environment(me)->query("no_fight") || environment(me)->query("no_fly"))
		return notify_fail("在这里不能用这个东西！\n");
    
    message_vision("$N小心翼翼地捧出$n吞了下去。\n",me, this_object());
	
	if (random(20)) {
		tell_object(me,"这药丸时间太长，似乎已经失效了。\n");
		return 1;
	}
		
	message_vision(BLU "$N只觉神魂飘忽，缕缕魂魄如抽丝般游出体外，飘飘悠悠向着鬼门关而去。\n"NOR, me);
	room = environment(me);
	if(objectp(corpse = CHAR_D->make_corpse(me, me)))
		corpse->move(room);
	me->move("/d/death/gate");
	me -> unconcious();  
	destruct(this_object());     
	return 1;
}
