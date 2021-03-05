
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "清师令" NOR, ({ "qingshi ling", "qingshi", "ling" }) );
        set_weight(100);

        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
                set("long", HIG "可使用他用来清除(qingshi )脱离师门不良记录一个。\n" NOR);
                set("value", 20000000);
                set("no_sell", 1);
                set("no_pawn",1);
                set("no_drop",1);
                set("no_give",1);
                set("unit", "块");
              
        }

        ::init_item();
}

void init()
{
        add_action("do_qingshi", "qingshi");
}

int do_qingshi(string arg)
{
        object me;
        me = this_player();

        if( arg ) return notify_fail("使用格式：qingshi \n");
        
        	me->delete("family");
 		me->delete("once_menpai");
 		me->delete("class");
 		me->delete("betrayer");
 		

        write(HIM "清师令使用成功，你的门派记录清除了！\n" NOR);
        write(HIG "清师令画作一缕青烟逐渐消失了！\n" NOR);
        me->save();
        destruct(this_object());

        return 1;
        //betrayer
}

