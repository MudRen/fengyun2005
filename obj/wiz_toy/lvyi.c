#include <ansi.h>

inherit ITEM;

int is_magic_item() { return 1; }

void create()
{
        set_name(NOR + MAG "绿绮" NOR, ({ "lvyi qin", "lvyi", "qin" }) );
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", NOR + MAG "这是一张传世名琴，琴内有铭文曰\n"
                                      "“桐梓合精”，即桐木、梓木结合的精华。\n"
                                      "相传弹奏(tan)后可恢复所有精、气、内力和异常状态。\n" 
                                      "使用tan ? 查看使用次数。\n" NOR);
              set("value", 20000);
                 set("material", "杉木");   

        }
        	::init_item();
}

void init()
{
        add_action("do_tan", "tan"); 
}

int do_tan(string arg)
{
        object me;
        mapping my;
        
        me = this_player();
        
        if(! objectp(present("lvyi qin", me)))return 0;
       if (arg && arg != "?")
       	   return notify_fail("请使用 tan ? 查看使用次数 。\n");
        if (arg == "?")
        {
                 write(HIG "使用次数 " + this_object()->query("count") + "/10\n" NOR);
                 return 1;
        }
                
        if (me->is_fighting() || me->is_busy())
                 return notify_fail("你正忙呢！\n");

        message_sort(NOR + MAG + "$N" NOR + MAG "盘膝而坐，轻轻地拨弄着绿绮琴，"
                                 "伴随着令人心醉的琴声，$N" NOR + MAG "只觉得周身"
                                 "舒泰之极。\n" NOR, me);

        my = me->query_entire_dbase();
        my["gin"]   = my["eff_gin"]   = my["max_gin"];
        my["sen"] = my["eff_sen"] = my["max_sen"];
        my["kee"]     = my["eff_kee"]     = my["max_kee"];
        my["force"]  = my["max_force"];
        my["food"]   = me->max_food_capacity();
        my["water"]  = me->max_water_capacity();
        me->clear_condition();
        me->save();
        
        me->start_busy(2);
        this_object()->add("count", 1);
        if (this_object()->query("count") >= 10)
        {
                write(HIW "只听得一阵脆响，绿绮似乎已经被你弹坏了。\n" NOR);
                destruct(this_object());        
        }

        return 1;
}
