// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
	int attr, max_attr;
	object room;
    seteuid(getuid());
    
    if( me->is_fighting() )
    	return notify_fail("战斗中不能打坐，会走火入魔的。\n");
    if( me->is_busy() )
        return notify_fail("你上一个动作还没有完成，不能打坐。\n");
	room = environment(me);
	if(room->query("NONPC") || room->query("no_fight") || room->query("no_pk")
		|| room->query("no_magic") || room->query("no_preach")
      	|| room->query("no_beg") || room->query("no_dazuo") || room->query("no_death_penalty")
		|| room->query("no_steal") || room->query("no_spells"))
		return notify_fail("你不可以在这里打坐。\n");
	if(me->is_ghost())
		return notify_fail("鬼魂不能打坐。\n");
	
	if (me->query("death_revive")+ 180 > time())
		return notify_fail("你现在的身体状况无法吐纳练功。\n");
	
	if (me->query("food") <= 0 || me->query("water") <=0)
		return notify_fail("你的食物或饮水为零，打坐是不会有效果的。\n");
	
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N盘腿跌坐在地上，闭上眼睛开始调息打坐。\n",me);
    me->set_temp("disable_inputs",1);

   	me->add_temp("block_msg/all", 1);
	me->set_temp("is_unconcious",1);
    me->set("disable_type",HIG "<打坐中>" NOR);
	me->set_temp("in_dazuo",1);
    me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me:), 4+ random(6));
	return 1;
}

void remove_dazuo(object me)
{
   	int attr, max_attr;
   	
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");


	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);


	me->delete_temp("in_dazuo");
   	me->delete_temp("is_unconcious");
   if(!me->is_ghost() && (int) me->query("food") > 0 && (int)me->query("water") > 0)
  {
	attr = (int) me->query("food");
	attr = attr  /10 * 5;
	me->set("food",attr);

        attr = (int) me->query("water");
        attr = attr  /10 * 5;
        me->set("water",attr);

	attr = (int)me->query("kee");
	max_attr = (int)me->query("eff_kee");
	if( 2*attr > max_attr) attr = max_attr;
	else attr *=2;
	me->set("kee",attr);
        attr = (int)me->query("gin");
        max_attr = (int)me->query("eff_gin");
        if( 2*attr > max_attr) attr = max_attr;
        else attr *=2;
        me->set("gin",attr);
        attr = (int)me->query("sen");
        max_attr = (int)me->query("eff_sen");
        if( 2*attr > max_attr) attr = max_attr;
        else attr *=2;
        me->set("sen",attr);

        attr = (int)me->query("mana");
        max_attr = (int)me->query("max_mana");
	if(attr < max_attr)
        {
	        if( 2*attr > max_attr) attr = max_attr;
	        else attr *=2;
        	me->set("mana",attr);
        }
        attr = (int)me->query("force");
        max_attr = (int)me->query("max_force");
        if(attr < max_attr)
        {
                if( 2*attr > max_attr) attr = max_attr;
                else attr *=2;
                me->set("force",attr);
        }
        attr = (int)me->query("atman");
        max_attr = (int)me->query("max_atman");
        if(attr < max_attr)
        {
                if( 2*attr > max_attr) attr = max_attr;
                else attr *=2;
                me->set("atman",attr);
        }
	me->status_msg("all");
	me->force_status_msg("all");
 	message_vision("$N从忘我的境界中回神敛气，睁开了眼睛。\n",me);
  }

}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	dazuo[0m
[0;1;37m────────────────────────────────[0m   

使你进入忘我的打坐状态中，可以增快精力，气血，心神，灵力，
内力，法力的恢复速度。

[0;1;37m────────────────────────────────[0m   

HELP
        );
        return 1;
}
 
