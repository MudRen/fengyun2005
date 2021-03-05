#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
        set_name("水桶般粗细的大海蟒", ({ "sea snake","snake" }) );
        set("race", "蛇类");
        set("age", 4);
        set("long", "一条全身乌黑，布满黑斑水桶般粗细的大海蟒。\n");
        set("attitude", "aggressive");
     	
		set("str",30);
        set_skill("dodge", 100);
        
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("combat_exp", 500000);
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        tell_object(ob, HIR+"\n\n"+name()+"盘上你的全身，使劲一勒！。只听到＂咯嚓＂一声．．．\n\n" +NOR);
                ob->receive_wound("kee",100,this_object());
}


void unconcious()
{
		::die();
}
