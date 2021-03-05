#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "任务宝箱" NOR, ({ "baoxiang" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个金色的宝箱，上面刻着几个字：任务奖励。ｏｐｅｎ\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg,int expnum)
{
        object gold, me,ob;
		me = this_player();
        if(arg != "baoxiang" && arg != "任务宝箱") return 0;
        if(query("opened"))
                return notify_fail("你打开任务宝箱，但里面是空的！\n");
 //       gold = new("/obj/money/gold");
 //       gold->set_amount(666);
 //       gold->set("name","纯金叶子");
 //       gold->set("base_unit","张");
 //       gold->move(this_player());
 //       ob=new("/d/wolfmount/npc/obj/zhuguo");
 //       ob->move(this_player());
        expnum=random(3000);
      if( me->query("combat_exp") >= 10000000 ) {
					me->add("extra_exp", expnum);
	}
	  me->add("combat_exp",expnum);
        me->add("potential",expnum/5);
        me->add("score",1);
		message_vision(HIR "\n$N悄悄打开任务宝箱，两眼发光，一阵窃喜！\n" NOR,me);
		tell_object(me,WHT"\n恭喜恭喜！你被奖励了：\n" + chinese_number(expnum) + "点实战经验\n" + chinese_number(expnum/5) + "点潜能\n" + chinese_number(1)+"点综合评价\n"NOR);
        set("opened",1);
        message_vision("打开的宝箱化作一阵清烟消失了。\n"NOR,me);
	    CHANNEL_D->do_sys_channel(
		"info",sprintf("%s打开任务宝箱，得到了" + expnum + "点实战经验，" + expnum/5 + "点潜能。\n"NOR,me->name(1)));
		destruct(this_object());
        return 1;
}