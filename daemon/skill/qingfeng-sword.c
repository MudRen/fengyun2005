// qingfeng-sword.c

//	清风十三式的特效
//  华山派武功的命中率提高１０％，每１０级提高０。５％
// 	华山派武功: qingfeng-sword, tanzhishentong, zhaixin-claw


#include <combat.h>
#include <ansi.h>
inherit SKILL;

int perform(object me, object target);
int do_yuexie(object me,object target,int count,object weapon);

string *qf_dance = ({
//"$N"NOR CYN"左手横眉，$w"NOR CYN"斜削而出，剑光似有似无，出手似快似慢，剑路似实似虚，招式将变
//未变。正是“清风十三式”中的第一式“清风徐来”",
"『流空萤火』-- $N"NOR CYN"回剑轻削，飘渺的剑光点点飞来如同夜空中流萤飞舞，袭向$n！",
"『竹外山岚』-- $N"NOR CYN"手腕轻抖横剑削来，只见剑意萧萧，飘摇不定! ",
"『云淡风轻』-- $N手中$w"NOR CYN"回掠，似乎意态优闲，然而剑势不经意的变幻之间已拂向$n!",
"『空穴来风』-- $N"NOR CYN"左手轻掠划了一个半弧，右手$w"NOR CYN"连点，淡淡的剑气忽然从四面八方掩向$n！",
"『落絮轻扬』-- $N"NOR CYN"手中$w"NOR CYN"慢慢挑起，剑势飘动间如团团落絮，悠悠漫漫织成一道剑网！",
"『霜笛清晓』-- $N"NOR CYN"横持$w"NOR CYN"左手斜挥而下，右手一转将$w"NOR CYN"平平推出，丝丝剑气飘然而至!",
"『风动千铃』-- $N"NOR CYN"剑光点点流动，如风铃此起彼伏，却分不清到底哪一处在响！",
"『绿涨春风』-- $N"NOR CYN"手中$w"NOR CYN"剑势忽左忽右，不断向前飘动，然而剑光却渐渐涨起，如春风点染绿林!",
"『寒梅落雪』-- $N"NOR CYN"剑势萧疏，剑光清冷，如点点落梅在风中飘向$n！",
"『雁阵偏吹』-- $N"NOR CYN"轻摆$w"NOR CYN"，剑光若有若无间斜飘而至!\n",
"『风送浮萍』-- $N"NOR CYN"手中$w"NOR CYN"轻转，一道道短短的弧光浮现身前，只见弧光飘动，浮向$n!”",
"『落霞流散』-- $N"NOR CYN"如风吹弱柳，微微侧身，反手挥出$w"NOR CYN"，剑光似片片落霞飘来!\n",
});



void setup() {
	set("name","清风十三式");
	set("type","sword");
	set("effective_level",160);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","huashan");
	set("difficulty",200);
	set("practice_limit",100);
	set("unarmed_parry_msg",({
		"$n手中$v慢慢挑起，剑势飘动间如团团落絮随风而起，“清风十三式”中
第六式“落絮轻扬”使出，悠悠漫漫织成一道剑网。\n",
		"$n轻摆$v，剑光若有若无间斜飘而至，使出“清风十三式”中第十一式
“雁阵偏吹”，将$N攻势化于无形。\n",
		"$n如风吹弱柳，微微侧身，反手挥出$v，剑光似片片落霞飘来，以“清风
十三式”中 第十三式“落霞流散”将$N封出。\n",
					})	
	);
	action = ({
        ([      "action":               
"$N左手横眉，$w斜削而出，剑光似有似无，出手似快似慢，剑路似实似虚，招式 
将变未变。正是“清风十三式”中的第一式“清风徐来”",
                "dodge":                100,
                "damage":               33,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出“清风十三式”中第八式“风动千铃”。剑光点点流动，如风铃此起彼伏，却 
分不清到底哪一处在响"NOR,
                "dodge":                120,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出“清风十三式”中第二式“流空萤火”，回剑轻削，飘渺的剑光点点飞来如同
夜空中流萤飞舞，袭向$n$l",
                "dodge":                100,
                "damage":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手腕轻抖横剑削来，只见剑意萧萧，飘摇不定，却是“清风十三式”中第三式
“竹外山岚” ",
                "dodge":                270,
                "damage":		40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w回掠，似乎意态优闲，停招不发，然而剑势不经意的变幻之间已拂向$n$l，
正是“清风十三式”中第四式“云淡风轻”",
                "dodge":                150,
                "damage":		100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N左手轻掠划了一个半弧，右手$w连点，使出“清风十三式”中第五式“空穴来风”， 
淡淡的剑气忽然从四面八方掩向$n",
                "dodge":                100,
                "damage":		10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N将$w横持在面前，左手斜挥而下，右手一转将$w平平推出，丝丝剑气飘然而至。 
正是“清风十三式”中第七式“霜笛清晓”",
                "dodge":                195,
                "damage":		70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w剑势忽左忽右，不断向前飘动，让人分不清方向，然而剑光却渐渐 
涨起，如春风点染绿林。正是“清风十三式”中第九式“绿涨春风”",
                "dodge":                110,
                "damage":		30,
                "damage_type":  "刺伤"
        ]),                       
        ([      "action":               
"$N使出“清风十三式”中第十式“寒梅落雪”，只见剑势萧疏，剑光清冷， 
如点点落梅在风中飘向$n$l",
                "dodge":                195,
                "damage":		120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w轻转，一道道短短的弧光浮现身前，正是“清风十三式”中 
第十二式“风送浮萍”，只见弧光飘动，浮向$n$l”",
                "dodge":                260,
                "damage":		130,
                "damage_type":  "割伤"
        ]),     
                   
	});
}


mapping query_action(object me, object weapon)
{
	int attack_act;
	int level;
//	object *victims,victim;
	mapping act;
	
	level = F_LEVEL->get_level(me->query("combat_exp"));
	
	attack_act=random(sizeof(action));
	me->set_temp("qingfeng-act",attack_act);
    
    if (level >= 110 && attack_act==0) {
    	act = 
        ([      "action":               
CYN"『清风徐来』-- $N"NOR CYN"左手横眉，$w"NOR CYN"斜削而出，剑光似有似无，出手似快似慢，剑路似实
似虚，招式将变未变!"NOR,
                "dodge":                100,
                "damage":               33,
                "damage_type":  "割伤"
        ]);
        
    	return act;
    }	
    return action[attack_act];
}



mixed hit_ob(object me, object victim)
{	int act;
        int pro, level;
        int dam;
      int level_bonus;
        string *type = ({ "gin","kee","sen"});
        string damtype;
		object weapon;
		
		if (userp(me) && me->query("class")!= "huashan")
			return ("");
			
		if (me->query_skill_mapped("force") != "hanmei-force")
			return ("");
				
		act=me->query_temp("qingfeng-act");			
		level = F_LEVEL->get_level(me->query("combat_exp"));
		
		CHANNEL_D->do_sys_channel("sys", sprintf("level = %d, act = %d", level, act));
         
		// 9 in 10 acts. 90% chance to have extra damage. 
		// 10% to start dancing attack
		switch(act) {
			case 2:
				damtype="kee";
				break;
			case 5:
				damtype="gin";
				break;
			case 8:
				damtype="gin";
				break;
			case 9:
				damtype="sen";
				break;
			case 1:	
				if (level < 48) break;
				damtype="kee";
				break;
			case 3: 
				if (level < 58) break;
				damtype="kee";
				break;
			case 4: 
				if (level < 74) break;
				damtype="kee";
				break;
			case 6: 
				if (level < 84) break;
				damtype="sen";
				break;
			case 7:
				if (level < 100) break;
				damtype = "kee";
				break;				
		}
		
		dam = me->query("force_factor")
				+ me->query_skill("qingfeng-sword",1)
				+ F_LEVEL->get_level(me->query("combat_exp"));
		
		if(damtype && me->query("class")=="huashan")
		{
			// dmg = 95+ 200 + 139 = 434 maximum			
			dam = COMBAT_D->magic_modifier(me, victim, damtype, dam);		
			victim->receive_damage(damtype,dam,me);
			return (YEL"$n"NOR YEL"浑身一麻，似乎已被$N"NOR YEL"的内劲所伤。\n" NOR);
		}
		
		if (ANNIE_D->check_buff(me,"swordshield")
			|| me->query_temp("annie/perform_sworddance"))	return 0;
		
		if (level >= 200 && act == 0 )	// 第一式		still need more test, so set level to be 200
			perform(me, victim);
		return "";				
}

int accuracy_level(object me){
	if (me && me->query_skill("qingfeng-sword",1)>=100) 
		return (me->query_skill("qingfeng-sword",1)-100);
	return 0;
}

int damage_level(object me){
	if (me && me->query_skill("zhaixin-claw",1)>=100)
		return (me->query_skill("zhaixin-claw",1)-100);
	return 0;
}


int perform(object me, object target)
{
	object weapon;
	mapping buff;

	if( !target ) return 0;
	
	buff =
	([
		"caster":me,
		"who": me,
		"type":"swordshield",
		"att":"bless",
		"name":"清风十三式·剑舞",
		"shield_type":"force",
		"shield_amount":10000,
		"shield_desc":WHT"$N一招攻去，却如攻入波光幻影，失去了$n的行踪！\n"NOR,
		"time":  40,
		"buff_msg": " ",
		"disa_msg": " ",
	]);
				
	ANNIE_D->buffup(buff);
	weapon = me->query_temp("weapon");
	message_vision( WHT"
剑色淡淡，轻得就像一阵微风，柔得就像一抹月色。
剑光闪在$N眸里，滴映$N温柔的脸上，
$N轻拈剑柄，起舞，淡青色的衣袖挥动，轻盈若诗，悠美如梦。\n\n" NOR, me,target);
    call_out("do_yuexie", 1, me,target,0,weapon);
	me->perform_busy(2);
	return 1;
}

int do_yuexie(object me,object target,int count,object weapon)
{
//	int i;
	string msg;
	if (!me)	return 0;
	
	if(!target||!me->is_fighting(target)||environment(target)!=environment(me))
	{
		ANNIE_D->debuff(me,"swordshield");
		return 0;
	}
	if(!present(weapon,me)||weapon->query("equipped")!="wielded")
	{
		ANNIE_D->debuff(me,"swordshield");
		return 0;
	}
	
	me->stop_busy();
	me->set_temp("annie/perform_sworddance",1);
//	i=me->query_skill("qingfeng-sword",1);
//	me->add_temp("apply/damage",i*(count+1));
   	msg = qf_dance[count];
   	COMBAT_D->do_attack(me,target, TYPE_PERFORM, CYN+msg+NOR);
//	me->add_temp("apply/damage",-i*(count+1));
	me->delete_temp("annie/perform_sworddance");
	me->perform_busy(2);
	if (count < 11 && ( count<3 || random(2)))
	{
		count++;
	    call_out("do_yuexie", 1, me,target,count,weapon);
	}
	else
	{
		ANNIE_D->debuff(me,"swordshield");
		message_vision(WHT"\n$N缓缓收势，如一只小蜻蜓落在荷叶上，不惊落一滴露珠。\n"NOR,me);
		me->start_busy(1);	// immune to parry busy
	}
	return 1;
}



int help(object me)
{
	write(@HELP   
清风剑法必须配合寒梅心法才有特效
清风剑法本身没有特殊技能，但如果击中对手，则可能造成敌人额外的精
气神伤害。随着自身经验等级的升高，有特殊效果的几率也会逐步增大。

伤害数值 = 加力（enforce）+清风剑法等级+自身经验等级

清风剑法100级以上，每10级提高华山武功（摘心手、清风剑、弹指神通）
命中等级+10。
HELP
    );
    return 1;
}