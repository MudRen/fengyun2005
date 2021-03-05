//	Silencer@fy4 workgroup
/*L100	『一字长蛇阵』啸警，脱离战斗，CDT30分钟
L150	『二龙汲水阵』*护卫攻击力增加（＋兵法／３），持续20分钟
L160	『三才天地人阵』召唤护卫，非战斗中使用，CDT1分钟
L170	『四车兜底阵』*护卫的招架增加（＋兵法／３），持续20分钟
L180	『五虎攒羊阵』所有护卫各自攻出一招，主人自我忙乱一回合
L200	『六子连芳阵』护卫牺牲自己来试图困住对手，
		若成功敌人忙乱三回合，若失败则护卫死亡
		此特技不受ＢＵＳＹ法则中９回合效率下降的影响，
L210	『七星斩将阵』所有护卫合力击出一招，主人自我忙乱一回合
		额外攻击力＝兵法＊５／２
		额外伤害力＝参与此招护卫数＊兵法等级
		此招杀伤力不受对方铁布衫的影响
L220	『八卦金锁阵』* 护卫为主人挡住敌人伤害，CDT 30分钟，
		主人所受伤害＊３转嫁到护卫身上，持续２分钟
L230	『九曜星宮阵』使出玉环，自身无忙乱，CDT 15分钟
L250	『十面埋伏阵』在一分钟内增加两个额外的护卫，CDT 30分钟
其使用方法分别为dodge.yi；dodge.er；dodge.san；dodge.si；
dodge.wu；dodge.liu；dodge.qi；dodge.ba；dodge.jiu；dodge.shi
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform_1(object me, object target)
{
    int skill, num, i, duration,title,hate;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	
	object soldier,*enemy;
	int strategy,leadership;
	int timer;
		
	skill = me->query_skill("strategy",1);

    timer = 1800 - F_ABILITY->check_ability(me,"yi_add")*60;
    duration = me->query("timer/pfm/alert")-time() + timer;
    if ( duration >0) {
		tell_object(me,"你还需要等待"+(int)(duration/60)+"分钟左右才能再次发动一字长蛇阵。\n");
 		return 1;
 	}
 	
    if (ANNIE_D->check_buff(me,"lockfield") >= 1) {
		tell_object(me,"此地地势不利，无法发动一字长蛇阵。\n");
		return 1;
	}
	
	if( !me->is_fighting() ){
        tell_object(me,"一字长蛇阵只能在战斗中发动！\n");
        return 1;
    }		
	
	if( me->query_temp("max_guard") > 1 ){
    	tell_object(me,"一字长蛇阵正在发动！\n");
		return 1;
	}
	
	msg = BGRN + HIY "$N挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"一字长蛇之阵！\n" NOR HIB"
滚滚烟云中，一人黑衣、黑马、黑旗，卷至$N身前叫道：阵法已动，将军速退，待末将断后！\n\n"NOR; 	

  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	seteuid(getuid());
	soldier= new("/obj/npc/danei_guard");
	soldier->set("possessed", me);
    soldier->set_leader(me);
      	   	
    soldier->set_name(WHT"死士"NOR,({ "sishi" })); 
	soldier->move(environment(me));	
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
		
	if (soldier) {       	
		    enemy = me->query_enemy();
		    if (enemy)
	    	for (i=0;i<sizeof(enemy);i++)
	    	{
	       		hate = enemy[i]->query_hate(me);
	       		enemy[i]->add_hate(soldier, hate);     	
	    	}   	
  			me->remove_all_killer();
        	me->add_temp("max_guard",1);
    }

    me -> set("timer/pfm/alert",time());      	        
    return 1;
}
	
int perform_2(object me, object target)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        tell_object(me,"你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        return 1;
    }
        
	if (me->query_temp("guard_count")<2) {
       	tell_object(me, "你的护卫太少，列不出阵法耶。\n");
        return 1;
    }
    	
	msg = BGRN + HIY "$N"BGRN + HIY "挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"二龙汲水之阵！\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	
		
    if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
    shiwei = filter_array(all_inventory(environment(me)),
        		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    num = sizeof(shiwei);	
	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"兵法·二龙汲水阵",
				"buff1":"apply/attack",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",		
				"disa_type":1,	
			]);
		ANNIE_D->buffup(buff);		
    }

    return 1;
}

int perform_3(object me, object target)
{
        int skill, num, i, duration;
	object *shiwei;
	mapping buff;
	string msg;
	
	int extra, maximum, gcount;
	object recruit;
	
	object *enemy;
		
        	
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        tell_object(me, "你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        return 1;
    }
    
    maximum = 2;
	if (me->query_skill("leadership",1)>= 250)	maximum = 4;
	else if (me->query_skill("leadership",1)>= 175) maximum = 3;
        	
    gcount=me->query_temp("guard_count");
	if(gcount>=maximum) {
		tell_object(me,"你现在不需要列三才天地人阵。\n",me);
        return 1;
   	}
   	        	
    if (userp(me) && me->is_fighting()) {
       	tell_object(me, "该阵法在战斗中使用没有效果的。\n");
        return 1;
    }
    	
    duration = me->query_temp("timer/pfm/gf_san")-time() + 60;
	if (userp(me))
        if (duration>0) {
        	tell_object(me,"『三才天地人阵』每分钟只能排练一次。\n");
        	return 1;
    }
    
	msg = BGRN + HIY "$N"BGRN + HIY "挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"三才天地人之阵！\n" NOR YEL"
忽见阵外腾腾腾走来一名壮士，扑地拜倒在$N"NOR+YEL"身前，朗声说道：将军之义，天高水长，
在下$n愿在帐前效力，卫国杀敌，万死不辞。\n\n"NOR; 	
  	
  	extra=me->query_skill("strategy",1)+ me->query_skill("leadership",1);
	seteuid(getuid());
	recruit=new("/obj/npc/huwei");
	recruit->invocation(me,extra);
	recruit->move(environment(me));
	
  	message_vision(msg, me, recruit);
  	me->set("timer/pfm/yue_array",time());
  	me->set_temp("timer/pfm/gf_san",time());	 		
	me->add_temp("guard_count",1);
	if (!userp(me))
	{
		enemy = me->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				recruit->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(shiwei);
				else enemy[i]->kill_ob(recruit);
			}
		}
	}
        return 1;
}

int perform_4(object me, object target)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        	tell_object(me,"你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        	return 1;
    }
    
	if (me->query_temp("guard_count")<2) {
        	tell_object(me, "你的护卫太少，列不出阵法耶。\n");
        	return 1;
    }
    
	msg = BGRN + HIY"$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"四车兜底之阵！\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	// 250/3 = 83
		
	if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
	// Well: SHiwei = shiwei + friend + myself:)
    shiwei = filter_array(all_inventory(environment(me)),
       		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    
    num = sizeof(shiwei);	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"兵法·四车兜底阵",
				"buff1":"apply/parry",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",
				"disa_type":1,			
			]);
		ANNIE_D->buffup(buff);		
    }
    return 1;
}

int perform_5(object me, object target)
{
        int skill, num, i, duration, mod;
	string msg, name;
	object *env, *huwei, weapon;
	string *poem = ({"『立马林岗豁战眸，阵云开处一溪流』"HIY"阵东转出一将，",
"『机舂水沾犹传晋，黍离宫庭孰悯周』"HIY"阵西转出一将，",
"『南服只今歼小丑，北辕何日返神州』"HIY"阵南转出一将，",
"『誓将七尺酬明圣，怒指天涯泪不收』"HIY"阵北转出一将，",
"『待从头，收拾旧山河』"HIY"阵前转出一将，",
"『朝天阙！』"HIY"阵后转出一将，"
	});

	skill = me->query_skill("strategy",1);
             
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei)) {
		tell_object(me, "你的护卫不在左近，无法发动『五虎攒羊陣』\n");
		return 1;
	}
	
	msg = "\n"BGRN + HIY"$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"五虎攒羊之阵！"NOR HIR" 	

$N"HIR"纵声喝道：雄气堂堂贯斗牛，誓将直节报君仇。斩除顽恶还车驾，不问登坛万户侯！
话音未落，身后众将齐声应和，声震云霄。\n"NOR;
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	for (i=0;i<sizeof(huwei);i++) {
  		if (huwei[i]->query_temp("is_unconcious") 
  			|| !huwei[i]->is_fighting(target)
  			|| huwei[i]->is_busy())	continue;
  			msg = HIW+poem[i]+ "拍马上前直取$n，"HIY"正是" + huwei[i]->name()+"！\n"NOR;
  		if (huwei[i]->query("skill")== "spear" || huwei[i]->query("skill")=="hammer") {
  			huwei[i]->add_temp("apply/attack", skill*2);
  			huwei[i]->add_temp("apply/damage", skill);

  			COMBAT_D->do_attack(huwei[i],target, TYPE_PERFORM,msg);

  			huwei[i]->add_temp("apply/attack", -skill*2);
  			huwei[i]->add_temp("apply/damage", -skill);
  			
  			huwei[i]->perform_busy(1);
		}
  	}

	me->perform_busy(1);	
    return 1;
}

	
int main (object me, string arg1)
{
	
	int num,stra,lead,duration;
	string *zheng = ({ "『一字长蛇阵』","『二龙汲水阵』","『三才天地人阵』","『四车兜底阵』","『五虎攒羊陣』",
						"『六子连芳阵』","『七星斩将阵』","『八卦金锁阵』","『九曜星宮阵』","『十面埋伏阵』"});
	int *zheng_r = ({100,150,160,170,180,200,210,220,230,250});
	string arg;
	object obj,target;
	
	if (userp(me))
    if (me->query("family/master_id")!="master yue" 
        || me->query("class")!="official")
        return notify_fail("只有岳飞的弟子才能使用阵法。\n");
    
    if (me->is_busy())
    	return notify_fail("你现在正忙，无法使用阵法。\n");
    	
   	if( environment(me)->query("no_fight"))
		return notify_fail("这里无法使用阵法。\n");

	if (!arg1)
		return notify_fail("你要使用哪一种阵法？\n");

	if (sscanf(arg1,"%d on %s", num, arg)!= 2) {
		num = atoi(arg1);	
		if (num>10 || num <0)
			return notify_fail("阵法正确使用格式为zheng 数字(1-10) on 对象\n");
	}
	
	if (num>10 || num <0)
		return notify_fail("阵法只有1-10种，正确使用格式为zheng 数字 on 对象\n");

    stra = me->query_skill("strategy",1);
    lead = me->query_skill("leadership",1);
    
    if (stra < zheng_r[num-1] || lead < zheng_r[num-1])
    	return notify_fail(zheng[num-1]+"至少需要"+ zheng_r[num-1]+"级兵法和用人之技。\n");
    	
    if (me->query_skill_mapped("force")!= "manjianghong")
    	return notify_fail(zheng[num]+"需要满江红心法为基础。\n");
    
    if (arg) {
    	if (!objectp(obj = present(arg, environment(me))))
			return notify_fail("此人不在你的周围。\n");
		if (! obj->is_character())
			return notify_fail("看清楚一点，那并不是生物。\n");
		if (!living(obj))
			return notify_fail("看清楚一点，那并不是生物。\n"); 
	}
	
    if( (int)me->query("force") < 50 )    
       	return notify_fail("演化阵法至少需要50点内力。\n");   	
    if (userp(me))
        	me->add("force", -50);

	// 变化阵法至少需要10秒钟的间隔
	duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0 && num !=1)
       	return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
    
    //	部分阵法至少需要2个护卫
    if (me->query_temp("guard_count")<2 && num == 5)
       	return notify_fail("你的护卫太少，列不出阵法耶。\n");
    
    //	攻击性的阵法只能在战斗中使用
    target = obj;
    if (num == 5) {	    	    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail(zheng[num-1]+"需要在战斗中施展，目前你不在战斗中，或是你指定的对象和你并不在战斗中。\n");
	}
	
	/*
	env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei)) {
		tell_object(me, "你的护卫不在左近，无法发动『五虎攒羊陣』\n");
		return 1;
	}*/
	
	CHANNEL_D->do_sys_channel("sys",sprintf("num= %O, target=%O",num, obj));

	switch (num) {
		case 1:	perform_1(me, target);break;
		case 2: perform_2(me, target);break;
		case 3:	perform_3(me, target);break;
		case 4: perform_4(me, target);break;
		case 5:	perform_5(me, target);break;
/*		case 6: perform_6(me, obj);break;
		case 7:	perform_7(me, obj);break;
		case 8: perform_8(me, obj);break;
		case 9:	perform_9(me, obj);break;
		case 10: perform_10(me, obj);break;	
	*/}
			
/*	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("你无法偷袭此人。\n");
	}*/
		
    
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	2word[0m
[0;1;37m────────────────────────────────[0m   

大昭高僧修炼观音明咒到170级以上后，可同时颂出数字真言，
但是，在使用之前必须静思片刻记忆。

格式举例：　2word an+an
又如：	   2word an+ni

使用cast 2word 便可将记忆住的真言同时颂出。

对于二字真言来说，耗费的法力最多不超过400，造成的自我忙乱
最多不超过4。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}