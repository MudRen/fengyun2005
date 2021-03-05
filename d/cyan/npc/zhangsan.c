#include <ansi.h>
inherit NPC;

void create()
{
		set_name("李二", ({ "li e","e","li" }) );
        set("gender", "男性" );
        set("age", 44);
		set("title","凡人");
		set("combat_exp", 8000000);

		set("skill_public",1);

        set("attitude", "friendly");
		set_skill("unarmed", 120);
        set_skill("ironcuff", 200);

        set("chat_chance", 1);
        set("chat_msg", ({
        "李二踏节而歌：众生云云难貌相，海水滔滔难斗量，平凡不是平凡客，昼长跌坐掩松关。\n",
        "李二笑道：看起来平凡的拳法，越学你就会发现越是艰难。\n",
        }) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform heihutaoxin") :),
             }) );
		set("busy_immune",4);
		map_skill("unarmed","ironcuff");
        setup();
}



int prevent_learn(object me, string skill)
{
  if (skill != "ironcuff")
  {
      command("shake");
      command("say 基本功要你自己去打，打好了再来找我学拳法。");
      return 1;
  }
  return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "ironcuff")
		return 0;
	
	return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query("class") || ob->query("once_menpai"))
	{
		message_vision("李二哈哈大笑：你既有名师，又何必找我一介粗人指点？\n",ob);
		return 0;
	}
	if (!ob->query("free_learn/ironcuff"))
	{
		ob->set("free_learn/ironcuff",1);
		message_vision(CYN"李二笑道：好眼光。\n\n",ob);
		message_vision("李二道：我这一套铁山破拳，收进的尽是天下俗之又俗的招式，既不花巧，也不好看。\n",ob);
		message_vision("然而俗招之所以成为俗招，就是因为好用，所以常常要用，用多了大家都会，因此而不希奇。\n",ob);
		message_vision("武学大师们无不想自创武功留名，招式难免追求奇巧，倒脱了反朴归真的本意。\n",ob);
		message_vision("正所谓他强任他强，清风拂山岗，他横自他横，明月照大江，真到了战阵之上，什么机变你也不用去管，\n",ob);
		message_vision("只要老老实实地一招一式将这铁山破拳打出，不由得他不手忙脚乱。\n\n",ob);
		message_vision("李二停了一停，又道：需知学海无涯，你学不到头也不必气馁，但知自己已经尽力便可以了。\n"NOR,ob);
	}
    return 1;
}

