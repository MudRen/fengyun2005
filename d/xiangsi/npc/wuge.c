// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int blade_book();
int starrain_book();
int spells_book();

void create()
{
	set_name("薛无歌", ({ "xue wuge", "wuge","xue" }) );
	set("class","moon");
	set("gender", "男性" );
	set("age", 25);

	set("nickname",HIY"轻狂不复少年时"NOR);
	set("title","皓月宫"NOR);
	set("attitude", "friendly");

	set("long","若有所思，双目微闭，他一身青衫笔挺，正是忘机密藏的守护之人。\n如果你需要什么书籍，可以向他打听打听。\n");

	set("no_arrest",1);
	set("inquiry",([

       	"月神": 	"素姐姐？她出门去了。\n",
       	"李坏": 	"休在我面前提那个负心薄幸之徒！\n",

		"recent": 	"刀法进阶，奇术观览，星海纵横，你想借哪本？\n",
       	"recent book": 	"刀法进阶，奇术观览，星海纵横，你想借哪本？\n",
       	"book": 	"刀法进阶，奇术观览，星海纵横，你想借哪本？\n",
       	"书": 	"刀法进阶，奇术观览，星海纵横，你想借哪本？\n",
       	"书籍": 	"刀法进阶，奇术观览，星海纵横，你想借哪本？\n",
       	"借书": 	"刀法进阶，奇术观览，星海纵横，你想借哪本？\n",
		"刀法进阶" : 	(: blade_book :),
		"奇术观览" : 	(: spells_book :),
		"星海纵横" : 	(: starrain_book :),
    	]) );


	set("combat_exp", 3600000);

	set_skill("starrain", 180);
	set_skill("throwing", 200);
	map_skill("throwing","starrain");

	set_skill("force", 200);
	set_skill("snowforce", 200);
	map_skill("force","snowforce");

	set_skill("dodge", 200);
	set_skill("move", 200);
	
	set_skill("stormdance", 150);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");
	map_skill("parry", "starrain");
	
	set_skill("unarmed",200);
	set_skill("lingxi-zhi",200);
	map_skill("unarmed","lingxi-zhi");

	setup();

	carry_object(__DIR__"obj/ccloth")->wear();
	carry_object(__DIR__"obj/feidao")->wield();

}


int blade_book()
{
	object me = this_player(),book;
   /*   if (!query("bladebook") || me->query("class") != "moon")
	{
		message_vision(CYN"$N说道：抱歉，书已经被人借走了。\n"NOR,this_object());
		return 1;
	}                    */   //add by ldb           一直能借 
	if (me->query("annie/moon_borrowbook"))
	{
		message_vision(CYN"$N冷冷的看了$n一眼，说道：你上次借走的书，还没有还。\n"NOR,this_object(),me);
		return 1;
	}    
	ccommand("ok");
	book = new("/obj/book/blade_51");
	message_vision(CYN"$N在书架上梭巡片刻，抽出一本书籍递给$n。\n"NOR,this_object(),me);
	if (book->move(me))
	{
		add("bladebook",-1);
		message_vision(CYN"$N说道：读过了，记得还来。\n"NOR,this_object(),me);
		me->set("annie/moon_borrowbook",1);
	}
	else
	{
		message_vision(CYN"$N一脚踢在$n的屁屁上，印出一个清楚的鞋印。\n"NOR,this_object(),me);
		message_vision(CYN"$N说道：先去倒掉垃圾，再来借书。\n"NOR,this_object(),me);
		destruct(book);
	}
	
	return 1;	
}

int spells_book()
{
	object me = this_player(),book;
    /*	if (!query("spellsbook") || me->query("class") != "moon")
	{
		message_vision(CYN"$N说道：抱歉，书已经被人借走了。\n"NOR,this_object());
		return 1;
	}                     */        //add by ldb           一直能借 
	if (me->query("annie/moon_borrowbook"))
	{
		message_vision(CYN"$N冷冷的看了$n一眼，说道：你上次借走的书，还没有还。\n"NOR,this_object(),me);
		return 1;
	}
	ccommand("ok");
	book = new("/obj/book/spells_51");
	message_vision(CYN"$N在书架上梭巡片刻，抽出一本书籍递给$n。\n"NOR,this_object(),me);
	if (book->move(me))
	{
		add("spellsbook",-1);
		message_vision(CYN"$N说道：读过了，记得还来。\n"NOR,this_object(),me);
		me->set("annie/moon_borrowbook",1);
	}
	else
	{
		message_vision(CYN"$N一脚踢在$n的屁屁上，印出一个清楚的鞋印。\n"NOR,this_object(),me);
		message_vision(CYN"$N说道：先去倒掉垃圾，再来借书。\n"NOR,this_object(),me);
		destruct(book);
	}
	
	return 1;	
}

int starrain_book()
{
	object me = this_player(),book;
   	if (!query("starrain") || me->query("class") != "moon")
	{
		message_vision(CYN"$N说道：抱歉，书已经被人借走了。\n"NOR,this_object());
		return 1;
	}                                       
	if (me->query("annie/moon_borrowbook"))
	{
		message_vision(CYN"$N冷冷的看了$n一眼，说道：你上次借走的书，还没有还。\n"NOR,this_object(),me);
		return 1;
	}
	ccommand("ok");
	book = new(__DIR__"obj/starrain");
	message_vision(CYN"$N在书架上梭巡片刻，抽出一本书籍递给$n。\n"NOR,this_object(),me);
	if (book->move(me))
	{
		add("starrain",-1);
		message_vision(CYN"$N说道：读过了，记得还来。\n"NOR,this_object(),me);
		me->set("annie/moon_borrowbook",1);
	}
	else
	{
		message_vision(CYN"$N一脚踢在$n的屁屁上，印出一个清楚的鞋印。\n"NOR,this_object(),me);
		message_vision(CYN"$N说道：先去倒掉垃圾，再来借书。\n"NOR,this_object(),me);
		destruct(book);
	}
	
	return 1;	
}


int accept_object(object who, object ob)
{
	if(ob->query("skill/name") == "blade" && ob->name() == "刀法进阶")
	{
		if (!who->query("annie/moon_borrowbook"))
		{
			ccommand("hmm "+who->query("id"));
			message_vision(CYN"$N问道：这本书你从哪里得来？\n"NOR,this_object(),who);
		}
		else
		{
			ccommand("pat "+who->query("id"));
			ccommand("say 有借有还，再借不难。");
			ccommand("smile "+who->query("id"));
			who->delete("annie/moon_borrowbook");
		}
		return 1;
	}
	if(ob->query("skill/name") == "spells" && ob->name() == "奇术观览")
	{
		if (!who->query("annie/moon_borrowbook"))
		{
			ccommand("hmm "+who->query("id"));
			message_vision(CYN"$N问道：这本书你从哪里得来？\n"NOR,this_object(),who);
		}
		else
		{
			ccommand("pat "+who->query("id"));
			ccommand("say 有借有还，再借不难。");
			ccommand("smile "+who->query("id"));
			who->delete("annie/moon_borrowbook");
		}
		return 1;
	}
	if(ob->query("skill/name") == "starrain" && ob->name() == "星海纵横")
	{
		if (!who->query("annie/moon_borrowbook"))
		{
			ccommand("hmm "+who->query("id"));
			message_vision(CYN"$N问道：这本书你从哪里得来？\n"NOR,this_object(),who);
		}
		else
		{
			ccommand("pat "+who->query("id"));
			ccommand("say 有借有还，再借不难。");
			ccommand("smile "+who->query("id"));
			who->delete("annie/moon_borrowbook");
		}
		return 1;
	}
	return 0;
}


void killed_enemy(object who)
{
	message_vision(CYN"薛无歌对$N摇头叹道：其实生活可以优渥挥霍，也可以简朴平实。\n要有梦、有理想，日子就可以过得舒适愉悦——你实在不该来的。"NOR,who);
}

