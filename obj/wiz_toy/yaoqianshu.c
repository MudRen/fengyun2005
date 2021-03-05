// 上古十大神器之 摇钱树 
// 可使用三次
// Create by Rcwiz for Hero.cn 2003/08

#include <ansi.h>

inherit ITEM;

int is_magic_item() { return 1; }

void create()
{
        set_name(NOR + YEL + "摇钱树" NOR, ({ "yaoqian shu", "yaoqian", "shu" }) );
        set_weight(100);
        set("value", 1000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");               
                set("long", NOR + YEL "这是一颗摇钱树，有半人高，树支上挂满了各种\n"
                                      "金银铜钱。\n"
                                      "可以将树上的钱币摇(yao)下来。\n" NOR);                
        }
         	::init_item();
}

void init()
{
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object me, g;
        int i;
        
        me = this_player();
        
        if(! objectp(present("yaoqian shu", me)))return 0;

        if (me->is_fighting() || me->is_busy())
                 return notify_fail("你正忙呢！\n");
       
        if (this_object()->query("count") >= 3)
                 return notify_fail("这颗摇钱树已经不能再摇出任何东西了！\n");

         message_vision(NOR + YEL + "\n$N" NOR + YEL "双手抱着摇钱树使劲的摇动着，"
                      "一时间，金银元宝纷纷落在地上，金光闪闪，令人砰然心动。\n" NOR, me);

        i = 100 + random(100);
        g = new("/obj/money/gold");
        g->set_amount(i);
        g->move(environment(me));

        this_object()->add("count", 1);
        if (this_object()->query("count") >= 3)
        {
                tell_object(me, HIG "伴随着一道光芒化过，摇钱树钻入地下，消失了！\n" NOR);
                destruct(this_object());
        }
        
        return 1;
}
