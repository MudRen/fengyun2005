// venomsnake.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("毒蛇", ({ "venomsnake", "snake" }) );
        set("long",     "一条昂首吐信的毒蛇正虎视眈眈地盯著你。\n");

        set("race", "蛇类");
        set("age", 3);
		set("combat_exp",20000);
        
        set_temp("apply/attack", 10);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10);
       
        setup();
}

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 2 ) {
                ob->apply_condition("snake_poison", 3);
                tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n"NOR );
        }
}
