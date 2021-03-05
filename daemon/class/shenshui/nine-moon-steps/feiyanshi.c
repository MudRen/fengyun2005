#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	object *enemy,*enemy_here;
	
	if (me->query("class")!="shenshui")
		return notify_fail("只有神水弟子才能使用『飞雁式』");
		
	if ( me->query_skill("nine-moon-steps",1) < 150
		|| me->query_skill("chaos-steps",1) < 100)
		return notify_fail("『飞雁式』需要150级的九阴步法和100级的倒乱七星步。\n");
	
	if( !target ) target = me;
	if( target != me)
		return notify_fail("『飞雁式』只能对自己使用。\n");
	
	enemy=me->query_enemy();
	if (enemy)	
		enemy_here=filter_array(enemy,(: environment($1)==environment($2) :),me);
	
	if (!enemy_here || !sizeof(enemy_here))
		return notify_fail("『飞雁式』只能在战斗中使用。\n");

	if(!me->is_fighting() )	
		return notify_fail("『飞雁式』只能在战斗中使用。\n");
			
	if (me->query("force")<150)
		return notify_fail("『飞雁式』至少需要150点的内力。\n");
	if (userp(me))	me->add("force",-150);
	
	msg = HIG "\n$N"HIG"虚晃一招，突然一飘一闪，似燕子般斜飞出去。。。。\n" NOR;
	message_vision(msg, me);
		
	me->delete_temp("marks/escape");
	GO_CMD->do_flee(me);

	me->perform_busy(1);		
	return 1;
}






/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
