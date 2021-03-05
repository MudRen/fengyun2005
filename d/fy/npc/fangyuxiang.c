#include <ansi.h>
inherit NPC;

void create()
{
        set_name("方玉香", ({ "fang yuxiang", "fang" }) );
        set("long","这位美人是银鹞子方玉飞的妹妹。\n");
        set("attitude", "heroism");
		set("title", HIW "银燕子"NOR);
        
		set("gender", "女性");
		set("per", 30);
		set("age",16);
        set("combat_exp", 300000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/move", 100);

        setup();
        carry_object(__DIR__"obj/goldcloth")->wear();
}


int accept_object(object me, object obj)
{
		object real;
		
		if( (string) obj->query("name") == "罗刹牌")
		{
        	if (REWARD_D->riddle_check(me,"计取罗刹") !=4)
        	{
        		command("say 原来是你偷的罗刹牌，你完了，松竹梅三长老不会放过你的。");
        		return 0;
        	}
        	
        	if (obj->query("fake"))
        	{
        		command("grin");
        		command("say 这罗刹牌其实是假的，本来我们还想再考验考验你，可是实在没时间。");
				command("say 所以尽管虎头蛇尾，也只能草草收场了。");
				command("sigh");
				command("say 这个你拿去吧。");
				REWARD_D->riddle_set(me, "计取罗刹", 5);
				real = new(BOOKS"skill/qiankunwuxing_50");
        		if(!real->move(me))
					real->move(environment());	
        		return 1;
			}
			
			command("say 你还是快把它还给松竹梅长老吧，否则他们不会放过你的。");
			return 0;
		}
		return 0;
}

