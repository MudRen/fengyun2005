#include <ansi.h>

inherit NPC;

void create()
{
        set_name("班察巴那", ({ "bancha bana","bancha" }) );
        set("gender", "男性" );
        set("long",
                "他的衣着依旧鲜明华丽，看来如同天神般英俊威武。\n"
                );
        set("title", "圣母峰下 第一勇士");
        set("nickname", HIY "五花箭神"NOR);
        set("attitude", "peaceful");
        set("reward_npc", 1);
	set("difficulty", 5);
	set("age", 38);
        set("per", 40);
        set("combat_exp", 1500000);
        
        set_temp("apply/damage", 100);

        set("chat_chance", 2);
        set("chat_msg", ({
                "班察巴那傲然道：卜鹰已死，我班察巴那就是圣母峰下第一勇士。\n",
                }) );
    	
    	set_skill("perception", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("throwing", 300);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/arrow")->wield();
}

int accept_fight(object me)
{
        if(me->query("combat_exp") > 500000)
        {
            command("say 好,看你似乎有点能耐,来,和我过几招!\n");
        	return 1;
        }
        else
        {
            command("say 就你?无端弄脏了我的五花神箭!\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
	command("say 想跟我斗，你还差的远呢！\n");
}
void lose_enemy(object winner)
{
	command("say 你本事不错，我口服心服。\n");
	winner->set_temp("marks/won_bancha",1);
}
