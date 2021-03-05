// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill, num, i, duration, mod, add;
	string msg, name;
	object *env, *huwei, weapon;
	string *poem = ({"『立马林岗豁战眸，阵云开处一溪流』"HIY"阵东转出一将，",
"『机舂水沾犹传晋，黍离宫庭孰悯周』"HIY"阵西转出一将，",
"『南服只今歼小丑，北辕何日返神州』"HIY"阵南转出一将，",
"『誓将七尺酬明圣，怒指天涯泪不收』"HIY"阵北转出一将，",
"『待从头，收拾旧山河』"HIY"阵前转出一将，",
"『朝天阙！』"HIY"阵后转出一将，"
	});

	
	if (userp(me))
        if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("只有岳飞的弟子才能使用『五虎攒羊陣』。\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 180 || me->query_skill("leadership",1)< 180)
		return notify_fail("『五虎攒羊陣』需要180级兵法和180级用人之技。\n");        		
	  
	    add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;     
    duration = me->query("timer/pfm/yue_array")-time() + 10 -add ;
	if (duration>0)
        	return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『五虎攒羊陣』只能在战斗中使用。\n");
		
    if (me->query_temp("guard_count")<2)
        	return notify_fail("你的护卫太少，列不出阵法耶。\n");
        
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei))
		return notify_fail("你的护卫不在左近，无法发动『五虎攒羊陣』\n");
	
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
