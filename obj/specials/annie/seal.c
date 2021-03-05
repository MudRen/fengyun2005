#include <ansi.h>
#include <combat.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name(CYN"缚法符"NOR,({"paper seal","seal"}));
	set_weight(10);
	set("unit", "叠");
   	set("long", "一张绘有明神至法的符纸。\n");
  	set("base_unit","张");
  	set("base_weight",50);
  	set("base_value",0);
  	set("volumn",1);
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
//	set("lore",1);
  	set_amount(1);
	::init_item();
}

void init(){
  	if(this_player()==environment())
  		add_action("do_shoot",({ "burn","burn" }));
}

int do_shoot(string arg)
{
	object me, target;
	int extra=150,myexp;
	string msg;

	
	me = this_player();
	if (!arg) return notify_fail("你要对谁使用法器？\n");
	if( !me->is_busy() )
		return notify_fail("你现在无法使用缚法符！\n");
	
	extra=me->query_busy()/2+random(me->query_busy());

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");	

	extra += target->query_busy();

	message_vision(HIY"\n$N"HIY"焚起一张缚法符纸，只见"NOR,  me); 
	message_vision(HIY"真火中寒芒一闪，一道白雾腾空而起，如绳索般\n绕着$N"HIY"缩转。\n"NOR, target); 
	message_vision(HIW"$N被雾气所滞，登时动弹不得。\n"NOR, target); 
	myexp=target->query("no_busy");
	target->delete("no_busy");
	target->force_busy(extra);
	target->set("no_busy",myexp);
	add_amount(-1);
	return 1;
}

    
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/




