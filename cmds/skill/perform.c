/*	Modifications
		
	-- 7/22/2004 by Silencer
		** 所有perform至少需要消耗50点内力，L51级以下免费。	
*/

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	object weapon;
    	string martial, skill;
    	string *skill_list = ({ "axe","blade","dagger","fork","hammer","parry","staff",
    				"sword","throwing","spear","unarmed","whip","musket"});
   		int force, mylevel, force2;
 	    string *freepass = ({ "chunxin","hengxie","jingpo", "juesha", "qianhuan", 
 	    					"yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"});       
    	string *freeforce = ({ "chunxin","hengxie","jingpo", "juesha", "qianhuan" });
//		string *freepass = ({});
//		string *freeforce = ({});
    	int chance;
    	
    	seteuid(getuid());
		
		
    	if( environment(me)->query("no_fight"))
		return notify_fail("这里无法使用特殊招式。\n");
    	if( me->is_busy() )
        	return notify_fail("（你上一个动作还没有完成，不能施用特殊招式。） \n");
        
    	if( !arg ) 
    		return notify_fail("你要使用哪一项特殊招式？\n");

    	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
	        if( weapon = me->query_temp("weapon") )
	            	martial = weapon->query("skill_type");
	        else if( weapon = me->query_temp("secondary_weapon"))
	            	martial = weapon->query("skill_type");
	        else
	            	martial = "unarmed";
    	} 
    	else{
			if( member_array(martial,skill_list) != -1)
            		return notify_fail("这种特殊招式不需指定武功种类！\n");
        	if( martial == "move")
        		return notify_fail("此类特殊招式应该使用闪躲术(dodge)的外功。\n");    
    	}
    	
    	mylevel = F_LEVEL->get_level(me->query("combat_exp"));
    	force = me->query("force");
    	if (userp(me) && mylevel > 50 && force < 50)
    		return notify_fail("使用特殊招式至少需要50点的内力。\n");	
    	
    	if( userp(me) && ANNIE_D->check_buff(me,"forceshield") && force < 300)
    		return notify_fail("在运行护盾类武功时使用特殊招式至少需要300点的内力。\n");	
    		
    	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
    	
    	if( stringp(skill = me->query_skill_mapped(martial)) ) {
	        if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time()
        		&& member_array(arg,freepass)== -1 )// 在战斗中　%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"一招不慎，露出了好大的一个破绽！！！\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n你运力不慎，没用出绝招反而露出了空门！\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
	        	
	        if( SKILL_D(skill)->perform_action(me, arg) ) {	        	       	
				if (userp(me) && member_array(arg,freeforce)== -1 && me->query_temp("pfm/free_perform")<1) {
					if (mylevel>50)
		        	{	  		
		        		force2 = me->query("force");
		        		if( ANNIE_D->check_buff(me,"forceshield")) {
		        			if (force - force2 < 300)
		        				me->set("force", force - 300);
		        		} else
		        		{		        			
		        			if (force - force2 < 50)
		        				me->set("force",force-50);
		        		}		        	
		        	}
	        	}
	        	// Give a mark for zeor force perform
	        	if (me->query_temp("pfm/free_perform")>0) {
					me->add_temp("pfm/free_perform",-1);
					if (me->query_temp("pfm/free_perform")<1)
						me->delete_temp("pfm/free_perform");
				}
	        	me->force_status_msg("force");
	            return 1;
	        
	        } else 
	        	return 0;
    	}
    	return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}



int help (object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	perform [<武功种类>]<招式名称> [<施用对象>][0m
[0;1;37m────────────────────────────────[0m   

风云中的武功可归为四大类：（分别对应的使用命令为）
（1）传统武技（如神机刀法、棋道心法）：（perform/exert）
（2）法术：（如兴国禅寺的八识神通）：(conjure)
（3) 咒术：（如三清的三清道术、大昭的观音六字明咒）：(cast)
（4）降头术：（如帝王谷的通天降，狼山的血狼咒）：（curse）

所谓传统武技多指拳脚、剑法、刀法等，这些功夫通常有一些特
殊的攻击招式，可以用这个指令来使用。

先用 enable 指令指定你所使用的武功，比如说
	enable sword diesword 后，就能使用其招式“彩蝶狂舞”
	perform caidiekuangwu

不属於拳脚跟武器技能的武功必须指明所用的基本武功，例如
	perform iron-cloth.daoqiangburu
	perform dodge.yexuechuji
	perform herb.canyunbi

而拳脚功夫或者兵器功夫则可以省略掉基本武功这一项，例如
	perform duangechangmeng
	perform tianxiawugou

在通常情况下，在有多个对手时，许多特殊招式可以制定对手，
比如说你在与 oldman, waiter, badguy 三个人厮杀，
使用
	perform dodge.luoyeqiufeng waiter
就可以将“落叶秋风”的特技使用到waiter上。	

在战斗中使用特殊技能有2%的可能会失败，造成自己忙乱，修习某些
特定的武功可以降低此概率。

使用一次特殊招式至少需要消耗50点内力。
（等级51以下可免去此要求）

注:
	风云中有的武功需要两人或多人才能使出，其格式为：
perform [<武功种类>]<招式名称> [<施用对象>] with 同伴名字

比如说，少林的莲心刀法，其使用的格式为：

perform yipianlianxin 敌人名字 with 同伴名字
perform yipianlianxin with 同伴名字

同理，铁雪的刀剑若梦，其使用的格式为：

perform daojianruomeng 敌人名字 with 同伴名字
perform daojianruomeng with 同伴名字

[0;1;37m────────────────────────────────[0m   
HELP
        );
    return 1;
}
 
