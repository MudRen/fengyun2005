inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()
{
		object weapon;
        set_name("了痕师太", ({ "liaohen"}) );
	    set("title",YEL"水梦庵主持"NOR);
		set("nickname",MAG"佛慈照世渡众生"NOR);
        set("gender", "女性" );
		
		set("class","shaolin");
    	set("long", "一位穿着素白僧袍的老尼，正端坐在蒲团之上，喃喃念经。\n");

		set("no_arrest",1);

		set("chat_chance", 1);
		set("chat_msg", ({
				"了痕师太微微一笑。\n",
				"了痕师太道：莲花心，不染尘，心入轮回皆为缘；心生缘，缘为心，三世因缘梦无痕。\n",
				"了痕师太道：山阴处无数怨魂，只恨近日道路阻塞，不能超度前行。\n",
		}) );

        set("inquiry",([
 		"超度"  :"想来那怨魂应当云集在葬魂谷中，你只需将其处鬼魂除尽便是。\n了痕师太顿了一顿，又道：那谷附近阴气极盛，只怕还有什么邪道法器作崇，你自己需得小心。\n",
 		"怨魂"  :"想来那怨魂应当云集在葬魂谷中，你只需将其处鬼魂除尽便是。\n了痕师太顿了一顿，又道：那谷附近阴气极盛，只怕还有什么邪道法器作崇，你自己需得小心。\n",
 		"山阴"  :"本来沿小径直走便是，但几天前一次骤雨引发的土石流将道路冲毁，现在需另觅他径。\n",
              ]) );

        set("age", 54);

        set("attitude","friendly");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//                (: smart_fight() :),
                (: ccommand("chant") :),
        }) );

        set("combat_exp", 5200000);
    
        set_skill("chanting", 150);
		set_skill("zen",250);
		set_skill("lamaism",250);
		set_skill("buddhism",250);
        
		set("skill_public",1);
        
		setup();

	carry_object("/obj/armor/cloth",([	"name": "素冷袍",
    						"long": "一件洗得发白的僧袍。\n",
    						"value": 1,
    						 ]))->wear();    
	carry_object("/obj/armor/necklace",([	"name": MAG"紫玉佛珠"NOR,
    						"long": "一条紫玉佛珠连成的颈链。\n",
    						"value": 1,
    						 ]))->wear();    
}


int recognize_apprentice(object ob)
{
	if (REWARD_D->riddle_check(ob,"超度亡魂/战死尸"))
		if (REWARD_D->riddle_check(ob,"超度亡魂/地缚"))
			if (REWARD_D->riddle_check(ob,"超度亡魂/食魂"))
				if (REWARD_D->riddle_check(ob,"超度亡魂/血炼"))
				{
					message_vision("\n了痕师太捻着佛珠，念道：阿弥陀佛，善哉，善哉。\n\n",ob);
					REWARD_D->riddle_done(ob,"超度亡魂",20,1);
					ob->set("free_learn/chanting",1);
				}

	if (!ob->query("free_learn/chanting"))
	{
		message_vision("了痕师太道：业障未除，请恕老尼无心授法讲经。\n\n",ob);
		return 0;
	}
    return 1;
}


int kill_ob(object who)
{
	ccommand("emote 念道：阿弥陀佛．．．");
	ccommand("emote 自蒲团上站起身来。");
	::kill_ob(who);
	return 1;
}



int prevent_learn(object me, string skill)
{
  if (skill != "chanting")
  {
      command("shake");
      command("say 这是学不来的，只能依靠你自己的顿悟。");
      return 1;
  }
  return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "chanting")
		return 0;
	
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

