#include <ansi.h>
#include <combat.h>
inherit COMBINED_ITEM;


void create()
{
  	set_name(CYN"疾電符"NOR,({"paper seal","seal"}));
	set_weight(10);
	set("unit", "叠");
   	set("long", "一张绘有五雷咒纹的符纸，可令敌人忙乱三回合。\n");
  	set("desc_ext","祭符（burn <敌人id>）");
  	set("base_unit","张");
  	set("base_weight",50);
  	set("base_value",500);
  	set("volumn",1);
	set("value", 0);
//	set("lore",1);
  	set_amount(1);
	::init_item();
}

void init(){
  	if(this_player()==environment())
  		add_action("do_shoot",({ "burn"}));
}

int do_shoot(string arg){
	object me, target;
	int extra=150,myexp;
	string msg;
	
	me = this_player();
	if (!arg) return notify_fail("你要对谁使用法器？\n");
	
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");	
	
	if (target->is_busy())
		return notify_fail("对方已经手忙脚乱了。\n");
   
	myexp = me->query("combat_exp")*2/5+ random(me->query("combat_exp") / 100 * extra);
	message_vision(HIY"\n$N"HIY"焚起一张疾电符纸，只见"NOR,  me); 
	if(myexp >target->query("combat_exp")&& !target->query("boss") && !target->query("big_boss"))
	{
		message_vision(HIY"真火中寒芒一闪，一道刺眼亮光飞\n窜而起，直没进$N"HIY"前额之中。\n"NOR, target); 
 		message_vision(HIW"$N顿时如遭雷殛，浑身麻软，动弹不得。\n"NOR, target); 
		extra=target->query("no_busy");
		target->delete("no_busy");
		target->force_busy(3);
		target->set("no_busy",extra);
	}
	else
		message_vision(HIY"符纸渐渐缩卷化为灰烬，却什么也没有发生。\n"NOR, target, me); 
	me->perform_busy(1);
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
