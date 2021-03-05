/* // Silencer @ FY4 workgroup. Aug.2004
	『雾隐』〔wuyin〕：中土五行遁甲术的一个变种，以浓雾防碍敌
方视野，化身身畔之物来避开他人的追击。虽远不及神水宫的假死术，在
山穷水尽之时却也是忍者唯一的生机。（需200级，成功率60%）
*/


#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
	int skill, n,duration,i;
	string msg;
	object *inv;
	
	skill = me->query_skill("ninjitsu",1);
	if ( skill < 200)
                return notify_fail("雾隐需要200级的忍术！\n");
                        
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("你不在战斗中，不需要雾隐。\n");

	duration = me->query("timer/pfm/wuyin")+ 1200 - time();
	if (duration >0)
		return notify_fail("需要等待"+ duration/60 + "分钟才能再次雾隐。\n");
	
	message_vision(BMAG HIM"
$N"NOR BMAG HIM"扬手，飞起一道七色虹桥，愈渐明显，奇彩流辉，彩气缤纷，霞光
澈舵。而这七道颜色又各自纵腾缠绕，化成彩凤飞龙一般，上下飞舞。
"NOR BMAG HIM"$N"NOR BMAG HIM"借机移形换影，隐入迷雾之中。\n"NOR,me);			
	    
	me->set("disable_type",HIG "<雾隐中>" NOR);
    me->set_temp("disable_inputs",1);
    me->set_temp("is_unconcious",1);
	me->set_temp("in_jiasi",1);
	me->add_temp("block_msg/all",1);
	
	n = random(100);
//	message_vision(" random(100) is " + n + "\n",me);
		
	if (n >50)	{
		message_vision( HIB"\n$N意为之乱，心为之迷，恨不得投身那幻丽的色彩里。\n"NOR,target);		
		me->remove_all_killer();
		me->remove_all_enemy();

		inv = all_inventory(environment(me));
		for (i=0;i<sizeof(inv);i++){
			if (inv[i]->query("possessed")==me)		// My pet	
			{
				inv[i]->remove_all_killer();
				inv[i]->remove_all_enemy();
			}
		}
    } else
	{
		message_vision(WHT"\n$N一掌击出，那道芒彩千寻，祥光万道的彩虹消失不见。\n"NOR, target);			
	}
	me->set("timer/pfm/wuyin",time());
	me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 40 + random(50));
	return 1;
}

void remove_dazuo(object me)
{
   	me->delete_temp("in_jiasi");
   	me->delete_temp("is_unconcious");
   	me->delete_temp("disable_inputs");
   	me->delete_temp("disable_type");
   	if (me->query_temp("block_msg/all")>0)	me->add_temp("block_msg/all",-1);
   	message_vision("$N从迷雾中慢慢现身出来。\n",me);
//	me->set("timer/jiasi",time());
}

