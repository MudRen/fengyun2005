#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "新春红包" NOR, ({ "hong bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的红包，上面绣着：恭喜发财。\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me,ob;
        me = this_player();
        if(arg != "hong bao" && arg != "新春红包") return 0;
        if(query("opened"))
                return notify_fail("你打开小红包，但里面是空的！\n");
        gold = new("/obj/money/gold");
        gold->set_amount(666);
        gold->set("name","纯金叶子");
        gold->set("base_unit","张");
        gold->move(this_player());
        ob=new("/d/wolfmount/npc/obj/zhuguo");
        ob->move(this_player());
        me->add("combat_exp",20000);
        me->add("potential", 10000);
        me->add("score",1000);
        message_vision(HIR "\n$N悄悄打开红包，两眼发光，一阵窃喜！\n\n" NOR,me);
        tell_object(me,HIC"\n恭喜恭喜！你被奖励了：\n" + chinese_number(20000) + "点实战经验\n" + chinese_number(10000) + "点潜能\n" + chinese_number(1000)+"点综合评价\n"NOR);
        message_vision(WHT"一粒红色的，散发着诱人香味的"+ob->query("name")+WHT"从红包里掉到$N手中。\n"NOR,me);
        set("opened",1);
        return 1;
}
