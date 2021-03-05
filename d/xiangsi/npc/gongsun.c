// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
int look_stone();

void create()
{
	set_name("公孙无胜", ({ "gongsun wusheng","gongsun","wusheng" }) );
	set("class","huashan");
	set("gender", "男性" );
	set("age", 75);

	set("title",YEL"平生无胜"NOR);

	set("attitude", "friendly");

	set("long",CYN"公孙无胜睨了你一眼。\n\n"NOR);
	set("chat_chance", 1);
	set("chat_msg", ({
	CYN"公孙无胜傲然道：老夫公孙败，落魄江湖数十年，与人交手，从无一胜，因此\n改名公孙败，表字无胜。\n"NOR,
	}) );

	set("death_msg",CYN"\n公孙无胜惨笑道：老夫与你交手，本就不求一胜。\n"NOR);

	set("inquiry",([
       	"月神": 	"月神乃是当下价格最高的杀手，可惜老夫遍访不得，不能在她手中求得一败。\n",
       	"铁银衣": "铁老儿是李家庄的大总管。\n",
       	"李家庄": "便是当年李寻欢后人的庄园了。\n",
		"李坏": (: look_stone :),
    	]) );


	set("combat_exp", 1500000);

	set("reward_npc",1);
	set("difficulty",1);

	set_skill("move", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("shuaijiao",140);
	set_skill("13-sword",1);
	map_skill("dodge","13-sword");
	map_skill("unarmed","shuaijiao");
	set_skill("force",200);
	set_skill("liangyi-force",200);
	set_skill("hanmei-force",200);
	map_skill("force","liangyi-force");
	

		set("perform_busy_d", "npc/dodge/13-sword/rufengsibi");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	setup();

	carry_object(__DIR__"obj/robe")->wear();
	carry_object(__DIR__"obj/wine");

}

void die()
{
	object me;
	object wine;
	me = query_temp("last_damage_from");
	if (me )
	{
		if (REWARD_D->riddle_check(me,"两世恩怨") == 7 && me->query_temp("annie/riddle/moonmaster") == 10)
		{
			message_vision(CYN"\n公孙无胜闷哼一声，收住身形。\n"NOR,me);
			ccommand("say 好，好本事，除李坏外，你是第一个击败我之人。");
			ccommand("say 当年与李坏一战，他曾向我允诺，只要执着这个葫芦，便可任意求他一事。");
			ccommand("say 这葫芦我留着已经三年，现在就送与你吧。");
			wine=new(__DIR__"obj/wine");
			wine->move(me);
			message_vision(CYN"\n公孙无胜将葫芦递给$N，击掌长歌，飘然而去，山谷中只剩下优越的歌声回响：\n年半心事总艰寒，为信天命仍多难。掸尘不知身远近，被发渐觉性疏狂。\n月满屡惊蝶归梦，夜长偏诵鬼华章。料得尘缘终须尽，素衣朱颜度风凉……\n\n"NOR,me);
			REWARD_D->riddle_set(me,"两世恩怨",8);
			destruct(this_object());
			return;
		}
	}
	::die();
}

int look_stone()
{
	object me;
	me=this_player();

	if (REWARD_D->riddle_check(me,"两世恩怨") == 7 		// to get lots of winepots ...
		|| REWARD_D->riddle_check(me,"两世恩怨") == 8)
	{
		ccommand("hmm");
		ccommand("say 想见李坏，先拿出你的本事再说！");
		me->set_temp("annie/riddle/moonmaster",10);
		kill_ob(me);
		return 1;
	}
	message_vision("$N说道：李坏是小李飞刀传人，铁银衣老儿曾经提过。\n"NOR,this_object(),this_player());
    return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
