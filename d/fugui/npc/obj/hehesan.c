#include <ansi.h>  
inherit ITEM;

void create()
{
set_name(HIY"阴阳和合散"NOR, ({ "hehesan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "包");
            set("long","这是昔年恶贯满盈的采花大盗雄娘子的独门密药，可以用（ｙｏｎｇ）在别人身上。\n");
        }
        ::init_item();
}
void init()
{
	add_action("do_yong","yong");
}

int do_yong(string arg)
{
	object ob;
	object me;
	int dp,gs;
	int damage;
	me=this_player();
	
	if(me->is_busy()) return notify_fail("你正忙着呢。\n");
	
	if (!arg) return notify_fail("你要用在谁身上？\n");
    
    if ( me->query("combat_exp") < 80000 )
		return notify_fail("你经验太差了，妄用"+this_object()->name()+"会引火烧身，伤害自己的。\n");
	
	ob=present(arg,environment(me));
	if (ob==me) return notify_fail("不要命了?\n");
    
    if( environment(me)->query("no_fight"))	return notify_fail("在这里不能用这个东西！\n");
    
    if (!objectp(ob) || !living(ob)) return notify_fail("只能对活的生物使用。\n");
	
	if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("你无法向此人下药。\n");
	}
	
	tell_object(me,"你摸出阴阳和合散下在"+ob->query("name")+"身上。\n");
	if ( random(3*me->query("combat_exp")) > ob->query("combat_exp") 
			&& !ob->query("boss")) {
            if (ob->query_skill("perception")/10>random(15))
			{
				message_vision(HIR"$N向$n下阴阳和合散的企图被发现了!$N心头一振，阴阳和合散洒落在自己身上。。\n"NOR,me,ob);
				message_vision(RED "$N只觉浑身炽热，体气蒸熏，情欲难遏，全身似乎简直要炸开一样。\n"NOR,me);
				if(!me->query_condition("hehe"))
					me->apply_condition("hehe",random(3)+3);
				destruct(this_object());

			}else
			{
				message_vision(RED "$N只觉浑身炽热，体气蒸熏，情欲难遏，全身似乎简直要炸开一样。\n"NOR,ob);
				if(!ob->query_condition("hehe"))
                    ob->apply_condition("hehe",random(5)+5);
				destruct(this_object());
			}
     }	else {
       	tell_object(me,"你被发现了!\n");
       	message_vision(HIR"$N向$n下阴阳和合散的企图被发现了!"NOR,me,ob);
       	ob->kill_ob(me);
       	me->kill_ob(ob);
       	destruct(this_object());
    }
    
    me->start_busy(3);       
	return 1;
}
