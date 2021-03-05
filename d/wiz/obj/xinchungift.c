#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIC "新春礼物" NOR, ({ "gift" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "件");
            set("no_drop",1);
            set("no_get",1); 
            set("material", "cloth");
            set("long", "一个大大的礼包，连续做满5个任务可以从礼物大使那里领到。还有机会得大奖噢你似乎可以打开(open)。\n");
        

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
        object note,gift,me;
        object obj;
        int level, base,bonus,combat_exp,silver;
        me = this_player();
        bonus=1;
        if(arg != "gift" && arg != name()) return 0;
     //   if (me->query("hgift/2011/xinchun"))
       //     return notify_fail("你已经开过礼物了，做人不能太贪心！\n");
        if(query("opened"))
                return notify_fail(name()+"好像被人打开过了，里面的东西被人拿光了！\n");
       
        if(!random(500))
		{
                        bonus = 10;
                    
			write(HIW"你拿到了大奖，恭喜恭喜！\n"NOR);
		}
       
      level = F_LEVEL->get_level(me->query("combat_exp"));
      base =  2*REWARD_D->quest_reward(level);
combat_exp = base * bonus * (100 + QUESTS_D->query_holiday())/100;
if (me->query("env/ability") 
			&& F_LEVEL->get_level(me->query("combat_exp"))>=80
			&& me->query("saved_quest")/60/100 < me->query("learned_ability") + 6) 
		{
			me->add("saved_quest",2*60*bonus);
			if (QUESTS_D->query_holiday())
				me->add("saved_quest",2*60*bonus*QUESTS_D->query_holiday()/100);
		}	
else {
			
			if (me->query("combat_exp")>= 10000000) {
				me->add("extra_exp", combat_exp);
			}
			
			if (me->query("combat_exp") < 10000000)
				me->add("combat_exp", combat_exp);
		
			if (me->query("combat_exp")>= 10000000)
				me->set("combat_exp",10000000);
		}
 silver = 30 * bonus * (100 + QUESTS_D->query_holiday())/100 ;
  me->add("deposit",silver*100);
	tell_object(me,WHT"\n恭喜你打开"+name()+"！，你得到了:\n" + chinese_number(silver) + "两银子！\n"+chinese_number(combat_exp)+"点经验！\n"NOR);
       
	
        set("opened",1);
       // me->set("hgift/2011/xinchun",1);
        destruct(this_object());
        return 1;
}
