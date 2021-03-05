// TIE@FY3
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIG  "千年温玉" NOR, ({ "old jade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块绿色的玉石，盈盈的绿意让人沉醉。
上书三个小字：黄山派。你似乎可以用它来疗伤（ｃｕｒｅ）。\n");
		set("value", 10000);
		set("max_cure",5);
		set("max_amount",1500);
		set("material", "stone");
	}
	::init_item();
}
void init()
{
	if(environment()==this_player())
	add_action("do_cure","cure");

}

int do_cure(string arg)
{
	object target, me;
	int amount;
	
	me = this_player();
	if(query("max_cure") <=0){
        set("name", "千年温玉");
        set("long", "一块绿色的玉石，然而绿色中隐隐带着一股黑气。\n");
        set("value", 1);
        return notify_fail("此温玉的疗效已经被用光了！\n");	    
    }
    if(!arg) {
        target = me;
    } else if(!objectp(target=present(arg, environment(me))) && !objectp(target=present(arg, me))){
        return notify_fail("这里没有这个人。\n");
    } else if(!target->is_character() || target->is_corpse()){
        return notify_fail("看清楚一点，那并不是活物。\n");
    }
	if(target->query("eff_kee") == target->query("max_kee"))
	return notify_fail("此温玉只能用来治疗外伤，对内伤没用！\n");

	amount = target->query("max_kee") - target->query("eff_kee");
	amount = amount/1500 ? amount/1500: 1;
	if (amount < 0 ) amount = 1;	
		
	target->set("eff_kee",(int)target->query("max_kee"));
	add("max_cure",-amount);
	
	
	if(target == this_player()){
    	message_vision("$N将一块千年温玉放在伤口上轻轻揉动，血淋淋的伤口
居然奇迹般的愈合了！！\n", me);
    } else {
    	message_vision("$N将一块千年温玉放在" + target->name() + "的伤口上轻轻揉动，血淋淋的伤口
居然奇迹般的愈合了！！\n", me);        
	}
    target->Cured(me);
	return 1;
}
