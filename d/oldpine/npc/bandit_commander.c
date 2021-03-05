#include <ansi.h>

inherit NPC;
void create()
{
        set_name("常老大", ({ "boss chang","boss","chang"}) );
        set("title", "老云寨寨主");
        set("nickname", "泼风刀王");
        set("gender", "男性");
        set("age", 53);
        set("combat_exp", 260000);
        
        set("bellicosity", 6000);
        set("attitude", "aggressive");

        set_skill("force", 60);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 70);

        set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);
		set("no_arrest",1);
        setup();

        carry_object(__DIR__"obj/glaive")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();
        carry_object(__DIR__"obj/bamboo_pipe");
}


void die()
{
         object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if (me)
        if(me->query_temp("quicksand/route_bandit") == "老云寨")
        {
                me->set_temp("quicksand/route_notice",1);
                me->delete_temp("quicksand/route_bandit");
                tell_object(me,WHT"\n恭喜你平定了老云寨的匪患!\n"NOR);
                tell_object(me,WHT"你可以去告诉小潘这个好消息了。\n\n"NOR);
        }
        ::die();
}