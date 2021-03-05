inherit NPC;
#include <ansi.h>
int kill_him();

void create()
{
    set_name("石观音", ({ "shi guanyin","guanyin" }) );
    set("nickname", HIG"芳华永驻"NOR );
    set("gender", "女性" );
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("agi",100);

    set("force_factor", 400);

    set("long","
石观音的美丽，竟已是今人不能想象的，因为她的美丽已全部占据了人们
的想象力。有很多人都常用“星眸”来形容女子的美丽，但星光又怎及她
这双眼睛的明亮与温柔。有很多人都常用“春山”来形容美女的眉，但纵
是雾里朦胧的春山也不及她秀眉的婉约。\n");
    	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        		"石观音道：“你......你不觉我老？”\n",
            		"石观音笑了笑，又道：“你可知道这里是什么地方？”\n",
            		"石观音眼光突然朦胧，柔声道：“你既知道，为何还不过来？”\n",
        }) );

    	set("chat_chance_combat", 90);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.yaozhan" :),
        }) );
    	set("combat_exp", 99999999);
    	set("inquiry", ([
        	"无花" : 	(: kill_him :),
        	"李姑娘" : 	(: kill_him :),
        	"李菊" : 	(: kill_him :),
        	"天枫十四郎" : 	(: kill_him :),
        	"南宫灵" : 	(: kill_him :),
        	"极乐之星": 	"极乐之星是龟兹王的宝物，据说里面藏着一个大秘密。\n",
        	"龟兹王": 	"龟兹王是西域龟兹国的国王。\n",
        ]));
    	set_skill("unarmed", 200);
    	set_skill("blade", 250);
    	set_skill("charm", 200);
    	set_skill("force", 200);
    	set_skill("parry", 200);
    	set_skill("literate", 200);
    	set_skill("dodge", 200);
    	set_skill("kongshoudao", 200);
    	set_skill("wind-blade", 180);
    	set_skill("ghosty-force", 300);
    	set_skill("ghosty-steps", 100);

    	map_skill("unarmed", "kongshoudao");
    	map_skill("blade", "wind-blade");
    	map_skill("force", "ghosty-force");
    	map_skill("parry", "wind-blade");
    	map_skill("dodge", "ghosty-steps");

    	setup();
    	carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/guyuehan")->wield();
}


void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你已经知道我的来历了！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}


int accept_object(object who, object ob)
{
	
	object item;
	if (ob->query("guizi")) {
		if (who->query_temp("zangbei/龟兹_还极乐")) {
			message_vision(CYN"
石观音微微一笑，声音光滑得像缎子一般，奴家不是早把『极乐之星』交还给你了么？”\n"NOR,who);
			return 0;
		}
		
  if (ob->query("item_owner")!=who) {
			message_vision(CYN"
石观音微微一笑，声音光滑得像缎子一般，“"+RANK_D->query_respect(who)+"一路辛苦，奴家原应拿出
『极乐之星』，只是贱妾如何向龟兹王交待呢？”\n"NOR,who);
			return 0;
		}
			
		message_vision(CYN"
石观音微微一笑，声音光滑得像缎子一般，“"+RANK_D->query_respect(who)+"一路辛苦，这『极乐之星』
贱妾替龟兹王保管已久，如今物归原主，贱妾亦可安心了。”\n"NOR,who);
		item = new(__DIR__"obj/gem");
		item->move(who);
		item->set("item_owner",who);
		who->set_temp("zangbei/龟兹_还极乐",1);
		message_vision(CYN"$N递给$n一颗"+item->name()+CYN"。\n"NOR,this_object(),who);
		return 1;
	}
		
	if(ob->query("name")=="乌鞘长刀") {	// we let ppl get this saki again if lost.
		if (REWARD_D->riddle_check( who,"浪人的悲哀")!= 3 
			&& REWARD_D->riddle_check( who,"浪人的悲哀")!= 4 )
//		if(!who->query("天枫_quest3"))
		{
			message_vision("石观音皱了皱眉：你这把刀是哪里来的。。。？\n",who);
			return 0;
		}
		message_vision("石观音抽出长刀，凝神伫立半晌，脸色变幻不停，似乎苍老了许多。。。\n",who);
		call_out("give_saki",5,who);
		who->perform_busy(3);
		return 1;
	}
	
	return 0;
}


int give_saki(object who)
{
	object saki;
		
	if(!who || environment(who)!=environment()) return 0;
    
    message_vision(HIY"石观音突然嫣然一笑道：一夜夫妻百日恩，唉，就劳烦这位"+ RANK_D->query_respect(who) +"把这瓶清酒
送于他，就算奴家报答当日情了。\n\n"NOR,who);
	saki=new(__DIR__"obj/saki");
	if (!saki->move(who))
		saki->move(environment());
	REWARD_D->riddle_set( who, "浪人的悲哀",4);
	who->stop_busy();
//	who->set("天枫_quest4","成功");
	return 1;
}
