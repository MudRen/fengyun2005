//libie.c
// - neon

/*    
黯然销魂者，唯别而已矣！
......

日下壁而沉彩，月上轩而飞光。
见红兰之受露，望青楸之离霜。
巡层楹而空掩，抚锦幕而虚凉。
知离梦之踯躅，意别魂之飞扬。
...

故别虽一绪，事乃万族。
...

至若龙马银鞍，朱轩绣轴，帐饮东都，送客金谷。
琴羽张兮箫鼓陈，燕、赵歌兮伤美人，
珠与玉兮艳暮秋，罗与绮兮娇上春。
惊驷马之仰秣，耸渊鱼之赤鳞。造分手而衔涕，感寂寞而伤神。
...

君结绶兮千里，惜瑶草之徒芳。
惭幽闺之琴瑟，晦高台之流黄。
春宫闭此青苔色，秋帐含此明月光，
夏簟清兮昼不暮，冬珙凝兮夜何长！
织锦曲兮泣已尽，回文诗兮影独伤。

...

是以别方不定，别理千名，有别必怨，有怨必盈。
使人意夺神骇，心折骨惊，虽渊、云之墨妙，严、乐之笔精，
金闺之诸彦，兰台之群英，赋有凌云之称，辨有雕龙之声，
谁能摹暂离之状，写永诀之情着乎？

...
*/

// 黯然销魂者唯别而巳		self-busy 3, every 5mins it's a dmg: = 2500-3000 potential pfm, and you break a leave hook.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int libie_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
	string msg, weather,wname;
	int extra,skill, damage,d;
	object weapon;

	// 2.5x150 = 375
	if (me->query_skill("xiaohun-sword",1)<120)
		return notify_fail("离别需要120级的黯然销魂剑法。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(MAG"［离别］"NOR"只能对战斗中的对手使用。\n");

	//	475 -- 525 + 150 = 625 
	extra = me->query_skill("sword") + F_LEVEL->get_level(me->query("combat_exp"));
	weapon = me->query_temp("weapon");

	//	I: atk+130  dmg 160
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/4);
	msg = HIC"$N手中"+ weapon->name()+ HIC"发出流星般的光芒划过长空。。。\n"
HIW "光芒虽短促，但天上已经没有星光能比它更灿烂，辉煌！！！\n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/4);
	
	
	if (
		(!REWARD_D->check_m_success(me,"销魂传人") || me->query("timer/libie")+300> time()))
	{	
		me->perform_busy(3);
		return 1;
	}
	
	if (userp(me))
	if (weapon->query("id") != "leave hook"){
		me->perform_busy(3);
		return 1;
	}
		
	me->set("timer/libie",time());
	
	target->set_temp("combat_no_report",1);
	
//	attack II, atk = 310,dmg = 625	
	
	msg = WHT"\n\n光芒淡去之后，$n"NOR+WHT"眼前忽然浮现出萧萧落叶下，天际间远去的孤帆，
一时心中充满永世分离般的寂寞与伤痛。";
	msg += YEL"\n\n$N手中" + weapon->name() + YEL"慢慢划过，隐隐似有呜咽之声，
金石震而色变，骨肉悲而心死。\n"NOR;
	message_vision(msg,me,target);	
	
	target->delete_temp("last_damage_from");
		
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra);

    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage",-extra);

//	attack III, atk=310, dmg = 625

    msg = HIB"\n四下里一片沉寂，风吹落木的声音都没有，也许是风根本就吹不到这里。"NOR;
    msg += HIG"\n\n$N手中" + weapon->name() + HIG"忽然发出幽幽声响如轻歌飘来 . . . 
谁能听出其中的暂离之状，永诀之情呢？\n"NOR;	    
	message_vision(msg,me,target);

	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage",-extra);
	target->delete_temp("no_check_pfm_win");

//  attack IV  sen damage, need previous hit + leave hook	
	if (!target->query_temp("damaged_during_attack"))
	{
		message_vision(HIR"\n$N遽然而惊，在秋风飘缈，离梦别魂般的剑影中急闪而出。 \n"NOR,target);
	}	
	else {
        	message_vision(HIW"\n\n\n     黯  然  销  魂  者 ， 唯  别  而  巳  ... ...  \n\n"NOR,me);
        	damage = COMBAT_D->magic_modifier(me, target, "sen", extra*2);
            		
    		target->receive_wound("sen",damage, me);
    		me->receive_damage("kee", damage, me);
    		me->receive_wound("kee", damage, me);
    		
			me->set_temp("last_damage_from","万念俱灰，郁郁而亡。\n");
       		
       		if (userp(me)) {
	       		msg = HIY "\n只听见「啪」地一声，$N手中的" + weapon->name() + HIY"在剧振中已经断为两截！\n"NOR;
	
				weapon->set("orig_name", weapon->query("name"));
				wname = replace_string( weapon->name(), "断掉的", "");
				weapon->set("name", "断掉的" + wname);
				d = weapon->query("weapon_prop/damage") - 1;
				weapon->set("weapon_prop/damage",1);
				me->add_temp("apply/damage",-d); 
				if (weapon->query("owner")) {
					weapon->save();
				}
				else {
					weapon->unequip();
					weapon->set("weapon_prop", 0);
					weapon->set("value", 0);
				}
	
	          	msg += YEL"\n$N强运内力，冷冷的剑风依然从断剑迫出... \n";
	          	msg += MAG"\n\n霎那间万籁俱寂，$n"MAG"突觉万事殊无意味，一阵冰冷涌上心头。\n\n"NOR;
	            message_vision(msg,me,target);	    		    	
			}
	}

	COMBAT_D->report_status(target,1);
	target->delete_temp("combat_no_report");
	me->perform_busy(3);
	return 1;
}
