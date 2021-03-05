// get.c
// last updated by April 2001.09.27     禁止在睡房里拿睡觉人的东西
// last updated by naihe 2002.09.25 
// 各文件可使用set("no_get","信息") 格式自定义no_get信息，
// 使用 set("no_get","1") 格式将使用默认信息：这个东西拿不起来。
// 之前的物件设定为 set("no_get",1) 的，也将使用默认信息。

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string from, item,no_get_message;
        object obj, *inv, env, obj2;
        int i, amount, newa;

        if( !arg ) return notify_fail("你要捡起什么东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        // Check if a container is specified.
        if( sscanf(arg, "%s from %s", arg, from)==2 ) {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
                if(wizardp(me) && living(env) && (wiz_level(me) <= wiz_level(env))
                && !env->query("ridable") && env->query_lord() != me)
                        return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
        } 
        else env = environment(me);
        
        // 不能在睡房里拿睡觉人的东西
        if (!wizardp(me) && living(env) && env->query_lord() != me)
                return notify_fail("光天化日的想抢劫啊？\n");
        else if(!wizardp(me) && env->query("no_get_from") )
                return notify_fail("边上有人看着呢，不如等人家醒了抢劫吧！\n");

        // Check if a certain amount is specified.
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("这里没有这样东西。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开拿走。\n");
                if( amount < 1 )
                        return notify_fail("东西的个数至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("这里没有那么多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() ) {
                        return do_get(me, obj);
               }else {
                        newa = (int)obj->query_amount();
                        obj->set_amount( amount );
                        obj2 = new(base_name(obj));
                        do_get(me, obj);
                        obj2->set_amount(newa - amount);
                        obj2->move(env);                        // For containers.
                        // Counting precise amount costs more time.
                        if( me->is_fighting() ) me->start_busy(3);
                        return 1;
                }
        }

        // Check if we are makeing a quick get.
        if(arg=="all") {
                if( me->is_fighting() ) return notify_fail("你还在战斗中！只能一次拿一样。\n");
                if( !env->query_max_encumbrance() )     return notify_fail("那不是容器。\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("那里面没有任何东西。\n");

                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        do_get(me, inv[i]);
                }
                write("捡好了。\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || living(obj) )
                return notify_fail("你附近没有这样东西。\n");

// 修改一下这里的描述。
        if(obj->query("no_get") )
    {
        no_get_message=obj->query("no_get");
        if(!stringp(no_get_message) || no_get_message=="1") return notify_fail("这个东西拿不起来。\n");
        else return notify_fail(no_get_message+"\n");
    }

        return do_get(me, obj);
}
       
int do_get(object me, object obj)
{
        object old_env, *enemy;
        int equipped;
        string amt,no_get_message;

        if( !obj ) return 0;
        old_env = environment(obj);

        if( obj->is_character() ) {
                if( living(obj) ) return 0;
                //      if( !userp(obj) && !obj->is_corpse() )
                //              return notify_fail("你只能背负其他玩家的身体。\n");
                // If we try to save someone from combat, take the risk :P
        }
    else if(obj->query("no_get") )
    {
        no_get_message=obj->query("no_get");
        if(!stringp(no_get_message) || no_get_message=="1") return notify_fail("这个东西拿不起来。\n");
        else return notify_fail(no_get_message+"\n");
    }

        if( obj->query("equipped") ) equipped = 1;
        if( obj->query_amount()) amt = chinese_number(obj->query_amount());
        if( obj->move(me) ) {
                if( me->is_fighting() ) me->start_busy(1);
                if( obj->is_character() )
                        message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
                else
                        message_vision( sprintf("$N%s%s%s$n。\n", 
                                old_env==environment(me)? "捡起":
                                        (old_env->is_character() ?
                                                "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
                                                "从" + old_env->name() + "中拿出"),
                                obj->query_amount()? amt : "一", 
                                obj->query_amount()? obj->query("base_unit") : obj->query("unit")), me, obj );
                return 1;
        }
        else return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : get <物品名称> [from <容器名>]
 
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}
 
