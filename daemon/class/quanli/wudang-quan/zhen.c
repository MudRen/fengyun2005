#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int level,extra,kee,i;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［棉里藏针］只能对战斗中的对手使用。\n");
        level = (int)me->query_skill("unarmed");
        extra = (int)me->query("wudang/level");
        extra = (extra >=2000)? 2000:extra;
        if(!me->query("wudang/zhen")){ 
                me->add_temp("apply/attack",extra/20);
                COMBAT_D->do_attack(me,target,TYPE_PERFORM, 0);
                me->add_temp("apply/attack",-extra/20);
                me->start_busy(1);
                if (me->query("wudang/level") < 3000){
                        me->add("wudang/level",1);
                        if ((int)me->query("wudang/level")%100==0)
                                tell_object(me, HIW "由於你勤习棉里藏针，你的熟练度提高了。\n" NOR);
                }
                else if (me->query("family/master_id") == "master shi"){
                        me->set("wudang/zhen",1);
                        tell_object(me, HIW "由於你勤习棉里藏针，你悟出了新的变化！\n" NOR);
                        me->set("wudang/level",0);
                }
                return 1;
        }else {
                if ( me->query_skill_mapped("force") != "taijiforce")
                        return notify_fail("棉里藏针必须和太极心法配和！\n");
                me->add_temp("apply/damage",level/10);
                me->add_temp("apply/attack",level/20);
                kee = target->query("kee");
                msg = HIR "\n$N"+HIR"双手猛然一抖一拢，一股气劲向$n"+HIR"撞到！" NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                me->add_temp("apply/damage",- level/10);
                me->add_temp("apply/attack",- level/20);
                msg =  HIW "气劲呼的一声，散开消失．．．\n" NOR;
                message_vision(msg, me, target);
                for (i=0; i< (int)level/50 ;i++){
                        if( (int)target->query("kee") < kee ) { 
                                if (level>300){
                                        msg = HIY"$N"+HIY"一击命中，双手顺势向外一拨，引开了$n"+HIY"的守势！\n"NOR;
                                        message_vision(msg, me, target);
                                        target->start_busy(1);
                                        me->start_busy(1);
                                        call_out("nextattack",1,me,target);
                                        break;
                                }else{
                                        msg = HIY"$N"+HIY"一击命中，但$n"+HIY"立刻将自己护住！\n"NOR;
                                        message_vision(msg, me, target);
                                        me->start_busy(2);
                                        break;
                                }
                        }else {
                                kee = target->query("kee");
                                msg = HIY"$N"+HIY"双手一翻一抖，一股气劲又向$n"+HIY"撞到！" NOR;
                                me->add_temp("apply/damage",level/10);
                                me->add_temp("apply/attack",level/20);
                                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                                me->add_temp("apply/damage",- level/10);
                                me->add_temp("apply/attack",- level/20);
                                msg =  HIW "气劲呼的一声，散开消失．．．\n" NOR;
                                message_vision(msg, me, target);
                        }
                }
                if (i == (int)level/50 ){
                        message_vision(HIY"$N"+HIY"一招"+chinese_number(i)+"式居然全部未中，立刻露出破绽。\n"NOR,me);
                        me->start_busy(5);
                }
                return 1;
        }
}

void nextattack(object me,object target)
{
        string msg;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIR"\n$N"+HIR"脚步一转，顺势侵入$n"+HIR"内宫，一肘急击$n"+HIR"胸口！\n"NOR;
                message_vision(msg,me,target);
                damage = me->query("str") * me->query("str")/10;
                damage = (damage + random(damage))/2;
                target->receive_damage("kee", damage,me);
                msg = "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
                message_vision(msg, me, target);
                target->set_temp("damaged_during_attack", 1); 
                COMBAT_D->report_status(target);
                me->start_busy(1);
                target->start_busy(1);
                call_out("nextattack1",1,me,target);
        }
}

void nextattack1(object me,object target)
{
        string msg;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIB"\n$n"+HIB"还不及反应，$N"+HIB"已一脚跟进，双手制住$n"+HIB"左臂，\n大喝一声欲将其折断！\n"NOR;
                message_vision(msg,me,target);
                damage = me->query("str");
                damage = damage + random(damage);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/4,me);
                msg = "结果只听$n的左臂发出「喀啦」一声轻响，竟似是骨碎的声音！$n的左臂登时肿得老高！\n";
                message_vision(msg, me, target);
                target->set_temp("damaged_during_attack", 2); 
                COMBAT_D->report_status(target);
                me->start_busy(1);
                target->start_busy(1);
                call_out("nextattack2",1,me,target);
        }
}

void nextattack2(object me,object target)
{
        string msg;
        object room;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIY"\n$n"+HIY"昏迷间，$N"+HIY"已托住$n"+HIY"的腰部，飞身掠起。\n"NOR;
                message_vision(msg,me,target);
                me->start_busy(2);
                target->start_busy(2);
                room = environment(me);
                me->move(__DIR__"null");
                target->move(__DIR__"null");
                call_out("nextattack3",2,me,target,room);
        }
}

void nextattack3(object me,object target,object room)
{
        string msg;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                me->move(room);
                target->move(room);
                msg = HIR"\n$N在空中将$n"+HIR"一倒，压住$n"+HIR"将$n"+HIR"重重撞向地面！\n"NOR;
                message_vision(msg,me,target);
                me->start_busy(1);
                target->start_busy(1);
                call_out("nextattack4",1,me,target);
        }
}

void nextattack4(object me,object target)
{
        string msg;
        int damage;
        if(!target || (environment(target) != environment(me)) || !me->is_fighting(target)){
                return ;
        }else{
                msg = HIW"\n彗星落！！！\n"+HIR"$N"+HIR"压着$n"+HIR"至空中重重落下！\n"NOR;
                message_vision(msg,me,target);
                damage = me->query_skill("unarmed")*4;
                damage = (damage + random(damage))/2;
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);
                msg = "结果只听「砰」地一声巨响，$n被反震而起，像一捆稻草般飞了出去！！\n";
                message_vision(msg, me, target);
                target->set_temp("damaged_during_attack", 2); 
                COMBAT_D->report_status(target);
                me->start_busy(3);
        }
}
