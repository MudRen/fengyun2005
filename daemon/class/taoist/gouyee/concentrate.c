// concentrate.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        int mana_gain;
        if (me->query_skill("gouyee",1)<50)
        	return notify_fail("『灵神诀』需要50级谷衣心法。\n");
        
        if( target && target!=me )
                return notify_fail("『灵神诀』只能用来恢复自己的法力。\n");
             
        if(amount == -1) amount = 30;
        else if(amount < 30 ) 
                return notify_fail("最少用三十内力。\n");

        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");
        
        if (me->query("mana") >= 2*me->query("max_mana"))
        	return notify_fail("你的法力已经是最大值了。\n");
        
        // eff. 1.5x
        mana_gain =  (10 + (int)me->query_skill("gouyee",1))*amount/100;
        
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana")*2 )
                me->set("mana", (int)me->query("max_mana")*2);
        else
                me->add("mana", mana_gain);
        me->add("force", -amount);
        message_vision(
                BGRN+ WHT "$N闭目凝神，用谷衣心法的内力运转了一次「灵神诀」．．．\n"
                "一股青气从$N身上散出，汇聚在$P的顶心，然後缓缓淡去。\n" NOR, me);

        if( me->is_fighting() ) me->perform_busy(1);
        	
        me->force_status_msg("all");
        	
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
