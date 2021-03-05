
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

        string *event1_msg=     ({
        CYN"\n痴迷之中，你执着长刀慢慢起舞，舞姿仿佛兮若轻云之蔽月，飘飘兮若流风之回雪。\n这正是非真刀法第一式：流风回雪！\n"NOR,
        MAG"\n刀光轻巧的飘转飞扬，在朦朦的薄雾中浅浅划下，宛如梦里花落。\n——梦里花落就是这一刀。\n"NOR,
        RED"\n你又回身曼旋，手中长刀"RED"轻轻振动，使出了＂烛影摇红＂。\n刀光的映射下，刀影恍若烛影，在风中摇摆不定。\n刀锋所过，一抹鲜红烛泪般随着刀影滴落。\n"NOR,
        WHT"\n舞渐渐的止了，你眼前的一切都渐渐淡去，还在的惟有漫天的星光与孤寂的明月。\n——相见争如不见，有情何似无情。笙歌散后酒初醒——\n深院月斜人静。\n"NOR,
        });

int perform(object me, object target)
{
//      object weapon;  it' a unarmed perform now * mingyue
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「月斜人静」只能对战斗中的对手使用。\n");

//      weapon = me->query_temp("weapon");
        message_vision( WHT "$N乍然沉静下来，眼中是迷朦的神色，再无纷乱的刀光，再无飞溅的鲜血。\n" NOR, me,target);
    call_out("do_yuexie", 1, me,target,0/*,weapon*/);

        me->start_busy(2);

        return 1;
}

int do_yuexie(object me,object target,int count/*,object weapon*/)
{
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
                return 0;
//      if(!present(weapon,me)||weapon->query("equipped")!="wielded")
//              return 0;
//      tell_object(me,"i="+count+event1_msg[count]);
        me->stop_busy();
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,event1_msg[count]);
        me->start_busy(2);
        if (count < 3)
        {
                count++;
            call_out("do_yuexie", 1, me,target,count/*,weapon*/);
        }
        return 1;
}


