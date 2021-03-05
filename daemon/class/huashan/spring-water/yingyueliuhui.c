// Silencer@fengyun	June.2005
//	此特技的作用类似于ＤｎＤ的Mirror_Image,受攻击时有50%几率免去伤害，共生效５次
//	starts from 3@100, then 5@120, 禁止在战斗中ｒｅｃａｓｔ

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int stone_done(object me, object caster);
int perform(object me, object target)
{
        int skill, num;
		mapping buff;	
		string msg;
	
        if(me->query("class")!="huashan")
    		return notify_fail("只有华山弟子才能使出『映月流辉』\n");

    	if( userp(me) && (string)me->query("gender") != "女性" )
        	return notify_fail("你一个大男人居然学来了这样扭扭捏捏的功夫，也好意思用？。\n");
        	
        skill = me->query_skill("spring-water",1);
		if(skill < 120 || me->query_skill("hanmei-force",1)<200) 
			return notify_fail("映月流辉需要120级的春水罗衫和200级的寒梅心法！\n");
        
        if (me->query_skill_mapped("force")!="hanmei-force")
        	return notify_fail("映月流辉唯有配合寒梅心法才有效。\n");
        
        if(!target) target = me;
        if( target != me ) 
        	return notify_fail("你只能将映月流辉用在自己的身上。\n");
        
        if( ANNIE_D->check_buff(me,"ironup")|| ANNIE_D->check_buff(me,"hs_yylh"))
        	return notify_fail("你已经在施展类似的护体神功了。\n");
        
        if (userp(me) && me->is_fighting())
			return notify_fail("映月流辉无法在战斗中使用。\n");	
		
        if( me->query("force") < 150 )     
        	return	notify_fail("映月流辉需要150点的内力。\n");
		if (userp(me))	me->add("force", -150);
		
    	msg = HIC
"$N凝眉低首，运起『映月流辉』，身上衣衫如月映星河，银波摇曳。\n"NOR;
    	msg += WHT
"波光中$N的身影似乎化作了数个，淡淡地飘动．．．\n" NOR;

        num = 3 + (skill - 100)/10;
		if (num >=5 ) num = 5;
	
		me->set_temp("pfm/hs_yingyueliuhui",num);
		buff =
			([
				"caster":me,
				"who":	me,
				"type2": "ironup",
				"type": "hs_yylh",
				"att": "bless",
				"name": "春水罗衫·映月流辉",
				"time":    180,
				"buff_msg":msg,
				"warn_msg":"",
				"finish_function": (: stone_done :),
			]);
		
		ANNIE_D->buffup(buff);
	    return 1;
}


int stone_done(object me, object caster){
	me->delete_temp("pfm/hs_yingyueliuhui");
	return 1;
}


